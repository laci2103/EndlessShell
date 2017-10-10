//
// Created by IanLachance on 5/27/2017.
//

#include <stdio.h>
#include "shell.h"
#include "tests/AllTests.h"

int main(int argc, char **argv) {

    printf("\nTesting mode? (y/n): ");
    if (getchar() == 'y') { RunAllTests(); }
    else { execute_console(); }

    return 0;
}