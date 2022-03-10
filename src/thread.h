/*
 * thread.h
 *
 *  Created on: 2022. 3. 10.
 *      Author: user
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <stdbool.h>

typedef pthread_t Thread;
typedef void *(*ThreadRoutine)(void *);
typedef int			int32_t;

typedef struct app_thread_param_t
{
	ThreadRoutine routine_;
	void *arg_;
	volatile bool running_;
} ThreadParam;


typedef struct app_thread_starter_t
{
	bool init_;
	Thread thread_;
	ThreadParam param_;
} ThreadStart;


void *don1(void *argumentPointer);
void *don2(void *argumentPointer);
void *don3(void *argumentPointer);
void *don4(void *argumentPointer);

bool create_all_threads();
bool ThreadStart_Start(ThreadStart *pStarter, ThreadRoutine routine, void *arg);
bool threadstart_init(ThreadStart *pStarter, ThreadRoutine routine, void *arg);
int32_t Thread_Create(Thread *th, void *attr, void *func, void *arg);
void release_all_threads(void);
void ThreadStart_Quit(ThreadStart *pStarter);
void ThreadStart_WaitReleased(ThreadStart *pStarter);
int32_t Thread_Join(Thread th, void **retval);
void ThreadStart_Abort(ThreadStart *pStarter);
int32_t Thread_Cancel(Thread th);
void release_all_threads2();
void create_all_threads2();


pthread_t threadID1,threadID2,threadID3,threadID4;

#endif /* THREAD_H_ */
