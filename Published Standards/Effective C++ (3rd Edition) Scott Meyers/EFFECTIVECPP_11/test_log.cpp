foo& foo::operator=(const foo& right)
{
  LOG("Method Entry"
      "on two lines");
  if (this != &right)
  {
  }
  LOG("Method Exit");
  return *this;
}

bar& bar::operator=(const bar& right)
{
  LOG("Method Entry/Exit with nested parens",(1),((1)));
  if (this != &right)
  {
  }
  return *this;
}

const foobar& foobar::operator=(const foobar& right)
{
  LOG("Method Entry/Exit");
  if (this != &right)
  {
    LOG("Inside self-assignment check");
  }
  return *this;
}
