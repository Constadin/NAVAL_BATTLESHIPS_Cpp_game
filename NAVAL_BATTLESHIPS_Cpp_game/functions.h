
#include "ships.h"
#include "player.h"


#include <stdlib.h>
#include <ctime>
#include <string>
#include <unistd.h>
#include <iostream>


#define FLD_LIN 10        //GRAMMES
#define FLD_COL 10       //STEILES
#define ALL_SHIPS 10    //arithmos olon ton ploion 


using namespace std;

 //========================== FUNCTIONS BODY =========================================================================



void gram_A() //diaxoristiko
{
	cout<<"\t\t================================"<<endl;
}


void gram_B() //diaxoristiko
{
	cout<<"\t\t---------------------------------"<<endl;
}



void printLogo() //EKTYPOSI LOGO
{
	gram_A(); //diaxoristiko
    cout<<"\t\t      -NAVAL BATTLESHIPS-"<<endl;
	gram_A(); //diaxoristiko
	
}



void odigiesGame()  //msg odigies paixnidiou
{
	printLogo();
	cout<<"\n    odigies:    Epilogi battle PLAYER vs apo to menou,\n";
	cout<<"\t\tO kathe PLAYER rixnei to zari kai o megaluteros arithmos kerdizei,\n";
	cout<<"\t\tO PLAYER autos epilegei protos ta ploia tou\n";
	cout<<"\t\tkai xekinaei kai protos tis voles\n";
	cout<<"\t\tKerdizei aytos pou tha buthisei ola ta ploia toy antipalou..."<<endl;
	cout<<"\n    kanones :   O kathe pektis topothetei ta ploia pou tha epilexei,\n";
	cout<<"\t\tsto pedio maxis (px. A5 dilonei ta shmeia ston pinaka pedioy maxis),\n";
	cout<<"\t\tme to ( V kai to H ) dilonei to katheta h orizontia antistoixa,\n";
	cout<<"\t\tme to ( L kai R ) dilonei thn kateythinsi toy ploioy aristera kai dexeia antistoixa,\n";
	cout<<"\t\tta symvola sthn emfanisi toy pedioy maxis(MAP BATTLESHIPS)symbolizoyn,\n";
	cout<<"\t\tto ^) kateyuinsi (PLORI) ploioy empros to <) kateyuinsi aristera kai (> kateyuinsi dexeia antistoixa,\n";
	cout<<"\t\tsthn emfanisi MAP GPS to X deixnei poy einai topothetimena ta ploia to idioy pekti (oxi toy antipaloy),\n";
	cout<<"\t\tsthn emfanisi MAP SHOOTS to X deixnei tis ASTOXES boles poy exei kanei o pektis,\n";
	cout<<"\t\tkai to H (HIT) dilonei oti exi xtipithei ploio toy antipaloy,\n";
	cout<<"\t\toi times (CREW KAI AMMO) ton eystoxon bolon se ploio metaferonte sto TOTAL toy alloy pexti se pontous.\n";
	
	cout<<"\t\t\t\t\t\t\t\t\t";	
	system("PAUSE");
	system("CLS");
}



 int checkInputNum(char* input_str_num)   //екемвос циа пкгйтокоцисг ломо аяихлым
{  
	int flag=1;
	int result_isdigit,i;
	int count;
	
	if((input_str_num [0]==0) && strlen(input_str_num)==0)          //аМ ПАТчСЕИ АЛщСЫР ENTER
           flag=0; 
	
	for(int i=0; i<=strlen(input_str_num); i++)	
	   {
	    if(input_str_num[i] =='.')
	      {
		   count++;
	      }
	   if(input_str_num[i] =='.' && count==1)
	      {
		   return result_isdigit=isdigit(input_str_num[i]);	   
	      }  
	   }
	   
	   
  	for( i=0; i<strlen(input_str_num); i++)
	   {
	    result_isdigit=isdigit(input_str_num[i]);
	   
		if(result_isdigit==0 )
		  {		  
			flag = flag*0;
		    break;
	       }
		else
		    {		
			 flag = flag*1;
	        }		  	        
	      }
	    return flag;  
}



int transformStrInput(char* input_str)    //летатяопг STR аяихлым се int
{
	int flag=1;
	int result_atoi;
	
	
	for(int i=0; i<strlen(input_str); i++)
	   {
		 result_atoi=atoi(input_str);	 
	    	    
	    if(result_atoi==0)
		   {		
			flag = flag*0;
	       } 		     
		else
		   {
		   	flag = flag*1;       
		    }
		  return result_atoi;  
       }

}



