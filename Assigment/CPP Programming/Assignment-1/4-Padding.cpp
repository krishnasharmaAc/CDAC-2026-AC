#include <iostream>
using namespace std;

// Same members ≠ same size. 
// The order of members affects alignment and padding.
struct Layout1{  
    char c1;
    int i;
    char c2;
};

struct Layout2{
    int i;
    char c1;
    char c2;
};

int main(){
    Layout1 obj1;
    Layout2 obj2;

    cout << "Size of Layout1 object = "
         << sizeof(obj1) << " bytes" << endl;

    cout << "Size of Layout2 object = "
         << sizeof(obj2) << " bytes" << endl;

    return 0;
}
// 1. Why the sizes differ:
//        Layout1 and Layout2 contain the same members, but the members
//        are arranged in a different order.

//        Layout1:
//            char c1  -> 1 byte                    
//            padding -> 3 bytes
//            int i   -> 4 bytes
//            char c2  -> 1 byte
//            padding -> 3 bytes    ==     Total = 12 bytes

//        Layout2:
//            int i   -> 4 bytes
//            char c1  -> 1 byte
//            char c2  -> 1 byte
//            padding -> 2 bytes   ==     Total = 8 bytes

//        Therefore, member ordering can change the amount of padding
//        required and consequently the total size of a structure.


//     2. What padding is and why the compiler adds it:

//        Padding is unused memory space inserted by the compiler between
//        or after structure members.

//        The compiler adds padding to properly align data members in memory.
//        For example, an int is commonly aligned on a 4-byte boundary.

//        Proper alignment allows the processor to access data efficiently
//        and, on some architectures, is required for correct memory access.



//     3. Why member order matters for network packet headers or
//        hardware register maps:

//        Member order determines the exact memory layout of a structure.

//        In network packet headers, the layout must match the exact byte
//        format defined by the communication protocol. Unexpected padding
//        can cause fields to appear at the wrong byte positions.

//        Similarly, hardware register maps depend on fixed memory addresses.
//        Changing the order of members or allowing unexpected padding can
//        make the program access the wrong hardware register.







