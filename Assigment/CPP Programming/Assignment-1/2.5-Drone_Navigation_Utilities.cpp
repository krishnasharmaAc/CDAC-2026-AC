#include <iostream>
#include <cmath>
using namespace std;


inline double distanceBetween(double x1, double y1, double x2, double y2)
// sqrt( pow(x2-x1, 2) + pow(y2-y1, 2) )
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


inline double toRadians(double degrees)
// degrees * (M_PI / 180.0)
{
    return degrees * (M_PI / 180.0);

}


inline double clamp(double value, double minVal, double maxVal)
// Restrict value to [minVal, maxVal]
{
    if (value < minVal) {
        return minVal;
    }

    if (value > maxVal) {
        return maxVal;
    }

    return value;
}

inline bool isInSafeZone(double x, double y, double cx, double cy, double radius)
// true if point (x,y) is within the circle centred at (cx,cy) with given radius
{
     return distanceBetween(x, y, cx, cy) <= radius;
}



int main(){
    // inline functions are used for reduce function call overhead

    // Home position
    double homeX = 0.0;
    double homeY = 0.0;

    // Safe-zone radius
    double radius = 50.0;

    // Three waypoints
    double x1 = 10.0;
    double y1 = 20.0;

    double x2 = 30.0;
    double y2 = 40.0;

    double x3 = 60.0;
    double y3 = 20.0;


    // Waypoint 1
    double d1 = distanceBetween(homeX, homeY, x1, y1);

    cout << "Waypoint 1 : (" << x1 << ", " << y1 << ")" << endl;
    cout << "Distance   : " << d1 << " units" << endl;
    cout << "Safe Zone  : "<< (isInSafeZone(x1, y1, homeX, homeY, radius) ? "YES" : "NO")<< endl;
    cout << endl;


    // Waypoint 2
    double d2 = distanceBetween(homeX, homeY, x2, y2);

    cout << "Waypoint 2 : (" << x2 << ", " << y2 << ")" << endl;
    cout << "Distance   : " << d2 << " units" << endl;
    cout << "Safe Zone  : "
         << (isInSafeZone(x2, y2, homeX, homeY, radius) ? "YES" : "NO")
         << endl;

    cout << endl;


    // Waypoint 3
    double d3 = distanceBetween(homeX, homeY, x3, y3);

    cout << "Waypoint 3 : (" << x3 << ", " << y3 << ")" << endl;
    cout << "Distance   : " << d3 << " units" << endl;
    cout << "Safe Zone  : "
         << (isInSafeZone(x3, y3, homeX, homeY, radius) ? "YES" : "NO")
         << endl;


    return 0;
}