#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *str);
char	*ft_str_chr(char *s, int c);
char	*ft_str_join(char *str, char *buffer);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *str);
char	*ft_new_str(char *str);

#endif
