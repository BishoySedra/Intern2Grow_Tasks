#include <iostream>
#include "area.cpp"

using namespace std;

int main()
{
    do
    {
        int choice;
        cout << "1. Rectangle\n2. Circle\n3. Square\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Area area;
        switch (choice)
        {
        case 1:
        {
            double length, width;
            cout << "Enter the length and width of the rectangle respectively: ";
            cin >> length >> width;
            cout << "Area of the rectangle: " << area.rectangleArea(length, width) << endl;
            break;
        }
        case 2:
        {
            double radius;
            cout << "Enter the radius of the circle: ";
            cin >> radius;
            cout << "Area of the circle: " << area.circleArea(radius) << endl;
            break;
        }
        case 3:
        {
            double side;
            cout << "Enter the side of the square: ";
            cin >> side;
            cout << "Area of the square: " << area.SquareArea(side) << endl;
            break;
        }
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice\n";
        }

        cout << "Do you want to continue? (1/0): ";
        int isContinued;
        cin >> isContinued;
        if (!isContinued)
        {
            cout << "Exiting...\n";
            break;
        }

    } while (true);

    return 0;
}