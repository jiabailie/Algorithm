#include "ImageOper.h"

FILE_ACCESS_STATUS
Open(const char* path, BMPIMAGE image, BMPINFO info)
{
	int rgb = 0;
	long bmpSize = 0;

	FILE* pFile = 0;
	BYTE* data = 0;

	fopen_s(&pFile, path, "rb");

	if(NULL == pFile)
	{
		return NOT_EXIST;
	}
	fseek(pFile, 0, SEEK_END);
	bmpSize = ftell(pFile);
	rewind(pFile);

	fread(&(image->fileHeader), 1, FILEHEADERSIZE, pFile);
	fread(&(image->infoHeader), 1, INFOHEADERSIZE, pFile);

	info->w = image->infoHeader.biWidth;
	info->h = image->infoHeader.biHeight;
	info->bitCount = image->infoHeader.biBitCount;

	switch(image->infoHeader.biBitCount)
	{
	case 1:
		rgb = 2;
		break;
	case 4:
		rgb = 16;
		break;
	case 8:
		rgb = 256;
		break;
	case 24:
		rgb = 0;
		break;
	default:
		break;
	}

	fread(&(image->rgbQuad), rgb * sizeof(RGBQUAD), 1, pFile);
	if(image->infoHeader.biBitCount == 24)
	{
		info->bmpSize = bmpSize - FILEHEADERSIZE - INFOHEADERSIZE;
		info->data = (BYTE*)malloc(sizeof(BYTE) * (bmpSize - FILEHEADERSIZE - INFOHEADERSIZE));
		fread(info->data, 1, bmpSize - FILEHEADERSIZE - INFOHEADERSIZE, pFile);
	}

	info->lenLine = ((image->infoHeader.biBitCount * image->infoHeader.biWidth) + 31) / 8;

	fclose(pFile);

	return SUCCESS;
}

void Save(const char* path, long width, long height, BYTE* data)
{
	FILE * pFile = 0;
	long lineLength = 0;
	long totalLength = 0;

	int bytePerpixel = 3;

	BYTE header[BMPHEADERSIZE] = {
		0x42, 0x4d, 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0,
		40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0};

	long fileSize = width * height * 3 + 54;

	header[2] = (BYTE)(fileSize  & 0x000000ff);
	header[3] = (fileSize >> 8)  & 0x000000ff;
	header[4] = (fileSize >> 16) & 0x000000ff;
	header[5] = (fileSize >> 24) & 0x000000ff;

	header[18] = width         & 0x000000ff;
	header[19] = (width >> 8)  & 0x000000ff;
	header[20] = (width >> 16) & 0x000000ff;
	header[21] = (width >> 24) & 0x000000ff;

	header[22] = height         & 0x000000ff;
	header[23] = (height >> 8)  & 0x000000ff;
	header[24] = (height >> 16) & 0x000000ff;
	header[25] = (height >> 24) & 0x000000ff;

	fopen_s(&pFile, path, "wb");
	if(pFile == NULL)
	{
		return;
	}
	fwrite(header, sizeof(BYTE), 54, pFile);

	lineLength = width * bytePerpixel;	

	while(lineLength % 4 != 0)	
	{
		lineLength++;
	}

	totalLength = lineLength * height;

	fwrite(data, sizeof(BYTE), (size_t)totalLength, pFile);
	fclose(pFile);
}