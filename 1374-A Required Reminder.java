import java.util.Scanner;

public class RequiredReminder {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
       int t=sc.nextInt();
       for (int i=0;i<t;i++){
           int a=sc.nextInt();
           int b=sc.nextInt();
           int c=sc.nextInt();
           int x=Math.max(a,b);
           int max=Math.max(x,c);
           if(max%a==0 && max%a==b){
               System.out.println("0");
               continue;
           }
           if(max%a==b){
               System.out.println(max);
           }
           while(max%a!=b){
               max--;
               if (max%a==b){
                   System.out.println(max);
               }
           }
       }
    }
}
