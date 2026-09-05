#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class Vehicle;
// Forward declaration of function
void printFleetReport(const vector<Vehicle*>& fleet, double tripKm);
class Vehicle{

   protected:
        string registrationNo;
        string ownerName;
        int yearOfManufacture;
        double kmDriven;
        
    public:

        Vehicle(const string& reg, const string& owner, int year, double km){
            registrationNo = reg;
            ownerName = owner;
            yearOfManufacture = year; 
            kmDriven = km;

            cout << "[Vehicle Constructor] " << registrationNo << " : " << ownerName << endl;
        }
      
        virtual double fuelCost(double kmToTravel) const = 0;

        virtual void   describe() const{
            cout<<"This is a Vehicle ::"<<endl;
        }      
        
        virtual string vehicleType() const = 0;

        string getOwnerName() const {
            return ownerName;
        }


        // Virtual destructor
        virtual ~Vehicle(){
            cout<<"{Vehicle Destructor}  "<<registrationNo<<endl;
        }

        double getKmDriven() const{
            return kmDriven;
        }
        string getRegNo() const{
            return registrationNo;
        }
};

class Car : public Vehicle{
    protected:
        string fuelType;
        double mileageKmpl;
    public:
        //Car coonstructor --- constructor initializer list
        Car(const string& reg, const string& owner, int year,
             double km, const string& fuel, double mileage): 
             Vehicle(reg, owner, year,km),fuelType(fuel), mileageKmpl(mileage){
                cout << "[Car Constructor] " << registrationNo << endl;
             }
        double fuelCost(double kmToTravel) const override {
            double price;
            if(fuelType == "Petrol"){
                price= 106.00;
            }
            else{
                price = 93.00;
            }
            return (kmToTravel / mileageKmpl) * price;
        }

        string vehicleType() const override{
            return "Car";
        }

         void describe() const override {

                Vehicle::describe();

                cout << "Fuel Type: "<< fuelType << endl;

                cout << "Mileage: "<< mileageKmpl<< " km/L" << endl;
         }

        ~Car() override{
            cout<<"{Car Destructor}  "<<registrationNo<<endl;
        }

};

class Truck : public Vehicle{
    protected:
        double payLoadCapacityTons;
        double fuelEfficiencyKmpl;
    
    public:
        //Truck coonstructor --- constructor initializer list
        Truck(const string& reg, const string& owner, int year,
             double km, const double cap, 
            double eff): Vehicle(reg, owner, year,km),
            payLoadCapacityTons(cap), fuelEfficiencyKmpl(eff){
               cout << "[Truck Constructor] " << registrationNo << endl;
            }

        double fuelCost(double kmToTravel) const override {
            double reduction = payLoadCapacityTons * 0.05;

            double actualEfficiency = fuelEfficiencyKmpl * (1 - reduction);

            double fuelRequired = kmToTravel / actualEfficiency;

            return fuelRequired * 93.00;
        }

        string vehicleType() const override{
            return "Truck";
        }

        void describe() const override {

        Vehicle::describe();

        cout << "Payload Capacity: "<< payLoadCapacityTons<< " tons" << endl;

        cout << "Fuel Efficiency: "<< fuelEfficiencyKmpl<< " km/L" << endl;
        }

        ~Truck() override{
            cout<<"{Truck Destructor}  "<<registrationNo<<endl;
        }
    
};

class ElectricTruck : public Truck {

private:
    double batteryCapacityKWh;
    double rangePerChargeKm;

public:

    ElectricTruck(
        const string& reg,const string& owner,int year,
        double km,double payload,double efficiency,
        double battery,double range)
        : Truck(reg, owner, year, km, payload, efficiency),
          batteryCapacityKWh(battery),rangePerChargeKm(range) {

        cout << "[ElectricTruck Constructor] " << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {

        return (kmToTravel / rangePerChargeKm)* batteryCapacityKWh* 9.50;
    }

    string vehicleType() const override {
        return "Electric Truck";
    }
    double getBatteryCapacity() const {
        return batteryCapacityKWh;
    }

    void describe() const override {

        Truck::describe();

        cout << "Battery Capacity: "<< batteryCapacityKWh<< " kWh" << endl;

        cout << "Range Per Charge: "<< rangePerChargeKm<< " km" << endl;
    }

    ~ElectricTruck() override {

        cout << "[ElectricTruck Destructor] "<< registrationNo << endl;
    }
};
class Van : public Vehicle {

private:
    int seatingCapacity;
    double mileageKmpl;

public:

