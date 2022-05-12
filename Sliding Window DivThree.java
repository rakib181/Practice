import java.io.*;
import java.util.StringTokenizer;
public class DivThree {
    static void letsTry(int[] arr, int n, int k, Pair pair){
        int ans=0,tmp=0;boolean ok=false;
        for(int i=0;i<k;i++){
            ans+=arr[i];
            tmp+=arr[i];
        }
        if(ans%3==0){
            pair.l=0;pair.r=k-1;
            ok=true;
        }
        for(int i=k;i<n;i++){
            if(ok){
                break;
            }
            tmp+=arr[i];
            tmp-=arr[i-k];
            if(tmp%3==0){
                ans=Math.max(ans,tmp);
                pair.l=i-k+1;pair.r=i;
                ok=true;
            }
        }
        if(!ok){
            out.println("Invalid !");
        }else {
            out.println(ans);
            for (int i = pair.l; i <= pair.r; i++) {
                out.print(arr[i] + " ");
            }
            out.println();
        }
    }
    public static void main(String[] args) {
        MyScanner sc=new MyScanner();
        out=new PrintWriter(new BufferedOutputStream(System.out));
        Pair pair=new Pair(0,0);
        int n=sc.nextInt(),k=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        letsTry(arr,n,k,pair);
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
            while (st==null || ! st.hasMoreElements()){
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
        Pair(int x,int y){
            this.l=x;
            this.r=y;
        }
    }
}
