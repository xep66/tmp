#include "../pipex.h"

t_cmd		*_init_default_cmd()
{
	t_cmd	*cmd;
	
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);

	cmd->argv = NULL;
	cmd->pathname = NULL;
	cmd->envp = NULL;
	cmd->infile_fd = -1;
	cmd->outfile_fd = -1;
	cmd->next = NULL;
	return (cmd);
}

void	_init_io_fd(t_cmd *cmd, char *infile, char *outfile)
{
	int	in_fd;
	int	out_fd;

	in_fd = open(infile, O_RDONLY);
	out_fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (in_fd == -1 || out_fd == -1)
		err("open");
	cmd->infile_fd = in_fd;
	cmd->outfile_fd = out_fd;
	if (cmd->infile_fd == -1 || cmd->outfile_fd == -1)
		err("open");
}
t_cmd	*_init_argv(const char *path, char **args)
{
	//	adds the path and args to a command node
	t_cmd	*cmd;
	int		size;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	size = array_size(args);
	cmd->pathname = path;
	cmd->argv = args;
	cmd->argv[size + 1] = NULL;
	return (cmd);
	
}
