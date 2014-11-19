/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:34:18 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/17 15:25:01 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

int main(int argc, char **argv)
{ 
	int ret;
	int fd;
	char *str;

	argc++;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("opent() failed\n");
		return (1);
	}
	while(ret > 0)
	{
		ret = get_next_line(fd, &str);
		write(1, str, ft_strlen(str));
		//ft_putstr("Get next line return : ");
		//ft_putnbr(ret);
		ft_putchar('\n');
		//ft_putchar('\n');
		free(str);
	}

	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
	return (0);
}
