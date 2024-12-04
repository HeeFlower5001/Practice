#include <stdio.h>

#define MAX_NODES 100 // Node의 최대 개수
#define INFINITE 1001 // 연결되지 않은 경로를 나타내는 가중치의 최대값 (1 ~ 1000 사이)

int main() {
    int N; // Node의 개수
    int M; // Edge의 개수
    int dist[MAX_NODES + 1][MAX_NODES + 1]; // 최단 거리를 저장할 배열

    // Node와 Edge의 개수 입력
    scanf("%d %d", &N, &M);

    // 거리 배열 초기화
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                dist[i][j] = 0; // 자기 자신으로 가는 거리는 0
            } 
            
            else {
                dist[i][j] = INFINITE; // 초기에는 연결되지 않은 경로로 설정
            }
        }
    }

    // 그래프 정보 입력
    for (int i = 0; i < M; i++) {
        int u, v, w; // u: 시작 노드, v: 끝 노드, w: 가중치
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = w; // 유향 그래프에서 Edge 설정
    }

    // Floyd-Warshall 알고리즘
    for (int k = 1; k <= N; k++) {       // 중간 Node
        for (int i = 1; i <= N; i++) {   // 시작 Node
            for (int j = 1; j <= N; j++) { // 끝 Node
                // 경유하는 경로가 연결되어 있는 경우에만 최단 거리 계산
                if (dist[i][k] < INFINITE && dist[k][j] < INFINITE) {
                    // 기존 거리와 경유한 거리를 비교하여 더 짧은 경로를 선택
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // 가장 먼 두 점 찾기
    int max_dist = -1;  // 최단 경로 중 가장 큰 거리
    int A = -1, B = -1; // 결과로 출력할 노드 쌍

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // 자기 자신이 아니고, 도달 가능한 경로만 고려
            if (i != j && dist[i][j] < INFINITE) {
                // 더 큰 거리를 찾으면 업데이트
                if (dist[i][j] > max_dist) {
                    max_dist = dist[i][j];
                    A = i;
                    B = j;
                } 
                // 거리가 같은 경우, A와 B의 번호를 사전순으로 정렬
                else if (dist[i][j] == max_dist) {
                    if (i < A || (i == A && j < B)) {
                        A = i;
                        B = j;
                    }
                }
            }
        }
    }

    // 결과 출력
    printf("%d %d\n", A, B);
    return 0;
}