int playerMenouSelection(string msg,int *zari_PL_A,int *zari_PL_B,int *zari_PL_pc) //menou epilogis paixton vs
{   
    int selection=0;  //gia epilogi paixton vs
    char *input_str_num;
    int flag;
    srand(time(0));
    
 do{
 	printLogo();
    cout<<msg<<endl;
    cout<<"\t\t_________________________________\n"<<endl;
    cout<<"\t\t    1. PLAYER_1  vs  PLAYER_2"<<endl;
    cout<<"\t\t    2. PLAYER_1  vs  PC"<<endl;
    cout<<" selection: ";
    cin>>input_str_num;
    flag=checkInputNum(input_str_num);   //екемвос циа пкгйтокоцисг ломо аяихлым 
    
    if(flag==true)
	  {
       selection=transformStrInput(input_str_num);    //летатяопг STR аяихлым се INT
       break;
	  }
	else 
	  {
	   cout<<"\t\t>>EXEIS DOSEI GRAMMATOSEIRA ..."<<endl;
	   cout<<"\t\t>>EPITREPOMENOI ARITHMOI 1 , 2 "<<endl;	
	   flag==false;	
	  }
	cout<<"\t\t\t\t\t\t\t\t\t";		  
    system("PAUSE");   
    system("CLS");
	  
    }while(flag==false);  
    cout<<"\t\t\\_______________________________/\n"<<endl;
	switch(selection)
	      {
	      	case 1:
	      		   cout<<"\t\t     PLAYER_1  vs  PLAYER_2 "<<endl;
	      	       cout<<"\n\t\tPLAYER_1 RIXE TO ZARI (Wait...)";
	      	       sleep(2);
	      	       *zari_PL_A=(1+rand()%6);
	      	       cout<<"\n\t\tPLAYER_1: EFERES "<<*zari_PL_A<<endl;
	      	       cout<<"\n\t\tPLAYER_2 RIXE TO ZARI (Wait...)";
	      	       sleep(2);
				   *zari_PL_B=(1+rand()%6);
				   cout<<"\n\t\tPLAYER_2: EFERES "<<*zari_PL_B<<endl;
				break;    
	      	case 2:
	      		   cout<<"\t\t      PLAYER_1   vs   PC "<<endl;
	      	       cout<<"\n\t\tPLAYER_1 RIXE TO ZARI (Wait...)";
	      	       sleep(2);
	      	       *zari_PL_A=(1+rand()%6);
	      	       cout<<"\n\t\tPLAYER_1: EFERES "<<*zari_PL_A<<endl;
	      	       cout<<"\n\t\tPLAYER_PC RIXE TO ZARI (Wait...)";
	      	       sleep(2);
				   *zari_PL_pc=(1+rand()%6);
				   cout<<"\n\t\tPLAYER_PC: EFERES "<<*zari_PL_pc<<endl;
	      		break;
	      	default:
	      		cout<<"\t\t>>EXEIS DOSEI LATHOS EPILOGI..."<<endl;
		  }
		return selection;     
}


