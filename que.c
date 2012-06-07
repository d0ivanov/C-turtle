#include <stdio.h>
#include <stdlib.h>

typedef int Item;

Item *que;
int size, top, bottom;

void initQueue( int );
int queEmpty();
void push( Item );
Item get();

int main(){
	int data = 0;
	
	printf("Queue size: ", size);
	scanf("%d", &size);
	initQueue( size );
	while( data != -1 ){
		scanf("%d", &data);
		if(data != 0){
			push( data );
		}else{
			printf("%d\n" ,get());
		}
	}
	free(que);
	return 0;
}

void initQueue( int size ){
	que = (Item *)malloc( size*sizeof(Item) );
	top = bottom = 0;	
}

int queFull(){
	return bottom % size == top;
}
	
void push( Item item ){
	que[bottom++] = item;
	bottom = bottom % size;
}

int queEmpty(){
	return top % size == bottom;
}


Item get(){
	top = top % size;
	return que[top++];
}
