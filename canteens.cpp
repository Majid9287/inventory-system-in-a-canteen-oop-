#include "canteens.h"
#include <string>
#include <fstream>
#include "canteens.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;


person::person(){
	name = '\0';
	email = '\0';
	age = 0;
}

void person::setname(string n){
	name = n;
}
void person::setemail(string n){
	email = n;
}
void person::setage(int a){
	age = a;
}
string person::getname(){
	return name;
}
string person::getemail(){
	return	email;
}
int person::getage(){
	return age;
}




biscuit::biscuit(){
	biscuit_name = NULL;
}
void biscuit::setbiscuit(char* n){
	int length = 0;
	while (1)
	{
		if (n[length] == '\0')
			break;

		length++;
	}

	biscuit_name = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		biscuit_name[i] = n[i];
	}

	biscuit_name[length] = '\0';
}



lays::lays(){
	lays_name = NULL;
}
void lays::setlays(char* n){
	int length = 0;
	while (1)
	{
		if (n[length] == '\0')
			break;

		length++;
	}

	lays_name = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		lays_name[i] = n[i];
	}

	lays_name[length] = '\0';
}


products::products(){
	quantity_name = 0;
	price_name = 0;
}
void products::setprice(int n){
	price_name = n;
}
void products::setquantity(int n){
	quantity_name = n;
}
void products::add_products(string file_name, string class_name, char* n, int pric, int qun){
	string name[100];
	int p[100], q[100];

	if (class_name == "biscuit"){
		setbiscuit(n);
	}
	if (class_name == "lays"){
		setlays(n);
	}
	setprice(pric), setquantity(qun);
	int counter = 0;
	ifstream in_file(file_name);

	for (int i = 0; !in_file.eof(); i++){
		in_file >> name[i] >> p[i] >> q[i];
		counter++;
	}
	counter--;
	in_file.close();
	ofstream out_file(file_name);
	for (int i = 0; i < counter; i++){
		out_file << name[i] << ' ' << p[i] << ' ' << q[i] << endl;
	}
	if (class_name == "biscuit"){
		out_file << biscuit_name << ' ' << price_name << ' ' << quantity_name << endl;
	}
	if (class_name == "lays"){
		out_file << biscuit_name << ' ' << price_name << ' ' << quantity_name << endl;
	}

	out_file.close();

}
void products::viewproducts(string file_name){
	string name[100];
	int p[100], q[100];

	int counter = 0;
	ifstream in_file(file_name);

	for (int i = 0; !in_file.eof(); i++){
		in_file >> name[i] >> p[i] >> q[i];
		counter++;
	}
	cout << "---------------------------------------------------------------" << endl;
	cout << "      products           price            quantity" << endl;
	for (int i = 0; i < counter - 1; i++){
		cout << "         " << name[i] << "                " << p[i] << "                " << q[i] << endl;
		cout << "---------------------------------------------------------------" << endl;
	}
	in_file.close();
}
int products::buy_products(string file_name, string n, int qun, int payes){
	int total_pay = 0;
	string name[100];
	int p[100], q[100];
	int counter = 0;
	string billproducts[50];
	int billpric[50];
	int	billcount = 0;


	ifstream in_file(file_name);
	for (int i = 0; !in_file.eof(); i++){
		in_file >> name[i] >> p[i] >> q[i];
		counter++;
	}
	counter--;
	in_file.close();


	ifstream bill_file("bill.txt");
	for (int i = 0; !bill_file.eof(); i++){
		bill_file >> billproducts[i] >> billpric[i];
		billcount++;
	}
	bill_file.close();
	ofstream ofbill_file("bill.txt");
	for (int i = 0; i < billcount - 1; i++){
		ofbill_file << billproducts[i] << ' ' << billpric[i] << endl;
	}

	for (int i = 0; i < counter; i++){
		if (name[i] == n){
			ofbill_file << name[i] << ' ' << p[i] << endl;
			total_pay = total_pay + qun*p[i];
			int edit_qunatity = q[i] - qun;

			edit_products(name[i], p[i], edit_qunatity, file_name);

		}



	}
	ofbill_file.close();
	counter = 0;
	billcount = 0;
	total_pay += payes;
	return total_pay;
}
void products::bill_of_buy_products(){

	cout << "bill" << endl;
	string name[100];
	int p[100];
	int counter = 0;
	ifstream in_file("bill.txt");
	for (int i = 0; !in_file.eof(); i++){
		in_file >> name[i] >> p[i];
		counter++;
	}
	for (int i = 0; i < counter - 1; i++){
		cout << "         " << name[i] << "           " << p[i] << endl;
		cout << "-----------------------------------------------" << endl;
	}
	in_file.close();
}
void products::edit_products(string n, int edit_price, int edit_qunatity, string file_name){
	string name[100];
	int p[100], q[100];
	int counter = 0;
	ifstream in_file(file_name);
	for (int i = 0; !in_file.eof(); i++){
		in_file >> name[i] >> p[i] >> q[i];
		counter++;
	}

	in_file.close();
	ofstream 	out_file(file_name);
	for (int i = 0; i < counter - 1; i++){
		if (name[i] == n){
			out_file << n << ' ' << edit_price << ' ' << edit_qunatity << endl;
		}
		else
		{
			out_file << name[i] << ' ' << p[i] << ' ' << q[i] << endl;
		}
	}
	out_file.close();

}

