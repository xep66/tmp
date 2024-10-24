#include "../pipex.h"

//		execute pipe
//		content of infile is input to cmd1
//		cmdn->next == NULL then output is sent to outfile
//		else cmd2 infile is STDIN, and cmd2 outfile is STDOUT
//		goes on until cmdn->next == NULL, then output is sent to outfile

void	exec_pipe(t_cmd *head, int infile_fd, int outfile_fd)
{
		int		pipefd[2];
		int		pid;
		t_cmd	*current;
	
		current = head;
		while (current != NULL)
		{
			//	This loop will execute for each node in the list
			//	i.e each command
			if (current->next != NULL && pipe(pipefd) == -1)
				err("pipe");
		
			pid = fork();
			if (pid == -1)
				err("fork");
			if (pid == 0)
			{
				// Child Process
				if (current->next == NULL)
				// If it's the last node, we will redirect output to outfile
					exec_child(current, infile_fd, outfile_fd, NULL);
				else
				// For every other node we use STDOUT
					exec_child(current, infile_fd, STDOUT_FILENO, pipefd);
			}
			else
			{
				// Parent Process
				if (current->next != NULL)
					close(pipefd[1]);
				// After the first node, when the input is STDIN
				if (infile_fd != STDIN_FILENO)
					close(infile_fd);
				infile_fd = pipefd[0];
			}
			current = current->next;
		}
		while (wait(NULL) > 0);
}

void	exec_child(t_cmd *cmd, int infile_fd, int outfile_fd, int *pipefd)
{
	if (infile_fd != STDIN_FILENO)
	{
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
	}
	if (pipefd != NULL)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		close(pipefd[0]);
	}
	else if (outfile_fd != STDOUT_FILENO)
	{
		dup2(outfile_fd, STDOUT_FILENO);
		close(outfile_fd);
	}
	if (execve(cmd->pathname, cmd->argv, cmd->envp) == -1)
		err("execve");
}
/*
void	exec_pipe(t_cmd *head, int infile_fd)
{
	int		pipefd[2];
	int		pid;
	t_cmd	*current;

	current = head;
	while (current != NULL)
	{
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			exec_child(current, infile_fd, pipefd);
			close(pipefd[1]);
			infile_fd = pipefd[0];
		}
		current = current->next;
	}
	while (wait(NULL) > 0);
}


void	exec_child(t_cmd *cmd, int infile_fd, int *pipefd)
{
	int	i;
	
	i = 0;
	if (infile_fd != 0)
	{
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
	}
	if (cmd->next != NULL)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
	}
	close(pipefd[0]);
	while (cmd->argv[i] != NULL)
		i++;
	if (execve(cmd->pathname, cmd->argv, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
*/
