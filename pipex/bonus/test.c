#include "pipex.h"

/*
	How do I want to parse the user arguments?
	-	./pipex infile "/usr/bin/cat" "/usr/bin/ls" "/usr/bin/grep "file.txt"" outfile
	-	6 args - we want argv[2], argv[3], argv[4] -> first is head, rest are appended
	-	while i > 2 && i < argc
	-	parse the pathname, check access
		   Function to init command struct
		1. Function to parse the whole array of **argv 
		2. Function for the "commands"
		3. Function for the infile/outfile
		4. Function for extracting the path (might be a part of 1)
 
		With the linked list approach EACH node will be a command
		The head will not be /usr/bin/cat /usr/bin/wc -l
			It will only be /usr/bin/cat
 
 */

//	is there a way to initialise the input fd in a function?



int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		fprintf(stderr, "%s: Incorrect number of args\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int	i_fd = open(argv[1], O_RDONLY);
	int	o_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (i_fd == -1 || o_fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	t_cmd	*cmd;
	cmd = _init_default_cmd();
	if (!cmd)
		err("init command");
	cmd = args_to_cmd(argv, argc);
	exec_pipe(cmd, i_fd, o_fd);
	free_lst(cmd);
	return (0);

}

/*
	cmd->infile = open(cmd->Argv[1], O_RDONLY);
	cmd->outfile = open(cmd->argv[cmd->argc - 1], O_RDWR | O_CREAT \
						| O_TRUNC, 0666);
	dup2(cmd->infile, STDIN_FILENO);

 */
