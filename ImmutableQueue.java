import java.util.NoSuchElementException;
public class ImmutableQueue<E> {
	private final int length; //length of the queue
	private class Node {
	/* This will represent a node in a linkedlist.
		Queue is implemented with a linkedlist*/
		E data; 
		Node next; 
		Node(E e) {
			data=e;
			next=null;
		}
	}
	final private Node front,rear;
	public ImmutableQueue() { //this can be invoked to create an empty queue,so public
		 front=null;
		 rear=null;
		 length=0;
	}
	private ImmutableQueue(Node f) { //this is only used by enqueue and dequeue so private
		if(f==null) throw new IllegalArgumentException();
		front = f;
		int temp_length=1;
		while(f.next!=null) {
			f=f.next;
			temp_length++;
		}
		rear=f;
		length=temp_length;
	}
	public ImmutableQueue<E> enqueue(E e) {
		if(e==null) throw new IllegalArgumentException();
		Node ptr=front;
		Node new_front=null,ptr_new_node=null;
		if(ptr==null) {
			new_front=new Node(e);
			return new ImmutableQueue<E>(new_front);
		}
		while(ptr!=null) {
			if(new_front==null) {
				new_front=new Node(ptr.data);
				ptr_new_node=new_front;
				ptr=ptr.next;
			}
			else {
				ptr_new_node.next=new Node(ptr.data);
				ptr_new_node=ptr_new_node.next;
				ptr=ptr.next;
			}
		}
		ptr_new_node.next=new Node(e);
		return new ImmutableQueue<E>(new_front);
	}
	public ImmutableQueue<E> dequeue() {
		if(length==0) throw new NoSuchElementException(); //when rear==front and front==null i.e. length=0
		if(front==rear) return new ImmutableQueue<E> (); // if rear!=null and front==rear i.e. 1 element only
		Node ptr=front.next;
		Node new_front=null,ptr_new_node=null;
		while(ptr!=null) {
			if(new_front==null) {
				new_front=new Node(ptr.data);
				ptr_new_node=new_front;
				ptr=ptr.next;
			}
			else {
				ptr_new_node.next=new Node(ptr.data);
				ptr_new_node=ptr_new_node.next;
				ptr=ptr.next;
			}
		}
		return new ImmutableQueue<E> (new_front);
	}
	public E peek() {
		if(length==0) throw new NoSuchElementException();
		else return front.data;
	}
	public int size() {
		return length;
	}
	private void print() {
		Node ptr=front;
		System.out.println(length);
		while(ptr!=null) {
			System.out.print(ptr.data+" ");
			ptr=ptr.next;
		}
		System.out.println();
	}
	/*public static void main(String ar[]) {
		ImmutableQueue<String> q1,q2,q3,q4,q5=null,q6=null,q7=null;
		q1=new ImmutableQueue<String> ();
		q2=q1.enqueue("hi");
		q3=q2.enqueue("swaraj");
		q4=q3.enqueue("khadanga");
		q1.print();q2.print();q3.print();q4.print();
		System.out.println(q2.peek());
		System.out.println(q4.peek());
		try{
		q5=q4.dequeue();
		q6=q5.dequeue();
		q7=q6.dequeue();
		} catch(Exception e) {
			System.out.println("Can't pop");
		}
		finally {
			q5.print();q6.print();q7.print();
		}
	}*/
}