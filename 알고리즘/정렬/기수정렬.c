#include <stdio.h>
#define MAX 10001

typedef struct{
	int data[MAX];
	int bottom;
	int top;
}queue;

void push(queue *q, int x){
	q->data[q->bottom]=x;
	q->bottom=(q->bottom-1+MAX)%MAX;
	return;
}
int pop(queue *q){
	int temp=q->data[q->top];
	q->top=(q->top-1+MAX)%MAX;
	return temp;
}

int empty(queue *q){
	if(q->bottom==q->top)
		return 1;
	else
		return 0;
}
void radixSort(int d[], int n, int max){
   int radix=1;
   queue q[10];
   for(int i=0;i<10;i++){
   	q[i].bottom=0;
   	q[i].top=0;
	}
   while(radix<=max)
      radix*=10;
   for(int i=1;i<radix;i*=10){
      for(int j=0;j<n;j++){
         int k;
         if(d[j]<i)
				k=0;
         else
				k=(d[j]/i)%10;
         push(&q[k], d[j]);
      }
      int index=0;
      for(int j=0;j<10;j++){
         while(empty(&q[j])==0)
            d[index++]=pop(&q[j]);
      }
   }
   return;
}
void print(int d[], int n){
	for(int i=0;i<n;i++)
		printf("%d ", d[i]);
	return;
}
int main(){
	int n, d[100001], max=-2147483648;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &d[i]);
		if(max<d[i])
			max=d[i];
	}
	radixSort(d, n, max);
	print(d, n);
	return 0;
}
