import java.util.Scanner;

public class OrdinaryNumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int j = 0; j < t; j++) {
            long n = sc.nextInt();
            if (n > 0 && n < 10) {
                System.out.println(n);
            } else {
                int c=9;
                for (int i = 10; i <= n; i++) {
                    if (i % 11 == 0 && i<=99) {
                        c++;
                    }else if (i%111==0 && i<=999){
                        c++;
                    }else if (i%1111==0 && i<=9999){
                        c++;
                    }else if (i%11111==0 && i<=99999){
                        c++;
                    }else if (i%111111==0 && i<=999999){
                        c++;
                    }else if (i%1111111==0 && i<=9999999){
                        c++;
                    }else if (i%11111111==0 && i<=99999999){
                        c++;
                    }else if (i%111111111==0 && i<=999999999){
                        c++;
                    }
                }
                System.out.println(c);

            }
        }
    }
}
