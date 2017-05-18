import java.util.Scanner;
import java.util.Vector;
import java.math.BigInteger;
class data {
	long a,b,c;
	data(long a,long b,long c) {
		this.a=a;
		this.b=b;
		this.c=c;
	}
}
class BigI {
	BigInteger b1,b2;
	long sol;
	static BigInteger SIX=new BigInteger("6");
	static BigInteger FIFTEEN=new BigInteger("15");
	static BigInteger TEN = new BigInteger("10");
	static BigInteger MINUSONE=new BigInteger("-1");
	static BigInteger THIRTY=new BigInteger("30");
	BigI(long l1,long l2,long m) {
		b2=new BigInteger(Long.toString(l2));
		if(l1==l2) {
			b1=b2.pow(4);
			System.out.println(b1);
			b1=b1.remainder(new BigInteger(Long.toString(m)));
			sol=b1.longValue();
			//sSystem.out.println(sol);
		}
		b1=get(l1);
		b2=get(l2-1);
		b1=b1.subtract(b2);
		b1=b1.remainder(new BigInteger(Long.toString(m)));
		sol=b1.longValue();
	}
	static BigInteger get(long l) {
		BigInteger b=new BigInteger(Long.toString(l));
		BigInteger bb=SIX.multiply(b.pow(5));
		BigInteger bb2=FIFTEEN.multiply(b.pow(4));
		bb=bb.add(bb2);
		bb2=TEN.multiply(b.pow(3));
		bb=bb.add(bb2);
		bb=bb.subtract(b);
		bb=bb.divide(THIRTY);
		return bb;
	}
	long getAns() {
		return sol;
	}
}
public class Floor {
static BigInteger SIX=new BigInteger("6");
	static BigInteger FIFTEEN=new BigInteger("15");
	static BigInteger TEN = new BigInteger("10");
	static BigInteger MINUSONE=new BigInteger("-1");
	static BigInteger THIRTY=new BigInteger("30");
	static long get1(long l,long m) {
		BigInteger b=new BigInteger(Long.toString(l));
		BigInteger ans=BigInteger.ZERO;
		ans=ans.subtract(b);
		b=b.multiply(b);
		b=b.multiply(new BigInteger(Long.toString(l)));
		BigInteger bb=TEN.multiply(b);
		ans=ans.add(bb);
		b=b.multiply(new BigInteger(Long.toString(l)));
		bb=FIFTEEN.multiply(b);
		ans=ans.add(bb);
		b=b.multiply(new BigInteger(Long.toString(l)));
		bb=SIX.multiply(b);
		ans=ans.add(bb);
		ans=ans.divide(THIRTY);
		ans=ans.remainder(new BigInteger(Long.toString(m)));
		return ans.longValue();
	}
	static long get(long l,long m) {
		m=30*m;
		long ans=0;
		long x=l%m;
		ans-=l;
		ans=ans%m;
		ans=m+ans;
		x=(x*l)%m;
		x=(x*l)%m;
		ans=(10*x+ans)%m;
		x=(x*l)%m;
		ans=(15*x+ans)%m;
		x=(x*l)%m;
		ans=(6*x+ans)%m;
		return ans/30;
	}
	public static void main(String ar[]) {
		Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		while(t-->0) {
			long n=s.nextLong();
			long m=s.nextLong();
			/*long rootn=(long)Math.ceil(Math.sqrt(n));
			Vector<data> v=new Vector<data>();
			for(long i=1;i<=rootn;i++) {
				data d=new data(i,i,n/i);
				v.add(d);
			}
			int x=v.size();
			//System.out.println(x);
			for(int i=x-1;i>0;i--) {
				data d=v.get(i);
				long v1=d.c+1;
				d=v.get(i-1);
				long v2=d.c;
				v.add(new data(v1,v2,d.b));
			}
			long ans=0;
			//System.out.println("abc");
			for(int i=0;i<v.size();i++) {
				data d=v.get(i);
				BigI bbb=new BigI(d.b,d.a,m);
				System.out.println(d.b+" "+d.a+" "+d.c+" "+bbb.getAns());
				long ans1=(d.c*(bbb.getAns()));
				ans=(ans+ans1);
				//
			}
			System.out.println(ans%m);*/
			long rootn=(long)Math.floor(Math.sqrt(n));
			long ans=0;
			for(int i=1;i<=rootn;i++) {
				long x=n/i;
				long ans1=(get(x,m))%m;
				ans = (ans+ans1)%m;
				//System.out.println(x+" "+i+" "+ans1+" "+ans);
			}
			long i=1;
			long a=1;
			while(true) {
				a=(n/i-rootn);
				if(a<=0) break;
				long j=((i%m)*(i%m))%m;
				long ans1=(j*j)%m;
				ans=(ans+a*ans1)%m;
				//System.out.println(ans);
				i++;
			}
			System.out.println(ans);
		}
	}
}