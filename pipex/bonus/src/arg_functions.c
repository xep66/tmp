#include "../pipex.h"

int		array_size(char **array)
{
	int	i;

	i = 0;
	while (*array != NULL)
	{
		i++;
		array++;
	}
	return (i);
}

int		ft_wordcount(const char *str, char c)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

char	**str_to_array(char *str)
{
	int		array_size;
	int		i;
	char	**array;

	array_size = ft_wordcount(str, ' ');
	i = 0;
	array = malloc((sizeof(char **) * array_size) + 1);
	if (!array)
		return (NULL);
	while (i < array_size)
	{
		array = ft_split(str, ' ');
		i++;
	}
	return (array);

}

t_cmd	*args_to_cmd(char **args, int argc)
{
	/*
	   Takes argv[2] to argv[argc - 1] and append a new node to the head of the list
	*/
	t_cmd	*cmd;
	int		i;

	cmd = NULL;
	i = 2;
	while (i < argc - 1)
	{
		append_node(&cmd, args[i]);
		i++;
	}
	args[i] = NULL;
	return (cmd);
}
