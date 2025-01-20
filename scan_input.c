#include "main.h"

void scan_input(char *prompt, char *input_string)
{
    extract_external_commands(external_command);

    char *command = '\0';
    while (1)
    {

	printf("%s",prompt);

	//read the input 
	scanf("%[^\n]",input_string);
	
	getchar();

	if (!(strncmp("PS1",input_string,3)))
	{
	    if (input_string[3] == ' ' || input_string[5] == ' ' || input_string[4] == ' ')
	    {
		printf("Command not found\n");
	    }
	    else{
		strcpy(prompt,&input_string[4]);
		//continue;
	    }
	}
	char *command = get_command(input_string);

	int ret = check_command_type(command);

	if (ret == EXTERNAL)
	{

	    int pid = fork();

	    if (pid == 0)
	    {
			//child process
			
			//execute external command 
			execute_external_commands(input_string);
	    }
	    else 
	    {
			//parent process
			int status;
			waitpid(pid,&status,WUNTRACED);
	    }
	}
	else if (ret == BUILTIN)
	{
	    //execute internal commands
		execute_internal_commands(input_string);
	}
    }
}

