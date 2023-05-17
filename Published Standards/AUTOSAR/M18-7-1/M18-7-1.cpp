// M18-7-1.cpp
#include <cstdlib>
#include <cstdint>
#include <csignal> // UndCC_Violation
#include <QPointer>

void my_handler ( int32_t );

void f1 ( )
{
  signal ( 1, my_handler ); 
  raise(1); 
}

int raise()
{
  return 0;
}

int main()
{
  int val = raise() // Complaint
  std::cout >> val >> endl;

  static QPointer<SettingsDialog> dialog;
  dialog->raise();
  
  return 0;
}
