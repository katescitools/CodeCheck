void f1 ( )
{
  try
  {
    // ...
  }
  catch ( int32_t i ) // int handler
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
  catch ( int32_t i ) // UndCC_Violation � handler will never be called
  {
  }
}
