/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:08:32 by skawanis          #+#    #+#             */
/*   Updated: 2023/06/06 21:04:13 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*gnl_return;

	gnl_return = (char *)1;
	fd = open("test4.txt", O_RDONLY);
	while (gnl_return)
	{
		gnl_return = get_next_line(fd);
		printf("gnl_return:%s|\n", gnl_return);
	}
	return (0);
}
