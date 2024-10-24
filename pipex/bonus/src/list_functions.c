#include "../pipex.h"

t_cmd	*create_cmd_node(char *str)
{
	char	**array;
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	array = str_to_array(str);
	cmd = _init_argv(array[0], array);
	return (cmd);
}

void	free_lst(t_cmd *lst)
{
	t_cmd	*current;
	t_cmd	*next;


	current = lst;
	while (current != NULL)
	{
		next = current->next;
		if (current->argv != NULL)
			free(current->argv);
		if (current->envp != NULL)
			free(current->envp);
		free(current);
		current = next;
	}
}

void	append_node(t_cmd **head, char *str)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = create_cmd_node(str);
	tmp = malloc(sizeof(t_cmd));
	if (*head == NULL)
	{
		*head = new;
		free(tmp);
		return;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new->infile_fd = tmp->outfile_fd;
	tmp->next = new;
}
