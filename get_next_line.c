/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:44:37 by                   #+#    #+#             */
/*   Updated: 2021/11/01 15:24:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_text(int fd, char *buf, char *str)
{
	int	number;

	number = 1;
	while ((!(ft_strchr(str, '\n')) && number > 0))
	{
		number = read(fd, buf, BUFFER_SIZE);
		if (number < 0)
		{
			free (buf);
			return (0);
		}
		buf[number] = '\0';
		if (!str)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

static char	*trim_end(char *str)
{
	char	*strout;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	strout = ft_substr(str, 0, i);
	return (strout);
}	

static char	*trim_out(char *str)
{
	int		i;
	int		cs;
	char	*new_str;

	i = 0;
	cs = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new_str = ft_substr(str, i, cs - i);
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*strout;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	str = read_text(fd, buf, str);
	if (!str || str[0] == '\0')
	{
		free(str);
		str = 0;
		return (0);
	}
	strout = trim_end(str);
	if (!strout || strout[0] == '\0')
	{
		free(strout);
		return (0);
	}
	str = trim_out(str);
	return (strout);
}
