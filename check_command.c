#include "main.h"

int check_command_type(char *command)
{
    char *builtins[] = {"echo", "printf", "read", "cd", "pwd", "pushd", "popd", "dirs", "let", "eval",
						"set", "unset", "export", "declare", "typeset", "readonly", "getopts", "source",
						"exit", "exec", "shopt", "caller", "true", "type", "hash", "bind", "help", NULL};
    
    for (int i = 0;builtins[i] != '\0';i++)
    {
        if(strcmp(command, builtins[i]) == 0)
        {
            return BUILTIN;
        }
    }

    extract_external_commands(external_command);
    
    for (int i = 0;external_command[i] != NULL;i++)
    {
        if (strcmp(command, external_command[i]) == 0)
        {
            return EXTERNAL;
        }
    }

    if (strcmp(command,"\0") == 0)
    {
        return NO_COMMAND;
    }
}

