
#include "player.h"

#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

player :: player(string in_name_player, float in_total,int in_shoots)
{
  //cout<<"costructing PLAYER...\n";
  name_player=in_name_player;
  total=in_total;
  shoots=in_shoots;	
}

player :: player(const player &obj_plr)//copy constuctor 
{
 //cout<<"copy costructing PLAYER...\n";
  name_player=obj_plr.get_in_name_player();
  total=obj_plr.get_in_total();
  shoots=obj_plr.get_in_shoots();	
}

player :: ~player()//destuctor
{
 //cout<<"destructing PLAYER...\n";	
}

 void player :: set_in_name_player(string in_name_player)
{
   name_player=in_name_player;
}

void player :: set_in_total(float in_total)
{
   total=in_total;
}

inline void player :: set_in_shoots(int in_shoots)
{
    shoots=in_shoots;
}

inline string player :: get_in_name_player() const 
{
	return name_player;
}

inline float player :: get_in_total() const
{
	return total;
}

inline int player :: get_in_shoots() const
{
 	return shoots;
}

void player :: printPlayers()
{
  cout<<"\n\tPLAYER: "<<" "<<name_player<<"\ttotal:  "<<total<<endl;	
}

