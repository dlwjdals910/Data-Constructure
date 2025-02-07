#include <stdio.h>

#define MAX_STACK_SIZE 100 // ���� ������

typedef int element; // ���ÿ� �� �ڷ���
typedef struct { // ���� ����ü
	element data[MAX_STACK_SIZE]; // �迭 ����
	int top; // ���� ������ ����Ű�� �ε���
} StackType; // ���� ����ü �ڷ���


// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
	s->top = -1; // ������ ���� �ε����� -1�� ����
}

// ���� ���� �˼� �Լ�
int is_empty(StackType* s) {
	return s->top == -1; // ������ ���� �������� ��/���� ��ȯ
}

// ���� ��ȭ �˼� �Լ�
int is_full(StackType* s) {
	
	return s->top == MAX_STACK_SIZE - 1; // ������ ���� ��ȭ���� ��/���� ��ȯ
}

// ���� �Լ�
void push(StackType* s, element item) {
	if (is_full(s)) { // ���� ��ȭ �˼�
		fprintf(stderr, "���� ��ȭ ����\n"); // ���� ���� ���
		return;
	}
	else
		s->data[++(s->top)] = item; // ������ ���� �ε����� +�ϰ� �ڷ� ����
}

// ���� �Լ�
element pop(StackType* s) {
	if (is_empty(s)) { // ���� ���� �˼�
		fprintf(stderr, "���� ���� ����\n"); // ���� ���� ���
		exit(1); // ���α׷� ���� ����
	}
	else
		return s->data[(s->top)--]; // ���� �ε����� �ڷ� ��ȯ �� �ε��� -
	
}

// ��ũ �Լ�
element peek(StackType* s) {
	if (is_empty(s)) { // ���� ���� �˼�
		fprintf(stderr, "���� ���� ����\n"); // ���� ���� ���
		exit(1); // ���α׷� ���� ����
	}
	else
		return s->data[s->top]; // ���� �ε����� �ڷ� ��ȯ
}

int main() {
	StackType s;
	init_stack(&s);

	push(&s, 1);
	push(&s, 2);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	// ��� ��� 
	//	2 
	//	1  .
}