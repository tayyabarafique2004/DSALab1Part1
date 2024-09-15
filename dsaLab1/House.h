#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class House
{
private:
	string owner;
	string address;
	int numberOfBedrooms=0;
	float price=0;
public:
	void readInfo()
	{
	
		do
		{
			cout << "Enter Owner: ";
			getline(cin, owner);
			if (owner.size() > 20)
				cout << "Owner Name should be no more than 20 characters, Enter Again!" << endl;
		} while (owner.size() > 20);
		
		do
		{
			cout << "Enter Address(CITY): ";
			getline(cin, address);
			if (address.size() > 20)
				cout << "Address should be no more than 20 characters, Enter Again!" << endl;
		} while (address.size() > 20);
		cout << "Enter Bedrooms: ";
		cin >> numberOfBedrooms;
		cin.ignore();
		cout << "Enter Price: ";
		cin >> price;
	
		
	}
	void displayInfo() const
	{
		cout <<setw(20)<< "Owner: " <<setw(20) << "Address: "<<setw(20) << "Bedrooms: "<<setw(20) << " Price: "<<endl;
		cout << setw(20) << owner << setw(20) << address << setw(20)<< numberOfBedrooms << setw(20) << price<<endl<<endl;
	
	}
	bool SearchByPriceAndBedrooms(float maxPrice,int minRooms)const
	{
		return(price <= maxPrice && numberOfBedrooms >= minRooms);

	}
	float getPrice()const
	{
		return price;
	}
	int getRooms()const
	{
		return numberOfBedrooms;
	}
	string getAddress()
	{
		return address;
	}

};

