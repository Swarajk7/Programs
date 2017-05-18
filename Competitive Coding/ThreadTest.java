class X implements Runnable {
	public void run() {
		System.out.println("Hello X");
	}
}
class G<T> {
	T a;
	G(T b) {
		a=b;
	}
	String get(G<?> b) {
		return b.toString();
	}
}
public class ThreadTest {
	public static void main(String ar[]) {
		X o=new X();
		Thread t1=new Thread(o,"First");
		Thread t2=new Thread(o,"2nd");
		t2.start();
	}
}