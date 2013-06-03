//----------------------------------------------
// NAME: Dobromir Ivanov
// CLASS: XI B
// NUMBER: 15
// PROBLEM: #5
// FILE NAME: shell.c
// FILE PURPOUSE: Main program file.
// Contains all code written for this problem.
//----------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

/*Keep track of argument count*/
int arg_count = 0;

typedef struct {
	char* command;
	char** argv;
	int stdin;
	int stdout;
} Job;

//----------------------------------------------
// FUNCTION: parse_cmdline
// Parse input to array of null-terminated strings
// PARAMETERS:
// const char* intput string
//----------------------------------------------
char** parse_cmdline(const char*);

//----------------------------------------------
// FUNCTION: readcmd
// Read from command line until EOF or \n
// can read an undefined number of characters.
// if memory allocated is filled, then the string is resized
// PARAMETERS:
// 	none
// RETURNS:
// the input read from console
//----------------------------------------------
char* readcmd();

//----------------------------------------------
// FUNCTION: includes
// Checks if the given arraay includes a symbol
// PARAMETERS:
// 	char** the parsed command line
// 	int size of the parsed command line
// 	char the symbol to look for
// RETURNS:
// 	position of the symbol if found
// 	-1 otherwise
//----------------------------------------------
int includes(char** argv, int argc, char* sym);

//----------------------------------------------
// FUNCTION: fix_args
// Removes any special chars from argument list
// PARAMETERS:
// 	const char** arg list
// 	int argument count
// 	int position of first special char
// RETURNS:
// 	void
//----------------------------------------------
void fix_args(char**, int, int);

//----------------------------------------------
// FUNCTION: redirect_output
// Redirects stdout to f_name
// PARAMETERS:
// 	const char* file name to redirect to
// 	int < 0 if output redirect
// 		> 0 if input redirect
// RETURNS:
// 	void
//----------------------------------------------
void redirect(const char* f_name, int);

//----------------------------------------------
// FUNCTION: redirect_output
// Creates the file in which we will write the
// output of the command and calls the redirect func
// PARAMETERS:
// 	const char** argument list
// 	int argument count
// 	int < 0 if output redirect
// 		> 0 if input redirect
// RETURNS:
// 	void
//----------------------------------------------
void do_redirect(char**, int, int);

//----------------------------------------------
// FUNCTION: do_pipe
// Creates a pipe
// PARAMETERS:
// 	const char** argument list
// 	int position of the pipe operator
// RETURNS:
// 	void
//----------------------------------------------
void do_pipe(char** args, int special_pos);

int main() {
	char* buff;
	while((buff = readcmd()) != NULL) {
		char** args = parse_cmdline(buff); //the command line split by " "
		pid_t child, end;
		int status;
		int special_pos;

		//if we have to make a pipe
		if((special_pos = includes(args, arg_count, "|")) > 0) {
			do_pipe(args, special_pos);
			continue;
		}
		/*Start a child process*/
		if ((child = fork()) == -1) {
			fprintf(stderr, "%s\n", "Failed to execute!");
		} /*This is the child*/
		else if (child == 0) {
			if(includes(args, arg_count, ">") > 0) {
				do_redirect(args, arg_count, -1);
			} else if(includes(args, arg_count, "<") > 0) {
				do_redirect(args, arg_count, 1);
			}
			int err = execv(args[0], args);
			if(err != -1) {
				exit(EXIT_SUCCESS);
			} else {
				fprintf(stderr, "%s\n", strerror(errno));
				exit(EXIT_FAILURE);
			}
		}/* This is the parent.*/
		else {
			end = waitpid(child, &status, WNOHANG|WUNTRACED);
			/* child ended*/
			if (end == child) {
				if (WIFSIGNALED(status))
					fprintf(stderr, "%s\n", "Command ended because of an uncaught signal");
				else if (WIFSTOPPED(status))
					fprintf(stderr, "%s\n", "Command has unexpectedly stopped");
			}
		}
	}
	return 0;
}

char** parse_cmdline(const char* cmdline) {
	int i, base, j, n = 0, argc = 0;
	/* Count number of spaces in string */
	for (i = 0, base = 0; cmdline[i+base] != '\0'; cmdline[base+i] == ' ' ? i++ : base++);
	/* Allocate memory for the array of strings */
	char** argv = malloc((i+1) * sizeof(char*));
	arg_count = i+1;
	for(i = 0; i < strlen(cmdline); i++) {
		/* Get position of nex space in input */
		for(n = 0; cmdline[i+n] != ' ' && (i+n) < strlen(cmdline); n++);
		/* Allocate memory for string */
		argv[argc] = (char*) malloc(n);
		/* Copy string in the array */
		for(j = 0; j < n; j++) {
			argv[argc][j] = cmdline[i+j];
		}
		argv[argc++][j+1] = '\0'; //null terminate
		i+=n; //skip to next space
	}
	return argv;
}

