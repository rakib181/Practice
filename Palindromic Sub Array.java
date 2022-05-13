import java.io.*;
import java.util.StringTokenizer;
public class PalSubArray {
    static boolean isPalindrome(int n){
        int num=0,x=n;
        while (n>0){
            num=num*10+(n%10);
            n/=10;
        }
        if(num==x){
            return true;
        }
        return false;
    }
    static boolean letsTry(int[] arr, int n, int k,Pair p){
        int sum=0;
        for (int i=0;i<k;i++){
            sum=sum*10+arr[i];
        }
        if(isPalindrome(sum)){
            p.l=0;p.r=k-1;
            return true;
        }
        for(int i=k;i<n;i++){
            sum=(sum%(int)Math.pow(10,k-1))*10+arr[i];
            if(isPalindrome(sum)){
                p.l=i-k+1;p.r=i;
                return true;
            }
        }
        return false;
    }
    public static void main(String[] args) {
        MyScanner sc=new MyScanner();
        Pair p=new Pair();
        out=new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt(),k=sc.nextInt();
        int[] arr=new int[n];
        for (int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        out.println(letsTry(arr,n,k,p));
        for(int i=p.l;i<=p.r;i++){
            out.print(arr[i]+" ");
        }
        out.flush();
        out.close();
    }
    public static PrintWriter out;
    public static class MyScanner{
        BufferedReader br;
        StringTokenizer st;
        MyScanner(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while (st==null || !st.hasMoreElements()){
                try {
                    st=new StringTokenizer(br.readLine());
                }catch (IOException e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
    }
    public static class Pair{
        int l,r;
    }
}
