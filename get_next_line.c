/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:01:10 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/16 10:28:43 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int const fd, char ** line)
{
	int ret;

	ret = read(fd, *line, BUFF_SIZE);
	(*line)[ret] = '\0';
	return (ret);
}
