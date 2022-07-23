#include <string>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "canteens.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

int main(){
	// MENUE

	person *p;
	

	string for_biscuit_file = "biscuit.txt";
	string for_lays_file = "lays.txt";
	string for_call_biscuit = "biscuit";
	string for_call_lays = "lays";
	int	press1 = 0;
	do{
		cout << "PRESS-->>(<1>)   FOR <<CUSTOMER MENU>>" << endl;
		cout << "PRESS-->>(<2>)   FOR <<EMPLOYEE MENU>>" << endl;
		cout << "PRESS-->>(<3>)   FOR <<OWNER MENU>>   " << endl;
		cout << "PRESS-->>(<4>)   FOR <<SYSTEM EXIT>>  " << endl;
		cin >> press1;
		if (press1 == 1)//CUSTOMER MENUE
		{
		
			custmer c;
			
			int totalbill = 0;
			int press2 = 0;
			do{


				cout << "PRESS-->>(<1>)   FOR <<PRODUCTS MENU >>     " << endl;
				cout << "PRESS-->>(<2>)   FOR <<BUY_PRODUCTS>>       " << endl;
				cout << "PRESS-->>(<3>)   FOR <<BILL OF PRODUCTS>>   " << endl;
				cout << "PRESS-->>(<4>)   FOR <<SYSTEM BACK>> >>     " << endl;
				cin >> press2;
				if (press2 > 4){
					cout << "NOTE!!<<<you pressed invalid value>>" << endl;
					cin >> press2;

				}
				else if (press2 == 1){
					int press3 = 0;
					do{                             //view
						cout << "PRESS-->>(<1>)   FOR <<VIEW ALL PRODUCTS>>     " << endl;
						cout << "PRESS-->>(<2>)   FOR <<BISCUIT_PRODUCTS>>       " << endl;
						cout << "PRESS-->>(<3>)   FOR <<LAYS PRODUCTS>>   " << endl;
						cout << "PRESS-->>(<4>)   FOR <<SYSTEM BACK>> >>     " << endl;
						cin >> press3;
						if (press3 > 4){
							cout << "NOTE!!<<<you pressed invalid value>>" << endl;
							cin >> press3;

						}
						else if (press3 == 1){
							c.viewProducts(for_biscuit_file);
							c.viewProducts(for_lays_file);
						}
						else if (press3 == 2){
							c.viewProducts(for_biscuit_file);
						}
						else if (press3 == 3){
							c.viewProducts(for_lays_file);
						}
					} while (press3 != 4);
				}
				else if (press2 == 2)
				{
					string product_name;
					int quantity = 0;

					int press4 = 0;
					do{                                          //buy
						cout << "PRESS-->>(<1>)   FOR <<BISCUIT_PRODUCTS>>       " << endl;
						cout << "PRESS-->>(<2>)   FOR <<LAYS PRODUCTS>>   " << endl;
						cout << "PRESS-->>(<3>)   FOR <<SYSTEM BACK>> >>     " << endl;
						cin >> press4;
						if (press4 > 3){
							cout << "\nNOTE!!<<<you pressed invalid value>>" << endl;
							cin >> press4;

						}
						else if (press4 == 1){
							c.viewProducts(for_biscuit_file);
							cout << "ENTER THE NAME OF PRODUCT WHICH YOU WANT TO BUY -->NOTE!PLEASE ENTER CORRECT NAME<<OTHERWISE SYSTEM SHOW ERROR" << endl;
							cin >> product_name;
							cout << "\nENTER THE quantity " << endl;
							cin >> quantity;


							totalbill = c.buyProducts(for_biscuit_file, product_name, quantity, totalbill);

						}
						else if (press4 == 2){
							c.viewProducts(for_lays_file);
							cout << "ENTER THE NAME OF PRODUCT WHICH YOU WANT TO BUY -->NOTE!PLEASE ENTER CORRECT NAME<<OTHERWISE SYSTEM SHOW ERROR" << endl;
							cin >> product_name;
							cout << "\nENTER THE quantity " << endl;
							cin >> quantity;
							totalbill = c.buyProducts(for_lays_file, product_name, quantity, totalbill);
						}
					} while (press4 != 3);
				}
				else if (press2 == 3)//bill
				{
					c.bill();
					cout << "         total=            " << totalbill << endl;
					cout << "-----------------------------------------------" << endl;
				}
			} while (press2 != 4);
		}//CUSTOMER MENUE end.
		if (press1 == 2){
			person *p;
			Canteen_employe m;
			p = &m;
			Canteen_employe M;
			int press5 = 0;
			do{
				cout << "PRESS-->>(<1>)   FOR <<set EMPLOYEE INFORMATION>>" << endl;
				cout << "PRESS-->>(<2>)   FOR <<Get EMPLOYEE INFORMATION>> NOTE! PLEASE SET INFORMATION BEFORE GET INFORMATION <<OTHERWISE SYSTEM SHOW ERROR" << endl;
				cout << "PRESS-->>(<3>)   FOR <<ADD PRODUCTS   >>" << endl;
				cout << "PRESS-->>(<4>)   FOR <<DELETE PRODUCTS   >>" << endl;
				cout << "PRESS-->>(<5>)   FOR <<EDIT PRODUCTS   >>" << endl;
				cout << "PRESS-->>(<6>)   FOR <<SYSTEM EXIT>> >>" << endl;
				cin >> press5;
				if (press5 > 6){
					cout << "NOTE!!<<<you pressed invalid value>>" << endl;
					cin >> press5;

				}
				if (press5 == 1)
				{
					string name, email;
					int age, salery;
					cout << "enter employee name:  " << endl;
					cin >> name;
					cout << "enter employee age:   " << endl;
					cin >> age;
					cout << "enter employee mail:  " << endl;
					cin >> email;
					cout << "enter employee salery:" << endl;
					cin >> salery;
					p->setname(name);
					p->setemail(email);
					p->setage(age);
					M.setsalery(2300);
				}
				else if (press5 == 2)
				{
					p->display();
				}
				else if (press5 == 3)//add products
				{
					int press6 = 0;
					char pname[20];
					int pri = 0, qunt = 0;
					do{
						cout << "PRESS-->>(<1>)   FOR <<BISCUIT_PRODUCTS>>       " << endl;
						cout << "PRESS-->>(<2>)   FOR <<LAYS PRODUCTS>>   " << endl;
						cout << "PRESS-->>(<3>)   FOR <<SYSTEM BACK>> >>     " << endl;
						cin >> press6;
						if (press6 > 3){
							cout << "NOTE!!<<<you pressed invalid value>>" << endl;
							cin >> press6;

						}
						else if (press6 == 1){
							cout << "ENTER THE NAME OF PRODUCT -->NOTE!PLEASE ENTER CORRECT NAME << OTHERWISE SYSTEM SHOW ERROR" << endl;
							cin.ignore();
							cin.getline(pname, 20);
							cout << "\nENTER THE price OF PRODUCT" << endl;
							cin >> pri;
							cout << "\nENTER THE quantity OF PRODUCT" << endl;
							cin >> qunt;
							M.addProducts(for_biscuit_file, for_call_biscuit, pname, pri, qunt);
						}
						else if (press6 == 2){
							cout << "ENTER THE NAME OF PRODUCT-->NOTE!PLEASE ENTER CORRECT NAME<<OTHERWISE SYSTEM SHOW ERROR" << endl;
							cin.ignore();
							cin.getline(pname, 20);
							cout << "\nENTER THE price OF PRODUCT" << endl;
							cin >> pri;
							cout << "\nENTER THE quantity OF PRODUCT" << endl;
							cin >> qunt;
							M.addProducts(for_lays_file, for_call_lays, pname, pri, qunt);
						}
					} while (press6 != 3);
				}
				else if (press5 == 4)//delete
				{
					char pname[20];
					int press7 = 0;
					do{
						cout << "PRESS-->>(<1>)   FOR <<BISCUIT_PRODUCTS>>       " << endl;
						cout << "PRESS-->>(<2>)   FOR <<LAYS PRODUCTS>>   " << endl;
						cout << "PRESS-->>(<3>)   FOR <<SYSTEM BACK>> >>     " << endl;
						cin >> press7;
						if (press7 > 3){
							cout << "NOTE!!<<<you pressed invalid value>>" << endl;
							cin >> press7;

						}
						else if (press7 == 1){
							M.seenPdroducts(for_biscuit_file);
							cout << "ENTER THE NAME OF PRODUCT-->NOTE!PLEASE ENTER CORRECT NAME<<OTHERWISE SYSTEM SHOW ERROR" << endl;
							cin.ignore();
							cin.getline(pname, 20);
							M.deletProducts(for_biscuit_file, pname);
						}
						else if (press7 == 2){
							M.seenPdroducts(for_lays_file);
							cout << "ENTER THE NAME OF PRODUCT-->NOTE!PLEASE ENTER CORRECT NAME<<OTHERWISE SYSTEM SHOW ERROR" << endl;
							cin.ignore();
							cin.getline(pname, 20);
							M.deletProducts(for_lays_file, pname);
						}
					} while (press7 != 3);
				}
				else if (press5 == 5)//edit
				{
					string pname;
					int edit_qunatity, edit_price;
					int press8 = 0;
					do{
						cout << "PRESS-->>(<1>)   FOR <<BISCUIT_PRODUCTS>>       " << endl;
						cout << "PRESS-->>(<2>)   FOR <<LAYS PRODUCTS>>   " << endl;
						cout << "PRESS-->>(<3>)   FOR <<SYSTEM BACK>> >>     " << endl;
						cin >> press8;
						if (press8 > 3){
							cout << "NOTE!!<<<you pressed invalid value>>" << endl;
							cin >> press8;

						}
						else if (press8 == 1){
							M.seenPdroducts(for_biscuit_file);
							cout << "ENTER THE NAME OF PRODUCT-->NOTE!PLEASE ENTER CORRECT NAME<<OTHERWISE SYSTEM SHOW ERROR" << endl;
							cin >> pname;
							cout << "\nENTER THE price OF PRODUCT" << endl;
							cin >> edit_price;
							cout << "\nENTER THE quantity OF PRODUCT" << endl;
							cin >> edit_qunatity;

							M.editProducts(pname, edit_price, edit_qunatity, for_biscuit_file);
						}
						else if (press8 == 2){
							M.seenPdroducts(for_lays_file);
							cout << "ENTER THE NAME OF PRODUCT-->NOTE!PLEASE ENTER CORRECT NAME<<OTHERWISE SYSTEM SHOW ERROR" << endl;
							cin >> pname;
							cout << "\nENTER THE price OF PRODUCT" << endl;
							cin >> edit_price;
							cout << "\nENTER THE quantity OF PRODUCT" << endl;
							cin >> edit_qunatity;

							M.editProducts(pname, edit_price, edit_qunatity, for_lays_file);

						}
					} while (press8 != 3);
				}
			} while (press5 != 6);
		}



		if (press1 == 3){
			int press9 = 0;
			person *p;
			Canteen_owner o;
			p = &o;
			Canteen_owner c;
			do{
				cout << "PRESS-->>(<1>)   FOR <<set owner INFORMATION>>" << endl;
				cout << "PRESS-->>(<2>)   FOR <<Get owner INFORMATION>> NOTE! PLEASE SET INFORMATION BEFORE GET INFORMATION <<OTHERWISE SYSTEM SHOW ERROR" << endl;
				cout << "PRESS-->>(<3>)   FOR <<view PRODUCTS>>        " << endl;
				cout << "PRESS-->>(<4>)   FOR <<view bill>>            " << endl;
				cout << "PRESS-->>(<5>)   FOR <<SYSTEM EXIT>>          " << endl;
				cin >> press9;
				if (press9 > 5){
					cout << "NOTE!!<<<you pressed invalid value>>" << endl;
					cin >> press9;

				}
				else if (press9 == 1){
					string name, email;
					int age;
					cout << "enter employee name:  " << endl;
					cin >> name;
					cout << "enter employee age:   " << endl;
					cin >> age;
					cout << "enter employee mail:  " << endl;
					cin >> email;
					p->setname(name);
					p->setemail(email);
					p->setage(age);
				}
				else if (press9 == 2){
					p->display();
				}
				else if (press9 == 3){
					int press10 = 0;
					do{                             //view
						cout << "PRESS-->>(<1>)   FOR <<VIEW ALL PRODUCTS>>     " << endl;
						cout << "PRESS-->>(<2>)   FOR <<BISCUIT_PRODUCTS>>       " << endl;
						cout << "PRESS-->>(<3>)   FOR <<LAYS PRODUCTS>>   " << endl;
						cout << "PRESS-->>(<4>)   FOR <<SYSTEM BACK>> >>     " << endl;
						cin >> press10;
						if (press10 > 4){
							cout << "NOTE!!<<<you pressed invalid value>>" << endl;
							cin >> press10;

						}
						else if (press10 == 1){
							c.viewProducts(for_biscuit_file);
							c.viewProducts(for_lays_file);
						}
						else if (press10 == 2){
							c.viewProducts(for_biscuit_file);
						}
						else if (press10 == 3){
							c.viewProducts(for_lays_file);
						}
					} while (press10 != 4);
				}
				else if (press9 == 4){
					c.sallesBILL();
				}
			} while (press9 != 5);
		}

	} while (press1 != 4 && press1 >!4);
	system("pause");
	return 0;
}
