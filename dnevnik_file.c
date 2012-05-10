#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[45];
  char clas[3];
  int number;
  int averageMark;
} student_info;

void addStudent();
void showStudents();
void showStudentsRecursive(int);

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
    case 50 : showStudentsRecursive(0);
      break;
    case 51 : return 0;
      break;
  }
 }
 
 return 0;
}

void addStudent()
{  
  student_info student;
  FILE *fp;
  
  fp = fopen("dnevnik_data.txt", "a");
  
  printf("\n");
  
  printf("Student name: ");
  scanf("%s", student.name);
  printf("\n");
  
  printf("Student class: ");
  scanf("%s", student.clas);
  printf("\n");
  
  printf("Student number: ");
  scanf("%d", &student.number);
  printf("\n");
  
  printf("Student average mark: ");
  scanf("%d", &student.averageMark);
  printf("\n");
  
  fputs(student.name, fp);
  fputc('#', fp);
  
  fputs(student.clas, fp);
  fputc('#', fp);
  
  fprintf(fp, "%d", student.number);
  fputc('#', fp);
  
  fprintf(fp, "%d", student.averageMark);
  fputc('*', fp);
  
  fclose(fp);
  getchar();
} 

showStudentsRecursive(int numOfStar)
{
  FILE *fp;
  char input, numberString[2]; // numberString - string used for storing data from file, which is later parsed to int
  student_info student;
  int i = 0;
  int fPos, nameLen, clasLen;  // fPos - used to give the current position in file to the child function
  
  fp = fopen("dnevnik_data.txt", "r");
  
  fseek(fp, numOfStar, SEEK_SET); // goes to the last position in file of the parent function
  
  if (fp != NULL)
  {
    input = fgetc(fp);
    while (input != '*') // '*' is been used to indicate the end of every student (structure)
    {
      while (input != '#') // '#' is been used to indicate the end of name variable
      {
	student.name[i] = input;
	input = fgetc(fp);
	i++;
      }
      nameLen = i;
      
      i = 0;
      input = fgetc(fp);
      while (input != '#') // '#' is been used to indicate the end of clas variable
      {
	student.clas[i] = input;
	input = fgetc(fp);
	i++;
      }
      clasLen = i;
	
      i = 0;
      input = fgetc(fp);
      while (input != '#') // '#' is been used to indicate the end of number variable
      {
	numberString[i] = input;
	input = fgetc(fp);
	i++;
      }
      if (i == 1) student.number = numberString[0] - 48; // parsing from char to int
	else student.number = (10 * (numberString[0] - 48)) + (numberString[1] - 48);
	
      input = fgetc(fp);
      student.averageMark = input - 48;
      // output the information of the student
      printf("Student name: "); for (i = 0; i < nameLen; i++) printf("%c", student.name[i]); printf("\n");
      printf("Student class: "); for (i = 0; i < clasLen - 1; i++) printf("%c", student.clas[i]); printf("\n");
      printf("Student number in class: %d\n", student.number);
      printf("Student average mark: %d\n\n", student.averageMark);
      i = 0;
      input = fgetc(fp);
    }  
  } else
  {
    printf("\nThere is no data... Please, make some data!\n");
  }
    
  fPos = ftell(fp); // get the current position in file (to the end of the last structure (student))
  input = fgetc(fp);
  fclose(fp);
  if (input != EOF) showStudentsRecursive(fPos); // checks if this is the last student or there is more and if there is more the child-function is called
}