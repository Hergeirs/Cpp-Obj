#include <iostream> // cin, cout...
#include <iomanip>	// setw(), right...
#include <random>	// default_random_engine randomator()...

using namespace std;

//------------------------------------------------------------------------------
// Struct for convenience, aProp stands for arrayProperties
//------------------------------------------------------------------------------

struct aProp 
{
	int* pos;		// Pointer to first element in array
	int size;		// size of array 
};

//------------------------------------------------------------------------------
// Function to fill dynamic array with random data (pretty standard)
//------------------------------------------------------------------------------

void randomFillArray (aProp a)
{
	default_random_engine randomator((unsigned long) time(NULL));
	uniform_int_distribution<int>dist(-5000, 5000);	// Limit range to int between -5000-5000

		for (int i=0 ; i < a.size; ++i)	// Populate array.
			*(a.pos+i)=dist(randomator);
}

//------------------------------------------------------------------------------
// Function to initialize an array of dynamic size;
//---------------------------------------------------------------------- --------

aProp initArray()
{
	int size;
	cout << "Enter amount of elements array shall contain as integer: ";
	cin >> size;
	cin.get();

	int *Array= new int[size];	// allocate array from heap
	aProp a={Array,size};		// using struct to keep size and adress knit together

	return a;					// return struct.
}

//------------------------------------------------------------------------------
// Printarr prints the array given and has a pause after each 200th element.
//------------------------------------------------------------------------------

void printArr (aProp a)
{
	for (int n = 0; n < a.size; n++)
	{
		if (n%10==0)	// every 10th element newline
			cout << endl;
		
		if (n%200==0 && n!=0) // every 200nth element
		{
			cout << endl << "Press enter to see further elements..." << endl;
			cin.get();
		}
		cout << setw(4) << "|" << setw(6) << *(a.pos+n);
	}
	cout << endl;
}

//------------------------------------------------------------------------------
// Function to calculate min, max and sum using pointers
//------------------------------------------------------------------------------

void arrayStatistic(aProp a)
{
	int * min, * max,sum=0; // initializing nessesary pointers and int.
	min=max=a.pos; 			// set pointers to adress of first element.

	for (int *i = a.pos ; i != (a.pos+a.size) ; ++i) // Stop condition is adress past last element.
	{
		sum+=*i;
		if (*i<*min) 		// If value contained in adree i is less than current
			min=i;			// -min we change adress contained in min to adress of i.
		if (*i>*max)
			max=i;
	}

	cout << endl << "Maximum value in array is: " << setw(8) << right << *max;
	cout << endl << "Minimum value in array is: " << setw(8) << right << *min;
	cout << endl << "The sum of the array is  : " << setw(8) << right << sum;
}

//------------------------------------------------------------------------------
// Main function. Only contains function calls
//------------------------------------------------------------------------------

int main ()
{
	aProp a = initArray();	// making array
	randomFillArray(a);		// "Slumpa" array
	printArr(a);			// Print array formatted
	arrayStatistic(a);		// Calculate min, max and sum
	delete []a.pos; 		// deallocate heap
}
