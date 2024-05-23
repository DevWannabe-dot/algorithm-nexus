#include <stdio.h>

int main(int argc, char ** argv)
{
	int num = 2;

	printf("%d, na base 2: %d\n", num, 10);
	num = num << 2;
	printf("%d, na base 2: %d\n", num, 1000);
	num = num >> 2;
	printf("%d, na base 2: %d\n", num, 10);

	return 0;
}
