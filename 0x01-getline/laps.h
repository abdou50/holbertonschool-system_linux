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
void race_state(int *id, size_t size);
char *_getline(const int fd);
#endif