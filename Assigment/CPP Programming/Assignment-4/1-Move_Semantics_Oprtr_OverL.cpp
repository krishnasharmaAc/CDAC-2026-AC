#include <iostream>
#include <string>
#include <utility>

using namespace std;

class LedgerEntry{
    private:
        string description;
        double * amounts;
        int days;
        static int totalEntries;
    
    public:
    // Constructor
        LedgerEntry(const string& desc, int days){
            this->description = desc;
            this->days = days;
            amounts = new double[days];

            cout<<"[LedgerEntry Created] "<<endl;
            
            totalEntries++;
        }
    // Copy Constructor with deep copy
        LedgerEntry(const LedgerEntry& other){
            days = other.days;
            description = other.description;
            amounts = new double[days];
            for(int i = 0; i<days; i++){
                    amounts[i] = other.amounts[i];
                }
            totalEntries++;
        }
    //Move Constructor
    LedgerEntry(LedgerEntry&& other) noexcept{
            description =other.description;
            amounts = other.amounts;
            days = other.days;

            
            other.amounts = nullptr;
            other.description = "";
            other.days = 0;
            totalEntries++;
    }

    //Copy Assignment Operator
    LedgerEntry& operator=(const LedgerEntry& other){

            if( this == &other){
                cout << "[Self-assignment detected — no operation]" << endl;
                return *this;
            }
            delete[] amounts;
            days = other.days;
            description = other.description;
            amounts = new double[days];
            for(int i = 0; i<days; i++){
                    amounts[i] = other.amounts[i];
                }
            return *this;
    }

    //Move Assignemnt Operator 
    LedgerEntry& operator=(LedgerEntry&& other) noexcept{
             if (this == &other) {
            return *this;
        }

        delete[] amounts;

        description = other.description;
        amounts = other.amounts;
        days = other.days;

        other.description = "";
        other.amounts = nullptr;
        other.days = 0;

        return *this;
    }

    //Destructor
    ~LedgerEntry(){
         delete[] amounts;
            totalEntries--;

            cout << "Destructor called" << endl;
    }

    static int getTotalEntries(){
        return totalEntries;
    }

    // Add corresponding daily amounts — return a new LedgerEntry
LedgerEntry operator+(const LedgerEntry& other) const{

     LedgerEntry result("Combined Sales", days);
    for (int i = 0; i < days; i++) {
    result.amounts[i] = amounts[i] + other.amounts[i];
    }
    return result;
}
// Compare total sum of amounts
bool operator==(const LedgerEntry& other) const{
    if(days!= other.days){
        return false;
    }
    if(description!=other.description){
        return false;
    }
    for(int i=0; i<days; i++){
        if(amounts[i]!= other.amounts[i]){
            return false;
        }
    }
    return true;
}
bool operator>(const LedgerEntry& other) const{
    double total1 = 0;
    double total2 = 0;

    for(int i=0; i<days; i++){
        total1 += amounts[i];
    }
    for(int i=0; i<other.days; i++){
        total2 += other.amounts[i];
    }

    return total1>total2;
}

double&       operator[](int index){
    return amounts[index];
}
const double& operator[](int index) const{
    return amounts[index];
}
// Stream operators — declared as friend functions
friend ostream& operator<<(ostream& out, const LedgerEntry& entry){
    out<<entry.description<<endl;

    for(int i=0; i<entry.days; i++){
        out<<entry.amounts[i]<<" ";
    }
    out<<endl;
    return out;
}
friend istream& operator>>(istream& in, LedgerEntry& entry){
    in>>entry.description;

    for(int i=0; i<entry.days; i++){
        in>>entry.amounts[i];
    }

    return in;
}
};
int LedgerEntry :: totalEntries = 0;


int main(){
       // Objective 1 — Constructor & deep copy
        LedgerEntry jan("January Sales", 5);
        jan[0] = 1200.50;  jan[1] = 3400.00;  jan[2] = 800.75;
        jan[3] = 2100.00;  jan[4] = 650.25;


        LedgerEntry feb("February Sales", 5);
        feb[0] = 900.00;   feb[1] = 2200.50;  feb[2] = 1750.00;
        feb[3] = 3000.00;  feb[4] = 475.50;


        cout << jan << endl;
        cout << feb << endl;


        // Objective 2 — Operator + (sum two ledgers into combined)
        LedgerEntry combined = jan + feb;
        cout << "Combined: " << combined << endl;


        // Objective 3 — Relational operators
        cout << "Jan == Feb : " << (jan == feb ? "Yes" : "No") << endl;
        cout << "Jan  > Feb : " << (jan  > feb ? "Yes" : "No") << endl;


        // Objective 4 — Move constructor (should NOT deep copy)
        LedgerEntry moved = move(jan);
        cout << "After move, jan.amounts is null: "<< (true ? "YES" : "NO") << endl;
        cout << "Moved entry: " << moved << endl;

        // Objective 5 — Move assignment
        LedgerEntry q1("Q1 Total", 5);
        q1 = move(feb);   

        // feb's resources transferred to q1
        cout << "Q1 (moved from feb): " << q1 << endl;


        // Objective 6 — Static member
        cout << "Live LedgerEntry objects: " << LedgerEntry::getTotalEntries << endl;

    return 0;
}