void playerSequence(int selection,int *winner_zari,int *loser_zari,int *flag,int zari_PL_A,int zari_PL_B,int zari_PL_pc,
                   int *play_first,int *play_second)   //epistrofi protereotitas paixti
{   
	
	    if(selection<1 || selection>2 )
    	   cout<<"\t\t   XANABALE AROTHMO APO 1-2\n"<<endl;
       
    	else if(selection==1 || selection==2)
		   {
		   	//ELENXOS GIA PROTEREOTITA PAIXTH   
    	    if(zari_PL_A>zari_PL_B && selection==1)
    	      {
    	       cout<<"\n\t\tWINNER IS PLAYER_1 ";
    	       cout<<"\tXEKINAEI PROTOS"<<endl;
		       *play_first=1;//o protos paixtis poy paizei
               *play_second=2;//o deuteros paixtis poy paizei
			   *winner_zari=1;//o protos paixtis poy grafei to onoma tou 
			   *loser_zari=2;//o deyteros paixtis poy grafei to onoma tou 	
		      }
	        else if(zari_PL_A<zari_PL_B && selection==1)
	          {
    	       cout<<"\n\t\tWINNER IS PLAYER_2 ";
    	       cout<<"\tXEKINAEI PROTOS"<<endl;
		       *play_first=2;//o protos paixtis poy paizei
               *play_second=1;//o deuteros paixtis poy paizei
			   *winner_zari=2;//o protos paixtis poy grafei to onoma tou 
			   *loser_zari=1;//o deyteros paixtis poy grafei to onoma tou 	
		      }	
		    else if(zari_PL_A>zari_PL_pc && selection==2)
		      {
    	       cout<<"\n\t\tWINNER IS PLAYER_1 ";
    	       cout<<"\tXEKINAEI PROTOS"<<endl;
		       *play_first=1;//o protos paixtis poy paizei
               *play_second=3;//o deuteros paixtis poy paizei 
			   *winner_zari=1;//o protos paixtis poy grafei to onoma tou 
			   *loser_zari=3;//o deyteros paixtis poy grafei to onoma tou  	
		      }	        
	        else if(zari_PL_A<zari_PL_pc && selection==2)
	          {
    	       cout<<"\n\t\tWINNER IS PLAYER_PC ";
    	       cout<<"\tXEKINAEI PROTOS"<<endl;
		       *play_first=3;//o protos paixtis poy paizei
               *play_second=2;//o deuteros paixtis poy paizei
			   *winner_zari=3;//o protos paixtis poy grafei to onoma tou 
			   *loser_zari=2;//o deyteros paixtis poy grafei to onoma tou   	
		      }		     
	        else
	          {
	          cout<<"\n\t\tYPARXEI ISSOPALIA EPISTROFH STO MENOU VS"<<endl;
		      *flag=false;
		      } 
			}
}



player typeNickName(player obj_player)   //ALGH ONOMATOS PLAYER 
{
	string nickname;
    
	   cout<<"\n\t\t>> HELLO :"<<obj_player.get_in_name_player()<<"...(first write your nickname CAPSLOCK): ";
	   cin>>nickname;
      
	obj_player.set_in_name_player(nickname);
	
    return obj_player;	
}




void printSelectPlayers(int selection,int winner_zari,player &player_A,player &player_B,player &player_PC)  // ektyposh pexton 
{
	switch(selection)
	      {
	      	case 1:
	      		  printLogo();
	              cout<<"\t	TWO PLAYERS:\n"; //arxikopoihsh PLAYERS
	              if(winner_zari==1)
	      		    {
	      		      cout<<"\t\t";	
	      		      player_A=typeNickName(player_A);
	                  player_A.printPlayers();
	                  cout<<"\t\t";
	                  player_B=typeNickName(player_B);
	                  player_B.printPlayers();
	                  cout<<"\t\t";
	                  cout<<"\n";
	                  printLogo();
	                  cout<<"\n\t\t"<<player_A.get_in_name_player()<<"       VS       "<<player_B.get_in_name_player()<<endl;	
	                  gram_B();
				     } 
	               else if(winner_zari==2)
	      		     {
	      		      cout<<"\t\t";	
	      		      player_B=typeNickName(player_B);
	                  player_B.printPlayers();
	                  cout<<"\t\t";
	                  player_A=typeNickName(player_A);
	                  player_A.printPlayers();
	                  cout<<"\t\t";
	                  cout<<"\n";
	                  printLogo();
	                  cout<<"\n\t\t"<<player_B.get_in_name_player()<<"       VS       "<<player_A.get_in_name_player()<<endl;	
	                  gram_B();
				     } 
				break;
				    
	      	case 2:
	      		  printLogo();
	              cout<<"\t	TWO PLAYERS:\n"; //arxikopoihsh PLAYERS
	              if(winner_zari==1)
	      		    {
	      		      cout<<"\t\t";	
	      		      player_A=typeNickName(player_A);
	                  player_A.printPlayers();
	                  cout<<"\t\t";	                  
	                  player_PC.printPlayers();
	                  cout<<"\t\t";
	                  cout<<"\n";
	                  printLogo();
	                  cout<<"\n\t\t"<<player_A.get_in_name_player()<<"\t\tVS\t"<<player_B.get_in_name_player()<<endl;	
	                  gram_B();
				     } 
	               else if(winner_zari==3)
	      		     {
	      		      cout<<"\t\t";	
	                  player_PC.printPlayers();
	                  cout<<"\t\t";
	                  player_A=typeNickName(player_A);
	                  player_A.printPlayers();
	                  cout<<"\t\t";
	                  cout<<"\n";
	                  printLogo();
	                  cout<<"\n\t\t"<<player_PC.get_in_name_player()<<"\t\tVS\t"<<player_A.get_in_name_player()<<endl;	
	                  gram_B();
				     } 
	      		break;
	      		
	      	default:
	      		cout<<"\t\t>>EXEIS DOSEI LATHOS EPILOGI..."<<endl;
		  }
	cout<<"\t\t  THE__ GAME_ IS__ BEGINNING..."<<endl;	  
	cout<<"\t\t\t\t\t\t\t\t\t";	  
    system("PAUSE");   
    system("CLS");
    
}



