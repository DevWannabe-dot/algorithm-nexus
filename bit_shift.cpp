/* Inclusions */
#include "headers/errors.h"
#include <iostream>
using namespace std;

/* Constants */

/* Types */

/* Functions */

int main(int argc, char ** argv)
{
	int num = 2;

	cout << num << ", na base 2: " << 10 << endl;
	num = num << 2;
	// printf("%d, na base 2: %d\n", num, 1000);
	num = num >> 2;
	// printf("%d, na base 2: %d\n", num, 10);

	return SUCCESS;
}