void products::delet_products(string file_name, char* n){
	string name[100];
	int p[100], q[100];

	int counter = 0;
	ifstream in_file(file_name);
	for (int i = 0; !in_file.eof(); i++){
		in_file >> name[i] >> p[i] >> q[i];
		counter++;
	}
	counter--;
	in_file.close();
	ofstream out_file(file_name);
	for (int i = 0; i < counter; i++){
		if (name[i] != n){
			out_file << name[i] << ' ' << p[i] << ' ' << q[i] << endl;
		}
	}
	out_file.close();
}


custmer::custmer(){
	custmer_ID = 0;
}
void custmer::setcustmer_ID(double n){
	custmer_ID = n;
}
double custmer::getcustmer_ID(){
	return custmer_ID;
}
void custmer::viewProducts(string name){
	obj->viewproducts(name);
}
int custmer::buyProducts(string file_name, string product_name, int qun, int bill){
	return obj->buy_products(file_name, product_name, qun, bill);
}
void custmer::bill(){
	obj->bill_of_buy_products();
}


void Canteen_owner::viewProducts(string name){
	obj->viewproducts(name);
}
void Canteen_owner::sallesBILL(){
	obj->bill_of_buy_products();
}
void Canteen_owner::display(){
	cout << "---------------------------------------------------------------";
	cout << "      NAME    " << name << endl;
	cout << "---------------------------------------------------------------";
	cout << "      EMAIL   " << email << endl;
	cout << "---------------------------------------------------------------";
	cout << "      AGE     " << age << endl;
	cout << "---------------------------------------------------------------";
	cout << "      Canteen_registration_num" << Canteen_registration_num << endl;
	cout << "---------------------------------------------------------------";
}


Canteen_employe::Canteen_employe(){
	salery = 0;
}
void Canteen_employe::addProducts(string file_name, string class_name, char* product_name, int pric, int qun){
	obj->add_products(file_name, class_name, product_name, pric, qun);
}
void Canteen_employe::deletProducts(string file_name, char* product_name){
	obj->delet_products(file_name, product_name);
}
void Canteen_employe::editProducts(string product_name, int edit_price, int edit_qunatity, string file_name){
	obj->edit_products(product_name, edit_price, edit_qunatity, file_name);
}
void Canteen_employe::seenPdroducts(string file_name){
	obj->viewproducts(file_name);
}

void Canteen_employe::display(){
	cout << "---------------------------------------------------------------";
	cout << "     NAME        " << name << endl;
	cout << "---------------------------------------------------------------";
	cout << "     EMAIL       " << email << endl;
	cout << "---------------------------------------------------------------";
	cout << "     AGE         " << age << endl;
	cout << "---------------------------------------------------------------";
	cout << "     salery      " << salery << endl;
	cout << "---------------------------------------------------------------";
}
void Canteen_employe::setsalery(int s){
	salery = s;
}
