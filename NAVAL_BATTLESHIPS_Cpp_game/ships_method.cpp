
#include "ships.h"

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;


ships :: ships()//DEFULT CONSTRUCTOR
{
   	name_ship="~~~~~~~~~";
	crew=-1;
	ammo=-1;
	ship_length=-1;
   // cout<<"costructing def SHIP...\n";
  //cout<<"\n\t\tship: "<<name_ship<<"  PLIROMA: "<<crew<<"  PYROMAXIKA: "<<ammo<<"  MHKOS PLOIOY: "<<ship_length<<endl;
}

ships :: ships(int in_id_ship ,string in_name_ship,int in_crew,int in_ammo,int in_ship_length)://constuctor
id_ship(in_id_ship),name_ship(in_name_ship),crew(in_crew),ammo(in_ammo),ship_length(in_ship_length)
{
 //cout<<"costructing SHIP...\n";
 	  
}

ships :: ships(const ships &obj_ship) //copy constructor
{
    //cout<<"copy costructing SHIP...\n";
    id_ship=obj_ship.get_in_id_ship();
	name_ship=obj_ship.get_in_name_ship();
	crew=obj_ship.get_in_crew();
	ammo=obj_ship.get_in_ammo();
	ship_length=obj_ship.get_in_ship_length();
}

ships :: ~ships()//destructror
{
   // cout<<"destructing SHIP...\n";	
}
	
void ships ::  set_in_name_ship(string in_name_ship)
{
  name_ship=in_name_ship;
}

void ships :: set_in_crew(int in_crew)
{
  crew=in_crew;	
}

 void ships :: set_in_ammo(int in_ammo)
{
  ammo=in_ammo;	
}

 void ships :: set_in_ship_length(int in_ship_length)
{
  ship_length=in_ship_length;	
}

 void ships :: set_in_id_lin(char in_id_lin)
{
    id_lin=in_id_lin;	
}

 void ships :: set_in_id_ship(int in_id_ship)
{
    id_ship=in_id_ship;	
}

 void ships :: set_in_horizontal(string in_horizontal)
{
	horizontal=in_horizontal;
}

 void ships :: set_in_vertical(string in_verticall)
{
	vertical=in_verticall;
}

void ships :: set_shipparts(string in_partname,int in_shipnumber)
{   
	if( in_partname=="^/-------")  //PLORI EMPROS
    {
	 if(in_shipnumber==1)
	                {name_ship="^)FOXI_35";
					    }
	   	            else if(in_shipnumber==2)
	   	            {name_ship="^)HACK_58" ;
					    }
	   	            else if(in_shipnumber==3)
	   	            {name_ship="^)ALEM_22";
					   }
	   	            else if(in_shipnumber==4)
	   	            {name_ship="^)IARI_12" ; 
					   }
	   	            else if(in_shipnumber==5)
	   	            {name_ship="^)KACP_10" ;
					   }
	   	            else if(in_shipnumber==6)
	   	            {name_ship="^)BITR_99" ; 
					   }
	   	            else if(in_shipnumber==7)
	   	            {name_ship="^)FATB_77";   
					   }
	   	            else if(in_shipnumber==8)
	   	            {name_ship="^)HIPER_9";  
					   }
	   	            else if(in_shipnumber==9)
	   	            {name_ship="^)WATER_2" ; 
					   }
                    else if(in_shipnumber==10)
                    {name_ship="^)AVAL_81";
					 } 
    else name_ship='\0';
   }
   
   
	else if( in_partname=="<|-------")   //plori aristera 
    {
	 if(in_shipnumber==1)
	                {name_ship="<)FOXI_35";
					    }
	   	            else if(in_shipnumber==2)
	   	            {name_ship="<)HACK_58" ;
					    }
	   	            else if(in_shipnumber==3)
	   	            {name_ship="<)ALEM_22";
					   }
	   	            else if(in_shipnumber==4)
	   	            {name_ship="<)IARI_12" ; 
					   }
	   	            else if(in_shipnumber==5)
	   	            {name_ship="<)KACP_10" ;
					   }
	   	            else if(in_shipnumber==6)
	   	            {name_ship="<)BITR_99" ; 
					   }
	   	            else if(in_shipnumber==7)
	   	            {name_ship="<)FATB_77";   
					   }
	   	            else if(in_shipnumber==8)
	   	            {name_ship="<)HIPER_9";  
					   }
	   	            else if(in_shipnumber==9)
	   	            {name_ship="<)WATER_2" ; 
					   }
                    else if(in_shipnumber==10)
                    {name_ship="<)AVAL_81";
					 } 
    else name_ship='\0';
   }
   
   
    else if( in_partname=="-------|>") //plori dejeia
    {
	 if(in_shipnumber==1)
	                {name_ship="FOXI_35(>";
					    }
	   	            else if(in_shipnumber==2)
	   	            {name_ship="HACK_58(>" ;
					    }
	   	            else if(in_shipnumber==3)
	   	            {name_ship="ALEM_22(>";
					   }
	   	            else if(in_shipnumber==4)
	   	            {name_ship="IARI_12(>" ; 
					   }
	   	            else if(in_shipnumber==5)
	   	            {name_ship="KACP_10(>" ;
					   }
	   	            else if(in_shipnumber==6)
	   	            {name_ship="BITR_99(>" ; 
					   }
	   	            else if(in_shipnumber==7)
	   	            {name_ship="FATB_77(>";   
					   }
	   	            else if(in_shipnumber==8)
	   	            {name_ship="HIPER_9(>";  
					   }
	   	            else if(in_shipnumber==9)
	   	            {name_ship="WATER_2(>" ; 
					   }
                    else if(in_shipnumber==10)
                    {name_ship="AVAL_81(>";
					 } 
    else name_ship='\0';
   } 
}



