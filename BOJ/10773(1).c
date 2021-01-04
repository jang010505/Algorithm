#include <stdio.h>
#include <string.h>

typedef struct{
	int data[100000];
	int top;
}stack;

void push(stack *s, int x){
	s->top++;
	s->data[s->top]=x;
	return;
}

void pop(stack *s){
	if(s->top==-1)
		printf("-1\n");
	else{
		//printf("%d\n", s->data[s->top]);
		s->top--;
	}
	return;
}

void size(stack *s){
	printf("%d\n", s->top+1);
	return;
}

void empty(stack *s){
	if(s->top==-1)
		printf("1\n");
	else
		printf("0\n");
	return;
}

void top(stack *s){
	if(s->top==-1)
		printf("-1\n");
	else
		printf("%d\n", s->data[s->top]);
	return;
}

int main(){
	int n, result=0;
	stack s;
	s.top=-1;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		if(x)
			push(&s, x);
		else
			pop(&s);
	}
	for(int i=0;i<=s.top;i++)
		result+=s.data[i];
	printf("%d", result);
	return 0;
}