char* readcmd() {
	const int MAX_LEN = 256;
	int size = MAX_LEN, i = 0;
	char c;
	char* buffer = (char*) malloc(MAX_LEN);
	if(buffer == NULL)
		return NULL;
	while((c = getchar()) != '\n' && c != EOF) {
		buffer[i++] = c; //copy every character from console
		if(i == size) { //if we run out of memory, we just reallocate some more
			size = i+MAX_LEN;
			buffer = realloc(buffer, size);
		}
	}
	buffer[i] = '\0';
	if(c == EOF)
		return NULL;
	return	buffer;
}

int includes(char** argv, int argc, char* sym) {
	int i;
	for(i = 0; i < argc; i++) {
		if(strcmp(argv[i], sym) == 0) {
			return i;
		}
	}
	return -1;
}

void fix_args(char** args, int argc, int pos) {
	int i;
	for(i = pos; i < argc; i++) {
		args[i] = NULL;
	}
}

void redirect(const char* f_name, int to) {
	int f;
	if(to < 0) {
		f = open(f_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	} else {
		f = open(f_name, O_RDONLY);
	}
	if(f < 0) {
		fprintf(stdout, "Unable to redirect output to %s\n", f_name);
		exit(0);
	}
	int res;
	if(to < 0)
		res = dup2(f, fileno(stdout));
	else
		res = dup2(f, fileno(stdin));
	if(res < 0) {
		fprintf(stdout, "Unable to redirect output to %s\n", f_name);
		exit(0);
	}
}

void do_redirect(char** args, int arg_count, int to) {
	char* f_name = args[arg_count-1];
	char* sym;
	if(to < 0)
		sym = ">";
	else
		sym = "<";
	fix_args(args, arg_count, includes(args, arg_count, sym));
	redirect(f_name, to);
}

void do_pipe(char** args, int special_pos) {
	Job job1, job2;
	int i, status;
	//prepare job 1
	job1.command = (char*) malloc(strlen(args[0]));
	strcpy(job1.command, args[0]);
	job1.argv = malloc((special_pos) * sizeof(char*));
	for(i = 0; i < special_pos; i++) {
		job1.argv[i] = (char*) malloc(strlen(args[i]));
		strcpy(job1.argv[i], args[i]);
	}
	//prepare job2
	job2.command = (char*) malloc(strlen(args[special_pos+1]));
	strcpy(job2.command, args[special_pos+1]);
	job2.argv = malloc((arg_count - special_pos) * sizeof(char*));
	for(i = 0; i < (arg_count - special_pos - 1); i++) {
		job2.argv[i] = (char*) malloc(strlen(args[i+special_pos+1]));
		strcpy(job2.argv[i], args[i+special_pos+1]);
	}

	int fd[2];
	pipe(fd);
	job1.stdin = fd[0];
	job1.stdout = fd[1];
	job2.stdin = job1.stdout;
	int child, child2, end;
	child = fork();
	switch (child) {
		case -1: /* Handle error */
			fprintf(stderr, "%s\n", "Failed to execute!");
					break;
		case 0:  /* Child of Parent - writes to pipe */
			child2 = fork();
			if(child2 == 0) { /* Child of Child - reads from pipe */
				dup2(job1.stdin, fileno(stdin));
				close(job1.stdout);               /* Write end is unused */
				int err = execv(job2.command, job2.argv);   /* Get data from pipe */
				close(job1.stdin);                /* Finished with pipe */
				if(err != -1) {
					exit(EXIT_SUCCESS);
				} else {
					fprintf(stderr, "%s\n", strerror(errno));
					exit(EXIT_FAILURE);
				}
			} else { /* Parent of Child - writes to pipe */
				dup2(job1.stdout, fileno(stdout));
				close(job1.stdin);               /* Read end is unused */
				int err = execv(job1.command, job1.argv);  /* Write data on pipe */
				close(job1.stdout);              /* Child will see EOF */
				end = waitpid(child, &status, WNOHANG|WUNTRACED);
				/* child ended*/
				if (end == child) {
					if (WIFSIGNALED(status))
						fprintf(stderr, "%s\n", "Command ended because of an uncaught signal");
					else if (WIFSTOPPED(status))
						fprintf(stderr, "%s\n", "Command has unexpectedly stopped");
				}
				if(err != -1) {
					exit(EXIT_SUCCESS);
				} else {
					fprintf(stderr, "%s\n", strerror(errno));
					exit(EXIT_FAILURE);
				}
			}
			break;
		default:
			end = waitpid(child, &status, WNOHANG|WUNTRACED);
			/* child ended*/
			if (end == child) {
				if (WIFSIGNALED(status))
					fprintf(stderr, "%s\n", "Command ended because of an uncaught signal");
				else if (WIFSTOPPED(status))
					fprintf(stderr, "%s\n", "Command has unexpectedly stopped");
			}
	}
}
