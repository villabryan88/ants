/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:36:11 by exam              #+#    #+#             */
/*   Updated: 2019/09/10 14:38:57 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				q_isempty(struct s_queue *queue)
{
	return (!queue->first);
}

struct s_queue	*q_init(void)
{
	struct s_queue *new;

	new = (struct s_queue*)malloc(sizeof(struct s_queue));
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void			q_push(struct s_queue *queue, void *content)
{
	struct s_qnode *new_node;

	new_node = (struct s_qnode*)malloc(sizeof(struct s_qnode));
	new_node->content = content;
	new_node->next = NULL;
	if (q_isempty(queue))
		queue->first = new_node;
	else
		queue->last->next = new_node;
	queue->last = new_node;
}

void			*q_pop(struct s_queue *queue)
{
	struct s_qnode	*first;
	void			*content;

	if (q_isempty(queue))
		return (NULL);
	first = queue->first;
	content = first->content;
	queue->first = queue->first->next;
	if (queue->first == NULL)
		queue->last = NULL;
	free(first);
	return (content);
}

void			*q_peek(struct s_queue *queue)
{
	if (q_isempty(queue))
		return (NULL);
	return (queue->first->content);
}
