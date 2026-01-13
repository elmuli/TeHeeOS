#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int rows = 21;
int current_row = 0;
int read_offset = 0;
char f_buf[4096];
char buf[512];
char c;

typedef struct Row {
    char r_buf[513];
    int rowNum;
    struct Row *next;
} Row;

Row *row_new(const char *r_buf){
    Row *R = malloc(sizeof(Row));
    if (R != NULL){
        strcpy(R->r_buf, r_buf);
        R->next = NULL;
        return R;
    }else{
        write(1, "MallocFailure\n", 15);
        return NULL;
    }
    
}

void Rows_push_front(Row **head, const char *r_buf) {
    Row *R = row_new(r_buf);
    if (!R){
        printf("Row setting failure\n");
        _exit(-1);
    }
    R->next = *head;
    *head = R;
}

void Rows_free(Row *head) {
    while (head) {
        Row *next = head->next;
        free(head);
        head = next;
    }
}

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDWR | O_CREAT, 0777);

    if(fd == -1){
        write(1, "Sum ting wong\r\n", 15);
        _exit(-1);
    }

    Row *head = NULL;

    for(int i=0; i<513; i++){
        int r = read(fd, &c, 1);
        if (r <= 0) break;

        buf[i] = c;
        if (c == '\n') {
            current_row++;
            Rows_push_front(&head, buf);
            i = 0;
            printf("%i\n", current_row);
            continue;
        }
    }

    for (;;) {
        for(Row *cur = head; cur; cur = cur->next){
            write(1, cur->r_buf, sizeof(cur->r_buf));
        }
        break;
    }

    Rows_free(head);

    _exit(0);
}
