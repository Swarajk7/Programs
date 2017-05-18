import java.util.*;
public class SubSetAnd {
	public static void main(String args[]) 
	{
		try {
			Scanner s = new Scanner(System.in);
			int t=s.nextInt();
			while(t>0) { 
				t--;
				int z=s.nextInt();
				int n=s.nextInt();
				int ar[]=new int[n];
				int mx=-1;
				for(int i=0;i<n;i++) {
					ar[i]=s.nextInt();
					if(mx<ar[i]) mx=ar[i];
				}
				int k=z,bit_no=0;
				boolean ans=true;
				while(k!=0) {
					int v=k&1;
					k=k>>1;
					if((v&1)==1) {
						int v1=1<<bit_no;
						//System.out.println(v1);
						boolean flag=false;
						for(int i=0;i<n;i++) {
							if(!((v1&ar[i])==1)) flag=true;
						}
						if(!flag) {
							ans=false;
							break;
						}
					}
					bit_no++;
				}
				if(ans) System.out.println("Yes");
				else System.out.println("No");
			}
		} catch (Exception e){
		}
	}
}