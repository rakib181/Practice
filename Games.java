import java.util.*;

public class Games {
	 static void GCD(int a, int b) {
		  int gcd = 1;

		    for (int i = 1; i <= a && i <= b; ++i) {
		      if (a % i == 0 && b % i == 0)
		        gcd = i;
		    }
		System.out.println(b/gcd);
	}

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int p=0;p<t;p++){
		String s=sc.next();
		int k=0;
		String s1="1";
		char[] ch=s.toCharArray();
		for(int i=0;i<s.length();i++) {
		if(ch[i]=='.') {
			 k=i+1;
			 for(int j=0;j<s.length()-k;j++) {
					s1+="0";
				}
			 break;
		}
		}
		String str=s.replace(".","");
		
		int y=Integer.parseInt(str);
		int x=Integer.parseInt(s1);
		//System.out.println(y+" "+x);
		GCD(y,x);
		}
	}
}
