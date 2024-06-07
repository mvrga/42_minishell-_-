/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:09:07 by jveras            #+#    #+#             */
/*   Updated: 2024/06/07 10:24:48 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lstdelone(t_env *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->env_var_s);
	free(lst);
}

void	ft_lstclear(t_env **lst, void (*del)(void *))
{
	t_env	*aux;

	if (!lst)
		return ;
	while ((*lst) != NULL)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
}

t_env	*ft_lstcopy(t_env *lst)
{
	t_env	*new_lst;
	t_env	*new_node;

	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew_env(ft_strdup(lst->env_var_s));
		if (!new_node)
		{
			ft_lstclear(&new_lst, free);
			return (NULL);
		}
		ft_lstadd_back_env(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

t_env	*ft_lstmap(t_env *lst, void *(*f)(void *), void (*del)(void *))
{
	t_env	*new_lst;
	t_env	*new_elem;

	if (!f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_elem = ft_lstnew_env(f(lst->env_var_s));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back_env(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}

void	ft_sortlist(t_env *lst, int (*cmp)(const char *, const char *))
{
	char	*swap;
	t_env	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while ((lst)->next != NULL)
	{
		if (((*cmp)((lst)->env_var_s, (lst)->next->env_var_s)) > 0)
		{
			swap = (lst)->env_var_s;
			(lst)->env_var_s = (lst)->next->env_var_s;
			(lst)->next->env_var_s = swap;
			lst = tmp;
		}
		else
			lst = (lst)->next;
	}
	lst = tmp;
}
