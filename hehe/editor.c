#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int row = 0;
int current_row = 1;
off_t offset = 0;
char c;

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDWR | O_CREAT, 0777);

    if(fd == -1){
        write(1, "Sum ting wong\r\n", 15);
        _exit(-1);
    }


    if(argv[2] != NULL){
        row = atoi(argv[2]);
        while (current_row < row){
            int r = read(fd, &c, 1);
            if (r <= 0) break;

            if (c == '\n') {
                current_row++;
            }

            offset += r;
        }
        lseek(fd, offset, SEEK_SET);
    }else{
        lseek(fd, offset, SEEK_END);
    }

    for (;;){
        char text[512];
        write(1, ">> ", 3);
        int ret = read(0, text, 512);
        text[ret - 1] = '\0';
        if(strcmp(text, "ENDL") == 0){
            break;
            close(fd);
            _exit(0);
        }
        text[ret - 1] = '\n';
        write(fd, text, ret);
    }

    close(fd);
    _exit(0);
}
