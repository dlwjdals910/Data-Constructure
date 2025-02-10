#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct { // 연결리스트 구조체																연결 리스트 = 배열의 맨 앞 값을 삽입, 삭제에 유리함
	element data; // 노드의 값
	struct ListNode* link; // 연결 노드 주소 저장 변수
}ListNode;

// 헤드 포인터가 가리키는 노드 삽입 함수
ListNode* insert_first(ListNode* head, element value) { 
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // 추가할 노드 p 동적할당
	p->data = value; // p노드의 값 저장
	p->link = head; // p 노드의 연결 노드 = 현재 head 노드
	head = p; // p를 head 노드로
	return head; // head리스트 반환
}

// 원하는 노드 앞에 삽입 함수
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->link = pre->link; // 지정 노드의 연결 노드를 p의 연결 노드로 지정
	pre->link = p; // 지정 노드의 연결 노드를 p로 지정
	p->data = value; // p 노드의 값 저장
	return head;
}

// 헤드 포인터가 가리키는 노드 삭제 함수
ListNode* delete_first(ListNode* head) {
	if (head == NULL)
		return NULL;
	ListNode* removed; // 삭제용 노드 생성
	removed = head; // 삭제용 노드에 현재 헤드 노드의 정보 저장
	head = removed->link; // 헤드 = 삭제 전 헤드의 연결 노드
	free(removed); // 할당 해제
	return head;
}

// 지정 노드의 연결 노드 삭제 함수
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed; // 삭제용 노드 생성
	removed = pre->link; // 삭제용 노드에 삭제할 노드 정보 저장
	pre->link = removed->link; // 지정 노드에 삭제할 노드의 연결 노드 연결
	free(removed); // 할당 해제
	return head;
}

// 출력 함수
void print_list(ListNode* head) { // 연결 노드가 NULL일 때까지 출력 후 연결된 노드로 이동 반복
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

int main() {
	ListNode* head, * next;
	head = (ListNode*)malloc(sizeof(ListNode));
	head->data = 10;
	head->link = NULL;

	head = insert_first(head, 40);
	head = insert(head, head, 30);
	print_list(head);
	head = delete(head, head);
	print_list(head);
}