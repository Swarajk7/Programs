public class Gener<T> 
{
	T a;
	Gener(T b) {
		a=b;
	}
	void print(Gener<?> a1) {
		System.out.println(a==a1.a);
	}
	public static void main(String ar[]) {
		Gener<Integer> obj1=new Gener<Integer> (100);
		Gener<String> obj2=new Gener<String> ("100");
		obj1.print(obj2);
	}
}