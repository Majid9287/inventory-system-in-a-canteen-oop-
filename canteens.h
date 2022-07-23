#pragma once
#include <string>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;
class person{
protected:
	string name;
	string email;
	int age;
public:
	person();
	virtual void display() = 0;
	void setname(string n);
	void setemail(string n);
	void setage(int a);
	string getname();
	string getemail();
	int getage();
};


class biscuit{
protected:
	char*biscuit_name;
public:
	biscuit();
	void setbiscuit(char* n);
};
class lays{
protected:
	char* lays_name;
public:
	lays();
	void setlays(char* n);
};
class products : public lays, public biscuit{
protected:
	int quantity_name;
	int price_name;
public:
	products();
	void setprice(int n);
	void setquantity(int n);
	void add_products(string file_name, string class_name, char* n, int pric, int qun);
	void viewproducts(string file_name);
	int buy_products(string file_name, string n, int qun, int payes);
	void bill_of_buy_products();
	void edit_products(string n, int edit_price, int edit_qunatity, string file_name);

	void delet_products(string file_name, char* n);



};
class custmer{
protected:
	double custmer_ID;
	products* obj;
public:
	custmer();
	void setcustmer_ID(double n);

	double getcustmer_ID();
	void viewProducts(string name);

	int buyProducts(string file_name, string product_name, int qun, int bill);
	void bill();

};
class Canteen_owner :public person{
protected:
	double Canteen_registration_num;
	products* obj;
public:

	void viewProducts(string name);

	void sallesBILL();
	void display();
};
class Canteen_employe :public person{
protected:
	int salery;
	products* obj;
public:
	Canteen_employe();
	void addProducts(string file_name, string class_name, char* product_name, int pric, int qun);
	void deletProducts(string file_name, char* product_name);

	void editProducts(string product_name, int edit_price, int edit_qunatity, string file_name);
	void seenPdroducts(string file_name);

	void display();
	void setsalery(int s);
};