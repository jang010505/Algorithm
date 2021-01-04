#include <stdio.h>
#include <string.h>
#define MAX 50000
typedef struct{
	int data[MAX];
	int bottom;
	int top;
}deque;

void push_front(deque *q, int x){
	q->data[q->bottom]=x;
	q->bottom=(q->bottom-1+MAX)%MAX;
	return;
}

void push_back(deque *q, int x){
	q->top=(q->top+1)%MAX;
	q->data[q->top]=x;
	return;
}

void pop_front(deque *q){
	if(q->bottom==q->top)
		printf("-1\n");
	else{
		q->bottom=(q->bottom+1)%MAX;
		printf("%d\n", q->data[q->bottom]);
	}
	return;
}

void pop_back(deque *q){
	if(q->bottom==q->top)
		printf("-1\n");
	else{
		printf("%d\n", q->data[q->top]);
		q->top=(q->top-1+MAX)%MAX;
	}
	return;
}

void size(deque *q){
	if(q->bottom<=q->top)
		printf("%d\n", q->top-q->bottom);
	else
		printf("%d\n", q->top-q->bottom+MAX);
	return;
}

void empty(deque *q){
	if(q->bottom==q->top)
		printf("1\n");
	else
		printf("0\n");
	return;
}

void front(deque *q){
	if(q->bottom==q->top)
		printf("-1\n");
	else
		printf("%d\n", q->data[(q->bottom+1)%MAX]);
	return;
}

void back(deque *q){
	if(q->bottom==q->top)
		printf("-1\n");
	else
		printf("%d\n", q->data[q->top]);
	return;
}

int main(){
	int n;
	deque q;
	q.top=0;
	q.bottom=0;
	scanf("%d\n", &n);
	for(int i=0;i<n;i++){
		char str[100];
		scanf("%s", str);
		if(!strcmp(str, "push_front")){
			int x;
			scanf("%d\n", &x);
			push_front(&q, x);
		}
		if(!strcmp(str, "push_back")){
			int x;
			scanf("%d\n", &x);
			push_back(&q, x);
		}
		if(!strcmp(str, "pop_front"))
			pop_front(&q);
		if(!strcmp(str, "pop_back"))
			pop_back(&q);
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
