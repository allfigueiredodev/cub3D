#include "../include/cub3D.h"

size_t	gnl_strlen(const char *s)
{
	int	counter;

	if (s == NULL)
		return (0);
	counter = 0;
	while (*s)
	{
		counter++;
		s++;
	}
	return (counter);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	i;

	i = 0;
	length = gnl_strlen(src);
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (length);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = NULL;
	if (!nmemb || !size)
		return (malloc(0));
	if (((nmemb * size) / size) != nmemb)
		return (ptr);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (ptr);
	while (i < (nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

void	clone_matrix(char ***map_copy, char **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = y;
	*map_copy = ft_calloc((y + 1), sizeof(char *));
	while (j > 0)
	{
		(*map_copy)[i] = ft_calloc((x + 1), sizeof(char));
		gnl_strlcpy((*map_copy)[i], map[i], x + 1);
		j--;
		i++;
	}
}