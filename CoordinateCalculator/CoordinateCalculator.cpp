// code for cartesian points 
// a = r, b = theta 

#include <iostream>
#include <string>
#include <cmath> 
#include <windows.h> 
using namespace std;

void cartesian();
void polar();


void GotoXY(int _iX, int _iY)
{
    COORD point; point.X = _iX;
    point.Y = _iY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

int main()
{
    int menu_option = 3;
    cout << "1) Cartesian to Polar \n";
    cout << "2) Polar to Cartesian \n";
    cout << "3) Quit \n";
    cout << "Input whether you want polar or cartesian conversion (1 or 2) or to quit (3): ";
    cin >> menu_option;
    cout << "\n";

    switch (menu_option) {
    case 1:
        cartesian();
        break;
    case 2:
        polar();
        break;
    }
    GotoXY(1, 43);
    return 0;
}
// this function is there for making and plotting a point on a graph 
bool plot(int px, int py) {
    int xMin = -15;
    int xMax = 15;
    int yMin = 15;
    int yMax = -15;

    if (px < xMin || px > xMax) return false;
    if (py > yMin || py < yMax) return false;

    cout << endl;

    for (int y = yMin; y >= yMax; --y) {

        cout << string(20, ' ');

        for (int x = xMin; x <= xMax; ++x) {
            if (x == px && y == py) {
                cout << "X";
            }
            else if (y == 0)
                cout << "-";
            else if (x == 0)
                cout << "|";
            else
                cout << " ";


            if (x != xMax) cout << "  ";

        }
        cout << endl;
    }
}

// this function is for calculating the cartesian coordinates and also graphing them
void cartesian()
{
    float x, y;
    float a;
    double b;

    cout << "Put in a value for x: ";
    cin >> x;
    cout << "Put in a value for y: ";
    cin >> y;

    a = hypot(x, y); // getting r 
    b = (atan(y / x) * 180) / 3.14159; // getting the angle and converting it from radians to degrees

    cout << "Cartesian: "; cout << (x); cout << ", "; cout << (y); cout << "\n";
    cout << "Polar: "; cout << (a); cout << ", "; cout << (b); cout << "\n";
    if (x > 0 && y > 0)
    {
        cout << "Quadrant: I";
    }

    if (x < 0 && y > 0)
    {
        cout << "Quadrant: II";
    }

    if (x < 0 && y < 0)
    {
        cout << "Quadrant: III";
    }

    if (x > 0 && y < 0)
    {
        cout << "Quadrant: IV";
    }

    if (x > 0 && y == 0)
    {
        cout << "Quadrant: I and IV";
    }
    plot(round(x), round(y));
    GotoXY(x, y);
    cout << "\n";
    //main();
}

// this funtion is for calculating the polar coordinates and graphing the cartesian coordinates
void polar()
{
    float x, y;
    float a;
    double b;
    char quadrant;

    cout << "Put in a value for r: ";
    cin >> a;
    cout << "Put in a value for Theta: ";
    cin >> b;

    x = (cos(b * 3.14159 / 180) * a);
    y = (sin(b * 3.14159 / 180) * a);

    cout << "Cartesian: "; cout << (x); cout << ", "; cout << (y); cout << "\n";
    cout << "Polar: "; cout << (a); cout << ", "; cout << (b); cout << "\n";
    if (x > 0 && y > 0)
    {
        cout << "Quadrant: I";
    }

    if (x < 0 && y > 0)
    {
        cout << "Quadrant: II";
    }

    if (x < 0 && y < 0)
    {
        cout << "Quadrant: III";
    }

    if (x > 0 && y < 0)
    {
        cout << "Quadrant: IV";
    }

    if (x > 0 && y == 0)
    {
        cout << "Quadrant: I and IV";
    }

    plot(round(x), round(y));
    GotoXY(x, y);
    cout << "\n";
    //main();
}