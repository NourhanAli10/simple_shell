#ifndef SHELL_H
#define SHELL_H

/** standard libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

/** global variables*/
extern char **environ;

/** string helper function*/
int _strlen(char *string);
char *_strcopy(char *dest, char *src);
char *my_strdup(char *source);
void reverse_string(char *str, int length);
char *_strcat(char *dest, char *src);


/** another helper function */
int _putchar(char c);
char *_itoa(int num);
int _lenNum(int num);
int _atoi(char *s);



/**command functions*/

char **tokenize_command(char *buffer, ssize_t n, const char *delimiter);
char **get_command();
void shell_interactive(void);

/** execute command*/
int exec_command(char **tokens, char *argv[]);
char *handle_command(char **tokens, char *argv[]);
void exceve_command(char *command, char **tokens, char *argv[]);
int handle_exit_status(int status);


/**env functions*/
char *get_env(char *name);
void *print_env(char **command);


/* exit*/
void exit_command(char **command);

/**path*/
char *full_path(char **path, char *command);
char *get_path(char *command);
char *get_current_path();
int count_token(char *path);

/**error*/
char *handle_error(char *argv[], char **command);

/**free memory*/
void free_env(void);
void free_memory(char **buffer);



#endif
