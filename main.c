#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

int	main() {
	clock_t start, end;
	double cpu_time_used;
		int i = 0;

	start = clock();
	int fd = open("t2.txt", O_RDONLY);
	char *line = "";// = get_next_line(fd);
	while (line)
	{
		line = get_next_line(10);
		printf("%d: %s", i, line);
		free(line);
		i++;
	}
	free(line);
	close(fd);

	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nrun time: %fs\n", cpu_time_used);

	return 0;
}

/*int	main() {
	clock_t start, end;
	double cpu_time_used;

	start = clock();
	int fd1 = open("t1.txt", O_RDONLY);
	int fd2 = open("t2.txt", O_RDONLY);
	char *line1 = get_next_line(fd1);
	char *line2 = get_next_line(fd2);
	while (line1 && line2)
	{
		printf("%s", line1);
		printf("%s", line2);
		free(line1);
		free(line2);
		line1 = get_next_line(fd1);
		line2 = get_next_line(99);
		// if (i == 10)
		// 	break;
	}	
	while (line1)
	{
		printf("%s", line1);
		free(line1);
		line1 = get_next_line(fd1);
		// if (i == 10)
		// 	break;
	}
	free(line1);
	close(fd1);
	close(fd2);

	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nrun time: %fs for file \n", cpu_time_used);

	return 0;
}
*/