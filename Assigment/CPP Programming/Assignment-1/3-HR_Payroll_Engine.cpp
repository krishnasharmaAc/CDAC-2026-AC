#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
    private:
        int empId;
        string name;
        string department;
        char grade;
        double basicSalary;
        bool isActive;
        static int employeeCount;
    
    public:

    Employee(){
         empId = 0;
         name = "";
         department = "";
         grade =' ';
         basicSalary = 0;
         isActive = true;

        employeeCount++;
    }

    // Getters
        int getEmpId()const{return empId;}
        //Const function promises not to modify the object's data members.
        string getName() const{return name;} 
        string getDepartment() const{return department;}
        char getGrade() const{return grade;}
        double getBasicSalary() const{return basicSalary;}
        bool  getIsActive() const{return isActive;}

    // Setters

    void setEmpId(int id) {

        if (id > 0) {
            empId = id;
        }
        else {
            cout << "ERROR: Employee ID must be greater than 0."<< endl;
        }
    }


    void setName(const string& n) {
        name = n;
    }


    bool setDepartment(const string& dept) {

        if (dept == "Engineering" || dept == "HR" || dept == "Finance" || dept == "Operations") {
            department = dept;
            return true;
        }
        cout << "ERROR: '" << dept << "' is not a registered department."<< endl;
        return false;
    }


    bool setGrade(char g) {

    if (g == 'A' || g == 'B' ||
        g == 'C' || g == 'D') {

        grade = g;
        return true;
    }

    cout << "ERROR: Invalid grade '" << g
         << "'. Accepted values: A, B, C, D."
         << endl;

    return false;
}


    bool setBasicSalary(double salary) {

    if (salary >= 10000 && salary <= 500000) {
        basicSalary = salary;
        return true;
    }

    cout << "ERROR: Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected."
         << endl;

    return false;
   }


    void deactivate() {
        isActive = false;
    }


        void acceptDetails(){
            // Reads all fields from the user — must call the corresponding setter for each
            // so that validation runs before any value is stored
            int id;
            string n;
            string dept;
            char g;
            double salary;

            cout << "Enter employee ID: ";
            cin >> id;
            setEmpId(id);

            cout << "Enter name: ";
            cin.ignore(1000, '\n');
            getline(cin, n);
            setName(n);

            do{
                cout << "Enter department: ";
                cin >> dept;
            }while(!setDepartment(dept));

            do{
                cout << "Enter grade: ";
                cin >> g;
            }while(!setGrade(g));

            do{
                cout << "Enter basic salary: ";
                cin >> salary;
            }while(!setBasicSalary(salary));
        }

        // ================= BUSINESS LOGIC =================

    // Grade A → 40%
    // Grade B → 30%
    // Grade C → 20%
    // Grade D → 10%

    double computeAllowances() const {

        switch (grade) {

            case 'A':
                return basicSalary * 0.40;

            case 'B':
                return basicSalary * 0.30;

            case 'C':
                return basicSalary * 0.20;

            case 'D':
                return basicSalary * 0.10;

            default:
                return 0;
        }
    }


    // Gross Salary = Basic Salary + Allowances

    double computeGrossSalary() const {

        return basicSalary + computeAllowances();
    }


    // Tax Rules:
    //
    // Gross <= 50,000 → 0%
    // 50,001 to 1,00,000→ 10% on amount above 50,000
    // >1,00,000 → 5,000 + 20% on amount above 1,00,000

    double computeTax() const {

        double gross = computeGrossSalary();

        if (gross <= 50000) {

            return 0;
        }

        else if (gross <= 100000) {

            return (gross - 50000) * 0.10;
        }

        else {

            return 5000 +
                   (gross - 100000) * 0.20;
        }
    }


    // Net Salary = Gross Salary - Tax

    double computeNetSalary() const {

        return computeGrossSalary() - computeTax();
    }


    // ================= PAYSLIP =================

    void printPayslip() const {

        double allowance = computeAllowances();
        double gross = computeGrossSalary();
        double tax = computeTax();
        double net = computeNetSalary();

        double allowancePercent = 0;

        switch (grade) {

            case 'A':
                allowancePercent = 40;
                break;

            case 'B':
                allowancePercent = 30;
                break;

            case 'C':
                allowancePercent = 20;
                break;

            case 'D':
                allowancePercent = 10;
                break;
        }


        cout << fixed << setprecision(2);

        cout << "\n============================================"
             << endl;

        cout << "EMPLOYEE PAYSLIP - AUG 2026"
             << endl;

        cout << "============================================"<< endl;

        cout << "Emp ID      : " << empId << endl;

        cout << "Name        : " << name << endl;

        cout << "Department  : " << department << endl;

        cout << "Grade       : " << grade << endl;

        cout << "Status      : "<< (isActive ? "Active" : "Inactive")<< endl;

        cout << "--------------------------------------------"<< endl;

        cout << "Basic Salary     : Rs. "<< basicSalary << endl;

        cout << "Allowances ("<< allowancePercent<< "%) : Rs. "<< allowance << endl;

        cout << "Gross Salary     : Rs. "<< gross << endl;

        cout << "--------------------------------------------"<< endl;

        cout << "Tax Deduction    : Rs. "<< tax << endl;

        cout << "Net Salary       : Rs. "<< net << endl;

        cout << "============================================"<< endl;
    }


    // ================= STATIC FUNCTION =================

    static int getEmployeeCount() {

        return employeeCount;
    }
};
int Employee::employeeCount = 0;

int main(){
    // Create objects — one on stack, two on heap
    Employee e1;
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();
    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();


    // e1.empId = 999; cannt be access private member variables from directly from object in main
    // e1.basicSalary = -1000;  we need to access them with the help of class member function


    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();


    // // Simulate a resignation
    e3->deactivate();
    if (!e3->getIsActive())
    cout << e3->getName() << " is no longer active. Payroll skipped." << endl;
    cout << "Total Employees : " << Employee::getEmployeeCount() << endl;


    
    delete e2;
    delete e3;  

    return 0;
};