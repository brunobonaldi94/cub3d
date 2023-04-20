/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:01:22 by harndt            #+#    #+#             */
/*   Updated: 2022/07/11 21:51:13 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Cleans the static buffer, erasing its contents until it reaches
 * a newline.
 * @param buffer The String to be cleaned.
 * @return A String containing what is in the buffer after the newline,
 * or NULL if an error occurs.
 */
static char	*ft_clean(char *buffer)
{
	size_t	i;
	char	*str;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	ft_strlcpy(buffer, &buffer[i + 1], BUFFER_SIZE - i);
	if (!*buffer)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
	if (!str)
		return (NULL);
	ft_cpyline(str, buffer, 0);
	return (str);
}

/**
 * @brief Allocates and expand me memory of a String
 * @param str The String to be allocated
 * @param len The actual lenght of the String.
 * @return A pointer to ne String or NULL if an erro occurs.
 */
static char	*ft_realloc(char *str, size_t len)
{
	char	*tmp;

	if (!str)
		str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	else
	{
		tmp = (char *)malloc(sizeof(char) * (len + BUFFER_SIZE + 1));
		ft_strlcpy(tmp, str, len + 1);
		free(str);
		str = tmp;
	}
	if (!str)
		return (NULL);
	return (str);
}

/**
 * @brief Reads the fd received as paramenter while copies a string until
 * it finds '\n'.
 * @param fd File descriptor to be readed.
 * @param buffer Pointer to the string that will allocate what was readed
 * @param str Pointer to the String that will alocate the current line.
 * @return The current line.
 */
static char	*ft_read(int fd, char *buffer, char *str)
{
	int		size;
	size_t	i;

	if (!str)
		i = 0;
	else
		i = ft_strlen(str);
	size = read(fd, buffer, BUFFER_SIZE);
	while (size)
	{
		if (size < 1)
			break ;
		buffer[size] = '\0';
		str = ft_realloc(str, i);
		i = ft_cpyline(str, buffer, i);
		if (ft_strchr(str, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
	}
	if (size < 1 && !str)
		return (NULL);
	return (str);
}

char	*ft_get_next_line(int fd)
{
	char		*str;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = NULL;
	if (ft_strchr(buffer, '\n'))
	{
		str = ft_clean(buffer);
		if (ft_strchr(str, '\n'))
			return (str);
	}
	return (ft_read(fd, buffer, str));
}
