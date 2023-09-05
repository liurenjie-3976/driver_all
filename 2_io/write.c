#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

char *filename = "liu";
mode_t mode = 0666;

int main()
{
    int fd;
    char buf[1024];
    int nbyres;
    ssize_t bytes_written;
    fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, mode);
    if (fd == -1)
    {
        printf("open error\n");
        return -1;
    }
    memset(buf, 0, sizeof(buf));
    strcpy(buf, "hello world\n");
    nbyres = strlen(buf);

    bytes_written = write(fd, buf, nbyres);

    printf("nbyres: %d  bytes_written:%d \n", nbyres, bytes_written);

    if (close(fd) < 0)
    {
        fprintf(stderr, "ERROR: close file %s failed:%s\n", filename, strerror(errno));
        return -1;
    }
    //	printf("%s\n",buf);
    return 0;

}