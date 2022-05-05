#include "get_next_line.h"

size_t	ft_str_len(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_str_chr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_str_len(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_str_join(char *str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	  *sol;

	if (!str || !buffer)
		return (NULL);
	sol = malloc(sizeof(char) * ((ft_str_len(str) + ft_str_len(buffer)) + 1));
	if (sol == NULL)
  {
    free (sol);
		return (NULL);
  }
	i = 0;
	j = 0;
	if (str)
		while (str[i] != '\0')
    {
      sol[i] = str[i];
      i++;
    }
	while (buffer[j] != '\0')
		sol[i++] = buff[j++];
	sol[i] = '\0';
	free(str);
	return (sol);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*sol;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	sol = (char *)malloc(sizeof(char) * i + 2);
	if (!sol)
  {
    free (sol);
		return (NULL);
  }
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		sol[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		sol[i] = str[i];
	i++;
  sol[i] = '\0';
	return (sol);
}

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*sol;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	sol = (char *)malloc(sizeof(char) * (ft_str_len(str) - i + 1));
	if (!sol)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		sol[j++] = str[i++];
	sol[j] = '\0';
	free(str);
	return (sol);
}
