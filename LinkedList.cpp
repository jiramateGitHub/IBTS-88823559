#include "LinkedList.h"
LinkedList::LinkedList() {
	this->head = NULL;
	this->tail = NULL;
	count = 0;
	count_center = 0;
	count_park = 0;
	count_shop = 0;
}
LinkedList::~LinkedList() {
	for(int i=0 ; i< count; i++) {
		node *tmp = head;
		head = head->link;
		delete tmp;
		tmp = NULL;
	}
	this->head = NULL;
	this->tail = NULL;
}
void LinkedList::add(int number,string station,string station2,string prefix,string fname,string lname,string status,string ic,string park,string shop) {
	node *newNode = new node(number,station,station2,prefix,fname,lname,status,ic,park,shop);
	if(isEmpty()) {
		this->head = newNode;
		this->tail = newNode;
	} else {
		newNode->plink = tail;
		tail->link = newNode;
		tail = newNode;
	}
	if(newNode->center == "i") {
		count_center++;
	}
	if(newNode->park == "p") {
		count_park++;
	}
	if(newNode->shop == "s") {
		count_shop++;
	}
	count++;
}

void LinkedList::add(int number,int price,int amount) {
	node *temp = head;
	for(int i=1; i<number; i++) {
		temp = temp->link;
	}
	if(temp->number == number) {
		temp->price = price;
		temp->amount = amount;
	}
}
void LinkedList::show() {
	string station_show,status_show,status_center,status_park,status_shop;
	for(node * temp = head; temp != NULL; temp = temp->link) {
		if(temp->station == "Siam") {
			station_show = temp->station + "(" + temp->station2 + ") (Interchange)";
		} else {
			station_show = temp->station + "(" + temp->station2 + ")";
		}
		if(temp->status == "1") {
			status_show = "/";
		} else {
			status_show = "-";
		}
		if(temp->center == "i") {
			status_center = "/";
		} else {
			status_center = "-";
		}
		if(temp->park == "p") {
			status_park = "/";
		} else {
			status_park = "-";
		}
		if(temp->shop == "s") {
			status_shop = "/";
		} else {
			status_shop = "-";
		}
		cout << setw(8) << left << temp->number;
		cout << setw(24) << left << station_show;
		cout << setw(16) << left<< status_show;
		cout << setw(24) << left<< status_center;
		cout << setw(16) << left<< status_park;
		cout << setw(16) << left<< status_shop;
		cout << setw(16) << left<< temp->prefix;
		string fname;
		fname = temp->fname.substr(0,1) + ".";
		cout << setw(2) << left << fname << " " << temp->lname;
		cout << endl;
	}
	cout << endl;
}
void LinkedList::show_group() {
	string station_show;
	string non_station[count];
	int i = 0;
	cout << "ID\tStation Name\t\tPrice Per Station" << endl;
	cout << "=====================================================================" << endl;
	for(node * temp = head; temp != NULL; temp = temp->link) {
		if(temp->status == "1") {
			if(temp->station == "Siam") {
				station_show = temp->station + "(" + temp->station2 + ") (Interchange)";
			} else {
				station_show = temp->station + "(" + temp->station2 + ")";
			}
			cout << setw(8) << left << temp->number;
			cout << setw(24) << left << station_show;
			cout << setw(16) << left << temp->price;
			cout << endl;
		} else {
			non_station[i] = temp->station;
			i++;
		}
	}
	cout << "=====================================================================" << endl;
	cout << "*** Non-Active Stations :" << endl;
	for(int p=0; p<i; p++) {
		cout << "- " << non_station[p] << endl;
	}
	cout << "=====================================================================" << endl;
}
void LinkedList::savefile(string type) {
	string type1;
	if(type == "A" || type == "a") {
		type = "Astations.dat";
		type1 = "Adetail.dat";
		cout << "Save file A Completed!!!" << endl;
	} else if(type == "B" || type == "b") {
		type = "Bstations.dat";
		type1 = "Bdetail.dat";
		cout << "Save file B Completed!!!" << endl;
	}
	ofstream file;
	file.open(type.c_str());
	for(node * temp = head; temp!=NULL; temp = temp->link) {
		file << temp->number << ",";
		file << temp->station << ",";
		file << temp->station2 << ",";
		file << temp->prefix  << " ";
		file << temp->fname  << " ";
		file << temp->lname  << ",";
		file << temp->status << ",";
		file << temp->center << ",";
		file << temp->park << ",";
		file << temp->shop  << endl;
	}
	file.close();
	file.open(type1.c_str());
	for(node * temp = head; temp!=NULL; temp = temp->link) {
		file << temp->number << ",";
		file << temp->price << ",";
		file << temp->amount  << endl;
	}
	file.close();
}
int LinkedList::calculate(int start,int end,int type) {
	int sum = 0;
	int round = 1;
	if(start < end) {
		if(type == 2){
			start++;	
		}
		for(node * temp=head; temp!=NULL; temp = temp->link) {
			if(round >= start && round <= end) {
				cout << temp->station << "," << temp->price << " + ";
				sum += temp->price;
			}
			if(round == end) {
				break;
			}
			round++;
		}
	} else {
		if(type == 2){
			start--;	
		}
		round = count;
		for(node * temp=tail; temp!=NULL; temp = temp->plink) {
			if(round <= start && round >= end) {
				cout << temp->station << "," << temp->price << " + ";
				sum += temp->price;
			}
			if(round == end) {
				break;
			}
			round--;
		}
	}
	return sum;
}

