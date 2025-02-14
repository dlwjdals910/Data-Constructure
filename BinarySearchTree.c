#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct BST {								// 이진탐색트리 : 특정한 값을 찾기 좋은 방법
	element key; // 노드의 키값
	struct BST* LEFT; // 노드의 왼쪽 자식 노드
	struct BST* RIGHT; // 노드의 오른쪽 자식 노드
}BST;

// 탐색 함수
BST * search(BST* node, element n) { // 키값을 입력해 탐색하는 함수
	if (node == NULL) return NULL; // 노드가 비어있다면 NULL값 반환
	if (n == node->key) return node; // 탐색에 성공하면 노드 반환
	else if (node->key > n) // 입력된 키값이 노드의 키값보다 작을시 왼쪽 노드로 이동
		return search(node->LEFT, n);
	else // 입력된 키값이 노드의 키값보다 크다면 오른쪽 노드로 이동
		return search(node->RIGHT, n);
}

// 추가 함수
BST* new_node(element item) {
	BST *temp = (BST*)malloc(sizeof(BST)); // 임의의 노드 할당
	temp->LEFT = NULL;
	temp->RIGHT = NULL;
	temp->key = item; // 입력한 키값을 노드에 저장
	return temp; // 할당한 노드를 반환
}

// 삽입 함수
BST* insert_node(BST* root, element key) { // 입력한 키값이 적절한 위치에 삽입되도록하는 함수
	if (root == NULL) return new_node(key); // 노드가 비어있다면 새로운 노드 추가
	if (root->key > key) { // 입력된 키값이 노드의 키값보다 작다면
		root->LEFT = insert_node(root->LEFT, key); // 왼쪽 자식 노드로 이동
	}
	else if (root->key < key) { // 입력된 키값이 노드의 키값보다 크다면
		root->RIGHT = insert_node(root->RIGHT, key); // 오른쪽 자식 노드로 이동
	}
	return root; // 노드가 추가된 루트 반환
}

BST* min_value_node(BST* node) { // 가장 작은 노드를 찾는 함수 - 삭제 함수에 이용
	BST* current = node;
	while (node->LEFT != NULL) { // 왼쪽 자식 노드가 있다면
		current = current->LEFT; // 계속 왼쪽 자식 노드로 이동
	}
	return current; // 가장 작은 노드 반환
}

// 삭제 함수
BST* delete_node(BST* root, element key) { // 1. 단말 노드 2. 자식이 하나 3. 자식이 둘의 경우로 나누어 삭제
	if (root == NULL) return NULL; // 루트가 비어있다면 NULL값 반환
	if (root->key > key) // 입력된 키값이 노드의 키값보다 작다면
		root->LEFT = delete_node(root->LEFT, key); // 왼쪽 자식 노드로 이동
	else if (root->key < key) { // 입력된 키값이 노드의 키값보다 크다면
		root->RIGHT = delete_node(root->RIGHT, key); // 오른쪽 자식 노드로 이동
	}
	else { // 입력된 키값과 노드의 키값이 같다면
		if (root->LEFT == NULL) { // 왼쪽 자식 노드가 업다면  ---- 1,2의 경우
			BST* temp = root->RIGHT; // 임의의 노드에 오른쪽 자식 노드의 정보 복사
			free(root); // 현재 위치의 노드 삭제
			return temp; // 오른쪽 자식 노드의 정보 반환
		}
		else if (root->RIGHT == NULL) { // 오른쪽 자식 노드가 없다면  ---- 1,2의 경우
			BST* temp = root->LEFT; // 임의의 노드에 왼쪽 자식 노드의 정보 복사
			free(root); // 현재 위치의 노드 삭제
			return temp; // 왼쪽 자식 노드의 정보 반환
		}
		else { // ---- 3의 경우
			BST* temp = min_value_node(root->RIGHT); // 임의의 노드에 오른쪽 자식 노드의 가장 작은 자식 노드의 정보 복사
			root->key = temp->key; // 현재 노드의 키값을 복사한 노드의 키값으로 설정
			root->RIGHT = delete_node(root->RIGHT, temp->key); // 복사한 노드를 삭제하기 위해 오른쪽 자식 노드로 이동
		}
	}
	return root; // 삭제 후 루트 반환
}

// 중위 순회
void inorder(BST* root) {
	if (root == NULL) return;
	inorder(root->LEFT);
	printf("[%d] ", root->key);
	inorder(root->RIGHT);
}

int main() {
	BST* root = NULL;
	BST* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	inorder(root);
}