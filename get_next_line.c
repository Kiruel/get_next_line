 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:01:10 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/16 18:08:19 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int const fd, char ** line)
{
	static char *data = NULL;
	char buffer[BUFF_SIZE + 1];
	int i;
	int ret;

	ret = 0;
	if (data == 0)
		data = "";
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		buffer[ret] = '\0';
		data = ft_strjoin(data, buffer);
		i = 0;
		while (i < (int)ft_strlen(data))
		{
			if (data[i] == '\0')
			{
				*line = ft_strdup(data);
				return (0);
			}
			if (data[i] == '\n')
			{
				data[i] = '\0';
				ft_putstr(data);
				*line = ft_strdup(data);
				return (1);
			}
			i++;
		}
	}
	return (0);

}
