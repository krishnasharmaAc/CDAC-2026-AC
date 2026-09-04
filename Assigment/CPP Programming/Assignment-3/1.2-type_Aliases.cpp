#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Type aliases using 'using'

using Header = pair<string, string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;

// Traditional typedef
typedef unsigned long long RequestId;

// Function to print headers
void printHeaders(const HeaderList& headers) {

    for (const Header& header : headers) {
        cout << header.first << " : " << header.second << endl;
    }
}

int main() {
    RequestId requestId = 174829384;
    Port serverPort = 8080;

    HeaderList headers = {
        {"Content-Type", "application/json"},
        {"Authorization", "Bearer eyJhbGci..."},
        {"Accept-Language", "en-US"} };

    cout << "Request ID   : " << requestId << endl;
    cout << "Server Port  : " << serverPort << endl;

    cout << "Headers:" << endl;

    printHeaders(headers);

    return 0;
}