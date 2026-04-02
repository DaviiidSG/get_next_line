#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char    *line;
    int     fd;

    // 1. Setup: Create a real file with some text
    fd = open("test.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    write(fd, "Lorem Ipsum", 11);
    close(fd);

    // 2. Initial Call: Get static_buff allocated
    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("First call\n");
	printf("%s", line);
    free(line);

    // 3. Trigger Error: Call with an invalid FD
    // This will likely enter your 'read_and_append' or 'get_next_line'
    // error logic where you FREE the static_buff.
    printf("\nSecond call\n");
    line = get_next_line(fd);
    printf("%s", line);

    // 4. The "Crash" Call: Call it again
    // If static_buff wasn't set to NULL, srch_newline will now
    // try to read from the freed memory address.
    //printf("Calling again to trigger Valgrind error...\n");
    //line = get_next_line(fd);
    //printf("Third call returned: %s\n", line);
    free(line);

    close(fd);
    return (0);
}
