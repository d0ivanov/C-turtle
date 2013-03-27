//----------------------------------------------
// NAME: Dobromir Ivanov
// CLASS: XI B
// NUMBER: 15
// PROBLEM: #2
// FILE NAME: wc.c
// FILE PURPOUSE: Main program file.
// Contains all code written for this problem.
//----------------------------------------------

#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

/* Flags for -w -l -c parameters */
unsigned int w_flag = 0;
unsigned int l_flag = 0;
unsigned int c_flag = 0;

/* Current file counters: chars, words, lines */
unsigned long chars;
unsigned long words;
unsigned long lines;

/* Total counters: chars, words, lines */
unsigned long total_chars = 0;
unsigned long total_words = 0;
unsigned long total_lines = 0;

//----------------------------------------------
// FUNCTION: parse_args
// Parse agrguments from command line, returns
// number or arguments after parsing -l -c -w
// PARAMETERS:
// int args count
// char** args value
//----------------------------------------------
int parse_args(int, char**);

//----------------------------------------------
// FUNCTION: print_stats
// Outputs counters for a given file
// PARAMETERS:
// char* file name
// unsigned long lines count
// unsigned long words count
// unsigned long chars count
//----------------------------------------------
void print_stats(char*, unsigned long, unsigned long, unsigned long);

//----------------------------------------------
// FUNCTION: is_dir
// Checks if file is directory. Returns 1 if file
// is directory, 0 if not, -1 if error occured.
// PARAMETERS:
// const char* file name to check
//----------------------------------------------
int is_dir(const char*);

//----------------------------------------------
// FUNCTION: is_word
// Checks if char is valid word part
// return 1 if it is, 0 if not
// PARAMETERS:
// char character to check
//----------------------------------------------
int is_word(char);

//----------------------------------------------
// FUNCTION: get_word
// Get next word from the input stream. Return 0 on end
// of file or loop break condition. Return 1 otherwise.
// PARAMETERS:
// FILE* pointer to file to get word from
//----------------------------------------------
int get_word(FILE*);

//----------------------------------------------
// FUNCTION: counter
// Process file.
// PARAMETERS:
// char* file name to process
//----------------------------------------------
void counter(char*);

int main(int argc, char **argv)
{
  int i;
	int args = parse_args(argc, argv);
  for(i = 1; i < argc; i++)
  {
  	if(strcmp(argv[i], "-") == 0)
  	{
  		counter("stdin");
  	}
  	else if((strcmp(argv[i], "-l") != 0) && (strcmp(argv[i], "-c") != 0) && (strcmp(argv[i], "-w") != 0))
  	{
  		counter(argv[i]);
  	}
  }
  
	
  if(args > 2)
    print_stats("total", total_chars, total_words, total_lines);
  return 0;
}

int parse_args(int argc, char **argv)
{
	int i;
	int args = argc;
	for(i = 0; i < argc; i++)
	{
		if(strcmp(argv[i], "-c") == 0)
		{
			c_flag = 1;
			args--;
		}
		if(strcmp(argv[i], "-w") == 0)
		{
			w_flag = 1;
			args--;
		}
		if(strcmp(argv[i], "-l") == 0)
		{
			l_flag = 1;
			args--;
		}
	}
	if(!c_flag && !w_flag && !l_flag)
	{
		c_flag = 1;
		w_flag = 1;
		l_flag = 1;
	}
	return args;
}

void print_stats(char *f_name, unsigned long chars, unsigned long words, unsigned long lines)
{
	if(l_flag)
		printf("%lu ", lines);
	if(w_flag)
		printf("%lu ", words);
	if(c_flag)
		printf("%lu ", chars);
  printf("%s\n", f_name);
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

int is_word(char c)
{
  return isalnum(c);//check if char is letter form aplhabet or digit
}

int get_word(FILE *fp)
{
  char c;
  int word = 0;

  if (feof (fp))
    return 0;

  while((c = getc(fp)) != EOF)
  {
    if(is_word(c)) 
    { //this is actual word counter
      words++;//if char is valid word part inc words and break
      break;
    }
    chars++;
    if(c == '\n')
      lines++;
  }
	//here we continue from last read char
	//and cound characters only
  for (; c != EOF; c = getc(fp))
  {
    chars++;
    if(c == '\n')
      lines++;
    if (!is_word(c))
      break;
  }
  return c != EOF;
}

void counter(char *f_name)
{
	FILE *fp;
	if(strcmp(f_name, "stdin") != 0)
	{
  	if(is_dir(f_name))
  	{
    	fprintf(stderr, "wc: %s No such file or directory\n", f_name);
			return;
		}
  	fp = fopen(f_name, "r");

  	if (!fp)
  	{
    	fprintf(stderr, "wc: %s: %s\n", f_name, strerror(errno));
			return;
		}
	}
	else
	{
		fp = stdin;
	}
  chars = words = lines = 0;
  while(get_word(fp)) //loop through file. get_word returns c != EOF, so loop has stable cond
    ;
  fclose (fp);

  print_stats(f_name, chars, words, lines);
  total_chars += chars;
  total_words += words;
  total_lines += lines;
}
