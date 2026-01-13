#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

extern int copy_file_range(int fd_in, off_t *off_in, int fd_out, off_t *off_out, size_t size, unsigned int flags);

int main(int argc, char *argv[])
{
    struct stat stat;
    size_t size;

    int fd_in = open(argv[1], O_RDONLY, 0777);

    if(fd_in == -1){
        write(1, "file not found\r\n", 16);
        _exit(-1);
    }

    int fd_out = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if(fd_out == -1){
        write(1, "Sum ting wong\r\n", 15);
        _exit(-1);
    }

    if (fstat(fd_in, &stat) == -1) {
        write(1, "fstat failure\r\n", 15);
        _exit(-1);
    }

    size = stat.st_size;

    int ret = 0;

    do {
        ret = copy_file_range(fd_in, NULL, fd_out, NULL, 64, 0);

        if (ret = -1) {
            write(1, "Copy failed\r\n", 13);
            _exit(-1);
        }

    } while (size > 0 && ret > 0);

    close(fd_in);
    close(fd_out);
    _exit(0);
}
