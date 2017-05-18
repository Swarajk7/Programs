import java.io.*;
public class Repair {
public static void main(String ar[]) {
	try {
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(bf.readLine());
		while(t-->0) {
			String a=bf.readLine();
			String b=bf.readLine();
			boolean broken[] = new boolean[26];
			boolean req []= new boolean[26];
			for(int i=0;i<26;i++) broken[i]=false;
			for(int i=0;i<26;i++) req[i]=false;
			for(int i=0;i<a.length();i++) {
				int k=a.charAt(i)-97;
				broken[k]=true;
			}
			for(int i=0;i<b.length();i++) {
				int k=b.charAt(i)-97;
				req[k]=true;
			}
			int ans=0;
			for(int i=0;i<26;i++) {
				if(req[i]==true && broken[i]==true) ans++;
			}
			System.out.println(ans);
		}
	} catch(IOException e) {
	}
}
}