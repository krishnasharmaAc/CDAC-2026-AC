
public class PrimeMembers extends Member{
	private int joiningYear; 
	private double joiningFees;
	private boolean isActive;
	
	public int getJoiningYear() {
		return joiningYear;
	}
	public void setJoiningYear(int joiningYear) {
		this.joiningYear = joiningYear;
	}
	public double getJoiningFees() {
		return joiningFees;
	}
	public void setJoiningFees(double joiningFees) {
		this.joiningFees = joiningFees;
	}
	public boolean isActive() {
		return isActive;
	}
	public void setActive(boolean isActive) {
		this.isActive = isActive;
	}
	
	// Display Full Prime Member class
	public void display() {
		
		//Parent class
		System.out.println("Name : " + getName());
		System.out.println("Age : " + getAge()); 
		System.out.println("Phone Number : " + getPhoneNumber());
		System.out.println("Address : " + getAddress()); 
		System.out.println("Salary : " + getSalary()); 
		
		//Child class
		System.out.println("Joining Year : " + joiningYear); 
		System.out.println("Joining Fees : " + joiningFees); 
		System.out.println("Is Active : " + isActive);
	}
	
	
}
