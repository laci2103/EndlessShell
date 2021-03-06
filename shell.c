#include "shell.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#define TOKEN_SIZE 64
#define TOKEN_DELIMITER " \t\r\n\a"

int console_help(char **args);
int console_exit(char **args);

char *builtin_str[] = {
        "help",
        "exit"
};

int (*builtin_func[]) (char **) = {
        &console_help,
        &console_exit
};

int num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

int console_help(char **args)
{
    int i;
    printf("EndlessShell\n");
    printf("Available built in:\n");

    for (i = 0; i < num_builtins(); i++) {
        printf("-%s\n", builtin_str[i]);
    }

    return 1;
}

int console_exit(char **args)
{
    return 0;
}

char *read_console_line(void)
{
    size_t buffer_len = BUFFER_SIZE;
    int position = 0;
    char *buffer = (char *) malloc(sizeof(char) * buffer_len);
    int current_char;

    // Buffer check
    if (!buffer) {
        fprintf(stderr, "console: memory allocation error\n");
        exit(0);
    }

    // We read the line, and reallocate memory if buffer size exceed
    while (1) {
        current_char = getchar();

        // If end of string detected, it's done
        if (current_char == EOF || current_char == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = (char) current_char;
        }
        position++;

        // Extra memory needed?
        if (position >= buffer_len) {
            buffer_len += BUFFER_SIZE;
            buffer = (char *) realloc(buffer, buffer_len);
            // Buffer check
            if (!buffer) {
                fprintf(stderr, "console: memory allocation error\n");
                exit(0);
            }
        }
    }
}

char **split_line(char *line)
{
    size_t buffer_len = TOKEN_SIZE;
    int position = 0;
    char **tokens = (char **) malloc(buffer_len * sizeof(char*));
    char *token;

    // Buffer check
    if (!tokens) {
        fprintf(stderr, "console: memory allocation error\n");
        exit(0);
    }

    // Extract each args from the string
    // strtok -> http://www.cplusplus.com/reference/cstring/strtok/
    token = strtok(line, TOKEN_DELIMITER);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        // Buffer check
        if (position >= buffer_len) {
            buffer_len += TOKEN_SIZE;
            tokens = (char **) realloc(tokens, buffer_len * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "console: memory allocation error\n");
                exit(0);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITER);
    }
    tokens[position] = NULL;
    return tokens;
}

int execute_commands(char **args)
{
    int i;

    if (args[0] == NULL) {
        // An empty command was entered.
        return 1;
    }

    for (i = 0; i < num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }
    return 1;
}


void execute_console(void)
{
    char *line;
    char **args;
    int response;

    do {
        printf(" > ");
        line = read_console_line();
        args = split_line(line);
        response = execute_commands(args);

        free(line);
        free(args);
    } while (response);
}