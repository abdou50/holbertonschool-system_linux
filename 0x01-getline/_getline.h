#ifndef lap
#define lap
#include <stdio.h>
#include <stdlib>
#include <math.h>
typedef struct reader_s
{
	int fd;
	char *buf;
	int bytes;
	struct reader_s *next;
} reader_t;
char *_getline(const int fd);
#endif