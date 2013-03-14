//----------------------------------------------
// NAME: Dobromir Ivanov
// CLASS: XI B
// NUMBER: 15
// PROBLEM: #1
// FILE NAME: cat.c
// FILE PURPOUSE: Main program file.
// Contains all code written for this problem.
//----------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

//----------------------------------------------
// FUNCTION: input_to_output
// Dumps everything read from stdin to stdout
// PARAMETERS:
// NONE
//----------------------------------------------
void input_to_output();

//----------------------------------------------
// FUNCTION: print_file
// Dumps file to stdout
// PARAMETERS:
// const char* file name to dump
//----------------------------------------------
void print_file(const char*);

//----------------------------------------------
// FUNCTION: is_dir
// Checks if file is directory. Returns 1 if file
// is directory, 0 if not, -1 if error occured.
// PARAMETERS:
// const char* file name to dump
//----------------------------------------------
int is_dir(const char*);

//----------------------------------------------
// FUNCTION: main
// Program entry point
// PARAMETERS:
// int argc argument count
// char *argv[] argument values vector
//----------------------------------------------
int main(int argc, char *argv[])
{
  if(argc == 1)
  {
    //if no arguments print stdin to stdout
    input_to_output();
    return 0;
  }
  //if arguments have been passed
  if(argc > 1)
  {
    int i;
    for(i = 1; i < argc; i ++)  //iterate through arguments
    {
      if(strcmp(argv[i], "-") == 0) // dash should be interpreted as "read from stdin"
      {
        input_to_output(); //read from stdin until EOF is reached
      }
      else
      {
        print_file(argv[i]); //if argv is not dash dump file
      }
    }
  }
  return 0;
}

void input_to_output()
{
  char buff[100];
  int bytes_read;
  while((bytes_read = read(fileno(stdin), buff, sizeof(buff))) > 0) //while tere are bytes to read from stdin
  {
    write(fileno(stdout), buff, bytes_read); //dump buffer to stdout
  }
}

void print_file(const char *f_name)
{
  int f = open(f_name, O_RDONLY); //open file
  if(f < 0) //if error occured
  {
    fprintf(stderr, "cat: %s: %s\n", f_name, strerror(errno)); //print error message to stderr
    return;
  }
  if(is_dir(f_name)) //if ifle is dir
  {
  	fprintf(stderr, "cat: %s: %s\n", f_name, "No such file or directory"); //print error message to stderr
  }
  char buff[100];
  int bytes_read;
  while((bytes_read = read(f, buff, sizeof(buff))) > 0) //while there are bytes to read from file
  {
    write(fileno(stdout), buff, bytes_read); //dump buffer to stdout
  }
  close(f); //finally close file
  return;
}

int is_dir(const char *f_name)
{
	struct stat s;
	if(stat(f_name,&s) == 0)
	{
		  if(s.st_mode & S_IFDIR)
		  {
		      return 1; //it's a directory
		  }
		  else
		  {
		      return 0; //something else
		  }
	}
	return -1; //error
}
