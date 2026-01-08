#include "common.h"
#include "utils.h"
#include <stdio.h>

int main(void){
    int running = 1;
    char target[CHAR_SIZE];

    while(running){
        printf("輸入單個漢字(退出:q): ");
        int check = get_target(target, CHAR_SIZE);

        if(check == 1){
            printf("Bye.\n");
            running = 0;
        }else if(check == -1){
            perror("get_target");
            return -1;
        }
    }

    return 0;
}
