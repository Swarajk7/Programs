import java.io.*;
public class ReadFile {
	public static void main(String ar[]) {
		if(ar.length!=2) {
			System.out.println("Error");
			return;
		}
		try {
			FileReader fr=new FileReader(ar[0]);
			BufferedReader br=new BufferedReader(fr);
			FileWriter fw=new FileWriter(ar[1]);
			BufferedWriter bw=new BufferedWriter(fw);
			PrintWriter p =new PrintWriter(bw);
			String s;
			while((s=br.readLine())!=null) {
				System.out.println(s);
				p.println(s);
			}
		} catch(IOException ioe) {
		}
	}
}