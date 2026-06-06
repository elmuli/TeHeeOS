#include <stdio.h>
int _exit(int);
int mount(const char *source, const char *target,
                 const char *filesystemtype, unsigned long mountflags,
                 const void *data);

int main(int argc, char *argv[])
{
    char* dev = argv[0];
    char* target = argv[1];
    char* fst;

    if(argc > 2){
        fst = argv[2];
    }else{
        fst = "ext4";
    }

    int stat = mount(dev, target, fst, 0, 0);

    if(stat == -1){
        perror("mount");
        _exit(-1);
    }

    _exit(0);
}
