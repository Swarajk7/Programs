class Person {
	String name;
	int age;
	String address;
	void setName(String name) {this.name=name; }
	void setAddress(String address) { this.address = address; }
	void setAge(int age) { this.age=age; }
	String getName() { return name; }
}
class Teacher extends Person {
	//String name;
	//int age;
	//String Address;
	
	int salary;
	
	void setSalary(int sal) {salary=sal;}
}
class Student extends Person {
	//String name;
	//int age;
	//String address;
	
	int standard;
	int rollno;
	
	void setStandard(int std) { standard=std;}
	void setRoll(int rollno) {this.rollno=rollno;}
}
public class School {
	Teacher t[];
	Student stu[];
	void createTeachers(int n) {
		t=new Teacher[n];
		for(int i=0;i<n;i++) {
			t[i]=new Teacher();
			t[i].setName("NAME"+i);
			t[i].setAge(30+i);
			t[i].setAddress("ADD"+i);
			t[i].setSalary(5000);
		}
	}
	void createStudents(int n) {
		stu=new Student[n];
		for(int i=0;i<n;i++) {
			stu[i]=new Student();
			stu[i].setName("NAME"+i);
			stu[i].setAge(30+i);
			stu[i].setAddress("ADD"+i);
			stu[i].setRoll(i+1);
			stu[i].setStandard(10 - (i&1));
		}
	}
	public static void main(String args[]) {
		School s=new School();
		s.createStudents(10);
		s.createTeachers(2);
		try {
		System.out.println(s.t[0].getName());
		} catch(Exception e) {
			System.out.println("Exception Caught");
		}
		System.out.println("END\n");
	}
}