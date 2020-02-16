#include "utils.h"
#include "queue.h"
#include "stack.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


/**************************************************
* Function Name: RandNumber
* Description:	 ����4����[min, max]��Χ�ڵ������
* Param:
*	@min		 int	�������Сֵ
*	@max		 int	��������ֵ
* return:		 int*	����һ������ָ��
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
* Description:	 ����׺���ʽת��Ϊ��׺���ʽ
* Param:
*	@str		 char*	ָ����׺���ʽ��ָ��
* return:		 Queue	�洢��׺���ʽ�Ķ���
***************************************************/
Queue InfixToPosfix(char* str)
{
	Stack s;
	Queue q;

	s = CreateStack();
	q = CreateQueue(10);

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '1' && str[i] <= '9')				// һ����������0��ͷ
		{
			if (str[i+1] >= '1' && str[i+1] <= '9')		// ���øó�����ÿ�������ֻ����λ����������
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
			if (str[i] == ')')							// �����ķ���Ϊ��)
			{
				while (!IsEmptyStack(s) && StackTop(s) != '(')
				{
					Enqueue(StackPop(s), q);
				}
				StackPop(s);
				continue;
			}
			else if (str[i] == '*' || str[i] == '/')	// �����ķ���Ϊ��* /
			{
				while (!IsEmptyStack(s) && (StackTop(s) == '*' || StackTop(s) == '/'))
				{
					Enqueue(StackPop(s), q);
				}
			}
			else if (str[i] == '+' || str[i] == '-')	// �����ķ���Ϊ��+ -
			{
				while (!IsEmptyStack(s) && StackTop(s) != '(')
				{
					Enqueue(StackPop(s), q);
				}
			}
			StackPush(str[i], s);
		}
	}

	while (!IsEmptyStack(s))							// ���������󣬵���ջ�����з���
	{
		Enqueue(StackPop(s), q);
	}

	DisposeStack(s);
	return q;
}

/**************************************************
* Function Name: CalcPosfix
* Description:	 ����洢�ڶ����еĺ�׺���ʽ�����ؽ��
* Param:
*	@q			 Queue	ָ��洢��׺���ʽ�Ķ���ָ��
* return:		 int	���ʽ�ļ�����
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
			StackPush(FrontAndDequeue(q) * 100, s);		// ջ��ÿ��������Ϊ��λС��
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
			StackPush(tmp * 100 + 0.5, s);				// ջ��ÿ��������Ϊ��λС������������
		}
	}

	tmp = StackPop(s) / 100;
	DisposeStack(s);
	return tmp;
}