#include "libft.h"

void	ft_sortlist(t_list *lst, int (*cmp)(const char *, const char *))
{
	char	*swap;
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while ((lst)->next != NULL)
	{
		if (((*cmp)((lst)->content, (lst)->next->content)) > 0)
		{
			swap = (lst)->content;
			(lst)->content = (lst)->next->content;
			(lst)->next->content = swap;
			lst = tmp;
		}
		else
			lst = (lst)->next;
	}
	lst = tmp;
}
