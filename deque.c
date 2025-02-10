#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#define MAX_DEQUE_SIZE 1001 // 덱 배열 사이즈

typedef int element; // 덱 자료 타입
typedef struct { // 덱 구조체						덱 = 배열의 앞과 뒤 양쪽에서 추가 제거가 되는 큐
	element data[MAX_DEQUE_SIZE]; // 큐 배열
	int rear; // 삽입 인덱스
	int front; // 삭제 인덱스
	int count; // 배열 속 자료 수
}DequeType; // 덱 자료형

// 초기화 함수
void init_deque(DequeType* d) {
	d->rear = 0; // 삽입 인덱스 0
	d->front = 1; // 삭제 인덱스 0
	d->count = 0; // 배열 속 자료 수 0
}

// 공백 검수 함수
int is_empty(DequeType* d) {
	return d->count == 0; // 자료 수가 0인지 참/거짓 반환
}

// 포화 검수 함수
int is_full(DequeType* d) {
	return d->count == MAX_DEQUE_SIZE; // 자료 수가 덱 사이즈와 같은지 참/거짓 반환
}

// 삽입 함수
void add_front(DequeType* d, element item) {
	if (is_full(d)) { // 포화 검수
		fprintf(stderr, "큐 포화 에러\n"); // 오류 상태 출력
		return;
	}
	else {
		d->count++; // 배열 속 자료 수 추가
		d->front = (d->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE; //  다음 front 인덱스로 이동
		d->data[d->front] = item;
	}
}

void add_rear(DequeType* d, element item) {
	if (is_full(d)) { // 포화 검수
		fprintf(stderr, "큐 포화 에러\n"); // 오류 상태 출력
		return;
	}
	else {
		d->count++; // 배열 속 자료 수 증가
		d->rear = (d->rear + 1) % MAX_DEQUE_SIZE; // 다음 rear 인덱스로 이동
		d->data[d->rear] = item;
	}
}

element del_front(DequeType* d) {
	if (is_empty(d)) { // 공백 검수
		fprintf(stderr, "큐 공백 에러\n"); // 오류 상태 출력
		return 0; // 프로그램 강제 종료
	}
	else {
		d->count--;
		element item = d->data[d->front];
		d->front = (d->front + 1) % MAX_DEQUE_SIZE; // 삭제 인덱스+1 % 덱 사이즈를 해 front의 값이 반복되도록 설정
		return  item;  // 증가한 삭제 인덱스의 자료 반환
	}
}
element del_rear(DequeType* d) {
	if (is_empty(d)) { // 공백 검수
		fprintf(stderr, "큐 공백 에러\n"); // 오류 상태 출력
		return 0; // 프로그램 강제 종료
	}
	else {
		d->count--;
		element item = d->data[d->rear];
		d->rear = (d->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;  // add_front함수의 알고리즘과 동일한 알고리즘 사용
		return  item;  // 증가한 삭제 인덱스의 자료 반환
	}
}
element get_front(DequeType* d) {
	if (is_empty(d)) { // 공백 검수
		fprintf(stderr, "큐 공백 에러\n"); // 오류 상태 출력
		return 0; // 프로그램 강제 종료
	}
	else
		return d->data[d->front];
}

element get_rear(DequeType* d) {
	if (is_empty(d)) { // 공백 검수
		fprintf(stderr, "큐 공백 에러\n"); // 오류 상태 출력
		return 0; // 프로그램 강제 종료
	}
	else
		return d->data[d->rear];
}


int main() {
	DequeType d;
	init_deque(&d);

	add_front(&d, 1);
	printf("%d\n",del_rear(&d));
	add_rear(&d, 2);
	printf("%d\n",del_front(&d));
}