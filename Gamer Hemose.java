import java.util.Arrays;
import java.util.Scanner;

public class GamerHemose {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt(), h = sc.nextInt(), max = 0;
            int[] a = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = sc.nextInt();
            }
            Arrays.sort(a);
            max = a[n - 1] + a[n - 2];
            int v = h / max;
            if (h % max == 0) {
                System.out.println(v * 2);
            } else if (h % max <= a[n - 1]) {
                System.out.println((v * 2) + 1);
            } else
                System.out.println((v * 2) + 2);
        }
    }
}

