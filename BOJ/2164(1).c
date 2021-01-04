#include <stdio.h>
#include <string.h>

typedef struct{
	int data[2000000];
	int bottom;
	int top;
}queue;

void push(queue *q, int x){
	q->top++;
	q->data[q->top]=x;
	return;
}

int pop(queue *q){
	int q_pop=q->data[q->bottom];
	q->bottom++;
	return q_pop;
}

int size(queue *q){
	return q->top+1-q->bottom;
}

int main(){
	int n;
	queue q;
	q.top=-1;
	q.bottom=0;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		push(&q, i);
	while(size(&q)!=1){
		pop(&q);
		if(size(&q)==1)
			break;
		int q_pop=pop(&q);
		push(&q, q_pop);
	}
	printf("%d", pop(&q));
	return 0;
}
