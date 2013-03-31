#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>


unsigned long lines;
unsigned long single_line_comments;
unsigned long multiple_line_comments;
unsigned long chars_in_comment;

int a_flag;
int b_flag;
int c_flag;
int d_flag;

void parse_args(int, char**);

void count_lines(const char*);

void count_single_line_comments(const char*);

void count_multiple_line_comments(const char*);

void print_results();

int main(int argc, char **argv)
{
  parse_args(argc, argv);
  int i;
  for(i = 0; i< argc; i++)
  {
    count_lines(argv[i]);
    count_single_line_comments(argv[i]);
    count_multiple_line_comments(argv[i]);
  }
  print_results();
}

void parse_args(int argc, char **argv)
{
	int i;
	int args = argc;
	for(i = 0; i < argc; i++)
	{
    if(argv[i][0] == '-')
    {
      int j;
      for(j = 1; j < strlen(argv[i]); j++)
      {
        if(argv[i][j] == 'a')
          a_flag = 1;
        if(argv[i][j] == 'b')
          b_flag = 1;
        if(argv[i][j] == 'c')
          c_flag = 1;
        if(argv[i][j] == 'd')
          d_flag = 1;
      }
    }
  }
  if(!a_flag && !b_flag && !c_flag && !d_flag)
  {
    a_flag = 1;
    b_flag = 1;
    c_flag = 1;
    d_flag = 1;
  }
}

void count_lines(const char *fname)
{
  lines = 0;
  FILE* fp = fopen(fname, "r");
  char c;
  while((c = fgetc(fp)) != EOF)
  {
    if(c == '\n')
      lines++;
  }
  return;
}

void count_multiple_line_comments(const char *fname)
{
  multiple_line_comments = 0;
  chars_in_comment = 0;
  FILE* fp = fopen(fname, "r");
  char c;
  char m;
  int in_comment = 0;
  while((c = fgetc(fp)) != EOF)
  {
    if(c == '/' && (m = fgetc(fp)) == '*')
    {
      in_comment = 1;
      multiple_line_comments++;
    }
    else if(c == '*' && (m = fgetc(fp)) == '/')
    {
      in_comment = 0;
    }
    if(in_comment)
      chars_in_comment++;
  }
}

void count_single_line_comments(const char *fname)
{
  FILE* fp = fopen(fname, "r");
  char c;
  while((c = fgetc(fp)) != EOF)
  {
    if(c == '/' && (c = fgetc(fp)) == '/')
      single_line_comments++;
  }
  return;
}

void print_results()
{
  if(a_flag)
    fprintf(stdout, "Single line comments: %lu\n", single_line_comments);
  if(b_flag)
    fprintf(stdout, "Single line comments percent: %f\n",(float)lines/single_line_comments);
  if(c_flag)
    fprintf(stdout, "Multiple line comments: %lu\n", multiple_line_comments);
  if(d_flag)
    fprintf(stdout, "Avarage chars per multiple line comment: %f\n", (float)chars_in_comment/multiple_line_comments);
}
