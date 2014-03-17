#include "windows.h"
#include <process.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

const char thinking = 1;
const char hungry = 2;
const char dining = 3;
const unsigned int philosopher_num = 5;

// each fork has a semaphore.
HANDLE semph[philosopher_num];

// mutex for printing information.
HANDLE mutex;

void philosopherProc(void *param)
{
	int id = 0;
	int ret = 0;
	char state;
	char idStr[128];
	char stateStr[128];
	unsigned int leftFork;
	unsigned int rightFork;

	id = *((int*)(param));
	itoa(id, idStr, 10);

	Sleep(10);

	// initial state is thinking.
	state = thinking;

	leftFork = id % philosopher_num;
	rightFork = (id + 1) % philosopher_num;

	while(true)
	{
		switch(state)
		{
		case thinking:
			state = hungry;
			strcpy(stateStr, "HUNGRY");
			break;
		case hungry:
			strcpy(stateStr, "HUNGRY");

			// first check the left fork.
			ret = WaitForSingleObject(semph[leftFork], 0);

			// if left fork is ready, take it up.
			if(ret == WAIT_OBJECT_0)
			{
				// now check the right fork.
				ret = WaitForSingleObject(semph[rightFork], 0);
				if(ret == WAIT_OBJECT_0)
				{
					// right fork is also ready
					// changing the state
					state = dining;
					strcpy(stateStr, "DINING");
				}
				else
				{
					// if right fork is being used by others
					// should put down the left fork
					ReleaseSemaphore(semph[leftFork], 1, NULL);
				}
			}
			break;
		case dining:
			// put down both the left and right fork.
			ReleaseSemaphore(semph[leftFork], 1, NULL);
			ReleaseSemaphore(semph[rightFork], 1, NULL);

			// changing the state
			state = thinking;
			strcpy(stateStr, "THINKING");
			break;
		}

		// try to print the state
		WaitForSingleObject(mutex, INFINITE);
		cout << "philosopher " << id << " is: " << stateStr << endl;
		ReleaseMutex(mutex);

		// sleep a random time between 1 to 5 seconds.
		int sleepTime = 0;
		sleepTime = 1 + (int)(5.0 * rand() / (RAND_MAX + 1.0));
		Sleep(sleepTime * 10);
	}
}

int main()
{
	int i = 0;
	srand(time(0));

	mutex = CreateMutex(NULL, false, NULL);
	for(i = 0; i < philosopher_num; ++i)
	{
		semph[i] = CreateSemaphore(NULL, 1, 1, NULL);
		_beginthread(philosopherProc, 0, (void*)&i);
		Sleep(10);
	}
	Sleep(1000);
	return 0;
}