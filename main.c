#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int i = 0;
	int fd = open("almoharaf.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}