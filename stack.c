#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
	ElementType data;
	Position next;
};

/**************************************************
* Function Name: StackPop
* Description:	 ջ����ز�����������ջ��һ��Ԫ�ص�����������ֵ
* Param:
*	@s			 Stack			��Ҫ����ջ��Ԫ�ص�Ŀ��ջ
* return:		 ElementType	��������ջ��Ԫ�ص�ֵ
***************************************************/
ElementType StackPop(Stack s)
{
	ElementType tmpData;
	StackNode firstCell;

	if (s == NULL)
	{
		return -1;
	}
	else
	{
		firstCell = s->next;
		s->next = s->next->next;
		tmpData = firstCell->data;
		free(firstCell);
	}

	return tmpData;
}

/**************************************************
* Function Name: StackTop
* Description:	 ջ����ز�������������ջ��Ԫ��ֵ
* Param:
* return:		 ElementType	ջ��ֵ
***************************************************/
ElementType StackTop(Stack s)
{
	return s->next->data;
}

/**************************************************
* Function Name: StackPush
* Description:	 ջ����ز�����������ջ������һ��Ԫ��
* Param:
*	@x			 Stack	��Ҫ�����Ԫ�ص�ֵ
*	@s			 Stack	��Ҫ��ջ������Ԫ�ص�Ŀ��ջ
* return:		 void
***************************************************/
void StackPush(ElementType x, Stack s)
{
	StackNode tmpCell;

	tmpCell = malloc(sizeof(struct StackNode));
	if (tmpCell == NULL)
	{
		return -1;
	}
	else
	{
		tmpCell->data = x;
		tmpCell->next = s->next;
		s->next = tmpCell;
	}
}

/**************************************************
* Function Name: IsEmptyStack
* Description:	 ջ����ز����������ж�ջ�Ƿ�Ϊ��
* Param:
*	@s			 Stack	��Ҫ�жϵ�Ŀ��ջ
* return:		 int	ջΪ��ʱ������0��ջΪ�ǿ�ʱ��Ϊ��0
***************************************************/
int IsEmptyStack(Stack s)
{
	return s->next == NULL;
}

/**************************************************
* Function Name: CreateStack
* Description:	 ջ����ز�������������һ����ջ
* Param:
* return:		 Stack	һ��ָ���ջ��ָ��
***************************************************/
Stack CreateStack()
{
	Stack s;

	s = malloc(sizeof(struct StackNode));
	if (s == NULL)
	{
		return -1;
	}
	else
	{
		s->next = NULL;
		MakeEmptyStack(s);
		return s;
	}
}

/**************************************************
* Function Name: DisposeStack
* Description:	 ջ����ز�������������ָ����ջ
* Param:
*	@s			 Stack	ָ����Ҫ���ٵ�ջ��ָ��
* return:		 void
***************************************************/
void DisposeStack(Stack s)
{
	MakeEmptyStack(s);
	free(s);
}

/**************************************************
* Function Name: StackMakeEmpty
* Description:	 ջ����ز�����������ָ��ջ�ÿ�
* Param:
*	@s			 Stack	ָ����Ҫ�ÿյ�ջ��ָ��
* return:		 void
***************************************************/
void MakeEmptyStack(Stack s)
{
	if (s == NULL)
	{
		return -1;
	}
	else
	{
		while (!IsEmptyStack(s))
		{
			StackPop(s);
		}
	}
}
