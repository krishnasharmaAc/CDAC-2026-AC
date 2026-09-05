#include <iostream>
#include<string>
#include <stdexcept>
using namespace std;

template <typename T>
class DataBuffer {
private:
    T* data;        
    int  capacity;
    int  head;        
    int  tail;        
    int  count;     

public:

    DataBuffer(int capacity){

        this->capacity = capacity;
        data = new T[capacity];
        head = 0;
        tail = 0;
        count = 0;

    }

    ~DataBuffer(){
        delete[] data;
    }

    void push(const T& value){
        data[tail] = value;

        tail = (tail + 1) % capacity;

        if (count < capacity) {
            count++;
        }
        else {
            // Buffer was full,
            // oldest element moves forward
            head = (head + 1) % capacity;
        }
    }  
    T pop() {

        if (isEmpty()) {
            throw underflow_error("Buffer is empty");
        }

        T value = data[head];

        head = (head + 1) % capacity;
        count--;

        return value;
    }
    T peek() const {
        if (isEmpty()) {
            throw underflow_error("Buffer is empty");
        }

        return data[head];
    }          
    bool isEmpty() const {
        return count == 0;
    }
    bool isFull() const {
        return count == capacity;
    }
    int size() const {
        return count;
    }

    template <typename U>
    friend ostream& operator<<(ostream& out, const DataBuffer<U>& buf);
};

template <typename U>
ostream& operator<<(ostream& out,
                    const DataBuffer<U>& buf) {

    out << "[";

    for (int i = 0; i < buf.count; i++) {

        int index = (buf.head + i) % buf.capacity;

        out << buf.data[index];

        if (i < buf.count - 1) {
            out << ", ";
        }
    }

    out << "]";

    return out;
}

int main(){
    // Integer buffer — simulate sensor tick IDs
    DataBuffer<int> tickBuffer(5);

    for (int i = 1; i <= 7; i++)
        tickBuffer.push(i * 10);  // Should overwrite oldest

    cout << "Tick Buffer: " << tickBuffer << endl;

    // Double buffer — simulate temperature readings
    DataBuffer<double> tempBuffer(4);
    tempBuffer.push(36.6); tempBuffer.push(37.1);
    tempBuffer.push(38.2); tempBuffer.push(36.9);

    cout << "Before pop: " << tempBuffer << endl;
    cout << "Popped: " << tempBuffer.pop() << endl;
    
    cout << "After pop:  " << tempBuffer << endl;

    // String buffer — simulate log message queue
    DataBuffer<string> logBuffer(3);
    logBuffer.push("INFO: Server started");
    logBuffer.push("WARN: High memory usage");
    logBuffer.push("ERROR: DB connection timeout");
    logBuffer.push("INFO: Retry successful");   
    // Overwrites oldest
    cout << "Log Buffer: " << logBuffer << endl;
    return 0;
}


// IMPORTANT:
// Template definitions must usually be placed entirely in the header (.h)
// file or in the same file as the template declaration.
//
// The compiler generates the actual template code only when it sees the
// template being used with a specific type, such as DataBuffer<int> or
// DataBuffer<double>. Therefore, the complete template definition must be
// visible at the point of instantiation.
//
// If the template definition is placed only in a separate .cpp file, the
// compiler cannot see the implementation when compiling main.cpp, which can
// result in "undefined reference" linker errors.
//
// Therefore, keep the template declaration and definition together in the
// .h file, or put everything in a single .cpp file.