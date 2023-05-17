void action_1();
void action_2();

void rule157( int flag_1, int flag_2 ) {
	if ( flag_1 )
	{
		action_1 ( );
	}
	else if ( flag_2 )
	{
		action_2 ( );
	}
	return; // UndCC_Violation
}
