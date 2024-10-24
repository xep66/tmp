#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int count;

	count = 0;
	current = lst;	
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
