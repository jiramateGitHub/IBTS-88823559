#include"LinkedList.h"
#include <ctime>
#include<fstream>
void readfile(string station1,string station2,LinkedList *obj) {
	string line;
	string str_station[10];
	int int_station[3];
	fstream file;
	file.open(station1.c_str());
	while(getline(file,line)) {
		for(int i=0; i<10; i++) {
			if(i == 3 || i == 4) {
				str_station[i] = line.substr(0,line.find(" "));
				line = line.erase(0,line.find(" ")+1);
			} else {
				str_station[i] = line.substr(0,line.find(","));
				line = line.erase(0,line.find(",")+1);
			}
		}
		int_station[0] = atoi(str_station[0].c_str());
		obj->add(int_station[0],str_station[1],str_station[2],str_station[3],str_station[4],str_station[5],str_station[6],str_station[7],str_station[8],str_station[9]);
	}
	file.close();
	file.open(station2.c_str());
	while(getline(file,line)) {
		for(int i=0; i<3; i++) {
			str_station[i] = line.substr(0,line.find(","));
			line = line.erase(0,line.find(",")+1);
			int_station[i] = atoi(str_station[i].c_str());
		}
		obj->add(int_station[0],int_station[1],int_station[2]);
	}
	file.close();
}
int main() {
	LinkedList *A = new LinkedList();
	LinkedList *B = new LinkedList();
	LinkedList log;
	readfile("Astations.dat","Adetail.dat",A);
	readfile("Bstations.dat","Bdetail.dat",B);
	////////////// LOGIN /////////////////
	time_t Begin,End;
	string id,password,type;
	int rowerror = 0;
      	
	time(&Begin);
	pass:
	cout << "======================================" << endl;
	cout << "Username : ";
	cin >> id;
	cout << "Password : ";
	cin >> password;
	time(&End);
	if(difftime(End,Begin) > 120){
		cout << "Time Out!!" << endl;
		return 0;
	}	
	if(log.login(id,password) == 1){
		type = "admin";		
	}else if(log.login(id,password) == 2){
		type = "staff";
	}else{
		cout << "You have entered the user name or password incorrectly." << endl;
		rowerror++;
		if(rowerror < 3){
			goto pass;
		}else{
			cout << "Maximum value of ID and PW errors = 3" << endl;
			return 0;
		}	
	}
	///////////////////////////////////////		
	int choice2,choice,price,amount,number;
	string station,station2;
	string prefix,fname,lname;
	string status,str_price;
	string ic,park,shop;
	string group;

	do {
		if(type == "admin"){
			cout << "================ MENU ===============" << endl;
			cout << "\t 1) Show All Station" << endl;
			cout << "\t 2) Add New Station" << endl;
			cout << "\t 3) Save Data" << endl;
			cout << "\t 4) Calculate transport rate" << endl;
			cout << "\t 5) Update/Edit Station Data" << endl;
			cout << "\t 6. Search Station Data" << endl;
			cout << "\t 0) Exit" << endl;
			cout << "================ MENU ===============" << endl;
			cout << "Enter Menu : ";
			cin >> choice;
		}else{
			cout << "================ MENU ===============" << endl;
			cout << "\t 1) Show All Station" << endl;
			cout << "\t 2) Calculate transport rate" << endl;
			cout << "\t 3) Search Station Data" << endl;
			cout << "\t 0) Exit" << endl;
			cout << "================ MENU ===============" << endl;
			cout << "Enter Menu : ";
			cin >> choice2;

		}
		if(choice == 1 || choice2 == 1) {
			cout << "==================== Stations A ======================================"<< endl;
			cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
			cout << "======================================================================" << endl;
			A->show_Count();
			cout << "======================================================================" << endl;
			A->show();
			cout << "======================================================================" << endl;
			cout << endl;
			cout << "==================== Stations B ======================================"<< endl;
			cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
			cout << "======================================================================" << endl;
			B->show_Count();
			cout << "======================================================================" << endl;
			B->show();
		}
		if(choice == 2) {
			amount = 0;
			cout << "Enter Station Group (A or B): ";
			cin >> group;
			cout << "Enter Station Name : ";
			cin >> station;
			cout << "Enter Station Short-Name : ";
			cin >> station2;
			cout << "Enter Prefix : ";
			cin >> prefix;
			cout << "Enter first name : ";
			cin >> fname;
			cout << "Enter last name : ";
			cin >> lname;
			cout << "Price : ";
			cin >> price;
			cout << "Station Status (1=Act. or 0=Non-Act.): ";
			cin >> status;
			cout << "Station Information Center (1=Act. or 0=Non-Act.): ";
			cin >> ic;
			cout << "Station Parking (1=Act. or 0=Non-Act.): ";
			cin >> park;
			cout << "Station iBST Shop (1=Act. or 0=Non-Act.): ";
			cin >> shop;
			if(ic == "1") {
				ic = "i";
			} else {
				ic = "-";
			}
			if(park == "1") {
				park = "p";
			} else {
				park = "-";
			}
			if(shop == "1") {
				shop = "s";
			} else {
				shop = "-";
			}

			if(group == "A") {
				A->add(A->size()+1,station,station2,prefix,fname,lname,status,ic,park,shop);
				A->add(A->size(),price,amount);
				cout << "==================== Stations A ======================================"<< endl;
				cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
				cout << "======================================================================" << endl;
				A->show_Count();
				cout << "======================================================================" << endl;
				A->show();
			}
			if(group == "B") {
				B->add(B->size()+1,station,station2,prefix,fname,lname,status,ic,park,shop);
				B->add(B->size(),price,amount);
				cout << "==================== Stations A ======================================"<< endl;
				cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
				cout << "======================================================================" << endl;
				B->show_Count();
				cout << "======================================================================" << endl;
				B->show();
			}
		}
		if(choice == 3) {
			A->savefile("A");
			B->savefile("B");
		}
		if(choice == 4 || choice2 == 2) {
			int pay = 0;
			string group_start,group_end;
			int id_start,id_end;
			
			cout << "Select Origin Station Group (A or B) : ";
			cin >> group_start;
			if(group_start == "A") {
				cout << "==================== Stations A ===================================="<< endl;
				A->show_group();
			} else if(group_start == "B") {
				cout << "==================== Stations B ===================================="<< endl;
				B->show_group();
			}
			cout << "Select Origin Station : ";
			cin >> id_start;
			cout << "Select Destination Station Group (A or B) : ";
			cin >> group_end;
			if(group_end == "A") {
				cout << "==================== Stations A ===================================="<< endl;
				A->show_group();
			} else if(group_end == "B") {
				cout << "==================== Stations B ===================================="<< endl;
				B->show_group();
			}
			cout << "Select Destination Station	: ";
			cin >> id_end;
			if(group_start == group_end) { //A
				if(group_start == "A") {
					pay = A->calculate(id_start,id_end,1);
				}
				if(group_start == "B") {
					pay = B->calculate(id_start,id_end,1);
				}
			} else {
				if(group_start == "A" && group_end == "B") {
					cout << "Price rate = Station A (";
					pay = A->calculate(id_start,A->find_Interchange(),1); 
					cout << ") + " << endl;
					cout << "Station B (";
					pay += B->calculate(B->find_Interchange(),id_end,2);
					cout << ") " << endl;
				}
				if(group_start == "B" && group_end == "A") {
					cout << "Price rate = Station B (";
					pay = B->calculate(id_start,B->find_Interchange(),1);
					cout << ") + " << endl;
					cout << "Station A (";
				    pay += A->calculate(A->find_Interchange(),id_end,2);
					cout << ") " << endl;
				}
			}
			cout << "\n Interchange Station have calculated  : " << pay << " Baht." << endl;
		}
		if(choice == 5) {
			string detail;
			int check5 = 1;
			cout << "================ Update/Edit Station Data ===============" << endl;
			cout << "Group Stations (A or B) : ";
			cin >> group;
			if(group == "A") {
				cout << "==================== Stations A ======================================"<< endl;
				cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
				cout << "======================================================================" << endl;
				A->show_Count();
				cout << "======================================================================" << endl;
				A->show();
				cout << "======================================================================" << endl;
			} else if(group == "B") {
				cout << "==================== Stations B ======================================"<< endl;
				cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
				cout << "======================================================================" << endl;
				B->show_Count();
				cout << "======================================================================" << endl;
				B->show();
				cout << "======================================================================" << endl;
			}
			cout << "Select Station	 : ";
			cin >> number;
			if(group == "A" && !A->getStation(number)) {
				cout << "No Data!!" << endl;
				check5 = -1;
			} else if(group == "B" && !B->getStation(number)) {
				cout << "No Data!!" << endl;
				check5 = -1;
			}
			if(check5 == 1) {
				cout << "=============================" << endl;
				cout << "  # Detail"<< endl;
				cout << "=============================" << endl;
				cout << "1. Station Name" << endl;
				cout << "2. Short title	" << endl;
				cout << "3. Status" << endl;
				cout << "4. Information Center" << endl;
				cout << "6. Shop" << endl;
				cout << "7. Prefix" << endl;
				cout << "8. Chief of Staff" << endl;
				cout << "9. Price" << endl;
				cout << "=============================" << endl;
				cout << "Select Detail to edit : ";
				cin >> detail;
				if(detail == "1") {
					cout << "Enter Station Name : ";
					cin >> station;
					if(group == "A") {
						A->edit(number,"station",station);
					} else if(group == "B") {
						B->edit(number,"station",station);
					}
				}
				if(detail == "2") {
					cout << "Enter Short title : ";
					cin >> station2;
					if(group == "A") {
						A->edit(number,"station2",station2);
					} else if(group == "B") {
						B->edit(number,"station2",station2);
					}
				}
				if(detail == "3") {
					cout << "Enter Status (1=Act. or 0=Non-Act.) : ";
					cin >> status;
					if(group == "A") {
						A->edit(number,"status",status);
					} else if(group == "B") {
						B->edit(number,"status",status);
					}
				}
				if(detail == "4") {
					cout << "Enter Information Center (1=Act. or 0=Non-Act.) : ";
					cin >> ic;
					if(group == "A") {
						A->edit(number,"ic",ic);
					} else if(group == "B") {
						B->edit(number,"ic",ic);
					}
				}
				if(detail == "4") {
					cout << "Enter Information Center (1=Act. or 0=Non-Act.) : ";
					cin >> ic;
					if(group == "A") {
						A->edit(number,"ic",ic);
					} else if(group == "B") {
						B->edit(number,"ic",ic);
					}
				}
				if(detail == "5") {
					cout << "Enter Parking (1=Act. or 0=Non-Act.) : ";
					cin >> park;
					if(group == "A") {
						A->edit(number,"park",park);
					} else if(group == "B") {
						B->edit(number,"park",park);
					}
				}
				if(detail == "6") {
					cout << "Enter Shop (1=Act. or 0=Non-Act.) : ";
					cin >> shop;
					if(group == "A") {
						A->edit(number,"shop",shop);
					} else if(group == "B") {
						B->edit(number,"shop",shop);
					}
				}
				if(detail == "7") {
					cout << "Enter Prefix : ";
					cin >> prefix;
					if(group == "A") {
						A->edit(number,"prefix",prefix);
					} else if(group == "B") {
						B->edit(number,"prefix",prefix);
					}
				}
				if(detail == "8") {
					cout << "Enter Chief of Staff : ";
					cin >> fname;
					cin >> lname;
					if(group == "A") {
						A->edit(number,"fname",fname);
						A->edit(number,"lname",lname);
					} else if(group == "B") {
						B->edit(number,"fname",fname);
						B->edit(number,"lname",lname);
					}
				}
				if(detail == "9") {
					cout << "Enter Price : ";
					cin >> str_price;
					if(group == "A") {
						A->edit(number,"price",str_price);
					} else if(group == "B") {
						B->edit(number,"price",str_price);
					}
				}
			}
		}
		if(choice == 6 || choice2 == 3) {
			int search_type;
			cout << "============== Selecting Search Type ==============" << endl;
			cout << "1. Most expensive" << endl;
			cout << "2. Minimal price" << endl;
			cout << "3. Most Destination Selected" << endl;
			cout << "4. Minimal Destination Selected " << endl;
			cout << "===================================================" << endl;
			cout << "Selecting Search Type : ";
			cin >> search_type;
			cout << "Group Stations (A or B) : ";
			cin >> group;
			if(search_type == 1) {
				if(group == "A") {
					cout << "==================== Stations A ======================================"<< endl;
					cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
					cout << "======================================================================" << endl;
					A->search(search_type);
				} else if(group == "B") {
					cout << "==================== Stations B ======================================"<< endl;
					cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
					cout << "======================================================================" << endl;
					B->search(search_type);
				}
			} else if(search_type == 2) {
				if(group == "A") {
					cout << "==================== Stations A ======================================"<< endl;
					cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
					cout << "======================================================================" << endl;
					A->search(search_type);
				} else if(group == "B") {
					cout << "==================== Stations B ======================================"<< endl;
					cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
					cout << "======================================================================" << endl;
					B->search(search_type);
				}
			} else if(search_type == 3) {
				if(group == "A") {
					cout << "==================== Stations A ======================================"<< endl;
					cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
					cout << "======================================================================" << endl;
					A->search(search_type);
				} else if(group == "B") {
					cout << "==================== Stations B ======================================"<< endl;
					cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
					cout << "======================================================================" << endl;
					B->search(search_type);
				}
			} else if(search_type == 4) {
				if(group == "A") {
					cout << "==================== Stations A ======================================"<< endl;
					cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
					cout << "======================================================================" << endl;
					A->search(search_type);
				} else if(group == "B") {
					cout << "==================== Stations B ======================================"<< endl;
					cout << "ID\tStation Name\t\tStatus\t\tInformation Center\tParking\t\tiBST Shop\tPrefix\t\tCheif of Staff" << endl;
					cout << "======================================================================" << endl;
					B->search(search_type);
				}
			}
		}
		choice2 = 99;
		if(choice2 == 0){
			choice = 0;
		}
	} while(choice != 0);
	return 0;
}
