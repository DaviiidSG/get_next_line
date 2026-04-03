#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char	*line;
    int		fd;

    // 1. Setup: Create a real file with some text
    // fd = open("test.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    // write(fd, "\n\n\n\n\n", 5);
    // close(fd);

    // 2. Initial Call: Get static_buff allocated
    fd = open("get_next_line.c", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);

    return (0);
}
