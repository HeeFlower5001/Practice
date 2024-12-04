#include <stdio.h>

#define MAX_INPUT 1000 // 입력이 1000개 이하

// call-by-reference를 통해 배열의 원소를 교체하고, 교환 횟수를 증가시킨다.
void swap(int* a, int * b, int* count) {
    int temp = *a;

    // 교체
    *a = *b;
    *b = temp;

    (*count)++; // 교환 횟수 증가
}

int main () {
    int N; // 입력받을 원소의 갯수
    int n[MAX_INPUT]; // 입력받을 원소를 담을 배열

    int count = 0;

    scanf("%d", &N); // 원소의 갯수 입력

    for (int i = 0; i < N; i++) // 배열에 원소 입력
        scanf("%d", &n[i]);

    // 버블 정렬 시작
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (n[j] > n[j + 1]) 
                swap(&n[j], &n[j + 1], &count);
        }
    }

    // 교환 횟수 출력
    printf("%d\n", count);
}