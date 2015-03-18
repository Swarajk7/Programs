import java.io.*;
import java.util.Scanner;
public class RAINBOW2 {
	static long M=1000000007;
	public static void main(String args[]) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		long ans=0;
		if(n==13) ans=1;
		if(n>13) {
			long ar[]=new long[n+1];
			ar[13]=1;
			ar[14]=1;
			for(int i=15;i<=n;i++) ar[i]=(ar[i-2]*7)%M;
			ans=ar[n];
		}
		System.out.println(ans);
	}
}