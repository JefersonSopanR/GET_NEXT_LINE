# GET_NEXT_LINE

This project implements the `get_next_line` function in C, which reads a line from a file descriptor efficiently. It is commonly used in coding schools and technical interviews to test understanding of file I/O, memory management, and buffer handling in C.

## Features
- Reads a line from a file descriptor, including handling multiple file descriptors.
- Supports both standard and bonus versions.
- Efficient buffer management.
- Handles edge cases such as EOF and errors.

## Files
- `get_next_line.c` / `get_next_line.h`: Main implementation and header for the standard version.
- `get_next_line_bonus.c` / `get_next_line_bonus.h`: Bonus version supporting multiple file descriptors.
- `get_next_line_utils.c` / `get_next_line_utils_bonus.c`: Utility functions for both versions.
- `int_main.c`: Example main function for testing.
- `file`: Example input file for testing.

## Usage
1. Compile the project:
   ```bash
   gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c int_main.c -o a.out
   ```
   For the bonus version:
   ```bash
   gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c int_main.c -o a.out
   ```
2. Run the executable:
   ```bash
   ./a.out
   ```

## Function Prototype
```c
char *get_next_line(int fd);
```

## How It Works
- The function reads from the file descriptor until a newline or EOF is found.
- Returns the line read, including the newline character if present.
- Returns `NULL` on error or when no more lines are available.

## License
This project is for educational purposes.

## Author
Jeferson Sopan R
