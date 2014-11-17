/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:01:10 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/17 14:54:40 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_to_fill(char **line, char **str, char *ptr)
{
	char *toto;

	*ptr = 0;
	*line = ft_strjoin("", *str);
	toto = *str;
	*str = ft_strjoin(++ptr, "");
	free(toto);
}

int		get_next_line(int const fd, char **line)
{
	static char *str;
	static int	i = BUFF_SIZE;
	char		buff[BUFF_SIZE + 1];
	char		*ptr;

	if (str == 0)
		str = "";
	ptr = str;
	while (*ptr || i < BUFF_SIZE)
	{
		if (*ptr == '\n' || *ptr == 0)
		{
			ft_to_fill(line, &str, ptr);
			return (i == BUFF_SIZE);
		}
		ptr++;
	}
	i = read(fd, buff, BUFF_SIZE);
	buff[i] = 0;
	str = ft_strjoin(str, buff);
	return (get_next_line(fd, line));
}
