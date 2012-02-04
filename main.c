#include "functions.h" 
#include <stdio.h>

enum{FALSE, TRUE};

int main()
{
	char shits[] = "1. Option1\n2. Option2\n3. Option 3\n4. Option 4";
	char shits2[] = "->";
	char *kyr = printMenu('2', shits, shits2);
	printf("%s", kyr);
}
