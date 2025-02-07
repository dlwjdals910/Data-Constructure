#include <stdio.h>

#define MAX_QUEUE_SIZE 100 // 큐 배열 사이즈

typedef int element; // 큐 자료 타입
typedef struct { // 선형큐 구조체							선형큐 = 선입선출 / 삽입, 삭제 인덱스가 증가만 하기 때문에 배열의 마지막에 도달함 - 이전 인덱스의 배열 사용 불가
	element data[MAX_QUEUE_SIZE]; // 큐 배열
	int rear; // 삽입 인덱스
	int front; // 삭제 인덱스
}QueueType; // 큐 자료형

// 초기화 함수
init_queue(QueueType* q) { 
	// 모든 인덱스 -1로
	q->rear = -1;
	q->front = -1;
}

// 공백 검수 함수
int is_empty(QueueType* q) {
	return (q->rear == q->front); // 삽입, 삭제 인덱스가 같은지 참/거짓 반환 ( 같다면 공백 )
}

// 포화 검수 함수
int is_full(QueueType* q) {
	return (q->rear == MAX_QUEUE_SIZE - 1); // 삽입 인덱스가 배열 사이즈 마지막인지 참/거짓 반환
}

// 삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q)) { // 포화 검수
		fprintf(stderr, "큐 포화 에러\n"); // 오류 상태 출력
		return;
	}
	else
		q->data[++(q->rear)] = item; // 삽입 인덱스++ 한 후 자료 삽입
}

// 삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q)) { // 공백 검수
		fprintf(stderr, "큐 공백 에러\n"); // 오류 상태 출력
		exit(1); // 프로그램 강제 종료
	}
	else
		return q->data[(++q->front)]; // 삭제 인덱스++ 한 후 자료 값 반환
}

int main() {
	QueueType q;

	init_queue(&q);

	enqueue(&q, 1);
	enqueue(&q, 2);

	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	// 출력 결과
	// 1
	// 2
}