#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int marks[5];
  int marksNum;
  int averageMark;
} subject;

typedef struct
{
  subject subjects[3];
  char name[45];
  char clas[10];
  int number;
  int averageMark;
} student_info;

student_info students[27];

void addStudent();
void showStudents();
void subject_Function(int, int);

int elementsNum = 0;

int main()
{
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
     case 49 : addStudent();
      break;
     case 50 : showStudents();
      break;
     case 51 : return 0;
      break;
   }
 }
 return 0;
}

void addStudent()
{
  char key = 49;
  int i = 0;
  printf("\n");
  
  printf("Student name: ");
  scanf("%s", students[elementsNum].name);
  printf("\n");
  
  printf("Student class: ");
  scanf("%s", students[elementsNum].clas);
  printf("\n");
  
  printf("Student number: ");
  scanf("%d", &students[elementsNum].number);
  printf("\n");
  
  subject_Function(elementsNum, 0);
  subject_Function(elementsNum, 1);
  subject_Function(elementsNum, 2);
 
  elementsNum++; 
  getchar();
}

void showStudents()
{
  int i, k, j;
  
  printf("\n");
  
  for (i = 0; i < elementsNum; i++)
  {
    printf("\nStudent Name: %s\n", students[i].name);
    printf("Student class %s\n", students[i].clas);
    printf("Student number %d\n", students[i].number);
    for (k=0; k < 3; k++)
    {
      for (j = 0; j < students[i].subjects[k].marksNum; j++)
      {
        printf("Mark %d: %d\n", ++j, students[i].subjects[k].marks[j]);
        j--;
      }
      printf("Average mark for this subject is: %d\n", students[i].subjects[k].averageMark);
      students[i].averageMark += students[i].subjects[k].averageMark;
    }
    students[i].averageMark /= 3;
    printf("Student average mark %d\n", students[i].averageMark);
  }
  
  getchar();
}

void subject_Function(int elemNum, int subNum)
{
  char key = 49;
  int i;
  
  printf("\nEnter how many marks will you input in Subject %d(from 1 to 5)", ++subNum);
  subNum--;
  students[elemNum].subjects[subNum].marksNum = 0;
  while (students[elemNum].subjects[subNum].marksNum < 1 || students[elemNum].subjects[subNum].marksNum > 5)
  {
    scanf("%d", &students[elemNum].subjects[subNum].marksNum);
    if (students[elemNum].subjects[subNum].marksNum < 1 || students[elemNum].subjects[subNum].marksNum >5) printf("\nFROM 1 to 5!!!");
  }
    
  for (i = 0; i < students[elemNum].subjects[subNum].marksNum; i++)
  {
    printf("Enter mark for Subject %d: ", ++subNum);
    subNum--;
    scanf("%d", &students[elemNum].subjects[subNum].marks[i]);
  }
  
  students[elemNum].subjects[subNum].averageMark = 0;
  for (i = 0; i < students[elementsNum].subjects[subNum].marksNum; i++)
  {
    students[elemNum].subjects[subNum].averageMark += students[elemNum].subjects[subNum].marks[i];
  }
  students[elemNum].subjects[subNum].averageMark /= students[elemNum].subjects[subNum].marksNum;
}