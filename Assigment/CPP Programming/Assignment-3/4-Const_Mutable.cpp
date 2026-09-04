#include <iostream>
#include<cstring>
using namespace std;

class LogBuffer{
    private:
        char* buffer;
        int capacity;  // max no of char 
        int size; // curr number stored 
        static int instanceCount;  //total objects trak

        mutable int accessCount = 0;
    
    public:
        LogBuffer(int capacity){
            this->capacity = capacity;
            size = 0;
            buffer = new char[capacity];
            buffer[0] = '\0';
            instanceCount++;

             cout << "[LogBuffer Created] capacity = " << capacity << endl;
        }

        // Copy Constructor — must perform a DEEP copy
        LogBuffer(const LogBuffer& other){
            capacity = other.capacity;
            size = other.size;

            buffer = new char[capacity];
            for (int i = 0; i <= size; i++) 
                buffer[i] = other.buffer[i];

            instanceCount++;

            cout << "[LogBuffer Deep Copied] capacity = " << capacity << endl;
        }

        // Copy Assignment Operator — must handle self-assignment, release old memory, deep copy
        LogBuffer& operator=(const LogBuffer& other){
                // 1. Check self-assignment
                if (this == &other) {
                    cout << "[Self-assignment detected — no operation]" << endl;
                    return *this;
                }

                // 2. Release old memory
                delete[] buffer;

                // 3. Copy simple data
                capacity = other.capacity;
                size = other.size;

                // 4. Allocate new memory
                buffer = new char[capacity];

                // 5. Deep copy the characters
                for (int i = 0; i <= size; i++) {
                    buffer[i] = other.buffer[i];
                }

                cout << "[LogBuffer Assigned]" << endl;

                // 6. Return current object
                return *this;
        }
        
        // Destructor
        ~LogBuffer() {
            delete[] buffer;
            instanceCount--;

            cout << "[LogBuffer Destroyed]" << endl;
        }

        // Append the mesg 
        // Append message
        void append(const char* msg) {

        int available = capacity - size - 1;
        int len = strlen(msg);

        if (len > available) {
            len = available;
        }

        for (int i = 0; i < len; i++) {
            buffer[size + i] = msg[i];
        }

        size += len;
        buffer[size] = '\0';
    }
        // Print buffer
        void print() const {
            accessCount++;
            cout << buffer << endl;
        }              
        // Clear buffer
        void clear() {
            size = 0;
            buffer[0] = '\0';
        }
         int getAccessCount() const{
            return accessCount;
         }

        // Get live object count
        static int getInstanceCount() {
            return instanceCount;
        }
};
// Static member definition
int LogBuffer::instanceCount = 0;

int main(){

    LogBuffer log1(256);

    log1.append("Server started on port 8080");

    const LogBuffer readOnly(log1);   
    readOnly.print();
    readOnly.print();
    readOnly.print();
    cout << "Times printed: " << readOnly.getAccessCount() << endl; 

    return 0;
}
//  A const member function promises that it will not modify the object's
//     normal data members. Since print() needs to increase accessCount every
//     time it is called, a regular member cannot be modified inside print().

//     The mutable keyword is an exception to this rule. It allows accessCount
//     to be modified even when:
//         1. The object is const.
//         2. The member function is const.

// const ----means that the function cannot modify the object's non-mutable data members.