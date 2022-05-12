import java.io.*;
import java.util.StringTokenizer;
public class LOG {
    static int LOG2(int n){
        return 31-Integer.numberOfLeadingZeros(n);
    }
    static int SWM(int[] arr,int k,int n){
        int ans=0,tmp=0;
        for(int i=0;i<k;i++){
            ans+=arr[i];
            tmp+=arr[i];
        }
        for(int i=k;i<n;i++){
            tmp+=arr[i];
            tmp-=arr[i-k];
            ans=Math.max(ans,tmp);
        }
        return ans;
    }
    public static void main(String[] args) {
        MyScanner sc=new MyScanner();
        out=new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt(),k=sc.nextInt();
      // out.println(LOG2(n));
       int[] arr=new int[n];
       for(int i=0;i<n;i++){
           arr[i]=sc.nextInt();
       }
       out.println(SWM(arr,k,n));
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
}
