import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 직사각형1 입력
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();

        // 직사각형2 입력
        //// 직사각형2의 점1
        int e = sc.nextInt();
        int f = sc.nextInt();

        //// 직사각형2의 점2
        int g = sc.nextInt();
        int h = sc.nextInt();

        // 직사각형2의 모든 점
        Point[] point = new Point[4];
        point[0] = new Point(e, h);
        point[1] = new Point(e, f);
        point[2] = new Point(g, f);
        point[3] = new Point(g, h);

        int answer = 0;
        
        // 직사각형1의 각 점이 직사각형1의 범위 안에 들어있는지 확인
        for (int i = 0; i < 4; i++) {
            // x의 범위 확인
            if (point[i].x <= a || c <= point[i].x) continue;

            // y의 범위 확인
            if (point[i].y <= b || d <= point[i].y) continue;

            // 직사각형1 안에 점이 있는 경우
            answer = 1;
            break;
        }

        System.out.print(answer);
    }
}

class Point {
    int x;
    int y;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}