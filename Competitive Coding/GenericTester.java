import java.util.NoSuchElementException;
public class GenericTester<E>
{
	E data;
	GenericTester(E e)
	{
		data=e;
	}
	GenericTester<E> getObject()
	{
		GenericTester<E> gtobj=new GenericTester<E>(data);
		return gtobj;
	}
	public static void main(String ar[])
	{
		GenericTester<Integer> g=new GenericTester<Integer>(10);
		GenericTester<Integer> g1=g.getObject();
		System.out.println(g1.data);
	}
}