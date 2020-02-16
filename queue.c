#include "queue.h"
#include <stdlib.h>

#define MinQueueSize ( 5 )

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType* Array;
};

int
IsEmptyQueue(Queue Q)
{
	return Q->Size == 0;
}

int
IsFullQueue(Queue Q)
{
	return Q->Size == Q->Capacity;
}

Queue
CreateQueue(int MaxElements)
{
	Queue Q;

	if (MaxElements < MinQueueSize)
		return -1;

	Q = malloc(sizeof(struct QueueRecord));
	if (Q == NULL)
		return -1;

	Q->Array = malloc(sizeof(ElementType) * MaxElements);
	if (Q->Array == NULL)
		return -1;
	Q->Capacity = MaxElements;
	MakeEmptyQueue(Q);

	return Q;
}

void
MakeEmptyQueue(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

void
DisposeQueue(Queue Q)
{
	if (Q != NULL)
	{
		free(Q->Array);
		free(Q);
	}
}

static int
Succ(int Value, Queue Q)
{
	if (++Value == Q->Capacity)
		Value = 0;
	return Value;
}

void
Enqueue(ElementType X, Queue Q)
{
	if (IsFullQueue(Q))
		return -1;
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}

ElementType
Front(Queue Q)
{
	if (!IsEmptyQueue(Q))
		return Q->Array[Q->Front];
	return -1;
	return 0;
}

void
Dequeue(Queue Q)
{
	if (IsEmptyQueue(Q))
		return -1;
	else
	{
		Q->Size--;
		Q->Front = Succ(Q->Front, Q);
	}
}

ElementType
FrontAndDequeue(Queue Q)
{
	ElementType X = 0;

	if (IsEmptyQueue(Q))
		return -1;
	else
	{
		Q->Size--;
		X = Q->Array[Q->Front];
		Q->Front = Succ(Q->Front, Q);
	}
	return X;
}
