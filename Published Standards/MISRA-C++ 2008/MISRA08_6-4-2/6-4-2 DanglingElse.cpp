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
