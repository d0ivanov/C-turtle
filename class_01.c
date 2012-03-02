#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[45];
  char clas[10];
  int number;
  int averageMark;
} student_info;

void addStudent(student_info **);
void showStudents(student_info *);

int elementsNum = 0;

int main()
{ 
 student_info students[27];
 char key;
 
 
 printf("############################\n");
 printf("# Press 1 to add student.  #\n");
 printf("# Press 2 to see students. #\n");
 printf("#                          #\n");
 printf("# Press 3 to exit.         #\n");
 printf("############################\n");
 
 while(1)
 {
   printf("\nChoose option from the menu: ");
   key = getchar();
  
  switch(key)
  {
    case 49 : addStudent(students);
      break;
    case 50 : showStudents(students);
      break;
    case 51 : return 0;
      break;
  }
 }
 
 return 0;
}

void addStudent(student_info students[0])
{  
  int *numPointer = &students[elementsNum].number;
  int *markPointer = &students[elementsNum].averageMark;
  
  printf("\n");
  
  printf("Student name: ");
  scanf("%s", students[elementsNum].name);
  printf("\n");
  
  printf("Student class: ");
  scanf("%s", students[elementsNum].clas);
  printf("\n");
  
  printf("Student number: ");
  scanf("%d", numPointer);
  printf("\n");
  
  printf("Student average mark: ");
  scanf("%d", markPointer);
  printf("\n");

  elementsNum++;  
  getchar();
}

void showStudents(student_info students[0])
{
  int i;
  
  printf("\n");
  
  for (i=0; i < elementsNum; i++)
  {
    printf("\nStudent Name: %s\n", students[i].name);
    printf("Student class %s\n", students[i].clas);
    printf("Student number %d\n", students[i].number);
    printf("Student average mark %d\n", students[i].averageMark);
  }
  getchar();
}
