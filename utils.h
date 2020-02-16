#ifndef _UTILS_H_
#define _UTILS_H_

#include "queue.h"

int* RandNumber(int min, int max);
Queue InfixToPosfix(char* str);
int CalcPosfix(Queue q);

#endif
