#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

class DataProcessor {
public:
    // Pure virtual functions — all subclasses MUST implement these
    virtual void   loadData(const string& source) = 0;
    virtual void   processData() = 0;
    virtual void   exportResult(const string& destination) = 0;
    virtual string processorType() const = 0;
    virtual int    recordCount() const = 0;


    // Non-pure virtual — base provides a default report format
    virtual void printSummary() const;


    virtual ~DataProcessor() = default;

};
void DataProcessor::printSummary() const {
    cout << "Processor Type: " << processorType() << endl;
    cout << "Record Count: " << recordCount() << endl;
}

class CSVProcessor : public DataProcessor{
    private:
        vector<string>records;
    public:
        void loadData(const string& source) override{
             records = {
                "alice,25,Delhi",
                "bob,30,Mumbai",
                "charlie,28,Pune",
                "david,35,Gwalior",
                "emma,22,Indore"
            };
            cout << "Loading CSV from: "<< source << endl;
        }

        void processData() override {
            for (string& record : records) {
                for (char& ch : record)
                    ch = toupper(ch);
            }
        }


        void exportResult(const string& destination) override {
            cout << "[CSV EXPORT → "<< destination << "]" << endl;

            for (const string& record : records) {
                cout << record << endl;
            }
        }

        string processorType() const override {
            return "CSV Processor";
        }

        int recordCount() const override {
            return records.size();
        }
   
};

class SensorStreamProcessor : public DataProcessor{
    private:
        vector<double> readings;
        double mean = 0;
        double minimum = 0;
        double maximum = 0;
    public:
        void loadData(const string& source) override{
             readings = {23.4,21.8,25.1,12.4,34.21,29.3,17.6,14.9};
            cout << "Loading CSV from: "<< source << endl;
        }
        void processData() override {
            double sum = 0;

            minimum = readings[0];
            maximum = readings[0];

            for (double value : readings) {

                sum += value;

                if (value < minimum)
                    minimum = value;

                if (value > maximum)
                    maximum = value;
            }

            mean = sum / readings.size();
        }

        void exportResult(const string& destination) override {
            cout << "[SENSOR EXPORT → "<< destination << "]" << endl;

            cout << fixed << setprecision(2);

            cout << "Mean: " << mean << endl;
            cout << "Min: " << minimum << endl;
            cout << "Max: " << maximum << endl;
        }

        string processorType() const override {
            return "Sensor Stream Processor";
        }

        int recordCount() const override {
            return readings.size();
        }
};

int main(){


    // DataProcessor dp;
    // Error: DataProcessor is an abstract class

    vector<DataProcessor*> pipeline;

    pipeline.push_back(new CSVProcessor());
    pipeline.push_back(new SensorStreamProcessor());

    for (auto* p : pipeline) {
        p->loadData("source_data");
        p->processData();
        p->printSummary();
        p->exportResult("output_dir");
        cout << "---" << endl;
    }

    for (DataProcessor* p : pipeline) {
        delete p;
    }
    return 0;
}