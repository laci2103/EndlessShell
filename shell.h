//
// Created by IanLachance on 5/27/2017.
//

#ifndef ENDLESSSHELL_SHELL_H
#define ENDLESSSHELL_SHELL_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#define TOKEN_SIZE 64
#define TOKEN_DELIMITER " \t\r\n\a"

void execute_console(void);
char *read_console_line(void);
char **split_line(char *line);
int execute_commands(char **args);

int console_help(char **args);
int console_exit(char **args);
int console_crypto(char **args);

#endif //ENDLESSSHELL_SHELL_H