#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

int	main() {
	clock_t start, end;
	double cpu_time_used;
	
	start = clock();
	int fd1 = open("a.txt", O_RDONLY);
	int fd2 = open("b.txt", O_RDONLY);
	char *line1 = get_next_line(fd1);
	char *line2 = get_next_line(fd2);
	while (line1 && line2)
	{
		printf("1: %s", line1);
		printf("2: %s", line2);
		free(line1);
		free(line2);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
	}
	free(line1);
	free(line2);
	close(fd1);
	close(fd2);

	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nrun time: %fs\n", cpu_time_used);

	return 0;
}
