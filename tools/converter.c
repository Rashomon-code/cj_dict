#include <stdio.h>
#include <string.h>
#include "common.h"

#define LINE_SIZE 16

int main(void){
    FILE *txt_file = fopen("data/cangjie5.txt", "r");
    FILE *bin_file = fopen("data/cangjie5.bin", "wb");
    
    if(!txt_file || !bin_file){
        fprintf(stderr, "Can not open the file.\n");
        return 1;
    }

    char line[LINE_SIZE];
    cangjie_record record;
    int count = 0;

    while(fgets(line, LINE_SIZE, txt_file)){
        memset(&record, 0, sizeof(cangjie_record));
        
        if(sscanf(line, "%7s %7s", record.code, record.character) == 2){
            fwrite(&record, sizeof(cangjie_record), 1, bin_file);
            count++;
        }
    }

    fclose(txt_file);
    fclose(bin_file);

    printf("%d changed.\n", count);

    return 0;
}