int LinkedList::find_Interchange(){
	int i = 1;
	for(node * temp = head;temp!=NULL;temp = temp->link){
		if(temp->station == "Siam"){
			return i;
		}
		i++;
	}
	return -1;
}

void LinkedList::show_Count() {
	cout << "iBTS: " << count << " Station ";
	cout << "[Information Center = " << count_center << "| ";
	cout << "Parking = " << count_park << "| ";
	cout << "iBST Shop = " << count_shop << endl;
}

void LinkedList::edit(int number,string str,string detail) {
	for(node * temp=head; temp!=NULL; temp = temp->link) {
		if(temp->number == number) {
			if(str == "station") {
				temp->station = detail;
			} else if(str == "station2") {
				temp->station2 = detail;
			} else if(str == "status") {
				temp->status = detail;
			} else if(str == "ic") {
				if(detail == "1") {
					temp->center = "i";
				} else if(detail == "0") {
					temp->center = "-";
				}

			} else if(str == "park") {
				if(detail == "1") {
					temp->park = "p";
				} else if(detail == "0") {
					temp->park = "-";
				}
			} else if(str == "shop") {
				if(detail == "1") {
					temp->shop = "s";
				} else if(detail == "0") {
					temp->shop = "-";
				}
			} else if(str == "prefix") {
				temp->prefix = detail;
			} else if(str == "fname") {
				temp->fname = detail;
			} else if(str == "lname") {
				temp->lname = detail;
			} else if(str == "price") {
				temp->price = atoi(detail.c_str());
			}
		}
	}
}
bool LinkedList::isEmpty() {
	if(count == 0) {
		return true;
	} else {
		return false;
	}
}
int LinkedList::size() {
	return count;
}

bool LinkedList::getStation(int number) {
	for(node * temp=head; temp!=NULL; temp = temp->link) {
		if(number == temp->number) {
			return true;
		}
	}
	return false;
}
void LinkedList::search(int type) {
	int max,min;
	int num;
	int i = 1;
	if(type == 1) {
		for(node *temp = head; temp!=NULL; temp=temp->link) {
			if(i == 1) {
				num = temp->price;
			} else if(i <= count) {
				if(num > temp->price) {
					max = num;
				} else {
					max = temp->price;
					num = temp->price;
				}
			}
			i++;
		}
		show_search(max);
	}
	if(type == 2) {
		for(node *temp = head; temp!=NULL; temp=temp->link) {
			if(i == 1) {
				num = temp->price;
			} else if(i <= count) {
				if(num < temp->price) {
					min = num;
				} else {
					min = temp->price;
					num = temp->price;
				}
			}
			i++;
		}
		show_search(min);
	}
	if(type == 3) {
		for(node *temp = head; temp!=NULL; temp=temp->link) {
			if(i == 1) {
				num = temp->amount;
			} else if(i <= count) {
				if(num > temp->amount) {
					max = num;
				} else {
					max = temp->amount;
					num = temp->amount;
				}
			}
			i++;
		}
		show_search(max);
	}
	if(type == 4) {
		for(node *temp = head; temp!=NULL; temp=temp->link) {
			if(i == 1) {
				num = temp->amount;
			} else if(i <= count) {
				if(num < temp->amount) {
					min = num;
				} else {
					min = temp->amount;
					num = temp->amount;
				}
			}
			i++;
		}
		show_search(min);
	}
}

void LinkedList::show_search(int num) {
	string station_show,status_show,status_center,status_park,status_shop;
	for(node *temp = head; temp!=NULL; temp=temp->link) {
		if(temp->amount == num || temp->price == num) {
			if(temp->station == "Siam") {
				station_show = temp->station + "(" + temp->station2 + ") (Interchange)";
			} else {
				station_show = temp->station + "(" + temp->station2 + ")";
			}
			if(temp->status == "1") {
				status_show = "/";
			} else {
				status_show = "-";
			}
			if(temp->center == "i") {
				status_center = "/";
			} else {
				status_center = "-";
			}
			if(temp->park == "p") {
				status_park = "/";
			} else {
				status_park = "-";
			}
			if(temp->shop == "s") {
				status_shop = "/";
			} else {
				status_shop = "-";
			}
			cout << setw(8) << left << temp->number;
			cout << setw(24) << left << station_show;
			cout << setw(16) << left<< status_show;
			cout << setw(24) << left<< status_center;
			cout << setw(16) << left<< status_park;
			cout << setw(16) << left<< status_shop;
			cout << setw(16) << left<< temp->prefix;
			string fname;
			fname = temp->fname.substr(0,1) + ".";
			cout << setw(2) << left << fname << " " << temp->lname;
			cout << endl;
		}
	}
}
int LinkedList::login(string id,string pass){
	string temp_id,temp_pass,type;
	ifstream user; //read file
	user.open("login.dat");
	if(user.is_open()){
		while(user >> temp_id >> temp_pass >> type){
			if(id == temp_id && pass == temp_pass){
				if(type == "admin"){
					user.close();
					return 1;
				}else{
					user.close();
					return 2;
				}
			}	
		}
		user.close();
		return 0;
	}	
}
