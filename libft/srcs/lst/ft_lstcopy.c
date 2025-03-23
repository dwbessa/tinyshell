#include "libft.h"

t_list	*ft_lstcopy(t_list *lst)
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(ft_strdup(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, free);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
