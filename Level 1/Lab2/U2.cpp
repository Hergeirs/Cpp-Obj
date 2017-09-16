#include <iostream>
#include "AddressClass/AddressClass.h"

using namespace std;

int main ()
{
Address Peter;

Peter.setStreetAddress("Mummiroad 200");
Peter.setZipCode(1650);
Peter.setCity("Cairo");

Peter.print();

Address Poul("Høvdarhagavegur 25",240,"Skopun");

cout << endl;
cout << setw(15) << "city: " << setw(15) << Poul.getCity() << endl;
cout << setw(15) << "streetAddress: " << setw(15) << Poul.getStreetAddress() << endl;
cout << setw(15) << "zipCode: " << setw(15) << Poul.getZipCode() << endl;
}
