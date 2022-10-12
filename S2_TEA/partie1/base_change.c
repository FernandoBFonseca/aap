#include "base_change.h"

void base_change_basic(int value, int new_base){
    int Q = value;
    while(Q!=0){
        printf("%d ", Q % new_base);
        Q /= new_base;
    }

    return;
}

void base_change_stack(int value, int new_base){
    T_stack s = NULL;
    int Q = value;
    while(Q!=0){
        push(Q % new_base, &s);
        Q /= new_base;
    }

    showStack(&s);
    
    freeStack(&s);

    return;
}