#include "main.h"

int main()
{
    //create an array

    char prompt[100] = {"MINISHELL$ "};
    char input_string[100];

    //implement clear commad to clear the section

    system("clear");

    scan_input(prompt, input_string);

    //exit(0);

    return 0;
}

