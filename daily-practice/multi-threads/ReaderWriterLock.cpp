#include "windows.h"
#include <process.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

char sharedStr[128] = "this is a shared string.";
char logFile[128] = "E:/Projects/lab/lab/txt/log.txt";

class ReaderWriterLock
{
protected:
	HANDLE readMutex;
	HANDLE writeSemaph;
	int numReaders;

public:
	ReaderWriterLock()
	{
		numReaders = 0;

		// create 1 Mutex and 1 Semaphore
		// 2 Semaphores also ok
		readMutex = CreateMutex(NULL, false, NULL);
		writeSemaph = CreateSemaphore(NULL, 1, 1, NULL);
		if(readMutex == NULL || writeSemaph == NULL)
		{
			MessageBox(NULL, (LPCWSTR)("create mutex failed."), NULL, 0);
		}
	}

	~ReaderWriterLock()
	{
		CloseHandle(readMutex);
		CloseHandle(writeSemaph);
	}

	void ReaderLock()
	{
		// lock readMutex for readers to access numReaders
		WaitForSingleObject(readMutex, INFINITE);
		++numReaders;
		if(numReaders == 1)
		{
			// for first reader, lock writeSemaph
			WaitForSingleObject(writeSemaph, INFINITE);
		}
		ReleaseMutex(readMutex);
	}

	void ReaderUnLock()
	{
		// lock readMutex for readers to access numReaders
		WaitForSingleObject(readMutex, INFINITE);
		--numReaders;
		if(numReaders == 0)
		{
			// for last reader, unlock writeSemaph
			ReleaseSemaphore(writeSemaph, 1, NULL);
		}
		ReleaseMutex(readMutex);
	}

	void WriterLock()
	{
		// lock writeSemaph for writers to access shared object
		WaitForSingleObject(writeSemaph, INFINITE);
	}

	void WriterUnLock()
	{
		// unlock writeSemaph for writers to access shared object
		ReleaseSemaphore(writeSemaph, 1, NULL);
	}
};

ReaderWriterLock *rwLock = new ReaderWriterLock();

void writeLogStr(char *s)
{
	FILE *f = 0;
	f = fopen(logFile, "a");

	if(f)
	{
		fwrite(s, strlen(s), 1, f);
		fwrite("\n", 1, 1, f);
	}
	fclose(f);
}

void readerProc(void *param)
{
	int id = 0;
	char idStr[128];
	char str[128];

	id = *((int*)(param));
	itoa(id, idStr, 10);

	strcpy(str, "reader ");
	strncat(str, idStr, 128);
	strcat(str, " begin...");

	writeLogStr(str);

	while(true)
	{
		// first sleep a random time: between 1 to 5 seconds.
		int sleepTime;
		sleepTime = 1 + (int)(5.0 * rand() / (RAND_MAX + 1.0));
		Sleep(sleepTime * 10);

		// prepare str
		strcpy(str, "reader ");
		strncat(str, idStr, 128);
		strcat(str, " is reading the shared string: ");

		// access the shared string
		rwLock->ReaderLock();
		strncat(str, sharedStr, 128);
		rwLock->ReaderUnLock();

		writeLogStr(str);
	}
}

void writerProc(void *param)
{
	int id = 0;
	char idStr[128];
	char str[128];

	id = *((int*)(param));
	itoa(id, idStr, 10);

	strcpy(str, "writer ");
	strncat(str, idStr, 128);
	strcat(str, " begin...");

	writeLogStr(str);

	while(true)
	{
		// get a random char
		int randChar = 0;
		randChar = id + (int)(5.0 * rand() / (RAND_MAX + 1.0));
		randChar += int('0');

		// then access the shared string
		rwLock->WriterLock();
		for(int i = 0; i < 20; ++i)
		{
			sharedStr[i] = randChar;
			Sleep(1);
		}
		sharedStr[20] = 0; // append a '\0' to end a string

		strcpy(str, "writer ");
		strncat(str, idStr, 128);
		strcat(str, " is writing the shared string to : ");
		strncat(str, sharedStr, 128);
		rwLock->WriterUnLock();

		writeLogStr(str);
	}
}

int main()
{
	int readerId = 0;
	int writerId = 0;

	FILE *f;

	// clear the log
	f = fopen(logFile, "w");
	fclose(f);

	srand(time(0));

	readerId = 1;
	_beginthread(readerProc, 0, (void*)&readerId);
	Sleep(10);

	writerId = 1;
	_beginthread(writerProc, 0, (void*)&writerId);
	Sleep(10);

	readerId = 2;
	_beginthread(readerProc, 0, (void*)&readerId);
	Sleep(10);

	writerId = 2;
	_beginthread(writerProc, 0, (void*)&writerId);

	readerId = 3;
	_beginthread(readerProc, 0, (void*)&readerId);

	// running for 5 seconds
	Sleep(5000);

	return 0;
}