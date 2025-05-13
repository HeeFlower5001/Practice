import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        boolean[][] list = new boolean[n + 1][n + 1];

        int x_first = Integer.MAX_VALUE;
        int x_last = Integer.MIN_VALUE;

        int y_first = Integer.MAX_VALUE;
        int y_last = Integer.MIN_VALUE;

        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();

            list[n - y][x] = true;
            if (x < x_first) x_first = x;
            if (x > x_last) x_last = x;
            if (y < y_first) y_first = y;
            if (y > y_last) y_last = y;
        }

        int answer = 0;

        for (int i = 0; i < n + 1; i++) {
            if (list[i][x_first]) answer++;
            if (list[i][x_last]) answer++;
            if (list[n - y_first][i]) answer++;
            if (list[n - y_last][i]) answer++;
        }

        if (list[n - y_first][x_first]) answer--;
        if (list[n - y_first][x_last]) answer--;
        if (list[n - y_last][x_first]) answer--;
        if (list[n - y_last][x_last]) answer--;

        System.out.printf("%d %d", answer, m - answer);
    }
}