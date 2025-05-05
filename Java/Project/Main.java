import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] coin = new int[n][m];
        int[][] dp = new int[n][m];

        // coin 입력 받기
        for (int i1 = 0; i1 < n; i1++) {
            for (int i2 = 0; i2 < m; i2++) {
                coin[i1][i2] = sc.nextInt();
            }
        }

        // 0행 채우기
        dp[0][0] = coin[0][0];

        for (int i1 = 1; i1 < n; i1++) {
            dp[i1][0] = dp[i1 - 1][0] + coin[i1][0];
        }

        // 0열 채우기
        for (int i2 = 1; i2 < m; i2++) {
            dp[0][i2] = dp[0][i2 - 1] + coin[0][i2];
        }

        // 1행 ~ (n - 1)행 채우기
        for (int i1 = 1; i1 < n; i1++) {
            for (int i2 = 1; i2 < m; i2++) {
                // 3가지 비교
                int value1 = Math.min(dp[i1 - 1][i2], dp[i1][i2 - 1]);
                int value2 = Math.min (value1, dp[i1 - 1][i2 - 1]);

                dp[i1][i2] = value2 + coin[i1][i2];
            }
        }

        System.out.print(dp[n - 1][m - 1]);
    }
}