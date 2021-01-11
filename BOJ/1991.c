#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	char data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
TreeNode* MakeNewNode(char data){
	TreeNode* newnode=(TreeNode*)malloc(sizeof(TreeNode));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
TreeNode* SerchNode(TreeNode* nownode, char taget){
	if(nownode){
		if(nownode->data==taget)
			return nownode;
		else{
			TreeNode* serchnode;
			serchnode=SerchNode(nownode->left, taget);
			if(serchnode)
				return serchnode;
			serchnode=SerchNode(nownode->right, taget);
			if(serchnode)
				return serchnode;
		}
	}
	return NULL;
}
void inoder(TreeNode* nownode){
	if(nownode){
		inoder(nownode->left);
		printf("%c", nownode->data);
		inoder(nownode->right);
	}
}
void preoder(TreeNode* nownode){
	if(nownode){
		printf("%c", nownode->data);
		preoder(nownode->left);
		preoder(nownode->right);
	}
}
void postoder(TreeNode* nownode){
	if(nownode){
		postoder(nownode->left);
		postoder(nownode->right);
		printf("%c", nownode->data);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	TreeNode* nownode=MakeNewNode(NULL);
	getchar();
	for(int i=0;i<n;i++){
		char root, right, left;
		scanf("%c %c %c", &root, &left, &right);
		getchar();
		TreeNode* serchnode=SerchNode(nownode, root);
		if(serchnode){
			serchnode->data=root;
			if(left!='.')
				serchnode->left=MakeNewNode(left);
			if(right!='.')
				serchnode->right=MakeNewNode(right);
		}
		else{
		 	nownode->data=root;
			if(left!='.')
				nownode->left=MakeNewNode(left);
			if(right!='.')
				nownode->right=MakeNewNode(right);
		}
	}
	preoder(nownode);
	printf("\n");
	inoder(nownode);
	printf("\n");
	postoder(nownode);
	return 0;
}