void printPlayerFirst(int winner_zari,player &player_A,player &player_B,player &player_PC) //ektyposi onomatos protoy pexti
{
    if(winner_zari==1)
      player_A.printPlayers();
    else if(winner_zari==2)
      player_B.printPlayers();
	else if(winner_zari==3)
      player_PC.printPlayers(); 
	   	   	
}



void printPlayerSecond(int loser_zari,player &player_A,player &player_B,player &player_PC) //ektyposi onomatos deyteroy pexti
{
    if(loser_zari==1)
      player_A.printPlayers();
    else if(loser_zari==2)
      player_B.printPlayers();
	else if(loser_zari==3)
      player_PC.printPlayers(); 
	   	   	
}



	      
void printMatrixDefult(ships obj_ship) //ektyposi pinaka defult ships (pedio)
{
    char letter='A';
	 
	cout<<"\n"<<"\t 0"<<"\t 1"<<"\t  2"<<"\t   3"<<"\t    4"<<"\t     5"<<"\t      6"<<"\t       7"<<"\t8"<<"\t 9\n"<<endl;
	for(int i=0; i<FLD_LIN; i++)
	   {
	   	cout<<" "<<letter<<"  ";
	   	letter++;
	   	for(int j=0; j<FLD_COL; j++)
	   	   {
	   	    cout<<"|"<<obj_ship.get_in_name_ship()<<"|";
			}
		cout<<"\n\t\t \n";	
	   } 
	   
}




