#include "dict.h"
#include <stdlib.h>
#include <stdio.h>

int init_cj(cangjie_record **dict){
    *dict = malloc(sizeof(cangjie_record));
    if(!dict){
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }

    return 0;
}
