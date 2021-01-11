#include <stdio.h>
#include <stdlib.h>
int visit[1001];
typedef struct GraphType{
	int n;
	int adj_mat[1001][1001];
}GraphType;
typedef struct QueueType{
	int data[1001];
	int front;
	int back;
}QueueType;
void init(QueueType* q){
	q->front=0;
	q->back=-1;
}
void push(QueueType* q, int x){
	q->data[++q->back]=x;
}
int pop(QueueType* q){
	return q->data[q->front++];
}
int size(QueueType* q){
	return q->back-q->front+1;
}
void dfs(GraphType* g, int v){
	visit[v]=1;
	printf("%d ", v);
	for(int w=1;w<=g->n;w++){
		if(g->adj_mat[v][w] && !visit[w]){
			dfs(g, w);
		}
	}
}
void bfs(GraphType* g, int v){
	visit[v]=1;
	QueueType q;
	init(&q);
	push(&q, v);
	printf("%d ", v);
	while(size(&q)){
		int now=pop(&q);
		for(int w=1;w<=g->n;w++){
			if(g->adj_mat[now][w] && !visit[w]){
				visit[w]=1;
				printf("%d ", w);
				push(&q, w);
			}
		}
	}
}
int main(){
	int n, m, v, a, b;
	scanf("%d %d %d", &n, &m, &v);
	GraphType* g=(GraphType *)malloc(sizeof(GraphType));
	g->n=n;
	for(int r=0;r<1001;r++)
		for(int c=0;c<1001;c++)
			g->adj_mat[r][c]=0;
	for(int i=0;i<m;i++){
		scanf("%d %d", &a, &b);
		g->adj_mat[a][b]=1;
		g->adj_mat[b][a]=1;
	}
	dfs(g, v);
	printf("\n");
	for(int i=1;i<=1000;i++)
		visit[i]=0;
	bfs(g, v);
}
