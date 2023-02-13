
#ifndef SHIPS_H
#define SHIPS_H


#include <iostream>
#include <string>
using namespace std;

class ships{
	 
	public:
		
	ships();//DEFULT CONSTRUCTOR		
	ships(int in_id_ship,string in_name_ship,int in_crew,int in_ammo,int in_ship_length);//constuctor
	ships(const ships &obj_ship); //copy constructor
	~ships();//destructror	
	void set_in_name_ship(string in_name_ship);
	void set_in_crew(int in_crew);
	void set_in_ammo(int in_ammo);
	void set_in_ship_length(int in_ship_length);
	void set_in_id_lin(char in_id_lin);
	void set_in_id_ship(int in_id_ship);
	void set_in_horizontal(string in_horizontal);
	void set_in_vertical(string in_vertical);
	void set_shipparts(string in_partname,int in_shipnumber);// GIA ANANGNORISI KATEYTHINSIS PLOIOY (PLORI)
	void set_mission(int in_id_ship,string in_target,int in_crew,int in_ammo,int in_ship_length);//gia senario ktypiMA stoxoy
	string get_in_name_ship() const;
	int get_in_crew() const;
	int get_in_ammo() const;
	int get_in_ship_length()const;
	char get_in_id_lin()const;
	int get_in_id_ship()const;
	string get_in_horizontal() const;
	string get_in_vertical() const;
	void printShips();//ektyposi 
		
	private:
		
	string name_ship; 	
	int crew;
	int ammo;
	int ship_length;
	char id_lin;
	int id_ship;
	string horizontal;
	string vertical;
};
#endif
