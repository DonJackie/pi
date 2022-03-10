/*
 * thread.c
 *
 *  Created on: 2022. 3. 10.
 *      Author: user
 */
#include <stdio.h>
#include <pthread.h>
#include "thread.h"

bool create_all_threads(){
	if(ThreadStart_Start(&threadID1, don1, NULL) == false)
	{
		printf("threadID1 start failed. \n");
		return false;
	}

	if(ThreadStart_Start(&threadID2, don2, NULL) == false)
	{
		printf("threadID2 start failed. \n");
		return false;
	}

	if(ThreadStart_Start(&threadID3, don3, NULL) == false)
	{
		printf("threadID3 start failed. \n");
		return false;
	}

	if(ThreadStart_Start(&threadID4, don4, NULL) == false)
	{
		printf("threadID4 start failed. \n");
		return false;
	}

	return true;
}

void create_all_threads2(){
	pthread_create(&threadID1, NULL, don1, NULL);
	pthread_create(&threadID2, NULL, don2, NULL);
	pthread_create(&threadID3, NULL, don3, NULL);
	pthread_create(&threadID4, NULL, don4, NULL);
}

bool ThreadStart_Start(ThreadStart *pStarter, ThreadRoutine routine, void *arg)
{
	if(threadstart_init(pStarter, routine, arg) == false)
	{
		return false;
	}

	if(Thread_Create(&pStarter->thread_, NULL,
		(void *)pStarter->param_.routine_, (void *)&pStarter->param_) < 0)
	{
		pStarter->param_.running_ = false;
		return false;
	}

	pStarter->param_.running_ = true;

	return true;
}

bool threadstart_init(ThreadStart *pStarter, ThreadRoutine routine, void *arg)
{
	pStarter->init_ = false;

	if(routine == NULL)
	{
		return false;
	}

	pStarter->param_.routine_ = routine;
	pStarter->param_.arg_ = arg;
	pStarter->param_.running_ = false;
	pStarter->init_ = true;

	return true;
}

int32_t Thread_Create(Thread *th, void *attr, void *func, void *arg)
{
	return pthread_create((pthread_t *)th, (const pthread_attr_t *)attr,
		(void *(*)(void *))func, arg);
}

void ThreadStart_Quit(ThreadStart *pStarter)
{
	pStarter->param_.running_ = false;
}

int32_t Thread_Join(Thread th, void **retval)
{
	return pthread_join(th, retval);
}

int32_t Thread_Cancel(Thread th)
{
	return pthread_cancel(th);
}

void ThreadStart_Abort(ThreadStart *pStarter)
{
	Thread_Cancel(pStarter->thread_);
}

void ThreadStart_WaitReleased(ThreadStart *pStarter)
{
	void *retval;
	if(Thread_Join(pStarter->thread_, &retval))
	{
		// if join failed
		ThreadStart_Abort(pStarter);
		printf("Join Fail");
	}
}

void release_all_threads(void)
{

	ThreadStart_Quit(&threadID1);
	ThreadStart_WaitReleased(&threadID1);
	printf("    * GPS main released. \n\n");

	ThreadStart_Quit(&threadID2);
	ThreadStart_WaitReleased(&threadID2);
	printf("    * CAN main released. \n\n");

	ThreadStart_Quit(&threadID3);
	ThreadStart_WaitReleased(&threadID3);
	printf("    * CAN main released. \n\n");

	ThreadStart_Quit(&threadID4);
	ThreadStart_WaitReleased(&threadID4);
	printf("    * CAN main released. \n\n");

}

void release_all_threads2(void)
{
	pthread_join(threadID1, NULL);
	pthread_join(threadID2, NULL);
	pthread_join(threadID3, NULL);
	pthread_join(threadID4, NULL);
}

void *don1(void *argumentPointer)
{
    pthread_t id = pthread_self();

    // TID를 반환하고 출력
    printf("thread ID (TID) :: %lu\n", id);

    // 부모 스레드 부분에서 리턴값을 받기때문에 항상 리턴을 해준다.
    while(1){
    	printf("Hello\n");
    }
    return NULL;
}

void *don2(void *argumentPointer)
{
    pthread_t id = pthread_self();

    // TID를 반환하고 출력
    printf("thread ID (TID) :: %lu\n", id);

    while(1){
        	printf("byebye\n");
	}
    // 부모 스레드 부분에서 리턴값을 받기때문에 항상 리턴을 해준다.
    return NULL;
}

void *don3(void *argumentPointer)
{
    pthread_t id = pthread_self();

    // TID를 반환하고 출력
    printf("thread ID (TID) :: %lu\n", id);

    // 부모 스레드 부분에서 리턴값을 받기때문에 항상 리턴을 해준다.
    return NULL;
}

void *don4(void *argumentPointer)
{
    pthread_t id = pthread_self();

    // TID를 반환하고 출력
    printf("thread ID (TID) :: %lu\n", id);

    // 부모 스레드 부분에서 리턴값을 받기때문에 항상 리턴을 해준다.
    return NULL;
}
