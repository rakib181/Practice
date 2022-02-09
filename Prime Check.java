import java.util.*;

public class PrimeTest {
	static boolean isPrime(int n) {
		if(n<=3) {
			return n>1;
		}
		if(n%2==0 || n%3==0) {
			return false;
		}
		int c=5;
		while(Math.pow(c, 2)<=n) {
			if(n%c==0 || n%(c+2)==0) {
				return false;	
			}
			c+=6;	
		}
		return true;
	}
	public static void main(String[] args) {
	
Scanner sc=new Scanner(System.in);
int n=sc.nextInt();
if(isPrime(n)) {
	System.out.println("YES");
}else {
	System.out.println("NO");
}
	}
}
