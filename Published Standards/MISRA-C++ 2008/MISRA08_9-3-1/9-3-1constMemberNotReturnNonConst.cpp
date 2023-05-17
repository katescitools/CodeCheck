class C_931
{
public:
	C_931 ( int & b_ ) : a_931 ( new int [ 10 ] ), b_931 ( b_ )
	{
	}
	int * getA_931 () const 		// UndCC_Violation
									// Returns non const pointer to data
	{
		return a_931;
	}
	int * getB_931 () const 		// UndCC_Violation
									// Returns non const pointer to data
	{
		return &b_931;
	}
	const int * getC_931 () const 	// UndCC_Valid
									// Returns const pointer to data
	{
		return &b_931;
	}
private:
	int * a_931;
	int & b_931;
};

int fn2_931 ( const int * a) {
	// Do something
	return 0;
}

void fn_931 ( C_931 const & c )
{
	c.getA_931()[ 0 ] = 0; 			// Modification to conceptual state of C
	*c.getB_931() = 0; 				// Modification to conceptual state of C
	fn2_931 ( c.getC_931() ); 		// Value can be used,
	*c.getC_931() = 0; 				// but compiler will report an error here
}


