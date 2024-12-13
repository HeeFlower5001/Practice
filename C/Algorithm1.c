#include <stdio.h>
#define MAX_N 100
#define INF 10000

int main() {
    int N;
    int A[2][MAX_N]; // 방 탈출 시간
    int T[2][MAX_N - 1]; // 이동 시간
    int dp[2][MAX_N]; // 최단 시간 저장

    // 입력 받기
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[0][i]); // (1, i) 방의 탈출 시간
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[1][i]); // (2, i) 방의 탈출 시간
    }
    for (int i = 0; i < N - 1; i++) {
        scanf("%d", &T[0][i]); // (1, i) -> (2, i+1) 이동 시간
    }
    for (int i = 0; i < N - 1; i++) {
        scanf("%d", &T[1][i]); // (2, i) -> (1, i+1) 이동 시간
    }

    // 초기값 설정
    dp[0][0] = A[0][0]; // (1, 1) 방에서 시작
    dp[1][0] = A[1][0]; // (2, 1) 방에서 시작

    // DP 계산
    for (int j = 1; j < N; j++) {
        dp[0][j] = A[0][j] + (dp[0][j - 1] < dp[1][j - 1] + T[1][j - 1] ? dp[0][j - 1] : dp[1][j - 1] + T[1][j - 1]);
        dp[1][j] = A[1][j] + (dp[1][j - 1] < dp[0][j - 1] + T[0][j - 1] ? dp[1][j - 1] : dp[0][j - 1] + T[0][j - 1]);
    }

    // 결과 출력
    int result = dp[0][N - 1] < dp[1][N - 1] ? dp[0][N - 1] : dp[1][N - 1];
    printf("%d\n", result);

    return 0;
}
