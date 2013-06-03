//----------------------------------------------
// NAME: Dobromir Ivanov
// CLASS: XI B
// NUMBER: 15
// PROBLEM: #4
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

int main() {
	char* buff;
	while((buff = readcmd()) != NULL) {
		char** args = parse_cmdline(buff);
		pid_t child, end;
		int status;
		/*Start a child process*/
		if ((child = fork()) == -1) {
			fprintf(stderr, "%s\n", "Failed to execute!");
		} /*This is the child*/
		else if (child == 0) {
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
