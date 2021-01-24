/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 15:05:07 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 15:05:09 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*copie;
	t_list		*deb;

	deb = NULL;
	copie = NULL;
	if (!lst || !(deb = ft_lstnew(lst->content)))
		return (deb);
	deb->content = f(deb->content);
	copie = deb;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(lst->content)))
		{
			ft_lstclear(&copie, del);
			return (NULL);
		}
		new->content = f(new->content);
		deb->next = new;
		deb = deb->next;
		lst = lst->next;
	}
	return (copie);
}
