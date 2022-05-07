#include "get_next_line.h"

char  *ft_read_more(int fd, char *buffer, char *line)
{
  int i;
  int j;
  size_t  size;
  char  *new_line;
  
  i = 0;
  size = ft_strlen(line);
  buffer = read(fd, buffer, BUFFER_SIZE);
  new_line = ft_calloc(sizeof(char) * BUFFER_SIZE + size + 1);
  if (!new_line)
    return (NULL);
  while (i < size)
     new_line[i] = line[i++];
  free (line);
  i = 0;
  while (buffer[i] != '\n' && buffer[i] != '\0')
  {
    new_line[size] = buffer[i];
    buffer[i] = '\0';
    size++;
    i++;
  }
  new_line[size] = buffer[i];
  if (i = BUFFER_SIZE)
    new_line = ft_read_more (fd, buffer, new_line);
  return (new_line);
}
  

char	*ft_get_line(int fd, char *buffer)
{
  int i;
  int j;
  char  *line;
  
  i = 0;
  while (buffer[i] == '\0')
    i++;
  i++;
  line = ft_calloc(BUFFER_SIZE - i + 1, sizeof(char));
  if (!line)
    return (NULL);
  j = 0;
  while (buffer[i] != '\n' && buffer[i] != '\0')
  {
    line[j] = buffer[i];
    buffer[i] = '\0';
    j++;
    i++;
  }
  line[j] = buffer[i];
  if (i = BUFFER_SIZE)
    line = ft_read_more(fd, buffer, line);
  return (line);  
}

char	*get_next_line(int fd, size_t BUFFER_SIZE)
{
	int i;
  int line_len;
  char		*line;
	static char	*buffer[1024];

	i = 0;
  if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (buffer[fd] == NULL)
    buffer[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
  if (!buffer[fd])
		return (NULL);
   while (buffer[i] == '\0')
    i++;
  if (i = BUFFER_SIZE)
    if (read(fd, buffer[fd], BUFFER_SIZE) == -1)
    {
      free(buffer);
      return (NULL);
    }
	line = ft_get_line(fd, buffer[fd]);
  if (!line)
    return (NULL);
  free (line);
	return (line);
}

int		main(void)
{
	int		fd;
	char	*line;
  
	fd = open(3, O_RDONLY);
	get_next_line(fd, BUFFER_SIZE);
		printf("%s\n", line);
	close(fd);
	return (0);
}
