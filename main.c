#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(void)
{
	int		fd;
	char	*line;
	char	*file;

	file = "get_next_line.c";
	printf("file = %s\n", file);
	fd = open(file, O_RDONLY);
	printf("fd = %d", fd);
	line = get_next_line(fd);
	printf("line = %s", line);
	while (line)
		printf("%s\n", line);
	close(fd);
	return (0);
}
