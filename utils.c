#include "utils.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


/**************************************************
	Function: RandNumber
	Description: ����4����[min, max]��Χ�ڵ������
	Input: param min: �������Сֵ
		   param max: ��������ֵ
	return: ����һ������ָ��
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