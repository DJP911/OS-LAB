#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd, i;
    char buf[2];
    
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    fd = open(argv[1], O_RDONLY);
    
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    while ((i = read(fd, buf, 1)) > 0) {
        printf("%c", buf[0]);
    }
    
    close(fd);
    
    return 0;
}

