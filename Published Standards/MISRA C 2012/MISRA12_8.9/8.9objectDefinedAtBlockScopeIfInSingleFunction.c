int N_89 = 10;	/* UndCC_Violation, only used in func_89	*/
int M_89;		/* UndCC_Violation, only used in func_89	*/
int L_89;		/* UndCC_Valid							*/

void func_89 ( void )
{
	M_89 = 11;
	L_89 = 12;
	int i_89;
	for ( i_89 = 0; i_89 < N_89; ++i_89 )
	{
	}
}

int count_89 ( void )
{
	L_89 = 12;
	static unsigned int call_count_89 = 0;
	++call_count_89;
	return call_count_89;
}
