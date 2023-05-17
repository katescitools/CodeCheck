
void nullTest(){
  while ( ( port & 0x80 ) == 0 ) 
  { 
   int i; /* Not Empty */
   ; /* wait for pin - Compliant */ 
    ;   
   int j; /* Not Empty */
   ; 
   ; int l;  // UndCC_Violation
   }
   for(;;){ //Exception
     i++;
   }
}
