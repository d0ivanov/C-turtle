#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

	/*
	 *	Fill array with random numbers
	 *	@arg int arr[] to be filled
	 *	@arg int max elements in the array
	 */
void fillArray(int arr[], int);

	/*
	 *	Copy an array into another array
	 *	@arg int arr[] to copy from
	 *	@arg int arr[] to copy in
	 *	@arg int max elements in the arrays
	 */
void copyArray(int arr[], int arr2[], int);

	/*
	 *	Comparison for descending sort
	 *	@arg int first number to compare
	 *	@arg int second number to compare
	 *	@return 0 if first > second number
	 */
int desc(int , int);

	/*
	 *	Comparison for ascending sort
	 *	@arg int first number to compare
	 *	@arg int second number to compare
	 *	@return 1 if first > second number
	 */
int asc(int , int);

	/*
	 *	Swap values of two variables
	 *	@arg int ptr to 1st value to be swapped
	 *	@arg int ptr to 2nd value to be swapped
	 */
void swap( int*, int* );
	
	/*
	 *	Sort an array by the bubble method
	 *	@arg int arr[] array to be sorted
	 *	@arg ptr order ascending or descending ordering
	 *	@arg int max elements in the array
	 */
void bubbleSort(int arr[], int(*order)(int, int), int);
	
	/*
	 *	Sort an array by the select method
	 *	@arg int arr[] array to be sorted
	 *	@arg ptr order pointer to comparison function
	 *	@arg max elements in the array
	 */
void selectSort(int arr[], int(*order)(int, int), int);

	/*
	 *	Sort an array by the quick method
	 *	@arg int arr[] array to be sorted
	 *	@arg ptr order pointer to comparison function
	 *	@arg max elements in the array
	 */
void quickSort(int arr[], int(*order)(int, int), int);

	/*
	 *	Sort an array by the interchange method
	 *	@arg int arr[] array to be sorted
	 *	@arg ptr order pointer to comparison function
	 *	@arg max elements in the array
	 */
void interchangeSort(int arr[], int(*order)(int, int), int);

	/*
 	 *	Print the menu string
 	 *	@arg char item number before which to place the pointer
 	 *	@arg char ms[] the menu string
 	 *	@arg char mp[] the menu pointer
 	 *	@return char menustr[] the menu string 
 	 *	with a pointer before the appropriate item
	 */
char *printMenu(char item, char ms[], char mp[]);
#endif
