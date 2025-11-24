#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("hh.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s|", line);
		printf("\n*****************************************\n");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}