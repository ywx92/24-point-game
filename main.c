#include <stdio.h>
#include "utils.h"
#include "queue.h"

char exp[] = "6/(1-3/4)";

int main()
{
	Queue q, tmp;

	tmp = InfixToPosfix(exp);
	q = InfixToPosfix(exp);

	printf("转换后的后缀表达式为：");
	while (!IsEmptyQueue(tmp))
	{
		if (Front(tmp) > 13)
		{
			printf("%c  ", FrontAndDequeue(tmp));
		}
		else
		{
			printf("%d  ", FrontAndDequeue(tmp));
		}
	}
	printf("\n");

	printf("计算结果为：%d\n", CalcPosfix(q));

	return 0;
}