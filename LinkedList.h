#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;
class LinkedList
{
	private:
		class node {
			public:
				int number;
				string station;
				string station2;
				string status;
				string fname;
				string lname;
				string prefix;
				int price;
				string center;
				string park;
				string shop;
				int amount;
				node(int number,string station,string station2,string prefix,string fname,string lname,string status,string ic,string park,string shop){
					this->number = number;
					this->station = station;
					this->station2 = station2;
					this->fname = fname;
					this->lname = lname;
					this->prefix = prefix;
					this->status = status;
					this->center = ic;
					this->park = park;
					this->shop = shop;
					link = NULL;
					plink = NULL;
				}
				node * link;
				node * plink;
		};
		node *head;
		node *tail;
		int count;
		int count_center;
		int count_park;
		int count_shop;
	public:
		LinkedList();
		~LinkedList();
		void add(int number,string station,string station2,string prefix,string fname,string lname,string status,string ic,string park,string shop);
		void add(int number,int price,int amount);
		void savefile(string type);
		void edit(int number,string str,string deltail);
		int calculate(int start,int end,int type);
		int find_Interchange();
		bool getStation(int number);
		bool isEmpty();
		void show();
		void show_group();
		void show_Count();
		void show_search(int num);
		void search(int type);
		int size();
		int login(string id,string pass);
	
};
