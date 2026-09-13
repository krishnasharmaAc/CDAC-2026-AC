
public abstract class Employee {
	protected String name;
	protected String address;
	protected int age;
	protected boolean gender;
	protected double basicSalary;
	
	public Employee(String name, String address, int age, boolean gender, double basicSalary) {
		super();
		this.name = name;
		this.address = address;
		this.age = age;
		this.gender = gender;
		this.basicSalary = basicSalary;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getAddress() {
		return address;
	}
	public void setAddress(String address) {
		this.address = address;
	}
	public int getAge() {
		return age;
	}
	
	public void setAge(int age) {
		if(age<18 || age>60)
			this.age = 21;
		else
			this.age = age;		
	}
	
	public boolean isGender() {
		return gender;
	}
	public void setGender(boolean gender) {
		this.gender = gender;
	}
	public double getBasicSalary() {
		return basicSalary;
	}
	public void setBasicSalary(double basicSalary) {
		if(basicSalary<1000 || basicSalary>100000) 
		this.basicSalary = 25000.00;
		else
			this.basicSalary = basicSalary;
	}
	
	
}
