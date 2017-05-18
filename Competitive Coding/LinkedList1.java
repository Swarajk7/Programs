public class LinkedList1 {
	class Node {
		int info;
		Node next;
		Node(int data) {
			info=data;
			next=null;
		}
	}
	Node head;
	LinkedList1()
	{
		head=null;
	}
	void insert(int info)
	{
		if(head==null) {
			head=new Node(info);
		} else {
			Node x=new Node(info);
			x.next=head;
			head=x;
		}
	}
	void print() {
		Node x=head;
		while(x!=null)
		{
			System.out.println(x.info);
			x=x.next;
		}
	}
	public static void main(String ar[]) {
		LinkedList1 l=new LinkedList1();
		l.insert(10);l.insert(20);l.insert(30);
		l.print();
	}
}