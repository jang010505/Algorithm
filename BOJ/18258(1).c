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

void pop(queue *q){
	if(q->top-q->bottom==-1)
		printf("-1\n");
	else{
		printf("%d\n", q->data[q->bottom]);
		q->bottom++;
	}
	return;
}

void size(queue *q){
	printf("%d\n", q->top+1-q->bottom);
	return;
}

void empty(queue *q){
	if(q->top-q->bottom==-1)
		printf("1\n");
	else
		printf("0\n");
	return;
}

void front(queue *q){
	if(q->top-q->bottom==-1)
		printf("-1\n");
	else
		printf("%d\n", q->data[q->bottom]);
	return;
}

void back(queue *q){
	if(q->top-q->bottom==-1)
		printf("-1\n");
	else
		printf("%d\n", q->data[q->top]);
	return;
}

int main(){
	int n;
	queue q;
	q.top=-1;
	q.bottom=0;
	scanf("%d\n", &n);
	for(int i=0;i<n;i++){
		char str[100];
		scanf("%s", str);
		if(!strcmp(str, "push")){
			int x;
			scanf("%d\n", &x);
			push(&q, x);
		}
		if(!strcmp(str, "pop"))
			pop(&q);
		if(!strcmp(str, "size"))
			size(&q);
		if(!strcmp(str, "empty"))
			empty(&q);
		if(!strcmp(str, "front"))
			front(&q);
		if(!strcmp(str, "back"))
			back(&q);
	}
	return 0;
}
