#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1 = open("test.txt", O_RDONLY);
	int		fd2 = open("test2.txt", O_RDONLY);
	char	*line;

	if (fd1 == -1 || fd2 == -1)
		return (1);
	while (1)
	{
		if (!(line = get_next_line(fd1)))
			break;
		else
		{
			printf("Test 1: %s", line);
			free(line);
		}
		if (!(line = get_next_line(fd2)))
			break;
		else
		{
			printf("Test 2: %s", line);
			free(line);
		}
	}
	close(fd1);
	close(fd2);
	return (0);
}
