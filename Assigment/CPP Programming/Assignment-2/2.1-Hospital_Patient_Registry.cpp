#include <iostream>
#include <string>
using namespace std;

class Patient{
    private:
        int patientId;
        string name;
        int age;
        string ward;
        const string bloodGroup;
    
    public:
    //    Use Constructor Initializer List to initialise bloodGroup in all three constructors 
   //    (it is const — it cannot be assigned inside the body).
    //default constructor 
        Patient(): 
          patientId(0),
          name("Unknown"),
          age(0),
          ward("General"),
          bloodGroup("O+")
          
        {
            cout<<"[Constructor] Default Patient Registered."<<endl;
        }
    //Emergy admision only:
        Patient(int id, const string& name):
          patientId(id),
          name(name),
          age(0),
          ward("General"),
          bloodGroup("O+")
        {
            cout<<"[Constructor] Emergenc : "<<name<<endl;
        }
    //FUll admission details
        Patient(int id, const string& name,int age , const string& ward , const string& bg):
          patientId(id),
          name(name),
          age(age),
          ward(ward),
          bloodGroup(bg)
        {
            cout<<"[Constructor] Full admission : "<< name <<endl;
        }

        void  displayRecord() const{
            cout << "\nPatient Record:" << endl;
            cout << "ID        : " << patientId << endl;
            cout << "Name      : " << name << endl;
            cout << "Age       : " << age << endl;
            cout << "Ward      : " << ward << endl;
            cout << "Blood Grp : " << bloodGroup << endl<<endl;
        }

        void transferWard(const string& nameNW){
            cout << "Ward Transfer: "<< ward << " to " << nameNW << endl;
            ward = nameNW;
        }
    // Destructor
    ~Patient() {
        cout << "[Destructor] Patient "
             << name << " discharged." << endl;
    }
};
int main(){
    // 1. Create one patient of each type
    Patient p1(1001, "Meera Joshi", 34, "Cardiology", "B+");

    Patient p2(1002, "Raj Patel");

    Patient p3;

    // Dynamic Array of 4 patients

    Patient * patients = new Patient[4];

    // Display All for patients

    for(int i=0; i<4; i++){
        patients[i].displayRecord();
        cout<<endl;
    }

    p1.displayRecord();

    // Transfer one patiets to ICU ward
    p2.transferWard("ICU");
    cout<<endl;

    //delete dyanmic array

    delete[] patients;

    return 0;
}