import java.io.*;
import java.util.*;
public class TwoDimGridTrav {
    static int MX=105,ans=0;
    static boolean[][] vis=new boolean[MX+1][MX+1];
    static int[] dx=new int[]{-1,-1,1,1};
    static int[] dy=new int[]{-1,1,-1,1};
    static void dfs(int x,int y,int n,int[][] arr){
        if(x<0 || x>=n)return;
        if(y<0 || y>=n)return;
        if(vis[x][y]){
           return;
        }
        vis[x][y]=true;
        ans+=arr[x][y];
        for (int i=0;i<4;i++){
            int xi=x+dx[i],yi=y+dy[i];
            dfs(xi,yi,n,arr);
        }
    }
    public static void main(String[] args) {
        MyScanner sc=new MyScanner();
        out=new PrintWriter(new BufferedOutputStream(System.out));
         int n=sc.nextInt();
        int[][] arr=new int[n][n];
        for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                arr[i][j]= sc.nextInt();
            }
        }
        dfs(1,2,n,arr);
        out.println(ans-arr[1][2]);
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
            while (st==null ||!st.hasMoreElements()){
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
