#include "windows.h"
#include <process.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

char sharedQueue[128];
const unsigned int queueLen = 10;
unsigned int producerPointer = 0;
unsigned int consumerPointer = 0;
char logFile[128] = "E:/Projects/lab/lab/txt/log.txt";

class ProducerConsumerLock
{
protected:
	HANDLE producerMutex;
	HANDLE consumerMutex;
	HANDLE wakenProducerSemaph;
	HANDLE wakenConsumerSemaph;
	unsigned int bufferLen;
public:
	ProducerConsumerLock(unsigned int bufLen = 100)
	{
		bufferLen = bufLen;

		// create 2 Mutexes and 2 Semaphores
		producerMutex = CreateMutex(NULL, false, NULL);
		consumerMutex = CreateMutex(NULL, false, NULL);
		wakenProducerSemaph = CreateSemaphore(NULL, bufferLen, bufferLen, NULL);
		wakenConsumerSemaph = CreateSemaphore(NULL, 0, bufferLen, NULL);

		if(!producerMutex || !consumerMutex || !wakenProducerSemaph || !wakenConsumerSemaph)
		{
			MessageBox(NULL, (LPCWSTR)("creating locks is failed."), NULL, 0);
		}
	}

	~ProducerConsumerLock()
	{
		CloseHandle(producerMutex);
		CloseHandle(consumerMutex);
		CloseHandle(wakenProducerSemaph);
		CloseHandle(wakenConsumerSemaph);
	}

	void ProducerLock()
	{
		// if the buffer is full, then wait
		WaitForSingleObject(wakenProducerSemaph, INFINITE);

		// if other producer is producing, then wait
		WaitForSingleObject(producerMutex, INFINITE);
	}

	void ProducerUnLock()
	{
		// inform other producers
		ReleaseMutex(producerMutex);

		// waken consumers
		ReleaseSemaphore(wakenConsumerSemaph, 1, NULL);
	}

	void ConsumerLock()
	{
		// if the buffer is empty, then wait
		WaitForSingleObject(wakenConsumerSemaph, INFINITE);

		// if other consumers is consuming, then wait
		WaitForSingleObject(consumerMutex, INFINITE);
	}

	void ConsumerUnLock()
	{
		// inform other consumers
		ReleaseMutex(consumerMutex);

		// waken producers
		ReleaseSemaphore(wakenProducerSemaph, 1, NULL);
	}
};

ProducerConsumerLock *pcLock = new ProducerConsumerLock(10);

void writeLogStr(char *s)
{
	FILE *f = 0;
	f = fopen(logFile, "a");
	if(!f)
	{
		fwrite(s, strlen(s), 1, f);
		fwrite("\n", 1, 1, f);
	}
	fclose(f);
}

void producerProc(void *param)
{
	int id = 0;
	char idStr[128];
	char str[128];

	id = *((int*)(param));
	itoa(id, idStr, 10);

	strcpy(str, "producer ");
	strncat(str, idStr, 128);
	strcat(str, " begin...");
	writeLogStr(str);

	while(true)
	{
		// first sleep a random time: between 1 to 5 seconds
		int sleepTime = 0;
		sleepTime = 1 + (int)(5.0 * rand() / (RAND_MAX + 1.0));
		Sleep(sleepTime * 10);

		// get a random char
		int randChar = 0;
		randChar = id + (int)(5.0 * rand() / (RAND_MAX + 1.0));
		randChar += 40;

		// prepare str
		strcpy(str, "producer ");
		strncat(str, idStr, 128);
		strcat(str, " has produced a new char: ");
		int len = strlen(str);
		str[len] = randChar;
		str[len + 1] = 0;

		// then access the shared var
		pcLock->ProducerLock();
		sharedQueue[producerPointer] = randChar;
		producerPointer = (producerPointer + 1) % queueLen;
		if(producerPointer == consumerPointer)
		{
			writeLogStr("The buffer queue is full.");
		}

		writeLogStr(str);
		pcLock->ProducerUnLock();
	}
}

void consumerProc(void *param)
{
	int id = 0;
	char idStr[128];
	char str[128];

	id = *((int*)(param));
	itoa(id, idStr, 10);
	strcpy(str, "consumer ");
	strncat(str, idStr, 128);
	strcat(str, " begin...");

	writeLogStr(str);
	while(true)
	{
		// first sleep a random time : 1 to 5 seconds.
		int sleepTime = 0;
		sleepTime = 1 + (int)(5.0 * rand() / (RAND_MAX + 1.0));
		Sleep(sleepTime * 10);

		// prepare str to print
		strcpy(str, "consumer ");
		strncat(str, idStr, 128);
		strcat(str, " has consumed a char : ");

		// then access the shared queue
		pcLock->ConsumerLock();
		int len = strlen(str);
		str[len] = sharedQueue[consumerPointer];
		str[len + 1] = 0;
		sharedQueue[consumerPointer] = 0;
		consumerPointer = (consumerPointer + 1) % queueLen;

		writeLogStr(str);
		pcLock->ConsumerUnLock();
	}
}

int main()
{
	int producerId = 0;
	int consumerId = 0;
	FILE *f = 0;

	// clear the log
	f = fopen(logFile, "w");
	fclose(f);

	srand(time(0));
	producerId = 1;
	_beginthread(producerProc, 0, (void*)&producerId);
	Sleep(10);

	consumerId = 1;
	_beginthread(consumerProc, 0, (void*)&consumerId);
	Sleep(10);

	producerId = 2;
	_beginthread(producerProc, 0, (void*)&producerId);
	Sleep(10);

	consumerId = 2;
	_beginthread(consumerProc, 0, (void*)&consumerId);
	Sleep(10);

	producerId = 3;
	_beginthread(producerProc, 0, (void*)&producerId);
	
	// running for 5 seconds
	Sleep(5000);
	return 0;
}