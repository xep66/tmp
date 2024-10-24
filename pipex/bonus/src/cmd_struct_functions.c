#include "../pipex.h"

void	print_cmd(t_cmd *cmd, int ac)
{
	char	**av;
	int		i;

	i = 2;
	av = cmd->argv;
	if (av != NULL)
	{
		while (av[i] != NULL && i < ac - 1)
		{
			printf("%s ", av[i]);
			i++;
		}
		printf("NULL\n");
	}
}

t_cmd	*create_cmd_node(char *arg)
{
	char 	**array;
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	array = str_to_array(arg);
	cmd = _init_argv(array[0], array);
	return (cmd);

}

