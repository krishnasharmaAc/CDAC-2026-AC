
public class AddEmployee {

    Employee[] employees;
    int employeeCount;

    public AddEmployee() {

        employees = new Employee[20];
        employeeCount = 0;
    }

    public void addManager() {

        System.out.println("\n******** Add Manager ********");

        System.out.print("Enter Name: ");
        String name = ConsoleInput.getString();

        System.out.print("Enter Address: ");
        String address = ConsoleInput.getString();

        System.out.print("Enter Age: ");
        int age = ConsoleInput.getInt();

        System.out.print("Enter Gender (1-Male / 0-Female): ");
        boolean gender = ConsoleInput.getInt() == 1;

        System.out.print("Enter Basic Salary: ");
        double basicSalary = ConsoleInput.getFloat();

        System.out.print("Enter HRA: ");
        float hra = ConsoleInput.getFloat();

        employees[employeeCount] =new Manager(name, address, age, gender, basicSalary, hra);

        employeeCount++;

        System.out.println("Manager added successfully.");
    }

    public void addEngineer() {

        System.out.println("\n******** Add Engineer ********");

        System.out.print("Enter Name: ");
        String name = ConsoleInput.getString();

        System.out.print("Enter Address: ");
        String address = ConsoleInput.getString();

        System.out.print("Enter Age: ");
        int age = ConsoleInput.getInt();

        System.out.print("Enter Gender (1-Male / 0-Female): ");
        boolean gender = ConsoleInput.getInt() == 1;

        System.out.print("Enter Basic Salary: ");
        double basicSalary = ConsoleInput.getFloat();

        System.out.print("Enter Over Time: ");
        int overTime = ConsoleInput.getInt();

        employees[employeeCount] = new Engineer(name, address, age, gender,basicSalary, overTime);

        employeeCount++;

        System.out.println("Engineer added successfully.");
    }
    

    public void addSalesPerson() {

        System.out.println("\n******** Add Sales Person ********");

        System.out.print("Enter Name: ");
        String name = ConsoleInput.getString();

        System.out.print("Enter Address: ");
        String address = ConsoleInput.getString();

        System.out.print("Enter Age: ");
        int age = ConsoleInput.getInt();

        System.out.print("Enter Gender (1-Male / 0-Female): ");
        boolean gender = ConsoleInput.getInt() == 1;

        System.out.print("Enter Basic Salary: ");
        double basicSalary = ConsoleInput.getFloat();

        System.out.print("Enter Commission: ");
        float commission = ConsoleInput.getFloat();

        employees[employeeCount] = new SalesPerson(name, address, age, gender,basicSalary, commission);

        employeeCount++;

        System.out.println("Sales Person added successfully.");
    }
    

    public Employee[] getEmployees() {
        return employees;
    }

    public int getEmployeeCount() {
        return employeeCount;
    }
}


