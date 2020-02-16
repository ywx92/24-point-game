#ifndef _STACK_H_
#define _STACK_H_

struct StackNode;
typedef struct StackNode* StackNode;
typedef StackNode Stack;
typedef StackNode Position;

typedef int ElementType;

ElementType StackPop(Stack s);
ElementType StackTop(Stack s);
void StackPush(ElementType x, Stack s);
int IsEmptyStack(Stack s);
Stack CreateStack();
void DisposeStack(Stack s);
void MakeEmptyStack(Stack s);

#endif