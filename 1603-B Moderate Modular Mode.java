import java.util.Scanner;

public class ModerateModularMode {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long t=sc.nextInt(),n,a,b;
        for (long i=0;i<t;i++){
            long x=sc.nextInt();
            long y=sc.nextInt();
            for (n=1;n<1000000000;n++){
                a=n%x;
                b=y%n;
                if (a==b && a%2==0){
                    System.out.println(n);
                    break;
                }
            }
        }
    }
}
