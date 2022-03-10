// Pthread create and join

#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include "thread.h"

int main()
{

    // threadID�� TID�� �޾ƿ���, threadRoutine��� �Լ� �����ͷ� �����带 �����Ѵ�.
    printf("Create Thread!\n");
    create_all_threads2();//create_all_threads()�� Segmentation fault �߻�

    // threadID�� ���� thread�� ����Ǵ� ���� ��ٸ���.
    printf("Main Thread is now waiting for Child Thread!\n");
    release_all_threads2();//release_all_threads()�� Bus Error �߻�

    // All thread released
    printf("Main Thread finish waitng Child Thread!\n");

    return 0;
}




