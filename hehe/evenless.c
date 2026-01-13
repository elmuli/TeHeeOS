#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char buf[4096];
char c;
static int row = 23;
int current_row = 1;
int can_read = 1;
int can_continue = 1;

int main(int argc, char *argv[])
{
    if(argv[0] == NULL) {
        write(1, "no file specified\r\n", 19);
        _exit(0);
    }

    int fd = open(argv[1], O_RDONLY, 0777);

    if(fd == -1){
        write(1, "Sum ting wong\r\n", 15);
        _exit(-1);
    }

    for (;;) {
        char key;
        strcpy(buf, "\0");
        if (!can_continue){
            if(read(0, &key, 1)){
                can_continue = 1;
            }
        }
        if (can_continue){
            int counter = 0;
            while (current_row <= row && can_read){
                if(counter > 4096){
                    can_read = 0;
                    buf[4096] = '\0';
                    break;
                }
                int r = read(fd, &c, 1);
                if (r <= 0){
                    can_read = 0;
                    buf[counter] = '\0';
                    break;
                }

                if (c == '\n') {
                    current_row++;
                }else if(c == 0 || c == '0'){
                    can_read = 0;
                    buf[counter] = '\0';
                    printf("break point\n");
                    break;
                }
                buf[counter] = c;
                counter++;
            }
            write(1, buf, 4096);
            if(current_row == row+1 && can_read){
                write(1, "-- more --", 10);
                current_row = 1;
                can_continue = 0;
            }else if(!can_read){
                close(fd);
                _exit(0);
                break;
            }
        }
    }

    close(fd);
    _exit(0);
}
