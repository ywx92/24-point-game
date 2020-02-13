#include "utils.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


/**************************************************
	Function: RandNumber
	Description: 产生4个在[min, max]范围内的随机数
	Input: param min: 随机数最小值
		   param max: 随机数最大值
	return: 返回一个数组指针
***************************************************/
int* RandNumber(int min, int max)
{
	int* arr;

	arr = (int*)malloc(sizeof(int) * 4);

	if (arr == NULL)
	{
		printf("Out of stack.");
	}

	for (int i = 0; i < 4; i++)
	{
		srand(time(NULL) + i);
		arr[i] = rand() % (max - min + 1) + min;
		printf("-->%d\n", arr[i]);
	}

	return arr;
}