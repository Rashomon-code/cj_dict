#include "utils.h"
#include <string.h>
#include <stdio.h>

int get_target(char *target, size_t size){
    for(;;){
        printf("> ");

        if(fgets(target, size, stdin) == NULL){
            fprintf(stderr, "Can not get input.\n");
            return -1;
        }

        if(target[0] == '\n'){
            fprintf(stderr, "Empty input. Try again.\n");
            continue;
        }

        if(strchr(target, '\n') == NULL){
            fprintf(stderr, "Input too long. Try again.\n");
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }else{
            target[strcspn(target, "\n")] = '\0';
        }

        if(strcmp(target, "q") == 0){
            return 1;
        }

        if(!is_singal_character((unsigned char *)target)){
            printf("暫不支持該文字\n");
            continue;
        }

        break;
    }

    return 0;
}

int is_singal_character(const unsigned char *character){
    unsigned char ch0 = character[0];
    if((ch0 & 0xF0) == 0xE0){
        return (character[1] & 0xC0) == 0x80 && (character[2] & 0xC0) == 0x80;
    }

    if((ch0 & 0xF8) == 0xF0){
        return (character[1] & 0xC0) == 0x80 && (character[2] & 0xC0) == 0x80 && (character[3] & 0xC0) == 0x80;
    }

    return 0;
}
