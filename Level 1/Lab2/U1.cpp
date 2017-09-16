#include <iostream>
#include <vector>
#include "NameClass/NameClass.h"



//------------------------------------------------------------------------------
// Main program to test Nameclass.
//------------------------------------------------------------------------------

int main ()
{
Name dude;
Name dudedidude("Snoop","Doog");
dude.setFirstName("Bárður");
dude.setLastName("Polli");
cout << setw(15) << "Name: " << setw(15) << dude.getFirstName() << " " << dude.getLastName();
dudedidude.print();
return 0;
}

