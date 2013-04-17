//----------------------------------------------
// NAME: Dobromir Ivanov
// CLASS: XI B
// NUMBER: 15
// PROBLEM: #3
// FILE NAME: cat.c
// FILE PURPOUSE: Main program file.
// Contains all code written for this problem.
//----------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<pwd.h>
#include<grp.h>
#include<stdint.h>

/* 1 if -l op used */
int l_flag = 0;
/* Min chars to print for username */
int user_size = 0;
/* Min chars to print for grooup */
int group_size = 0;
/* Min chars to print for file size */
int size_size = 0;

//----------------------------------------------
// FUNCTION: parse_args
// Checks for -l option and sorts arguments
// PARAMETERS:
// 	int argc arg count
//	char ** argv arg values
//----------------------------------------------
void parse_args(int argc, char **argv);

//----------------------------------------------
// FUNCTION: sort_args
// Performs bubble sort on argument values
// PARAMETERS:
// 	int argc arg count
//	char ** argv arg values
//----------------------------------------------
void sort_args(int argc, char **argv);

//----------------------------------------------
// FUNCTION: normalize_path
// Make sure path is valid
// PARAMETERS:
// 	char *path path to normalize
//	char *name final dir name/file name
//  char *full_path where the normalized_path is written
//----------------------------------------------
void normalize_path(char *path, char *name, char *full_path);

//----------------------------------------------
// FUNCTION: error_check
// Check for errors. If any print and exit.
// PARAMETERS:
// 	char *path where we are looking for errors at
//----------------------------------------------
void error_check(char *path);

//----------------------------------------------
// FUNCTION: list_dir_files
// Get all files/folders in dir alphabetically and list them
// PARAMETERS:
// 	int argc arg count
//	char ** argv arg values
//----------------------------------------------
void list_dir_files(char *path);

//----------------------------------------------
// FUNCTION: filter
// Performs filter agains directory list
// PARAMETERS:
// 	struct dirent *dir holds info about file
// RETURNS
// 	1 if dir should be excluded from dir_list
//  0 if dir should be in dir_list
//----------------------------------------------
int filter(const struct dirent *dir);

//----------------------------------------------
// FUNCTION: print_file_stat
// Gets and prings all file stats
// PARAMETERS:
// 	char *f_name to get stats for
//	char *full_path gull path to file
//----------------------------------------------
void print_file_stat(char *f_name, char *full_path);

//----------------------------------------------
// FUNCTION: column_sizes
// Calculates column sizes for -l option
// PARAMETERS:
// 	char *path the path we are listing
//----------------------------------------------
void column_sizes(char *path);

//----------------------------------------------
// FUNCTION: is_dir
// Check if path is directory
// PARAMETERS:
// 	char *path path to check
// RETURNS
// 	1 if exists 0 otherwise
//----------------------------------------------
int is_dir(char *path);

//----------------------------------------------
// FUNCTION: file_exists
//	Checks if file exists
// PARAMETERS:
// 	char *path path to file
// RETURNS
// 	1 if exists 0 otherwise
//----------------------------------------------
int file_exists(char *path);

int main(int argc, char **argv)
{
  int i;
  parse_args(argc, argv);

  //if no directory passed passed
  if(argc == 1 || (argc == 2 && l_flag))
  {
    column_sizes(".");
    list_dir_files(".");
    return;
  }

  for(i = 0; i < argc; i++)
  {
    if(argv[i][0] != '-' && strcmp(argv[i], "./ls") != 0)
    {
      if(!is_dir(argv[i]))
      {
        if(file_exists(argv[i]))
          printf("%s\n", argv[i]); //if file is not dir and it exists print it's name
        else
          fprintf(stderr, "ls: cannot access %s: No such file or directory", argv[i]);
      }
      else
      {
        column_sizes(argv[i]);
        if((argc == 3 && !l_flag) || argc >= 4)
          printf("%s:\n", argv[i]);
        list_dir_files(argv[i]);
      }
    }
  }
}

void parse_args(int argc, char **argv)
{
  int i;
  for(i = 1; i < argc && l_flag == 0; i++)
  {
    if(argv[i][0] == '-')
      l_flag = 1;
  }
  sort_args(argc, argv);
}

void sort_args(int argc, char **argv)
{
	//pure bubble sort
  int i, j;
  for(i = 0; i < argc; i++)
  {
    for(j = 0; j < argc - 1; j++)
    {
      if(strcmp(argv[j], argv[j+1]) > 0)
      {
        char *temp;
        temp = argv[j+1];
        argv[j+1] = argv[j];
        argv[j] = temp;
      }
    }
  }
}

