#include "utils.h"
#include "queue.h"
#include "stack.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


/**************************************************
* Function Name: RandNumber
* Description:	 产生4个在[min, max]范围内的随机数
* Param:
*	@min		 int	随机数最小值
*	@max		 int	随机数最大值
* return:		 int*	返回一个数组指针
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

/**************************************************
* Function Name: InfixToPosfix
* Description:	 将中缀表达式转换为后缀表达式
* Param:
*	@str		 char*	指向中缀表达式的指针
* return:		 Queue	存储后缀表达式的队列
***************************************************/
Queue InfixToPosfix(char* str)
{
	Stack s;
	Queue q;

	s = CreateStack();
	q = CreateQueue(10);

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '1' && str[i] <= '9')				// 一个数不能以0开头
		{
			if (str[i+1] >= '1' && str[i+1] <= '9')		// 利用该程序中每个数最多只有两位数的特殊性
			{
				Enqueue((str[i] - 48) * 10 + (str[++i] - 48), q);
			}
			else
			{
				Enqueue(str[i] - 48, q);
			}
		}
		else
		{
			if (str[i] == ')')							// 遇到的符号为：)
			{
				while (!IsEmptyStack(s) && StackTop(s) != '(')
				{
					Enqueue(StackPop(s), q);
				}
				StackPop(s);
				continue;
			}
			else if (str[i] == '*' || str[i] == '/')	// 遇到的符号为：* /
			{
				while (!IsEmptyStack(s) && (StackTop(s) == '*' || StackTop(s) == '/'))
				{
					Enqueue(StackPop(s), q);
				}
			}
			else if (str[i] == '+' || str[i] == '-')	// 遇到的符号为：+ -
			{
				while (!IsEmptyStack(s) && StackTop(s) != '(')
				{
					Enqueue(StackPop(s), q);
				}
			}
			StackPush(str[i], s);
		}
	}

	while (!IsEmptyStack(s))							// 遍历结束后，弹出栈中所有符号
	{
		Enqueue(StackPop(s), q);
	}

	DisposeStack(s);
	return q;
}

/**************************************************
* Function Name: CalcPosfix
* Description:	 计算存储在队列中的后缀表达式并返回结果
* Param:
*	@q			 Queue	指向存储后缀表达式的对列指针
* return:		 int	表达式的计算结果
***************************************************/
int CalcPosfix(Queue q)
{
	Stack s;
	float x, y, tmp;

	s = CreateStack();

	while (!IsEmptyQueue(q))
	{
		if (Front(q) >= 1 && Front(q) <= 13)
		{
			StackPush(FrontAndDequeue(q) * 100, s);		// 栈中每个数精度为两位小数
		}
		else
		{
			x = StackPop(s) / 100.0;
			y = StackPop(s) / 100.0;
			switch (FrontAndDequeue(q))
			{
			case '+': tmp = y + x;	break;
			case '-': tmp = y - x;	break;
			case '*': tmp = y * x;	break;
			case '/': tmp = y / x;	break;
			default:
				return -1;
			}
			StackPush(tmp * 100 + 0.5, s);				// 栈中每个数精度为两位小数，四舍五入
		}
	}

	tmp = StackPop(s) / 100;
	DisposeStack(s);
	return tmp;
}