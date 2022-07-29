#include "App.h"
#include "Gptm.h"
#include "Isr.h"
int main()
{
  Init_Drivers ();
  while (1)
  {
    App_Start();
  }
}
