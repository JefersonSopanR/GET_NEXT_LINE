#include "get_next_line_bonus.h"
#include <fcntl.h>

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);

    char *line = get_next_line(fd);
    char *line2 = get_next_line(0);

    while(line2 && line)
    {
        printf("LINE: %s", line);
        line = get_next_line(fd);
        printf("LINE_BONUS: %s", line2);
        line2 = get_next_line(0);
    }
    close(fd);
}
