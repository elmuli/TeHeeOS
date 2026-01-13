#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret = 0;

    ret = unlink(argv[1]);
    if(ret != 0){
        ret = 0;
        ret = rmdir(argv[1]);
        if (ret != 0){
            write(1, "Sum ting wong\r\n", 15);
            _exit(-1);
        }
    }

    _exit(0);
}
