#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char data;
	struct node* next;
	struct node* prev;
}node;

int main(){
	node* headnode=(node*)malloc(sizeof(node));
	headnode->data='k';
	headnode->next=NULL;
	headnode->prev=NULL;
	node* nownode=headnode;
	char x;
	x=getchar();
	while(x!='\n'){
		node* newnode=(node*)malloc(sizeof(node));
		newnode->data=x;
		newnode->next=NULL;
		newnode->prev=nownode;
		nownode->next=newnode;
		nownode=newnode;
		x=getchar();
	}
	int n;
	scanf("%d\n", &n);
	for(int i=0;i<n;i++){
		char str[100];
		scanf("%s", str);
		if(!strcmp(str, "L") && nownode->prev)
			nownode=nownode->prev;
		else if(!strcmp(str, "D") && nownode->next)
			nownode=nownode->next;
		else if(!strcmp(str, "B") && nownode->prev){
			node* delnode=(node*)malloc(sizeof(node));
			delnode=nownode;
			nownode=delnode->prev;
			if(delnode->next){
				nownode->next=delnode->next;
				delnode->next->prev=nownode;
				delnode->prev=NULL;
			}
			else
				nownode->next=NULL;
			free(delnode);
		}
		else if(!strcmp(str, "P")){
			char temp;
			scanf(" %c", &temp);
			node* newnode=(node*)malloc(sizeof(node));
			newnode->data=temp;
			newnode->prev=nownode;
			if(nownode->next){
				newnode->next=nownode->next;
				nownode->next->prev=newnode;
			}
			else
				newnode->next=NULL;
			nownode->next=newnode;
			nownode=nownode->next;
		}
	}
	headnode=headnode->next;
	while(headnode){
		printf("%c", headnode->data);
		headnode=headnode->next;
	}
}
