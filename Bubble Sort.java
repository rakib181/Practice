package mypackage;

import java.util.Scanner;


public class BubbleSort {
static void solve(int[] arr,int n){
for(int i=0;i<n-1;i++){
  for(int j=0;j<n-i-1;j++){
    if(arr[j]>arr[j+1]){
      //int tmp=arr[j];
     // arr[j]=arr[j+1];
      //arr[j+1]=tmp;
      arr[j]^=arr[j+1];
      arr[j+1]^=arr[j];
      arr[j]^=arr[j+1];
    }
  }
}
  for(int i=0;i<n;i++){
    System.out.print(arr[i]+" ");
  }
}

  public static void main(String[] args) {
  Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int[] arr=new int[n];
  for(int i=0;i<n;i++){
    arr[i]=sc.nextInt();
  }
  //Bubble Sort
  solve(arr,n);

  }

}
