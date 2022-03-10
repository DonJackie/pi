// Pthread create and join

#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include "thread.h"

int main()
{

    // threadID로 TID를 받아오고, threadRoutine라는 함수 포인터로 스레드를 실행한다.
    printf("Create Thread!\n");
    create_all_threads2();//create_all_threads()는 Segmentation fault 발생

    // threadID를 가진 thread가 실행되는 동안 기다린다.
    printf("Main Thread is now waiting for Child Thread!\n");
    release_all_threads2();//release_all_threads()는 Bus Error 발생

    // All thread released
    printf("Main Thread finish waitng Child Thread!\n");

    return 0;
}




