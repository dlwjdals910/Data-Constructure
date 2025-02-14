#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{ // 트리 구현
	element data;
	struct TreeNode *LNode, *RNode;
}TreeNode;

// 전위 순회 루 -> 왼 -> 오
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("%d->", root->data);
		preorder(root->LNode);
		preorder(root->RNode);
	}
	else
		return;
}

// 중위 순회 왼 -> 루 -> 오
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->LNode);
		printf("%d->", root->data);
		inorder(root->RNode);
	}
	else
		return;
}

// 후위 순회 왼 -> 오 -> 루
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->LNode);
		postorder(root->RNode);
		printf("%d->", root->data);
	}
}

int main() {
	TreeNode *root, *n1,*n2,*n3,*n4,*n5,*n6;
	root = (TreeNode*)malloc(sizeof(TreeNode));
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n4 = (TreeNode*)malloc(sizeof(TreeNode));
	n5 = (TreeNode*)malloc(sizeof(TreeNode));
	n6 = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = 1;
	n1->data = 2;
	n2->data = 3;
	n3->data = 4;
	n4->data = 5;
	n5->data = 6;
	n6->data = 7;
	root->LNode = n1; root->RNode = n2;
	n1->LNode = n3; n1->RNode = n4;
	n2->LNode = n5; n2->RNode = n6;
	n3->LNode = NULL; n3->RNode = NULL;
	n4->LNode = NULL; n4->RNode = NULL;
	n5->LNode = NULL; n5->RNode = NULL;
	n6->LNode = NULL; n6->RNode = NULL;
	printf("전위 순회");
	preorder(root);
	printf("\n");
	printf("중위 순회");
	inorder(root);
	printf("\n");
	printf("후위 순회");
	postorder(root);
	printf("\n");
}