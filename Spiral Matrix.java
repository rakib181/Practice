import java.util.*;

public class SpiralMatrix {
    static void solve(int n,int m,int[][] arr){
        int top=0,down=n-1,left=0,right=m-1,dir=0;
        while(top<=down && left<=right){
         if(dir==0){
             for (int i=left;i<=right;i++){
                 System.out.print(arr[top][i]+" ");
             }
             top++;
             dir=1;
         }
         else if(dir==1){
             for (int i=top;i<=down;i++){
                 System.out.print(arr[i][right]+" ");
             }
             right--;
             dir=2;
         }else if (dir==2){
             for (int i=right;i>=left;i--){
                 System.out.print(arr[down][i]+" ");
             }
             down--;
             dir=3;
         }else {
             for (int i=down;i>=top;i--){
                 System.out.print(arr[i][left]+" ");
             }
             left++;
             dir=0;
          }
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),m=sc.nextInt();
        int[][] arr=new int[n][m];
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                arr[i][j]=sc.nextInt();
            }
        }
        solve(n,m,arr);
    }
}




//Practice


import java.util.*;

public class SpiralPrac {
	static void solve(int n,int m,int[][] arr) {
		int top=0,down=n-1,left=0,right=m-1,dir=0;
		while(top<=down && left<=right) {
			if(dir==0) {
				for(int i=left;i<=right;i++) {
					System.out.print(arr[top][i]+" ");
				}
				dir=1;
				top++;
			}else if(dir==1) {
				for(int i=top;i<=down;i++) {
					System.out.print(arr[i][right]+" ");
				}
				dir=2;
				right--;
			}else if(dir==2) {
				for(int i=right;i>=0;i--) {
					System.out.print(arr[down][i]+" ");
				}
				dir=3;
				down--;
			}else {
				for(int i=down;i>=top;i--) {
					System.out.print(arr[i][left]+" ");
				}
				dir=0;
				left++;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
        int[][] arr=new int[n][m];
        for(int i=0;i<n;i++) {
        	for(int j=0;j<m;j++) {
        		arr[i][j]=sc.nextInt();
        	}
        }
        solve(n,m,arr);
	}
}

