#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>

int real_waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);
int _mkdir(const char *path, mode_t mode);

int check_internal_commands(char *argv[]);
int get_directory();

int main(){
  char command[255];
  for (;;){
   write(1, "# ", 2);

    int count = read(0, command, 255);
    if (count > 0 && command[count - 1] == '\n') {
        command[count - 1] = '\0';
    }else {
        command[count] = '\0';
    }

    char *argv[16];
    char *token;

    token = strtok(command, " ");

    int i = 0;
    while (token != NULL || i == 15){
        argv[i] = token;
        token = strtok(NULL, " ");
        i++;
    }


    int intCmCheck = check_internal_commands(argv);
    if(intCmCheck == 0){
        continue;
    }else if(intCmCheck == -1){
        write(1, "Sum ting wong\r\n", 15);
        continue;
    }

    command[count - 1] = 0;
    pid_t fork_result = fork();

    if(fork_result == 0){
      execve(command, argv, 0);
      _exit(-1);
    }else if(fork_result == -1){
      write(1, "Sum ting wong\r\n", 15);
    }else {
      siginfo_t info;
      real_waitid(P_ALL, 0, &info, WEXITED);
    }
  }

  _exit(0);
}

int get_directory(){
    struct dirent *dir;

    DIR *dr = opendir(".");

    while((dir = readdir(dr)) != NULL){
        write(1, dir->d_name, strlen(dir->d_name));
        write(1, " ", 1);
    }

    write(1, "\r\n", 2);

    closedir(dr);
    return 0;
}

int check_internal_commands(char *argv[]){
    int ret = 1;

    char *arg = argv[0];

    if(strcmp(arg, "cd") == 0){
        ret = chdir(argv[1]);
        if (ret != 0){
            perror("cd");
        }
    }else if(strcmp(arg, "mkdir") == 0){
        ret = _mkdir(argv[1], 0777);
    }else if(strcmp(arg, "ls") == 0){
        ret = get_directory();
    }else if(strcmp(arg, "rm") == 0){
        ret = rmdir(argv[1]);
        if(!ret){
            ret = unlink(argv[1]);
        }
    }else if(strcmp(arg, "pwd") == 0){
        char path[2049] = "";
        getcwd(path, 2048);
        write(1, path, strlen(path)+1);
        write(1, "\r\n", 2);
        ret = 0;
    }

    return ret;
}
