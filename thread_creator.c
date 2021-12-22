#include "types.h"
#include "stat.h"
#include "user.h"

#define PAGESIZE 4096

int thread_create(void (*fn) (void *), void *arg, int status){
    void *fptr = malloc(2 * PAGESIZE);
    void *stack;
    if(fptr == 0)
        return -1;

    int mod = (unit) fptr % PAGESIZE;

    if(mod == 0)
        stack = fptr;
    else
        stack = fptr + (PAGESIZE - mod);
    
    int thread_id = thread_create((void*)stack);

    if(thread_id < 0)
        printf(1, "clone failed\n");
    else if (thread_id == 0){
        //child
        (fn)(arg); //call the function passed to thread_create
        free(stack); //free space when function is finished
        exit();
    }
    return thread_id;
}