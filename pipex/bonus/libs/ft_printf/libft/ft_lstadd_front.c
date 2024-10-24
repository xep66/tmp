#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return;

	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	if (*lst != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
