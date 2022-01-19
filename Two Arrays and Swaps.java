import java.util.Arrays;
import java.util.Scanner;

public class TwoArraysAddSwaps {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int j = 0; j < t; j++) {
            int n = sc.nextInt(), k = sc.nextInt(), c = 0, m = 0;
            int[] a = new int[n];
            int[] b = new int[n];
            for (int p = 0; p < n; p++) {
                a[p] = sc.nextInt();
            }
            for (int e = 0; e < n; e++) {
                b[e] = sc.nextInt();
            }
            Arrays.sort(a);
            Arrays.sort(b);
            int p = 0;
            while (p < k) {
                int temp = a[p];
                a[p] = b[n - p - 1];
                b[n - p - 1] = temp;
                p++;
            }
  /* for (int r=0;r<n;r++){
        System.out.print(a[r]+" ");
    }
    for (int u=0;u<n;u++){
        System.out.print(b[u]+" ");
    }*/
            for (int x = 0; x < n; x++) {
                c+=a[x];
            }
            for (int y=0;y<n;y++){
                m+=b[y];
            }
            if (c>m){
                System.out.println(c);
            }else
                System.out.println(m);
        }
    }
}