void ships :: set_mission(int in_id_ship,string in_target,int in_crew,int in_ammo,int in_ship_length)
{
	int new_crew;
	int new_ammo;
	
  
    if(in_target!="(x)TARGET")
	     {
			switch(in_id_ship)
			      {
			      	case 1:
			      		  	name_ship=in_target;
			              	new_ammo=in_ammo/in_ship_length;
			    			ammo=new_ammo*(in_ship_length-1);
							new_crew=in_crew/in_ship_length;
							crew=new_crew*(in_ship_length-1);
				         	ship_length=in_ship_length-1;				         	
		                    //cout<<"\tTO PLOIO XTYPITHIKE!!!  ";
							if(ship_length==0)
		                       cout<<"\n\n\tTO PLOIO BUTHISTIKE"<<endl; 
						break;
						    
			      	case 2:
			      		    name_ship=in_target;
			              	new_ammo=in_ammo/in_ship_length;
			    			ammo=new_ammo*(in_ship_length-1);
							new_crew=in_crew/in_ship_length;
							crew=new_crew*(in_ship_length-1);
				         	ship_length=in_ship_length-1;
		                    //cout<<"\tTO PLOIO XTYPITHIKE!!!  ";
							if(ship_length==0)
		                       cout<<"\n\n\tTO PLOIO BUTHISTIKE"<<endl;
			      		break;
			      	case 3:
			      		  	name_ship=in_target;
			              	new_ammo=in_ammo/in_ship_length;
			    			ammo=new_ammo*(in_ship_length-1);
							new_crew=in_crew/in_ship_length;
							crew=new_crew*(in_ship_length-1);
				         	ship_length=in_ship_length-1;
		                   // cout<<"\tTO PLOIO XTYPITHIKE!!!  ";
							if(ship_length==0)
		                       cout<<"\n\n\tTO PLOIO BUTHISTIKE"<<endl;; 
						break;
						    
			      	case 4:
			      		    name_ship=in_target;
			              	new_ammo=in_ammo/in_ship_length;
			    			ammo=new_ammo*(in_ship_length-2);
							new_crew=in_crew/in_ship_length;
							crew=new_crew*(in_ship_length-1);
				         	ship_length=in_ship_length-1;
		                   // cout<<"\tTO PLOIO XTYPITHIKE!!!  ";
							if(ship_length==0)
		                       cout<<"\n\n\tTO PLOIO BUTHISTIKE"<<endl;
			      		break;
			      	case 5:
			      		  	name_ship=in_target;
			              	new_ammo=in_ammo/in_ship_length;
			    			ammo=new_ammo*(in_ship_length-1);
							new_crew=in_crew/in_ship_length;
							crew=new_crew*(in_ship_length-1);
				         	ship_length=in_ship_length-1;
		                    //cout<<"\tTO PLOIO XTYPITHIKE!!!  ";
							if(ship_length==0)
		                       cout<<"\n\n\tTO PLOIO BUTHISTIKE"<<endl;
						break;
						    
			      	case 6:
			      		    name_ship=in_target;
			              	new_ammo=in_ammo/in_ship_length;
			    			ammo=new_ammo*(in_ship_length-1);
							new_crew=in_crew/in_ship_length;
							crew=new_crew*(in_ship_length-1);
				         	ship_length=in_ship_length-1;
		                    //cout<<"\tTO PLOIO XTYPITHIKE!!!  ";
							if(ship_length==0)
		                       cout<<"\n\n\tTO PLOIO BUTHISTIKE"<<endl;
			      		break;
			      		
			      	case 7:
			      		  	name_ship=in_target;
			              	new_ammo=in_ammo/in_ship_length;
			    			ammo=new_ammo*(in_ship_length-1);
							new_crew=in_crew/in_ship_length;
							crew=new_crew*(in_ship_length-1);
				         	ship_length=in_ship_length-1;
		                    //cout<<"\tTO PLOIO XTYPITHIKE!!!  ";
							if(ship_length==0)
		                       cout<<"\n\n\tTO PLOIO BUTHISTIKE"<<endl;
						break;
						    
			      	case 8:
			      		    name_ship=in_target;
			              	new_ammo=in_ammo/in_ship_length;
			    			ammo=new_ammo*(in_ship_length-1);
							new_crew=in_crew/in_ship_length;
							crew=new_crew*(in_ship_length-1);
				         	ship_length=in_ship_length-1;
		                    //cout<<"\tTO PLOIO XTYPITHIKE!!!  ";
							if(ship_length==0)
		                       cout<<"\n\n\tTO PLOIO BUTHISTIKE"<<endl;
			      		break;
					case 9:
			      		  	name_ship=in_target;
			              	new_ammo=in_ammo/in_ship_length;
			    			ammo=new_ammo*(in_ship_length-1);
							new_crew=in_crew/in_ship_length;
							crew=new_crew*(in_ship_length-1);
				         	ship_length=in_ship_length-1;
		                    //cout<<"\tTO PLOIO XTYPITHIKE!!!  ";
							if(ship_length==0)
		                       cout<<"\n\n\tTO PLOIO BUTHISTIKE"<<endl; 
						break;
						    
			      	case 10:
			      		    name_ship=in_target;
			              	new_ammo=in_ammo/in_ship_length;
			    			ammo=new_ammo*(in_ship_length-1);
							new_crew=in_crew/in_ship_length;
							crew=new_crew*(in_ship_length-1);
				         	ship_length=in_ship_length-1;
		                    //cout<<"\tTO PLOIO XTYPITHIKE!!!  ";
							if(ship_length==0)
		                       cout<<"\n\n\tTO PLOIO BUTHISTIKE"<<endl;
			      		break;		  	
				  }
	     }
	     
   
}  




inline string ships :: get_in_name_ship() const
{
  return name_ship;	
}

inline int ships :: get_in_crew() const
{
  return crew;	
}

inline int ships :: get_in_ammo() const
{
  return ammo;	
}

inline int ships :: get_in_ship_length()const
{
  return ship_length;	
}

inline char ships :: get_in_id_lin() const
{
	return id_lin;
}

inline int  ships :: get_in_id_ship() const
{
	return id_ship;
}

inline string ships :: get_in_horizontal() const
{
	return horizontal;
}

inline string ships :: get_in_vertical() const
{
	return vertical;
}

void ships :: printShips() //ektyposi 
{
 cout<<"\n\t\tship: No"<<id_ship<<". SHIPNAME:"<<name_ship<<"  PLIROMA: "<<crew<<"  PYROMAXIKA: "<<ammo<<"  MHKOS PLOIOY: "<<ship_length<<endl;	
}

