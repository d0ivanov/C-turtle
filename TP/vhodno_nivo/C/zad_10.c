/*
Да се разработи програма,  която изисква от потребителя да въведе четири числа x, y, w, h където x>0, y>0, w>0, h>0. Числото x е дължината на плоча дървесина, а числото y е височината. Да се определи на колко цели плочи с размери w, h може да се разреже голямата плоча. Да се инициализира масив от 10 елемента. Стойностите на елементите на масива да са първите 10 координати по дължина на плочата, в които тя трябва да се разреже, за да се получат по-малките плочи.
*/
#include <stdio.h>

#define MAX_ARR 10

#define calcSurface(x, y) x * y

	/* 
	 * Sets values for 4 int variables.
	*/
void setValues( int*, int*, int*, int* );

	/* Cuts from surface.
	 * @arg  int x width of suface
	 * @arg  int y height of surface
	 * @arg  int w width of cut
	 * @arg  int h height of cut
	*/
int cut( int x, int y, int w, int h, int coords[] );

	/*
	 * Prints array.
	 * @arg int arr array to print
	 * @arg int max array size.
	 */
void printArr( int arr[], int max );

void main(){
	int x, y, w, h, s, plates, coords[MAX_ARR] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	setValues( &x, &y, &h, &w );
	s = calcSurface(x, y);
	plates = cut( x, y, w, h, coords );
	
	switch( plates ){
		case 0:{
			printf("%d square cm surface can not be cut.\n", s);
		}
		break;
		case 1:{
			if( s == w*h ){
				printf("%d square cm surface does not need to be cut.\n", s);
			}else{
				printf("Only 1 peace can be cut from %d square cm surface.\n", s);
				printf("longitudinal cut will have to be on the following spot: \n");
				printArr(coords, MAX_ARR);
			}
		}
		break;
		default:{
			printf("%d square cm surface can be cut into %d pcs.\n", s, plates);
			printf("longitudinal cuts will have to be on the following spots: \n");
			printArr(coords, MAX_ARR);
		}
	}	
}

void setValues( int *x, int *y, int *h, int *w ){

	do{
		printf("x=");
		scanf("%d", x);
	}while( x < 0 );
	
	do{
		printf("y=");
		scanf("%d", y);
	}while( x < 0 );
	
	do{
		printf("w=");
		scanf("%d", w);
	}while( x < 0 );
	
	do{
		printf("h=");
		scanf("%d", h);
	}while( x < 0 );
}

	/* Cuts from surface.
	 * @arg  int x width of suface
	 * @arg  int y height of surface
	 * @arg  int w width of cut
	 * @arg  int h height of cut
	 &
	*/
int cut( int x, int y, int w, int h, int coords[] ){
	int i = 0, n = 0;
	for( i = 0; x > (coords[n] + w); i++ ){
		if( i==0 ){
			coords[i] = w;
		}else{
			coords[i] = coords[i-1] + w;
			n++;
		}
	}
	
	if( x > y ){
		return ( x/w ) * ( y/h );
	}else{
		return ( x/h ) * ( y/w );
	}
}

void printArr( int arr[], int max ){
	int i;
	for( i = 0; i < max; i++ ){
		if( arr[i] != 0 ){
			printf("cutting spot %d: %dcm\n", i+1, arr[i]);
		}
	}
}
