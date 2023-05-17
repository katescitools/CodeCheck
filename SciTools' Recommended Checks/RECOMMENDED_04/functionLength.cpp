void	reallyLongFunction(float *C,const float *cP,const float *cdPdu,const float *cdPdv,const float *cN,CShadingContext *context) { // UndCC_Violation
	const CShadingScratch	*scratch		=	&(context->currentShadingState->scratch);

	// Is this a point based lookup?
	if ((scratch->occlusionParams.pointbased) && (scratch->occlusionParams.pointHierarchy != NULL)) {
		int	i;

		for (i=0;i<7;i++)	C[i]	=	0;

		scratch->occlusionParams.pointHierarchy->lookup(C,cP,cdPdu,cdPdv,cN,context);
	} else {
		CCacheSample		*cSample;
		CCacheNode			*cNode;
		float				totalWeight		=	0;
		CCacheNode			**stackBase		=	(CCacheNode **)	alloca(maxDepth*sizeof(CCacheNode *)*8);
		CCacheNode			**stack;
		int					i;
		float				coverage;
		vector				irradiance,envdir;
		vector				P,N;
		
		// A small value for discard-smoothing of irradiance
		const float			smallSampleWeight = (flags & CACHE_SAMPLE) ? 0.1f : 0.0f;

		// Transform the lookup point to the correct coordinate system
		mulmp(P,to,cP);
		mulmn(N,from,cN);
		
		// Init the result
		coverage	=	0;
		initv(irradiance,0);
		initv(envdir,0);

		// The weighting algorithm is that described in [Tabellion and Lamorlette 2004]
		// We need to convert the max error as in Wald to Tabellion 
		// The default value of maxError is 0.4f
		const float			K		=	0.4f / scratch->occlusionParams.maxError;

		// Note, we do not need to lock the data for reading
		// if word-writes are atomic
		
		// Prepare for the non recursive tree traversal
		stack		=	stackBase;
		*stack++	=	root;
		while(stack > stackBase) {
			cNode	=	*(--stack);

			// Sum the values in this level
			for (cSample=cNode->samples;cSample!=NULL;cSample=cSample->next) {
				vector	D;

				// D = vector from sample to query point
				subvv(D,P,cSample->P);

				// Ignore sample in the front
				float	a	=	dotvv(D,cSample->N);
				if ((a*a / (dotvv(D,D) + C_EPSILON)) > 0.1)	continue;

				// Positional error
				float	e1 = sqrtf(dotvv(D,D)) / cSample->dP;

				// Directional error
				float	e2 =	1 - dotvv(N,cSample->N);
				if (e2 < 0)	e2	=	0;
				e2		=	sqrtf(e2*weightNormalDenominator);

				// Compute the weight
				float	w		=	1 - K*max(e1,e2);
				if (w > context->urand()*smallSampleWeight) {
					vector	ntmp;

					crossvv(ntmp,cSample->N,N);
					
					// Sum the sample
					totalWeight		+=	w;
					coverage		+=	w*(cSample->coverage		+ dotvv(cSample->gP+0*3,D) + dotvv(cSample->gR+0*3,ntmp));
					irradiance[0]	+=	w*(cSample->irradiance[0]	+ dotvv(cSample->gP+1*3,D) + dotvv(cSample->gR+1*3,ntmp));
					irradiance[1]	+=	w*(cSample->irradiance[1]	+ dotvv(cSample->gP+2*3,D) + dotvv(cSample->gR+2*3,ntmp));
					irradiance[2]	+=	w*(cSample->irradiance[2]	+ dotvv(cSample->gP+3*3,D) + dotvv(cSample->gR+3*3,ntmp));
					envdir[0]		+=	w*(cSample->envdir[0]		+ dotvv(cSample->gP+4*3,D) + dotvv(cSample->gR+4*3,ntmp));
					envdir[1]		+=	w*(cSample->envdir[1]		+ dotvv(cSample->gP+5*3,D) + dotvv(cSample->gR+5*3,ntmp));
					envdir[2]		+=	w*(cSample->envdir[2]		+ dotvv(cSample->gP+6*3,D) + dotvv(cSample->gR+6*3,ntmp));
				}
			}

			// Check the children
			for (i=0;i<8;i++) {
				CCacheNode	*tNode;

				if ((tNode = cNode->children[i]) != NULL) {
					const float	tSide	=	tNode->side;

					if (	((tNode->center[0] + tSide) > P[0])	&&
							((tNode->center[1] + tSide) > P[1])	&&
							((tNode->center[2] + tSide) > P[2])	&&
							((tNode->center[0] - tSide) < P[0])	&&
							((tNode->center[1] - tSide) < P[1])	&&
							((tNode->center[2] - tSide) < P[2])) {
						*stack++	=	tNode;
					}
				}
			}
		}

		// Do we have anything ?
		if (totalWeight > C_EPSILON) {
			double	normalizer	=	1 / totalWeight;

			normalizevf(envdir);

			C[0]			=	(float) (irradiance[0]*normalizer);
			C[1]			=	(float) (irradiance[1]*normalizer);
			C[2]			=	(float) (irradiance[2]*normalizer);
			C[3]			=	(float) (coverage*normalizer);
			mulmv(C+4,from,envdir);		// envdir is stored in the target coordinate system
		} else {
			// Are we sampling the cache ?
			if (flags & CACHE_SAMPLE) {
				vector	dPdu,dPdv;

				// Convert the tangent space
				mulmv(dPdu,to,cdPdu);
				mulmv(dPdv,to,cdPdv);

				// Create a new sample
				sample(C,P,dPdu,dPdv,N,context);
				mulmv(C+4,from,C+4);	// envdir is stored in the target coordinate system
			} else {

				// No joy
				C[0]	=	0;
				C[1]	=	0;
				C[2]	=	0;
				C[3]	=	1;
				C[4]	=	0;
				C[5]	=	0;
				C[6]	=	0;
			}
		}

    // Do we have anything ?
		if (totalWeight > C_EPSILON) {
			double	normalizer	=	1 / totalWeight;
      
			normalizevf(envdir);
      
			C[0]			=	(float) (irradiance[0]*normalizer);
			C[1]			=	(float) (irradiance[1]*normalizer);
			C[2]			=	(float) (irradiance[2]*normalizer);
			C[3]			=	(float) (coverage*normalizer);
			mulmv(C+4,from,envdir);		// envdir is stored in the target coordinate system
		} else {
			// Are we sampling the cache ?
			if (flags & CACHE_SAMPLE) {
				vector	dPdu,dPdv;
        
				// Convert the tangent space
				mulmv(dPdu,to,cdPdu);
				mulmv(dPdv,to,cdPdv);
        
				// Create a new sample
				sample(C,P,dPdu,dPdv,N,context);
				mulmv(C+4,from,C+4);	// envdir is stored in the target coordinate system
			} else {
        
				// No joy
				C[0]	=	0;
				C[1]	=	0;
				C[2]	=	0;
				C[3]	=	1;
				C[4]	=	0;
				C[5]	=	0;
				C[6]	=	0;
			}
		}
    // Do we have anything ?
		if (totalWeight > C_EPSILON) {
			double	normalizer	=	1 / totalWeight;
      
			normalizevf(envdir);
      
			C[0]			=	(float) (irradiance[0]*normalizer);
			C[1]			=	(float) (irradiance[1]*normalizer);
			C[2]			=	(float) (irradiance[2]*normalizer);
			C[3]			=	(float) (coverage*normalizer);
			mulmv(C+4,from,envdir);		// envdir is stored in the target coordinate system
		} else {
			// Are we sampling the cache ?
			if (flags & CACHE_SAMPLE) {
				vector	dPdu,dPdv;
        
				// Convert the tangent space
				mulmv(dPdu,to,cdPdu);
				mulmv(dPdv,to,cdPdv);
        
				// Create a new sample
				sample(C,P,dPdu,dPdv,N,context);
				mulmv(C+4,from,C+4);	// envdir is stored in the target coordinate system
			} else {
        
				// No joy
				C[0]	=	0;
				C[1]	=	0;
				C[2]	=	0;
				C[3]	=	1;
				C[4]	=	0;
				C[5]	=	0;
				C[6]	=	0;
			}
		}

		// Make sure we don't have NaNs
		assert(dotvv(C,C) >= 0);
	}
}
