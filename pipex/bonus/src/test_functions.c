#include "../pipex.h"

// functions that won't be used in the final thing, just for testing purposes

int		lst_size(t_cmd *lst)
{
	t_cmd	*tmp;
	int		count;

	count = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	print_list(t_cmd *lst)
{
	t_cmd	*current;
	int		count;
	int		i;

	count = 0;
	current = lst;
	i = 0;
	while (current != NULL)
	{
		ft_printf("[NODE %d]\n", count);
		ft_printf("Infile_fd: %d\nOutfile_fd: %d\n", current->infile_fd, current->outfile_fd);
		ft_printf("Path:\t%s\n", current->pathname);
		i = 0;
		while (i < array_size(current->argv))
		{
			ft_printf("\targ[%d]: %s\n", i, current->argv[i]);
			i++;		
		}
		current = current->next;
		count++;
	}
	ft_printf("NULL\n");
}

void	status(char *str)
{
	ft_printf("[STATUS]:\t%s\n", str);
}

void	err(char *str)
{
	fprintf(stderr, "[ERROR]:\t%s\n", str);
	exit(EXIT_FAILURE);
}
