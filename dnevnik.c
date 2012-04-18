#include <stdio.h>
#include <stdlib.h>

typedef struct 
  { 
    int number; 
    int averageMark; 
    char name[43]; 
  } student_type;
  

void addStudent(student_type *);
void showStudents(student_type *);
void changeStudent();

int elementsCount = 0;

int main()
{
  student_type student;  
  student_type *clas;
  student_type *sp = clas;
  char key;
  int exit = 1;
  
  printf("#####################################################################\n");
  printf("#                                                                   #\n");
  printf("#  - To add student press '1'                                       #\n");
  printf("#  - To show list of all students press '2'                         #\n");
  printf("#  - To change student information press '3'                        #\n");
  printf("#                                                                   #\n");
  printf("#  - To Exit press '4'                                              #\n");
  printf("#                                                                   #\n");
  printf("#####################################################################\n");
  
  while (exit)
  {
    printf("\nPress 1-4 to call menu commands.");
    key = getchar();
    while(key != 49 && key != 50 && key != 51 && key != 52)
    {
      printf("Unexisting command.");
      key = getchar();
    }
    printf("\n");
    
    switch (key)
    {
      case 49 : addStudent(sp);
	break;
      case 50 : sp = &clas;
		showStudents(sp);
	break;
      case 51 : 
	break;
      case 52 : return 0;
        break;
    }
  }
  
  return 0;
}

void addStudent(student_type *sp)
{
  sp = (student_type*) malloc(sizeof(student_type));
  elementsCount++;
  
  int *numPointer = &(sp->number);
  int *markPointer = &(sp->averageMark);
  //char *namePointer = &(sp->name);
  char test[43];
  
  printf("Student name: ");
  scanf("%s", sp->name);
  printf("\n");
  
  printf("Student number in class: ");
  scanf("%d", numPointer);
  //printf("");
  
  printf("Student average mark: ");
  scanf("%d", markPointer);
  printf("\n");
  
  printf("\n\n");
  printf("###############################################################################\n");
  printf("# Student %s (number %d) was successfully created, with average mark %d\n", sp->name, sp->number, sp->averageMark);
  printf("###############################################################################\n");
  
  getchar();
}

void showStudents(student_type *sp)
{
  int i;
  //printf("n of stud %d", elementsCount);
  //int test = sp->number;
  
  for (i = 0; i < elementsCount; i++)
  {
    //sp = sp +i*sizeof(student_type);
    printf("N %d\n", sp->number); //test);
    printf("Name %s\n", sp->name);
    printf("Average mark %d\n", sp->averageMark);
  }
}