int inputGpsShip(char *let_choice,char *let_choice_2,char *let_choice_3,int *simeio_i,
     int *simeio_j,int *posision,int *sail_ship,ships &baffer_ship,int winner_zari,int loser_zari)//topothetisi ploiy gps
{
	int flag;
	char buf_simeio_j[50];
	
	cout<<"\nDOSE SYNTETAGMENES  PLOIOY APO  A-J  KAI  APO 0-9:";	
	do{
	   flag=true;	
	   cout<<"\nGPS SIMEIO (KATHETO PINAKA) PLOIOY :";
	   if(winner_zari==5 && loser_zari==5)
	     {
	      cout<<"   i am robot  "<<endl;
	      *simeio_i=rand()%10;
	      //cout<<*simeio_i<<endl;
		  flag=true;	
		 }
		else 	
	     cin>>*let_choice;
	     
		if(*let_choice)
		  {
			if(*let_choice=='A' || *let_choice=='a')
			  {flag=true; *simeio_i=0;}
			else if(*let_choice=='B' || *let_choice=='b')
			  {flag=true; *simeio_i=1;}
			else if(*let_choice=='C' || *let_choice=='c')
			  {flag=true; *simeio_i=2;}
			else if(*let_choice=='D' || *let_choice=='d')
			  {flag=true; *simeio_i=3;}   
			else if(*let_choice=='E' || *let_choice=='e')
			  {flag=true; *simeio_i=4;}
			else if(*let_choice=='F' || *let_choice=='f')
			  {flag=true; *simeio_i=5;}
			else if(*let_choice=='G' || *let_choice=='g')
			  {flag=true; *simeio_i=6;}
			else if(*let_choice=='H' || *let_choice=='h')
			  {flag=true; *simeio_i=7;}
			else if(*let_choice=='I' || *let_choice=='i')
			  {flag=true; *simeio_i=8;}
			else if(*let_choice=='J' || *let_choice=='j')	      
		      {flag=true; *simeio_i=9;}
		    else
		      {
		       cout<<"LATHOS EPILOGI DOSE GRAMMATA APO TO A - J  OR a - j"<<endl;
		       flag=false;
		       }    
	    }
   }while(flag==false);
   
    do{
       flag=true;	
       cout<<"GPS SIMEIO (ORIZONTIO PINAKA) PLOIOY:";
       if(winner_zari==5 && loser_zari==5)
	     {
	      cout<<"   i am robot  "<<endl;
	      *simeio_j=rand()%10;;
	      //cout<<*simeio_j<<endl;
		  flag=true;
		  if(flag==true)
		     { 
		      if(*simeio_j>=0 && *simeio_j<10)
		        {
		         flag=true;
			    }
		      else
			    {
			     cout<<"EPITREPOMENOI ARITHMOI 0-9"<<endl;
			     flag=false;
			    }   	
		     }	
		  }
		else 
		  {
		   cin>>buf_simeio_j;
	       if(buf_simeio_j)
	         {
	          flag=checkInputNum(buf_simeio_j);   //екемвос циа пкгйтокоцисг ломо аяихлым 	
	          if(flag==true)
		        {
		         *simeio_j=transformStrInput(buf_simeio_j);    //летатяопг STR аяихлым се INT
		         if(*simeio_j>=0 && *simeio_j<10)
		           {
		            flag=true;
			       }
		         else
			       {
			        cout<<"EPITREPOMENOI ARITHMOI 0-9"<<endl;
			        flag=false;
			       }   	
		         }
	          }	
		   }
	  }while(flag==false);  
	  
	cout<<"\nAYTOMATI APOTHIKEYSH (MIKOS PLOIOY) ANALOGA TO MONTELO PLOIOY: "<<baffer_ship.get_in_ship_length()<<" Range\n";
	do{
	   cout<<endl; 
	   cout<<"'V'. GIA KATHETH   TOPOTHETISI PLOIOY"<<endl;
	   cout<<"'H'. GIA ORIZONTIA TOPOTHETISI PLOIOY >>:";
	   if(winner_zari==5 && loser_zari==5)
	     {
	      cout<<"   i am robot  "<<endl;
		  *posision=1+rand()%2;
		  //cout<<*posision<<endl;
		  flag=true;	
		 }
		else
		 {
		  cin>>*let_choice_2;
	      if(*let_choice_2)
	        {
	          if(*let_choice_2=='V' || *let_choice_2=='v')
	           {flag=true; *posision=1;}
	          else if(*let_choice_2=='H' || *let_choice_2=='h')
	           {flag=true; *posision=2;}
	          else
	           {
	            cout<<"LATHOS EPILOGI DOSE GRAMMATA TO V OR H  / v or h"<<endl;
	            flag=false;	
	           }		       
             }	
		  } 
    }while(flag==false);
    
    do{
	   if(*posision==2)
		 {
	      flag=true;	
		  cout<<"\n'L'. GIA ARISTRI <<() TOPOTHETISI  PLOIOY"<<endl;
		  cout<<"'R'. GIA DEXEIA  ()>> TOPOTHETISI  PLOIOY ->:";
		  if(winner_zari==5 && loser_zari==5)
	       {
	        cout<<"   i am robot  "<<endl;
		    *sail_ship=1+rand()%2;
		    //cout<<*sail_ship<<endl;
			flag=true;	
		   }
		  else
		   {
		   	cin>>*let_choice_3;
		    if(*let_choice_3)
		      {
			   if(*let_choice_3=='L' || *let_choice_3=='l')
			      {flag=true; *sail_ship=1;}
			   else if(*let_choice_3=='R' || *let_choice_3=='r')
			      {flag=true; *sail_ship=2;}
			   else
	            {
	             cout<<"\nLATHOS EPILOGI DOSE GRAMMATA  TO L OR R  / l or r"<<endl;
	             flag=false;	
	            } 
		      }		   	
		    }  
	      }
	  }while(flag==false);     
	return flag;
}



void printBattleShips(ships *battleships,int all_ships)  //ektyposi pinaka olon ton diadesimon ploion
{
	
	for(int i=0 ; i<all_ships ; i++)
	   {
	   	cout<<"\t\tNo."<<battleships[i].get_in_id_ship()<<"\tSHIP_NAME: "<<battleships[i].get_in_name_ship()<<"   PLHROMA: "
		<<battleships[i].get_in_crew()<<"   PYROMAXIKA: "<<battleships[i].get_in_ammo()<<"   MHKOS_PLOIOY: "
		<<battleships[i].get_in_ship_length()<<endl;	
	    } 
	
}      



void matxinitializationShoots(char matx_shoots_firstplayer[FLD_LIN][FLD_COL])//arxikopoihsh pinaka volon
{  
    int fld_lin=FLD_LIN;
    int fld_col=FLD_COL;
    
	for(int i=0; i<fld_lin; i++)
		for(int j=0; j<fld_col; j++)
			matx_shoots_firstplayer[i][j]='~'; 
} 




