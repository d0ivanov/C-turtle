#include "functions.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

//Define TRUE and FALSE vars
enum{FALSE, TRUE};

	/*
	 * Fill an array with random numbers
	 * @arg array[] array to be filled
	 * @arg max elements in the array
	 */
void fillArray(int arr[], int max)
{
	srand(time(NULL));
	int i;
	for(i = 0; i < max; i++)
	{
		arr[i] = rand();
	}
}

	/*
	 *	Copy an array into another array
	 *	@arg array to copy from
	 *	@arg array to copy in
	 */
void copyArray(int arr[], int arr2[], int max)
{
	unsigned int i;
	for(i = 0; i < max; i++)
	{
		arr2[i] = arr[i];
	}
}

	/*
	 *	Comparison for descending sort
	 */
int desc(int a, int b)
{
	if(a > b)
	{
		return 0;
	}
	return 1;
}

	/*
	 *	Comparison for ascending sort
	 */
int asc(int a, int b)
{
	if( a > b )
	{
		return 1;
	}
	return 0;
}

	/*
	 *	Swap values of two variables
	 *	@arg pointer to 1st value to be swapped
	 *	@arg pointer to 2nd value to be swapped
	 */
void swap( int *a, int *b )
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

	/*
	 *	Sort an array by the bubble method
	 *	@arg int arr[] array to be sorted
	 *	@arg ptr order ascending or descending ordering
	 *	@arg int max elements in the array
	 */
void bubbleSort(int arr[], int(*order)(int, int), int max)
{
	int swaped = FALSE, i, j;
	
	while(!swaped)
	{
		swaped = TRUE;
		for(i = 0; i < max; i++)
		{
			if( order(arr[i], arr[i+1]) )
			{
				swap(&arr[i], &arr[i+1]);
				swaped = FALSE;
			}
		}
		max -= 1;
	}	
}
	/*
	 *	Sort an array by the select method
	 *	@arg int arr[] array to be sorted
	 *	@arg ptr order pointer to comparison function
	 *	@arg max elements in the array
	 */
void selectSort(int arr[], int(*order)(int, int), int max)
{
	exit (1);
}

	/*
	 *	Sort an array by the quick method
	 *	@arg int arr[] array to be sorted
	 *	@arg ptr order pointer to comparison function
	 *	@arg max elements in the array
	 */
void quickSort(int arr[], int(*order)(int, int), int max)
{
	exit(1);
}

	/*
	 *	Sort an array by the interchange method
	 *	@arg int arr[] array to be sorted
	 *	@arg ptr order pointer to comparison function
	 *	@arg max elements in the array
	 */
void interchangeSort(int arr[], int(*order)(int, int), int max)
{
	exit(1);
}

	/*
 	 *	Print the menu string
 	 *	@arg char item number before which to place the pointer
 	 *	@arg char ms[] the menu string
 	 *	@arg char mp[] the menu pointer
 	 *	@return char menustr[] the menu string 
 	 *	with a pointer before the appropriate item
	 */
char *printMenu(char item, char ms[], char mp[])
{
	int i, j, n, mplen, c;
	char *newmenu = (char *)calloc(sizeof(ms) + sizeof(mp) - 1, sizeof(char));	//allocate memory
	j = 0;
	n = strlen(ms); //size of original menu string
	for(i = 0; i < n; i++)
	{
		if(ms[i] == item && ms[i+1] == '.')
		{
			mplen = strlen(mp);
			for(c = 0; c < mplen; c++)
			{
				newmenu[j] = mp[c];
				j++;
			}
		}
		newmenu[j] = ms[i];
		j++;
	}
	//add terminating char
	newmenu[j+1] = '\0';
	return newmenu;
}
