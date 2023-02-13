
#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <string>
using namespace std;

class player{
	
	public:
		
	player(string in_name_player,float in_total,int in_shoots);//constuctor defult
	player(const player &obj_plr);//copy constuctor 
	~player();//destuctor
	void set_in_name_player(string in_name_player);
	void set_in_total(float in_total);
	void set_in_shoots(int in_shoots);
	string get_in_name_player() const ;
	float get_in_total() const;
	int get_in_shoots() const;
	void printPlayers();//ektyposi
	 
	private:
		
	string name_player;	
	int shoots;
	int total;	
};
#endif
