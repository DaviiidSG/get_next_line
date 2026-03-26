*This project has been created as part of the 42 curriculum by dserrano*
# Description
The **get_next_line** project aims to implement a function that reads a line ending with a newline character (\n) from a file descriptor. This project is designed to help understand the concept of static variables in C and dynamic memory management.
## Project structure
- `get_next_line.c`: Main logic and management of the static variable.
- `get_next_line_utils.c`: String manipulation functions (`strlen`, `strdup`, `strjoin`, `substr`).
- `get_next_line.h`: Prototypes and definitions.
- `buffer_size.h`: Advanced management and protection of the `BUFFER_SIZE` macro.
# Instructions
## Compilation and use
1. Copy the `.c` and `.h` files to your repo.
2. You can compile the function along with your `main.c` by defining `BUFFER_SIZE`, for example: `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o test`
3. Usage example:

		#include "get_next_line.h"
		#include <fcntl.h>
		#include <stdio.h>

		int	main(void)
		{
			int		fd = open("test.txt", O_RDONLY);
			char	*line;

			if (fd == -1)
				return (1);
			while (line = get_next_line(fd))
			{
				printf("%s", line);
				free(line);
			}
			return (0);
		}

# Resources
- [Declaración de variables](https://www.it.uc3m.es/pbasanta/asng/course_notes/variables_es.html)
- C Programming A Modern Approach 2nd edition. K. N. King
## Use of AI
In this project, AI was used to improve the README file.
# Algorithm and data structure
## Iterative Reading and Persistence
My implementation uses a logical flow divided into three phases:
- **Read Phase (read_and_append)**: The function reads from the file in blocks of size `BUFFER_SIZE`. These blocks are concatenated to a static variable using `ft_strjoin`. This process is repeated in a while loop until a `\n` character is encountered or the end of the file (EOF) is reached.
- **Return Phase (ret_line)**: Once the buffer contains *at least* one complete line, `ft_substr` is used to return the string from the beginning up to the first \n (inclusive).
- **Cleaning Phase (del_line)**: After returning the line, it is essential not to lose the “remaining” data that may have been read after the line break. The algorithm updates the static variable by *removing the portion that has already been returned*, preparing it for the next call.
## Data Structures: Static Variables and Dynamic Memory
The central element is a static variable of type `static char *static_buff`.
- **Static variable**: Unlike local variables, the static variable resides in the data segment, which allows it to retain its value across different calls to `get_next_line`. This is essential for storing any characters left over after reading a line, allowing the next call to start exactly where the previous one ended.
- **Memory Management**: Since the size of the line is unknown in advance, the buffer grows dynamically on the heap.
## Error Handling and Edge Cases
- **Variable BUFFER_SIZE**: The code is designed to handle sizes ranging from 1 to very large values (limited by `buffer_size.h`).
- **Memory Leak Management**: I have implemented a helper function called `free_all` to ensure that, whether a read error occurs or the end of the file is reached, all allocated memory is properly released, thereby preventing memory leaks.