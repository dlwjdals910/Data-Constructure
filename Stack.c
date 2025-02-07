#include <stdio.h>

#define MAX_STACK_SIZE 100 // 스택 사이즈

typedef int element; // 스택에 들어갈 자료형
typedef struct { // 스택 구조체							스택 = 후입선출
	element data[MAX_STACK_SIZE]; // 배열 스택
	int top; // 현재 스택이 가리키는 인덱스
} StackType; // 스택 구조체 자료형


// 스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1; // 스택의 현재 인덱스를 -1로 설정
}

// 스택 공백 검수 함수
int is_empty(StackType* s) {
	return s->top == -1; // 스택이 현재 공백인지 참/거짓 반환
}

// 스택 포화 검수 함수
int is_full(StackType* s) {
	
	return s->top == MAX_STACK_SIZE - 1; // 스택이 현재 포화인지 참/거짓 반환
}

// 삽입 함수
void push(StackType* s, element item) {
	if (is_full(s)) { // 스택 포화 검수
		fprintf(stderr, "스택 포화 에러\n"); // 오류 상태 출력
		return;
	}
	else
		s->data[++(s->top)] = item; // 스택의 현재 인덱스를 +하고 자료 삽입
}

// 삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) { // 스택 공백 검수
		fprintf(stderr, "스택 공백 에러\n"); // 오류 상태 출력
		exit(1); // 프로그램 강제 종료
	}
	else
		return s->data[(s->top)--]; // 현재 인덱스의 자료 반환 후 인덱스 -
	
}

// 피크 함수
element peek(StackType* s) {
	if (is_empty(s)) { // 스택 공백 검수
		fprintf(stderr, "스택 공백 에러\n"); // 오류 상태 출력
		exit(1); // 프로그램 강제 종료
	}
	else
		return s->data[s->top]; // 현재 인덱스의 자료 반환
}

int main() {
	StackType s;
	init_stack(&s);

	push(&s, 1);
	push(&s, 2);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	// 출력 결과 
	//	2 
	//	1
}