void normalize_path(char *path, char *name, char *full_path)
{
  char full_path_temp[900];
  strcpy(full_path_temp, path);
  if(path[strlen(path) - 1] != '/')
  {
  	//if path does not end with / concatenate it
  	// line PATH + / + file name
  	// in order to get full path
    strcat(full_path_temp, "/");
    strcat(full_path_temp, name);
    strcpy(full_path, full_path_temp);
  }
  else
  {
  	//if path ends in /
  	//just put the file name in the end
    strcat(full_path, name);
    strcpy(full_path, full_path_temp);
  }
}

void error_check(char *path)
{
  DIR *dir;
  if((dir = opendir(path)) == NULL)
  {
    fprintf(stderr, "ls: cannot open %s: %s\n", path, strerror(errno));
    closedir(dir);
    exit(1);
  }
}

void list_dir_files(char *path)
{
  error_check(path);
  struct dirent **list;
  int i, total = scandir(path, &list, filter, alphasort); //scans dir and returns sorted array of dir entities

  for(i = 0; i < total; i++)
  {
    if(!l_flag)
      printf("%s ", list[i]->d_name);
    else
    {
      char full_path[900];
      normalize_path(path, list[i]->d_name, full_path);
      print_file_stat(list[i]->d_name, full_path);
    }
  }
  printf("\n");
}

int filter(const struct dirent *dir)
{
  if (dir->d_name[0] == '.')
    return 0;
  else
    return 1;
}

void column_sizes(char *path)
{
  DIR *dirp;
  struct dirent *dp;
  struct stat st;
  struct passwd* pw;
  struct group*  gr;
  char full_path[900];

  error_check(path);
  dirp = opendir(path);
  while((dp = readdir(dirp)) != NULL)
  {
    normalize_path(path, dp->d_name, full_path);
    stat(full_path, &st);
    pw = getpwuid(st.st_uid); // take user name
    gr = getgrgid(st.st_gid); // take group name
    if(user_size < strlen(pw->pw_name))
      user_size = strlen(pw->pw_name);
    if(group_size < strlen(gr->gr_name))
      group_size = strlen(gr->gr_name);
    if (size_size < st.st_size)
      size_size = (intmax_t)st.st_size;
  }

  //get max column size
  char size_s[13], user_s[13], group_s[13];
  sprintf(size_s, "%d", size_size);
  sprintf(user_s, "%d", user_size);
  sprintf(group_s, "%d", group_size);

  user_size = strlen(user_s);
  group_size = strlen(group_s);
  size_size = strlen(size_s);
}

void print_file_stat(char *f_name, char *full_path)
{
  struct stat s;
  struct passwd *pwd;
  struct group *grp;
  char time_str[25];

  stat(full_path, &s);

  printf( (S_ISDIR(s.st_mode)) ? "d" : "-"); //is it a dir?
  printf( (s.st_mode & S_IRUSR) ? "r" : "-"); //user can read?
  printf( (s.st_mode & S_IWUSR) ? "w" : "-"); //user can write?
  printf( (s.st_mode & S_IXUSR) ? "x" : "-"); //user can execute?
  printf( (s.st_mode & S_IRGRP) ? "r" : "-"); //group can read?
  printf( (s.st_mode & S_IWGRP) ? "w" : "-"); //group can write?
  printf( (s.st_mode & S_IXGRP) ? "x" : "-"); //group can execute?
  printf( (s.st_mode & S_IROTH) ? "r" : "-"); //others can read?
  printf( (s.st_mode & S_IWOTH) ? "w" : "-"); //others can write?
  printf( (s.st_mode & S_IXOTH) ? "x" : "-"); //others can execute
  pwd = getpwuid(s.st_uid); //get passwd structure - info about user
  grp = getgrgid(s.st_gid); //get group structure - info about group
  strftime(time_str, 25, "%b %d %H:%M", localtime(&s.st_mtime));//convert time_t to readable str
  printf(" %4d %*s %*s %*d %s %s\n", s.st_nlink, user_size, pwd->pw_name, group_size, grp->gr_name, size_size, (int)s.st_size, time_str, f_name);
}

int is_dir(char *path)
{
	struct stat s;
	if(stat(path,&s) == 0)
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

int file_exists(char* path)
{
  struct stat st;

  if (stat(path, &st) == 0)
    return 1;
  return 0;
}
