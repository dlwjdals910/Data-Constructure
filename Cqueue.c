#include <stdio.h>

#define MAX_QUEUE_SIZE 5 // 큐 배열 사이즈

typedef int element; // 큐 자료 타입
typedef struct { // 선형큐 구조체							원형큐 = 인덱스의 값이 0~MAX_QUEUE_SIZE를 반복해 배열의 끝에 가도 계속 사용 가능 / count 변수로 공백, 포화를 관리해 빈 칸 없이 사용 가능
	element data[MAX_QUEUE_SIZE]; // 큐 배열
	int rear; // 삽입 인덱스
	int front; // 삭제 인덱스
	int count; // 배열 속 자료 수
}QueueType; // 큐 자료형

// 초기화 함수
init_queue(QueueType* q) {
	q->rear = 0; // 삽입 인덱스 0
	q->front = 0; // 삭제 인덱스 0
	q->count = 0; // 배열 속 자료 수 0
}

// 공백 검수 함수
int is_empty(QueueType* q) {
	return q->count == 0; // 자료 수가 0인지 참/거짓 반환
}

// 포화 검수 함수
int is_full(QueueType* q) {
	return q->count == MAX_QUEUE_SIZE; // 자료 수가 큐 사이즈와 같은지 참/거짓 반환
}

// 삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q)) { // 포화 검수
		fprintf(stderr, "큐 포화 에러\n"); // 오류 상태 출력
		return;
	}
	else {
		q->count++; // 배열 속 자료 수 증가
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // 삽입 인덱스+1 % 큐 사이즈를 해 rear의 값이 반복되도록 설정
		q->data[q->rear] = item; // 증가한 삽입 인덱스의 배열에 자료 삽입
	}
}

// 삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q)) { // 공백 검수
		fprintf(stderr, "큐 공백 에러\n"); // 오류 상태 출력
		exit(1); // 프로그램 강제 종료
	}
	else {
		q->count--; // 배열 속 자료 수 감소
		q->front = (q->front + 1) % MAX_QUEUE_SIZE; // 삭제 인덱스+1 % 큐 사이즈를 해 front의 값이 반복되도록 설정
		return  q->data[q->front];  // 증가한 삭제 인덱스의 자료 반환
	}
}

// 출력 함수
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear); // 큐의 시작 부분과 마지막 부분까지 출력
	if (!is_empty(q)) {
		int i = q->front; // 출력 시작 점
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear) {
				break;
			}
		} while (i != q->front);
	}
	printf("\n");
}

int main() {
	QueueType q;

	init_queue(&q);

	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	//enqueue(&q, 5);

	queue_print(&q);

	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	queue_print(&q);
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	//printf("%d\n", dequeue(&q));
	enqueue(&q, 6);

	printf("%d\n", dequeue(&q));
}