#include <iostream>
#include <string>
#include <iomanip>
#include "House.h"

using namespace std;


House available[100] = {};
int houseNumber = 0;
char choice = 0;
float price = 0;
int bedrooms = 0;
string city;

static void case1(int houseNumber);
static void case2(int houseNumber);
static void case3(int houseNumber);
static void case4(int houseNumber);
static void noPreference(int houseNumber);

static void case1(int houseNumber)
{
    cout << "Enter Maximum Price: ";
    cin >> price;
    cout << "Enter Minimum Number of Bedrooms: ";
    cin >> bedrooms;

    for (int i = 0; i <= houseNumber; i++)
    {
        if (available[i].SearchByPriceAndBedrooms(price, bedrooms))
        {
            available[i].displayInfo();
        }
    }
}

static void case2(int houseNumber)
{
    

    int lowestPrice = 0;
    for (int i = 0; i <= houseNumber; i++)
    {
        if (available[i].getPrice() < available[lowestPrice].getPrice())
        {
            lowestPrice = i;
        }
    }
    cout << "The cheapest House available is: " << endl;
    available[lowestPrice].displayInfo();
}

static void case3(int houseNumber)
{
   

    int maxBedrooms = 0;
    for (int i = 0; i <= houseNumber; i++)
    {
        if (available[i].getRooms() > available[maxBedrooms].getRooms())
        {
            maxBedrooms = i;
        }
    }

    cout << "The house with the maximum number of bedrooms: " << endl;
    available[maxBedrooms].displayInfo();
}

static void case4(int houseNumber)
{
    cout << "Enter the city to find the best houses: ";
    cin.ignore(); 
    getline(cin, city); 
    cout << "Enter Maximum Price: ";
    cin >> price;
    cout << "Enter Minimum Number of Bedrooms: ";
    cin >> bedrooms;

    bool found = false;

    for (int i = 0; i <= houseNumber; i++)
    {
        if (available[i].getAddress() == city && available[i].SearchByPriceAndBedrooms(price, bedrooms))
        {
            cout << "House " << i + 1 << " is the best match for your family: " << endl;
            available[i].displayInfo();
            found = true;
        }
    }

    if (!found) {
        cout << "No houses found in " << city << " with the specified criteria." << endl;
    }
}

static void noPreference(int houseNumber)
{
    if (houseNumber == 0) {
        cout << "No houses available." << endl;
        return;
    }

    for (int i = 0; i <= houseNumber; i++)
    {
        available[i].displayInfo();
    }
}

int main()
{
    do
    {
        available[houseNumber].readInfo();
        cout << "Do you want to enter more houses? press y/Y " << endl;
        cin >> choice;
        if ((choice == 'y' || choice == 'Y') && houseNumber < 100)
        {
            houseNumber++;
        }
        cin.ignore(); 

    } while ((choice == 'y' || choice == 'Y') && houseNumber < 100);

    choice = 0;
    cout << "Welcome to R real estate to find a perfect house for you!" << endl;

    do {
        cout << setw(20) << "Press \n1. to search by price and number of Bedrooms\n2. to show the lowest price House\n3. To Show the Largest House\n4. To search By City \n?. to indicate no preference\nX/x to exit!" << endl;
        cin >> choice;

        if (choice == '1')
        {
            case1(houseNumber);
        }
        else if (choice == '2')
        {
            case2(houseNumber);
        }
        else if (choice == '3')
        {
            case3(houseNumber);
        }
        else if (choice == '4')
        {
            case4(houseNumber);
        }
        else if (choice == '?')
        {
            noPreference(houseNumber);
        }

    } while (choice != 'x');

    return 0;
}
