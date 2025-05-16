import java.util.*;

public class Main {
    static class Point implements Comparable<Point> {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            if (this.x != o.x) return Integer.compare(this.x, o.x);
            return Integer.compare(this.y, o.y);
        }
    }

    static long cross(Point o, Point a, Point b) {
        return (long)(a.x - o.x) * (b.y - o.y) - (long)(a.y - o.y) * (b.x - o.x);
    }

    static List<Point> convexHull(Point[] points) {
        Arrays.sort(points);
        int n = points.length;
        List<Point> hull = new ArrayList<>();

        // Lower hull
        for (int i = 0; i < n; i++) {
            while (hull.size() >= 2 &&
                   cross(hull.get(hull.size() - 2), hull.get(hull.size() - 1), points[i]) <= 0) {
                hull.remove(hull.size() - 1);
            }
            hull.add(points[i]);
        }

        // Upper hull
        int lowerSize = hull.size();
        for (int i = n - 2; i >= 0; i--) {
            while (hull.size() > lowerSize &&
                   cross(hull.get(hull.size() - 2), hull.get(hull.size() - 1), points[i]) <= 0) {
                hull.remove(hull.size() - 1);
            }
            hull.add(points[i]);
        }

        if (hull.size() > 1) hull.remove(hull.size() - 1);

        return hull;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); 
        int m = sc.nextInt(); 

        Point[] prisoners = new Point[m];

        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            prisoners[i] = new Point(x, y);
        }

        List<Point> hull = convexHull(prisoners);

        int watch = hull.size();
        int noWatch = m - watch;

        System.out.printf("%d %d\n", watch, noWatch);
    }
}