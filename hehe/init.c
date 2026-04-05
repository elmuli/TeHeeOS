
int _exit(int);
int mount(const char *source, const char *target,
                 const char *filesystemtype, unsigned long mountflags,
                 const void *data);
int fork(void);
int execve(const char *path, char *const argv[],
                  char *const envp[]);

char *argv[3];
int main()
{
    argv[0] = "/bin/";
    argv[1] = "/usr/bin/";
    argv[2] = "";

    mount("devtmpfs", "/dev", "devtmpfs", 0, 0);
    mount("/sys", "/sys", "sysfs", 0, 0);
    mount("/proc", "/proc", "proc", 0, 0);
    mount("devpts", "/dev/pts", "devpts", 0, 0);
    mount("tmpfs", "/run", "tmpfs", 0, 0);
    mount("tmpfs", "/tmp", "tmpfs", 0, 0);
    mount("tmpfs", "/dev/shm", "tmpfs", 0, 0);

    int fork_result = fork();
    if(fork_result == 0){
        execve("/bin/shell", argv, 0);
        _exit(1);
    }

    while (1) {}
}