int inputshootsShip(char *shoot_i,int *simeio_i,int *simeio_j,int winner_zari,int loser_zari)
{
	int flag;
	char buf_simeio_j[50];
	
	cout<<"\nDOSE SYNTETAGMENES  PLOIOY APO  A-J  KAI  APO 0-9:";	
	do{
	   flag=true;	
	   cout<<"\nGPS SIMEIO (KATHETO PINAKA) PLOIOY :";
	   if(winner_zari==5 && loser_zari==5)
	     {
	      cout<<"   i am robot  "<<endl;
	      *simeio_i=rand()%10;
	      //cout<<*simeio_i<<endl;
		  flag=true;	
		 }
		else 	
	    cin>>*shoot_i;
	    
		if(*shoot_i)
		  {
			if(*shoot_i=='A' || *shoot_i=='a')
			  {flag=true; *simeio_i=0;}
			else if(*shoot_i=='B' || *shoot_i=='b')
			  {flag=true; *simeio_i=1;}
			else if(*shoot_i=='C' || *shoot_i=='c')
			  {flag=true; *simeio_i=2;}
			else if(*shoot_i=='D' || *shoot_i=='d')
			  {flag=true; *simeio_i=3;}   
			else if(*shoot_i=='E' || *shoot_i=='e')
			  {flag=true; *simeio_i=4;}
			else if(*shoot_i=='F' || *shoot_i=='f')
			  {flag=true; *simeio_i=5;}
			else if(*shoot_i=='G' || *shoot_i=='g')
			  {flag=true; *simeio_i=6;}
			else if(*shoot_i=='H' || *shoot_i=='h')
			  {flag=true; *simeio_i=7;}
			else if(*shoot_i=='I' || *shoot_i=='i')
			  {flag=true; *simeio_i=8;}
			else if(*shoot_i=='J' || *shoot_i=='j')	      
		      {flag=true; *simeio_i=9;}
		    else
		      {
		       cout<<"LATHOS EPILOGI DOSE GRAMMATA APO TO A - J  OR a - j"<<endl;
		       flag=false;
		       }    
	    }
   }while(flag==false);
   
    do{
       flag=true;	
       cout<<"GPS SIMEIO (ORIZONTIO PINAKA) PLOIOY:";
       if(winner_zari==5 && loser_zari==5)
	     {
	      cout<<"   i am robot  "<<endl;
	      *simeio_j=rand()%10;;
	      //cout<<*simeio_j<<endl;
		  flag=true;
		  if(flag==true)
		     { 
		      if(*simeio_j>=0 && *simeio_j<10)
		        {
		         flag=true;
			    }
		      else
			    {
			     cout<<"EPITREPOMENOI ARITHMOI 0-9"<<endl;
			     flag=false;
			    }   	
		     }	
		  }
		else 
		  {
		   cin>>buf_simeio_j;
	       if(buf_simeio_j)
	         {
	          flag=checkInputNum(buf_simeio_j);   //екемвос циа пкгйтокоцисг ломо аяихлым 	
	          if(flag==true)
		        {
		         *simeio_j=transformStrInput(buf_simeio_j);    //летатяопг STR аяихлым се INT
		         if(*simeio_j>=0 && *simeio_j<10)
		           {
		            flag=true;
			       }
		         else
			       {
			        cout<<"EPITREPOMENOI ARITHMOI 0-9"<<endl;
			        flag=false;
			       }   	
		         }
	          }	
		   }
	  }while(flag==false); 
	  
}



	
void matxPrintShoots(char matx_shoots_firstplayer[FLD_LIN][FLD_COL]) //EKTYPOSI pinaka volon	    
{
	cout<<"\n\t-MAP GPS MY BATTLESHIPS-"<<endl;  
	char letter='A';
	cout<<"\n    "<<" 0"<<" 1"<<" 2"<<" 3"<<" 4"<<" 5"<<" 6"<<" 7"<<" 8"<<" 9\n"<<endl;
	for(int i=0; i<FLD_LIN; i++)
	   {
	   	cout<<" "<<letter<<"  ";
	   	letter++;
	   	
		for(int j=0; j<FLD_COL; j++)
			cout<<" "<<matx_shoots_firstplayer[i][j];
		cout<<"\n";	
	   }
	    cout<<"\n";
}



