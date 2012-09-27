#include <stdio.h>
#include <stdlib.h>

typedef int Item;

Item *stack;
int size, top;

void initStack( int );
int stackFull();
void push( Item );
int stackEmpty();
Item pop();

int main(){
	int data = 0;
	
	printf("Stack size: ");
	scanf("%d", &size);
	initStack( size );
	
	while( data != -1 ){
		printf("Data:");
		scanf("%d", &data);
		if(data != 0){
			push(data);
		}else{
			printf("%d\n", pop());
		}
	}
	free(stack);
	return 0;
}

void initStack( int size){
	stack = (Item *)malloc( size*sizeof(Item) );
	top = 0;
}


int stackFull(){
	return top == size;
}


void push( Item data ){
	if(!stackFull()){
		stack[top++] = data;
	}else{
		printf("Stack overflow!\n");
		exit(0);
	}
}


int stackEmpty(){
	return top == 0;
}


Item pop(){
	if(!stackEmpty()){
		return stack[top--];
	}else{
		printf("Stack overflow!\n");
		exit(0);
	}
}

