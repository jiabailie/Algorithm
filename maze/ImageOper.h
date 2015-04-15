#ifndef	_READ_VERIFY_CODE_H_
#define _READ_VERIFY_CODE_H_

#include "GenerateSampleImages.h"

FILE_ACCESS_STATUS
Open(const char* path, BMPIMAGE image, BMPINFO info);

void Save(const char* path, long width, long height, BYTE* data);

#endif