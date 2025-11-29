#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;
	int i = 0;

    start = clock();
	int fd1 = open("test 1", O_RDONLY);
	int fd2 = open("test 2", O_RDONLY);
	char *line1 = get_next_line(fd1);
	char *line2 = get_next_line(fd2);
	while (line1)
	{
		printf("%s", line1);
		printf("%s", line2);
		free(line1);
		free(line2);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		i++;
	}
	free(line1);
	close(fd1);
	free(line2);
	close(fd2);

    end = clock();

	printf("\nPrinted: %d-times.", i);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nrun time: %fs\n", cpu_time_used);

    return 0;
}
