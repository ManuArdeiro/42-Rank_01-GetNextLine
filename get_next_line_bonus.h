#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_buffer(int fd, char *str);
char	*ft_get_line(char *container);
char	*ft_new_container(char *container);
size_t	ft_str_len(char *s);
char	*ft_str_chr(char *s, int c);
char	*ft_str_join(char *str, char *buffer);

#endif
