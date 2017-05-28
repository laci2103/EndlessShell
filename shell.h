//
// Created by IanLachance on 5/27/2017.
//

#ifndef ENDLESSSHELL_SHELL_H
#define ENDLESSSHELL_SHELL_H

void execute_console(void);
char *read_console_line(void);
char **split_line(char *line);
int execute_commands(char **args);

int console_help(char **args);
int console_exit(char **args);

#endif //ENDLESSSHELL_SHELL_H