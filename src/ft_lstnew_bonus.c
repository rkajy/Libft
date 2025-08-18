/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnoor <fnoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:30:06 by fnoor             #+#    #+#             */
/*   Updated: 2025/08/18 17:46:48 by fnoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function copies the input parameter to the content inside the node.
** This function should work even if the content is NULL.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*current;

	current = (t_list *)malloc(sizeof(struct s_list));
	if (current == NULL)
		return (NULL);
	current->content = content;
	current->next = NULL;
	return (current);
}
