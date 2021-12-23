#include "types.h"
#include "stat.h"
#include "user.h"

void childPrint(void *args){
    printf(1, "hi, childs function executed properly with argument: %d\n", *(int *) args);

}
int main(void){
    int argument = 0x0F01;
    int thread_id = thread_creator(&childPrint, (void *)&argument, 0);
    if(thread_id < 0)
        printf(1, "thread_creator failed\n");
    thread_wait();
    printf(1, "thread_id is: %d\n", thread_id);

    exit();
}