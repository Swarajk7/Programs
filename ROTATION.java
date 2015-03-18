import java.io.*;
import java.util.Scanner;
public class ROTATION {
	public static void main(String args[]) {
		int n,m;
		try {
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			Scanner s=new Scanner(System.in);
			n=s.nextInt();m=s.nextInt();
			int ar[]=new int[n];
			for(int i=0;i<n;i++) {
				ar[i]=s.nextInt();
			}
			String s1;
			int d,ind=0;
			while(m>0) {
				m--;
				s1=s.next();
				d=s.nextInt();
				if(s1.equals("R")) {
					int kk=(ind+d-1)%n;
					System.out.println(ar[kk]);
				}
				else if(s1.equals("C")) {
					d=(d+ind)%n;
					ind=d;
				}
				else {
					d=ind-d;
					if(d<0) d=d+n;
					ind=d;
				}
			}
		}
		catch(Exception ioe) {
		}
	}
}