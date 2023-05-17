void f1 ( )
{
  try
  {
	  try
	  {
		  // ...
	  }
	  catch ( int i ) // int handler
	  {
		  // Handle int exceptions
	  }
	  catch( ... ) // -all handler
	  {
		  // Handle all other exception types
	  }
  }
  catch ( int i ) // int handler
  {
    // Handle int exceptions
  }
  catch( ... ) // -all handler
  {
    // Handle all other exception types
  }
  try
  {
	  try
	  {
		  // ...
	  }
	  /*
	  catch
	  */
	  catch( ... ) // catch-all handler
	  {
		  // Handle all exception types
	  }
	  catch( int i ) // UndCC_Violation � handler will never be called
	  {
	  }
  }
  catch ( int i ) // int handler
  {
	  // Handle int exceptions
  }
  catch( ... ) // -all handler
  {
	  // Handle all other exception types
  }
}
void f2 ( )
{
  try
  {
    // ...
  }
  /*
  catch
  */
  catch( ... ) // catch-all handler
  {
    // Handle all exception types
  }
  catch( int i ) // UndCC_Violation � handler will never be called
  {
  }
}
