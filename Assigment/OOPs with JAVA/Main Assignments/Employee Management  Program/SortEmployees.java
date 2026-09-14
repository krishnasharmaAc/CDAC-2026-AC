
public class SortEmployees {
	Employee[] employees;
	int employeeCount;
	
	SortEmployees(Employee [] emp, int employeeCount){
		this.employees = emp;
		this.employeeCount =  employeeCount;
	}
	
	// Sort all Employees in ascending order
	public void sortAscending() {
		
		for(int itemp = 0; itemp< employeeCount-1; itemp++) {
			for(int jTemp = itemp+1; jTemp< employeeCount; jTemp++) {
				if(employees[itemp].getName().compareToIgnoreCase(employees[jTemp].getName())>0) {
					Employee em = employees[itemp];
					employees[itemp] = employees[jTemp];
					employees[jTemp] = em;
				}
			}
		}
		System.out.println("Employees sorted in ascending order.");
	}
	
	// Sort all Employees in Descending order
		public void sortDescending() {
			
			for(int itemp = 0; itemp< employeeCount-1; itemp++) {
				for(int jTemp = itemp+1; jTemp< employeeCount; jTemp++) {
					if(employees[itemp].getName().compareToIgnoreCase(employees[jTemp].getName())<0) {
						Employee em = employees[itemp];
						employees[itemp] = employees[jTemp];
						employees[jTemp] = em;
					}
				}
			}
			System.out.println("Employees sorted in ascending order.");
		}
		
}
