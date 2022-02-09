import java.util.*;
public class UpsAndDowns {
	public  static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++) {
			int n=sc.nextInt(),d=0,c=0;
			List<Integer>list=new ArrayList<>();
			for(int j=0;j<n;j++) {
				list.add(sc.nextInt());
			}
			Collections.sort(list);
			List<Integer>list1=new ArrayList<>();
			for(int k=0;k<n;k++) {
				if(k%2==0) {
				list1.add(list.get(c));
				c++;
				}else {
					d++;
					list1.add(list.get(n-d));
				}
			}
			for(Integer x:list1) {
			System.out.print(x+" ");
			}
		}
	
	}
}
