#include <stdio.h>
#include <stdlib.h>

typedef struct 
  { 
    int number; 
    int aveageMark; 
    char name[43]; 
  } student_type;
  

void addStudent(student_type *);
void showStudents();
void changeStudent();

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
    key = getchar();
    printf("\n");
    
    switch (key)
    {
      case 49 : addStudent(sp);
	break;
      case 50 : 
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
   
  int *numPointer = &(sp->number);
  int *markPointer = &(sp->aveageMark);
  //char *namePointer = &(sp->name);
  char test[43];
  
  printf("Student name: ");
  scanf("%s", sp->name[43]);
  printf("\n");
  
  printf("Student number in class: ");
  scanf("%d", numPointer);
  //printf("");
  
  printf("Student average mark: ");
  scanf("%d", markPointer);
  printf("\n");
  
  printf("\n\n");
  printf("#########################################################################\n");
  printf("# Student %s (number %d) was successfully created, with average mark %d #", sp->name, sp->number, sp->aveageMark);
  printf("#######################################################################################################################################");
}