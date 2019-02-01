#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h> 

int prime(int num)
{
    for (int c = 2; c <= num - 1; c++) {
        if (num % c == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char header[20] = "P3 500 500 255 ";
    int rgb[3];
    char line[20];
    int fd;

    fd = open("pic.pmm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    write(fd, header, strlen(header));
    for (int i = 0; i < 500; i++) {
        for (int x = 0; x < 500; x++) {
           if (prime(i + x) == 1) {
                rgb[0] = 255;
                rgb[1] = 255;
                rgb[2] = 0;
            }
	   else {
                rgb[0] = (i * x) % 256;
                rgb[1] = ((i + x)) % 256;
                rgb[2] = ((i + x)) % 256;
            }

            snprintf(line, sizeof(line), "%d %d %d ", rgb[0], rgb[1], rgb[2]);
            write(fd, line, strlen(line));
        }
    }

    close(fd);

    return 0;
}
