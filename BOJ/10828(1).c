#include <stdio.h>
#include <string.h>

typedef struct{
	int data[10000];
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
		printf("%d\n", s->data[s->top]);
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
	int n;
	stack s;
	s.top=-1;
	scanf("%d\n", &n);
	for(int i=0;i<n;i++){
		char str[100];
		scanf("%s", str);
		if(!strcmp(str, "push")){
			int x;
			scanf("%d\n", &x);
			push(&s, x);
		}
		if(!strcmp(str, "pop"))
			pop(&s);
		if(!strcmp(str, "size"))
			size(&s);
		if(!strcmp(str, "empty"))
			empty(&s);
		if(!strcmp(str, "top"))
			top(&s);
	}
	return 0;
}
