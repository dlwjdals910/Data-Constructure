#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {  // 배열 리스트 구조체
	element array[MAX_LIST_SIZE]; // 배열 리스트의 배열
	int size; // 배열 리스트의 현재 크기
}ArrayListType;

// 초기화 함수
void init_list(ArrayListType* l) {
	l->size = 0;
}

// 공백 검수 함수
int is_empty(ArrayListType* l) {
	return l->size == 0;
}

// 포화 검수 함수
int is_full(ArrayListType* l) {
	return l->size == MAX_LIST_SIZE;
}

// 원하는 인덱스에 삽입 함수
void insert(ArrayListType* l, int pos, element item) {
	if (is_full(l)) {
		fprintf(stderr, "리스트 포화 에러\n");
		exit(1);
	}
	else if (pos > l->size || pos < 0) {
		printf("위치 오류\n");
		return;
	}
	else { // 정상 입력시
		if (l->array[pos] != '\0') { // 지정 인덱스부터 마지막 인덱스까지 한 칸씩 밀기
			for (int i = l->size; i > pos; --i) {
				l->array[i] = l->array[i - 1];
			}
		}
			l->array[pos] = item;
			l->size++; // 배열의 현재 크기 증가
	}
}

// 마지막 인덱스에 삽입 함수
void insert_last(ArrayListType* l, element item) {
	if (is_full(l)) {
		fprintf(stderr, "리스트 포화 에러\n");
		exit(1);
	}
	else {
		l->array[l->size] = item; // 배열은 사이즈 -1까지 이기 때문에 사이즈 인덱스에 삽입
		l->size++;
	}
}

// 처음 인덱스에 삽입 함수
void insert_first(ArrayListType* l, element item) {
	if (is_full(l)) {
		fprintf(stderr, "리스트 포화 에러\n");
		exit(1);
	}
	else { 
		if (!is_empty(l)) { // 배열에 값이 들어있다면 한칸 씩 밀기
			for (int i = l->size; i >= 1; --i) {
				l->array[i] = l->array[i - 1];
			}
		}
		l->array[0] = item;
			l->size++;
	}
}

// 지정 인덱스 삭제 함수
void delete(ArrayListType* l, int pos) {
	if (is_empty(l)) {
		fprintf(stderr, "리스트 공백 에러\n");
		exit(1);
	}
	else if (pos > l->size - 1 || pos < 0) { // 입력 인덱스가 범위 밖이라면 오류
		printf("위치 오류\n");
		return;
	}
	else { // 정상 입력 시
		for (int i = pos; i < l->size-1; ++i) { // 지정 인덱스 다음 인덱스부터 마지막까지 한 칸씩 땡기기
			l->array[i] = l->array[i + 1];
		}
		l->array[l->size - 1] = '\0';
		l->size--;
	}
}

// 모든 값 삭제 함수
void clear(ArrayListType* l) { // 배열을 NULL값으로 덮고 사이즈 0으로 초기화
	for (int i = 0; i < l->size; i++) {
		l->array[i] = '\0';
		l->size = 0;
	}
}

// 지정 인덱스 값 반환 함수
element get_entry(ArrayListType* l, int pos) {
	if (is_empty(l)) {
		printf("리스트에 아무것도 없습니다\n");
		return;
	}
	else if (pos > l->size - 1 || pos < 0) {
		printf("위치 오류\n");
		return;
	}
	else { // 지정 인덱스의 값 반환
		return l->array[pos];
	}
}

// 배열 크기 반환 함수
int get_length(ArrayListType* l) {
	return l->size;
}

// 배열의 처음부터 마지막까지 출력 함수
void print_list(ArrayListType* l) {
	for (int i = 0; i < l->size; ++i) {
		printf("%d | ", l->array[i]);
	}
	printf("\n");
}

int main() {
	ArrayListType l;
	init_list(&l);

	insert_first(&l, 1);
	insert(&l,1, 2);
	insert_last(&l, 3);

	print_list(&l);

	delete(&l, 1);
	print_list(&l);

	printf("%d\n", get_entry(&l, 0));
}