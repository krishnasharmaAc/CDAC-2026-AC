
public class SalesPerson extends Employee {
	float commission;

	public SalesPerson(String name, String address, int age, boolean gender, double basicSalary,float commission) {
		super(name, address, age, gender, basicSalary);
		// TODO Auto-generated constructor stub
		this.commission = commission;
	}

	public float getCommission() {
		return commission;
	}

	public void setCommission(float commission) {
		this.commission = commission;
	}
	
}
