// Every 'else if' must have an 'else'.

void okay1()
{
  if (1)
    ;
}

void okay2()
{
  if (1)
    ;
  else if (2)
    ;
  else
    ;
}

void okay3()
{
  if (1)
    if (2)
      else
        ;
  else
    ;
}

void okay4()
{
  if (1)
    ;
  else {
    if (2)
      ;
  }
}


void okay5(void){
  if( a){
  }else if( b){
    if( d){
    }else{}
  }
  else{}
  
  return;
}

static void okay6(void)
{
  if( a ){}
  else if( a ){
    if( a ){}
    else if( a ){}
    else{
      d;
    }
    if( a ) { }
  }else{}
}


void violation1()
{
  if (1)
    ;
  else if (2)
    ;
} // UndCC_Violation

void violation2()
{
  if (1) {
    if (2)
      ;
  } else if (3)
    ;
} // UndCC_Violation

void violation3()
{
  if (1) {}
  else if (2) {
    3;
    4;
  }
} // UndCC_Violation
