import java.io.*;
public class CHEFLR {
	static long M=1000000007;
	public static void main(String ar[]) {
		try {
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int t=Integer.parseInt(br.readLine());
			while(t>0) {
				t--;
				String s=br.readLine();
				long ans=1;
				for(int i=0;i<s.length();i++) {
					if(s.charAt(i)=='l') {
						switch(i%2) {
							case 0:
								ans=(2*ans)%M;
								break;
							case 1:
								ans=(2*ans-1)%M;
								break;
						}
					}
					else {
						switch(i%2) {
							case 0:
								ans=(2*ans+2)%M;
								break;
							case 1:
								ans=(2*ans+1)%M;
								break;
						}
					}
				}
				System.out.println(ans);
			}
		} catch(IOException ioe) {
		}
	}
}