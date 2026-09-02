#include <iostream>
using namespace std;


// Physics namespace
namespace Physics
{
    // Clamp a velocity
    double clamp(double val, double min, double max)
    {
        if (val < min)
            return min;

        if (val > max)
            return max;

        return val;
    }

    // Linear interpolation for physics
    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}


// GameMath namespace
namespace GameMath
{
    // Clamp an integer stat
    int clamp(int val, int min, int max)
    {
        if (val < min)
            return min;

        if (val > max)
            return max;

        return val;
    }

    // Lerp for UI animations
    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}


int main()
{
    // Calling Physics versions
    double velocity = Physics::clamp(120.5, 0.0, 100.0);

    double physicsValue = Physics::lerp(0.0, 100.0, 0.5);


    // Calling GameMath versions
    int health = GameMath::clamp(120, 0, 100);

    double uiValue = GameMath::lerp(0.0, 500.0, 0.5);


    cout << "Physics velocity : " << velocity << endl;
    cout << "Physics lerp     : " << physicsValue << endl;

    cout << "Game health      : " << health << endl;
    cout << "GameMath lerp    : " << uiValue << endl;


     // Limited block scope
    {
        using namespace Physics;

        double result3 = lerp(10.0, 20.0, 0.5);

        cout << "Physics LERP: " << result3 << endl;
    }
    // Outside the block
    // lerp(10.0, 20.0, 0.5);  Not available directly

    double result4 = Physics::lerp(10.0, 20.0, 0.5); 

    return 0;
}