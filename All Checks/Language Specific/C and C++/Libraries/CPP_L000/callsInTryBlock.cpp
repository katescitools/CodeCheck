void no_throw() throw ();
void does_throw() throw (int);
void may_throw();
void no_check();
void do_check();


void okay1()
{
  no_throw();   // okay, because it claims no throw // UndCC_Violation
  no_check();   // okay, sample we are ignoring; see CUSTOMIZE // UndCC_Violation
  try {
    does_throw();
    may_throw();
    do_check();
    try {
      does_throw();
      { does_throw(); }
    } catch (int) {};
  } catch (int) {};
}

void violation1()
{
  does_throw(); // UndCC_Violation, because it claims throw
  may_throw();  // unknown, makes no throw claim // UndCC_Violation
  do_check();   // UndCC_Violation, sample we are forcing; see CUSTOMIZE
  try {} catch (int) {};
  does_throw(); // UndCC_Violation
}
