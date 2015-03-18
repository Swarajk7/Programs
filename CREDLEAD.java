import java.io.*;
import java.util.*;
public class CREDLEAD
{
public static void main(String ar[]) {
	try {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		Vector<String> v=new Vector<String>();
		HashMap<String,Integer> map=new HashMap<String,Integer>();
		//System.out.println("size="+v.capacity());
		for(int i=0;i<n;i++) {
			String inp=br.readLine();
			if(map.containsKey(inp)) {
				int q=map.get(inp);
				//System.out.println("size="+v.size());
				if(v.size()<=q) {
					v.add(inp);
				}
				map.put(inp,q+1);
			}
			else {
				map.put(inp,1);
				if(v.size()==0) v.add(inp);
			}
		}
		//for(String s:v) System.out.println(s);
		for(int i=0;i<v.size();i++) {
			if(v.get(i)==null) break;
			System.out.println(i+1+" "+v.get(i));
		}
	} catch(IOException ioe) {
	}
}
}