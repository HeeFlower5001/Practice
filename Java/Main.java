import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
<<<<<<< HEAD

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Buuble Sort
        for (int i = 0; i < n - 1; i++) {
            boolean swapped = false;

            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    // swap
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }

            if (!swapped) break;
        }

        // 결과 출력
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}




=======
        int k = sc.nextInt();

        boolean[] home = new boolean[n];
        for (int i = 0; i < n; i++) home[sc.nextInt()] = true;

        

        System.out.print(answer);
    }
}
>>>>>>> c90db09115e9127ca7aaafb0847b0b94ca8aa60a