    Van(const string& reg,const string& owner,
        int year,double km,int seats,double mileage)
        : Vehicle(reg, owner, year, km),seatingCapacity(seats),
          mileageKmpl(mileage) {
        cout << "[Van Constructor] "<< registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {

        return (kmToTravel / mileageKmpl)* 106.00;
    }

    string vehicleType() const override {
        return "Van";
    }

    void describe() const override {

        Vehicle::describe();

        cout << "Seating Capacity: "<< seatingCapacity << endl;

        cout << "Mileage: " << mileageKmpl<< " km/L" << endl;
    }

    ~Van() override {
        cout << "[Van Destructor] "<< registrationNo << endl;
    }
};

int main(){
    // ElectricTruck et("V-Etoo1", "Green Logistis",2025,50000,2.0,8.0,400,600);
    // //provide the same output


    vector<Vehicle*> fleet;

    fleet.push_back(new Car("KA01AA001","Ramesh Kumar",2022,70000,"Diesel",20.0));

    fleet.push_back(new Car("MP07DD004","Amit Sharma",2023,45200,"Petrol",18.0));

    fleet.push_back(new Truck("MH04BB002","Shyam Logistics",2020,123500,10.0,5.0));

    fleet.push_back(new ElectricTruck("GJ07CC003","Green Fleet Co",2025,89000,2.0,8.0,400,600));

    fleet.push_back(new Van("DL05EE005","City Transport",2021,67000,8,12.0));

    double tripKm = 200;

    printFleetReport(fleet, tripKm);

    cout<<endl<<endl;

    // Cleanup
    for (Vehicle* v : fleet) {
    delete v;
    }

    return 0;
}


void printFleetReport(
    const vector<Vehicle*>& fleet,
    double tripKm
) {

    cout << fixed << setprecision(2);

    cout << "===== FLEET REPORT — Trip Distance: "
         << tripKm << " km =====\n";

    cout << left
         << setw(12) << "Reg"
         << setw(20) << "Type"
         << setw(20) << "Owner"
         << setw(12) << "Km Driven"
         << endl;

    cout << string(64, '-') << endl;


    // -------------------------------
    // FLEET TABLE
    // -------------------------------

    for (Vehicle* v : fleet) {

        cout << left
             << setw(12) << v->getRegNo()
             << setw(20) << v->vehicleType()
             << setw(20) << v->getOwnerName()
             << setw(12) << fixed
             << setprecision(0)
             << v->getKmDriven()
             << endl;
    }


    // -------------------------------
    // COST ESTIMATE
    // -------------------------------

    cout << "\n===== FUEL / CHARGE COST ESTIMATE =====\n";

    double minCost =
        numeric_limits<double>::max();

    Vehicle* mostEfficient = nullptr;


    for (Vehicle* v : fleet) {

        // Runtime polymorphism
        double cost = v->fuelCost(tripKm);

        cout << left
             << setw(12) << v->getRegNo()
             << " (" << v->vehicleType() << ")"
             << " : Rs. "
             << fixed << setprecision(2)
             << cost;


        // Check whether this is ElectricTruck
        ElectricTruck* et =
            dynamic_cast<ElectricTruck*>(v);

        if (et != nullptr) {

            cout << " [Battery: "
                 << et->getBatteryCapacity()
                 << "% Charged";
        }

        cout << endl;


        // Find cheapest
        if (cost < minCost) {

            minCost = cost;
            mostEfficient = v;
        }
    }


    // -------------------------------
    // MOST EFFICIENT
    // -------------------------------

    if (mostEfficient != nullptr) {

        cout << "\nMost Efficient Vehicle: "
             << mostEfficient->getRegNo()
             << " ("
             << mostEfficient->vehicleType()
             << ") — Rs. "
             << fixed << setprecision(2)
             << minCost
             << " for "
             << tripKm
             << " km\n";
    }
}