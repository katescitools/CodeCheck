extern int a_645;
extern int b_645;
extern int x_645;

int main () {
  switch ( x_645 )
  {
	case 0:
	  break;  // UndCC_Valid
	case 1:   // UndCC_Valid - empty drop through
	case 2:   // allows a group
	  break;  // UndCC_Valid
	case 3: // UndCC_Violation
	  throw;  // UndCC_Valid
	case 4: // UndCC_Violation
	  a_645 = b_645;
              
	case 5:
	  a_645 = b_645;
#ifdef __SOMETHING_ENABLED__
	  Dosomethingelse();
#endif
	  break;
	default: // UndCC_Violation
	  ;       
  }
}


