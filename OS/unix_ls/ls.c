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


int l_flag = 0;

void get_files(char *path);
void get_perms(char *path, char *name);
int is_dir(char *path);
void parse_args(int argc, char **argv);

int main(int argc, char **argv)
{
  parse_args(argc, argv);

  //if only one arg list files in current dir
  if(argc == 1 || (argc == 2 && l_flag))
  {
    get_files(".");
    return;
  }

  int i;
  for(i = 1; i < argc; i++)
  {
    if(argv[i][0] != '-')
    {
      if((argc == 3 && !l_flag) || argc >= 4)
      {
        printf("%s\n", argv[i]);
      }
      get_files(argv[i]);
    }
  }

  return 0;
}

void get_files(char *path)
{
  DIR *dir;
  struct dirent *ent;

  if((dir = opendir(path)) != NULL)
  {
    while((ent = readdir(dir)) != NULL)
    {
      if(ent->d_name[0] != '.')
      {
        if(l_flag)
        {
          get_perms(path, ent->d_name);
          printf(" %s\n", ent->d_name);
        }
        else
        {
          printf("%s ", ent->d_name);
        }
      }
    }
    closedir(dir);
    printf("\n");
  }
  else if(!is_dir(path))
  {
    printf("%s\n", path);
  }
  else
  {
    fprintf(stderr, "ls: cannot open %s: %s\n", path, strerror(errno));
  }
}

void get_perms(char *path, char* name)
{
  struct stat s;
  struct passwd *pwd;
  struct group *grp;
  char time_str[25];
  char *temp_ = path;
  if(temp_[strlen(temp_)] != '/')
    stat(strcat(strcat(temp_, "/"), name), &s);
  else
    stat(strcat(temp_, name), &s);

  int i;
  for(i = 0; i < strlen(temp_); i++)
  {
    temp_[i] = '\0';
  }
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
  printf(" %d %s %s %d %s", s.st_nlink, pwd->pw_name, grp->gr_name, (int)s.st_size, time_str);
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

void parse_args(int argc, char **argv)
{
  int i;
  for(i = 0; i < argc; i++)
  {
    if(strcmp(argv[i], "-l") == 0)
    {
      l_flag = 1;
      return;
    }
  }
}
