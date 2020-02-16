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
* Description:	 栈的相关操作函数，将栈顶一个元素弹出并返回其值
* Param:
*	@s			 Stack			需要弹出栈顶元素的目标栈
* return:		 ElementType	被弹出的栈顶元素的值
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
* Description:	 栈的相关操作函数，返回栈顶元素值
* Param:
* return:		 ElementType	栈顶值
***************************************************/
ElementType StackTop(Stack s)
{
	return s->next->data;
}

/**************************************************
* Function Name: StackPush
* Description:	 栈的相关操作函数，向栈顶推入一个元素
* Param:
*	@x			 Stack	需要推入的元素的值
*	@s			 Stack	需要向栈顶推入元素的目标栈
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
* Description:	 栈的相关操作函数，判断栈是否为空
* Param:
*	@s			 Stack	需要判断的目标栈
* return:		 int	栈为空时，返回0；栈为非空时，为非0
***************************************************/
int IsEmptyStack(Stack s)
{
	return s->next == NULL;
}

/**************************************************
* Function Name: CreateStack
* Description:	 栈的相关操作函数，创建一个空栈
* Param:
* return:		 Stack	一个指向空栈的指针
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
* Description:	 栈的相关操作函数，销毁指定的栈
* Param:
*	@s			 Stack	指向需要销毁的栈的指针
* return:		 void
***************************************************/
void DisposeStack(Stack s)
{
	MakeEmptyStack(s);
	free(s);
}

/**************************************************
* Function Name: StackMakeEmpty
* Description:	 栈的相关操作函数，将指定栈置空
* Param:
*	@s			 Stack	指向需要置空的栈的指针
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
