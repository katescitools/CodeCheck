/* UndCC_Valid 													*/
extern short func1_82 ( short n_82 );

 
extern void func2_82 ( short ); // UndCC_Violation


static short func3_82 ( ); // UndCC_Violation

/* UndCC_Valid - prototype specifies 0 parameters 				*/
static short func4_82 ( void );

/* UndCC_Valid 													*/
short func5_82 ( short n_82 )
{
	return n_82;
}


static short func6_82 ( vec_82, n_82 ) // UndCC_Violation
short *vec_82;
short n_82;
{
	return vec_82[ n_82 - 1 ];
}



short ( *pf_82 ) ( ); // UndCC_Violation

/* UndCC_Valid - prototype specifies 0 parameters 				*/
short ( *pf1_82 ) ( void );


typedef short ( *pf2_t_82 ) ( short ); // UndCC_Violation

/* UndCC_Valid 													*/
typedef short ( *pf3_t_82 ) ( short n_82 );

pf2_t_82 ptr = func1_82;
