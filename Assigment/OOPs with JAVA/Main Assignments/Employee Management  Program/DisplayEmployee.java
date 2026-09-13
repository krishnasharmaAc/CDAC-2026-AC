
public class DisplayEmployee {

    Employee[] employees;
    int employeeCount;

    int currentPosition;

    public DisplayEmployee(Employee[] employees, int employeeCount) {

        this.employees = employees;
        this.employeeCount = employeeCount;

        currentPosition = 0;
    }

    public void displayAll() {

        if (employeeCount == 0) {
            System.out.println("No employees available.");
            return;
        }

        for (int temp = 0; temp < employeeCount; temp++) {

            System.out.println("\nEmployee " + (temp + 1));

            displayEmployee(employees[temp]);
        }
    }

    public void firstEmployee() {

        if (employeeCount == 0) {
            System.out.println("No employees available.");
            return;
        }

        currentPosition = 0;

        displayEmployee(employees[currentPosition]);
    }

    public void nextEmployee() {

        if (employeeCount == 0) {
            System.out.println("No employees available.");
            return;
        }

        if (currentPosition < employeeCount - 1) {

            currentPosition++;

            displayEmployee(employees[currentPosition]);

        } else {

            System.out.println("Already at the last employee.");
        }
    }

    public void previousEmployee() {

        if (employeeCount == 0) {
            System.out.println("No employees available.");
            return;
        }

        if (currentPosition > 0) {

            currentPosition--;

            displayEmployee(employees[currentPosition]);

        } else {

            System.out.println("Already at the first employee.");
        }
    }

    public void lastEmployee() {

        if (employeeCount == 0) {
            System.out.println("No employees available.");
            return;
        }

        currentPosition = employeeCount - 1;

        displayEmployee(employees[currentPosition]);
    }

    public void displayEmployee(Employee employee) {

        System.out.println("-----------------------------");
        System.out.println("Name       : " + employee.getName());
        System.out.println("Address    : " + employee.getAddress());
        System.out.println("Age        : " + employee.getAge());
        System.out.println("Gender     : " + employee.isGender());
        System.out.println("Basic Salary: " + employee.getBasicSalary());

        if (employee instanceof Manager) {

            Manager manager = (Manager) employee;

            System.out.println("Type       : Manager");
            System.out.println("HRA        : " + manager.getHra());

        } else if (employee instanceof Engineer) {

            Engineer engineer = (Engineer) employee;

            System.out.println("Type       : Engineer");
            System.out.println("Over Time  : " + engineer.getOverTime());

        } else if (employee instanceof SalesPerson) {

            SalesPerson salesPerson = (SalesPerson) employee;

            System.out.println("Type       : Sales Person");
            System.out.println("Commission : " + salesPerson.getCommission());
        }

        System.out.println("-----------------------------");
    }
}

