import java.io.*;
import java.util.*;
public class BiggerIsGreater {
	public static void main(String ar[]) {
		Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		while(t-->0) {
			String s1=s.next();
			System.out.println(process(s1));
		}
	}
	static String process(String b) {
		StringBuilder sb=new StringBuilder(b);
		if(b.length()==1) return "no answer";
		int index=-1;
		for(int i=b.length()-2;i>=0;i--) {
			if(b.charAt(i)<b.charAt(i+1)) {
				index=i;
				break;
			}
		}
		if(index==-1) return "no answer";
		char ar[]=b.toCharArray();
		char ccc=(char) 150;
		int index2=-1;
		for(int i=index+1;i<b.length();i++) {
			if(ar[i]>ar[index]) {
				if(ar[i]<ccc) {
					ccc=ar[i];
					index2=i;
				}
			}
		}
		char z=ar[index];
		ar[index]=ar[index2];
		ar[index2]=z;
		Arrays.sort(ar,index+1,b.length());
		return new String(ar);
	}
}