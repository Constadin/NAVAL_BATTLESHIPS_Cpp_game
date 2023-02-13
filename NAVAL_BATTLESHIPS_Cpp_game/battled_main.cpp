
//naval battleships

#include "ships.h"
#include "player.h"
#include"functions.h"

#include <stdlib.h>
#include <ctime>
#include <string>
#include <unistd.h>
#include <iostream>


#define FLD_LIN 10        //GRAMMES
#define FLD_COL 10       //STEILES
#define ALL_SHIPS 10    //arithmos olon ton ploion 
#define CHOIS_SHIPS 3 //arithmos EPILEGMENON  ploion 
#define VOLES 30      //arithmos volon pekton

using namespace std;







//========================== M A I N DECLARATION OF VARIABLES ===============================
 
   
 int main(void)
{   
    int flag=1;
    int selection;          //GIA EPILOGI PAIйTON VS
    int zari_PL_A;         //ZARI PLAYER 1
    int zari_PL_B;        //ZARI PLAYER 2
    int zari_PL_pc;      //ZARI PLAYER PC
    int play_first;     //O PROTOS PAIйTIS POY PAIZEI
    int play_second;   //O  DEYTEROS PAIKTHS POY PAIZEI
    int select_ships; //GIA EPILOGI PLOIOY APO PAIйTI
    char buf_ch_select_ships[10];
    
    player player_A("PLAYER_1",0.00,50);     //ARXIKOPIHSH OBJ PLAYERS
    player player_B("PLAYER_2",0.00,50);    //ARXIKOPIHSH OBJ PLAYERS
    player player_PC("PLAYER_PC",0.00,50); //ARXIKOPIHSH OBJ PLAYERS
    
    //perasma ploion se pinaka modiastato gia epilogi ploioy apo paixti
    ships battleships[ALL_SHIPS]={
    ships(1,"  FOXI_35",38,5000,5),    
    ships(2,"  HACK_58",55,5000,5),    
    ships(3,"  ALEM_22",16,2000,3),    
    ships(4,"  IARI_12",15,2000,3),    
    ships(5,"  KACP_10",27,4000,4),    
    ships(6,"  BITR_99",22,4000,4),    
    ships(7,"  FATB_77",55,8000,6),    
    ships(8,"  HIPER_9",74,8000,6),    
    ships(9,"  WATER_2",10,1000,2),    
    ships(10,"  AVAL_81",11,1000,2)};
    
    
    ships matrix_Ships_player_first[FLD_LIN][FLD_LIN];        //PINAKAS PAIDIOY PROTOY PEXTI
	ships matrix_Ships_player_second[FLD_LIN][FLD_LIN];      //PINAKAS PAIDIOY PROTOY PEXTI    
	ships shp;                                              //DEFULT OBJ 
	ships baffer_ship;                                     //BUFFER OBJ
	int baffer_mtxchoose_first_ply[ALL_SHIPS]={0};        //BUFFER MATRIX EPILEGMENON PLOION PROTOY PEKTI               
	int baffer_mtxchoose_second_ply[ALL_SHIPS]={0};      //BUFFER MATRIX EPILEGMENON PLOION DEYTEROY PEKTI    
	
	char let_choice_1;            //епикоцH сумтетацлемг ваяайтгяас
	char let_choice_2;           //епикоцH сумтетацлемг KATHETA / ORIZINTIA
	char let_choice_3;          //епикоцH сумтетацлемг ARISTERA /DEXEIA  H PLORH
	int simeio_i;              //епикоцH сумтетацлемг  
	int simeio_j;             //епикоцH сумтетацлемг  
	int thesis;              //MIKOS THESEON PLOIOY
	int posision;           //KATHETH H ORIZONTIA TOPOTHETISI
	char letter='A';       //ARXIKOPOIHSH GRAMMON PINAKA ONOMATODOSIA
	int  meter=0;         //METRITIS
	int  cnt=0;          //metritis
	int winner_zari;    //NIKITIS  AANAMETRISIS STO ZARI 
	int loser_zari;    //XAMEMOS  ANAMETRISIS STO ZARI
	int sail_ship;    //PROSANATOLISMOS PLoRHS PLOIOY
	char matx_gps_firstplayer[FLD_LIN][FLD_COL];   //pinakas gps  protou paixti
	char matx_gps_secondplayer[FLD_LIN][FLD_COL]; //pinakas gps deyterou paixti
	int  visual_maps;        //GIA EISODO STO MENOY VISUAL
	int shoot_cnt=0;        //METRITIS
	int shoot_cnt_first=0;              //METRITIS VOLON PROTOY PEXTI
	int shoot_cnt_second=0;            //METRITIS VOLON DEYTEROY PEXTI
	char shoot_first_ply_voli_i;      //GIA ELENXO EISODOY VOLIS CHAR
	int shoot_first_ply_voli_j;      //GIA EPILOGI VOLIS
	char shoot_second_ply_voli_i;   //GIA ELENXO EISODOY VOLIS CHAR
	int shoot_second_ply_voli_j;   //GIA EPILOGI VOLIS
	float total_sum_LS=0;         //GIA SYSOREYSI BONUS 
	float total_sum_WN=0;        //GIA SYSOREYSI BONUS
	char matx_SHOOT_firstplayer[FLD_LIN][FLD_COL];  //PINAKAS ENDIJIS VOLON
	char matx_SHOOT_secondplayer[FLD_LIN][FLD_COL]; //PINAKAS ENDIXIS VOLON
	
	 
//============================= BODY MAIN ============================================================================
    srand(time(0));
	
    odigiesGame(); //odigies paixnidioy
       
    //-------------------------------------ODIGIES PAIXNIDIOY-------------------------------------------   
       
  do{	
	 printLogo();  //logo game
	 
	 flag=1;
	 cout<<"\n\t\tPLAYER_1\tvs \tPLAYER_2\n\t\t\t\t:: \n\t\tPLAYER_1\tvs \tPC\n"<<endl;
	 
    //--------------------------------EPILOGI MENOY PEKTON KAI ANAMETRISI ME ZARI---------------------- 
	   
	 //menou epilogis paixton vs 
     selection=playerMenouSelection("\n\t\t  EPELEXE PAIKTES APO TO MENOU",&zari_PL_A, &zari_PL_B, &zari_PL_pc);
     
	 
	//----------------------------ANADIXI NIKITI ZARIOY KAI ARXIKOPOIHSH EPILOGON WINNER OR LOSER-------------- 
	
	 //epistrofi protereotitas paixti
     playerSequence(selection,&winner_zari,&loser_zari,&flag,zari_PL_A,zari_PL_B,zari_PL_pc,&play_first,
                   &play_second);   
                  
	 cout<<"\t\t\t\t\t\t\t\t\t";		  
     system("PAUSE");   
     system("CLS");   
	}while(selection<1 || selection>2 || flag==false);

    //-------------------------SET TON 2 PLAYER ANALOGA THN  EPILOGI KAI EPILOGI ALLAGIS ONOMATOS PAIKTI---------
	    
	printSelectPlayers(selection,winner_zari,player_A,player_B,player_PC);
	
//----------AN KAI EFOSON PROTOS PEKTIS GINONTE TA PARAKATO-----------------------------------
	    
//PROTOS PAIXTIS===============================================================================	


  if((winner_zari==play_first) && (play_first!=play_second))
    {
     cout<<"\n\t\tEPELEXE "<<CHOIS_SHIPS<<" PLOIA APO TA PARAKATO"<<endl;
	 cout<<"\t\t=============================================================================\n";			      
	 printBattleShips(battleships,ALL_SHIPS);  					//EKTYPOSI OLON TON DIATHESIMON PLOION    
	
     //printMatrixDefult(shp);   								 //ektyposi pinaka defult ships

     matxinitializationShoots(matx_gps_firstplayer);			//arxikopoihsh pinaka GPS PAIKTI PROTOU
    
      //arxikopihsi DEFULT PINAKA PLOION EPILOGIS PAIXTI
    do{
    	meter++;
    	
    	printPlayerFirst(winner_zari,player_A,player_B,player_PC); //ektyposi onomatos protoy pexti
    
    	
//-----------------TOPOTHETISI DIATHESIMON PLOION SE PINAKA----------------------------     //**NA GINEI SYNARTISIS 

   	
    	cout<<"\n\t\tmy ships (NUMBER):";                        //EKTYPOSI PLOION POY EPILEGEI arithmoi            
        for(int i=1; i<=ALL_SHIPS;i++)
	       {
	   	    if(baffer_mtxchoose_first_ply[i-1]!=0 )
	   	      cout<<baffer_mtxchoose_first_ply[i-1]<<" ";
		   } 
	
//-----------------EMFANISI PINAKA PEDIOY MAXHS --------------------------------------------- //**NA GINEI SYNARTISIS

   	
    	cout<<"\n\n\t-MAP MY BATTLESHIPS* -"<<endl;               //EKTYPOSI PEDIOY DEFULT "ADEIO" ^^~~~~~~~~~^^
	    letter='A';
	    cout<<"\n    "<<"\t  0"<<"\t     1"<<"\t        2"<<"\t   3"<<"\t      4"<<
		      "\t         5"<<"\t    6"<<"\t       7"<<"\t  8"<<"\t     9\n"<<endl;
	    for(int i=0; i<FLD_LIN; i++)
	       {
	   	    cout<<" "<<letter<<"  |";
	   	    letter++;
	   	
		    for(int j=0; j<FLD_COL; j++)
			    cout<<"^"<<matrix_Ships_player_first[i][j].get_in_name_ship()<<"^";
		    cout<<"\n";	
	       }
	       cout<<"\n";   
   
 	    flag=false;
    
//-----------------------------------ELENXOS ARITHMON EPILOGIS PLION APO XRISTI-------------  
        /*cout<<"winzar"<<winner_zari<<endl;
        cout<<"playfirst"<<play_first<<endl;
        cout<<"playsec"<<play_second<<endl;
        cout<<"loozar"<<loser_zari<<endl;*/
        
	    while(flag==false){
			cout<<"\nepilogi "<<meter<<" ship: ";
			if(winner_zari==3 && (winner_zari==play_first) && (play_first!=play_second)  )
			 {
				cout<<"  i am robot  "<<endl;
				flag=true;
			 }
			else 
			 {
			   cin>>buf_ch_select_ships;
			   flag=checkInputNum(buf_ch_select_ships);  //екемвос циа пкгйтокоцисг ломо аяихлым    	
			 }
		   	 
			if(flag==false )
			  {
			   cout<<"LATHOS EPILOGI DOSE ARITHMO APO 1-10 "<<endl;	
		       cout<<"\t\t\t\t\t\t\t\t\t";		 
		       system("PAUSE");   
		       system("CLS");
		       cout<<"\nPaizeis protos :";
    		   cout<<"\n\t\tEPELEXE "<<CHOIS_SHIPS<<" PLOIA APO TA PARAKATO"<<endl;
	           cout<<"\t\t=============================================================================\n";
			   printBattleShips(battleships,ALL_SHIPS);                //EKTYPOSI OLON TON DIATHESIMON PLOION
			   
			   cout<<"\n\n\t-MAP MY BATTLESHIPS* -"<<endl;             //EKTYPOSI PEDIOY DEFULT "ADEIO"		//**NA GINEI SYNARTISIS
			    letter='A';
			    cout<<"\n    "<<"\t  0"<<"\t     1"<<"\t        2"<<"\t   3"<<"\t      4"<<
				      "\t         5"<<"\t    6"<<"\t       7"<<"\t  8"<<"\t     9\n"<<endl;
			    for(int i=0; i<FLD_LIN; i++)
			       {
			   	    cout<<" "<<letter<<"  |";
			   	    letter++;
			   	
				    for(int j=0; j<FLD_COL; j++)
					    cout<<"^"<<matrix_Ships_player_first[i][j].get_in_name_ship()<<"^";
				    cout<<"\n";	
			       }
			     cout<<"\n"; 	 	
			    }
			    
			else if(flag==true)
			    {
		         if(winner_zari==3 && (winner_zari==play_first) && (play_first!=play_second)  )
			       {
				    select_ships=rand()%10;
				    for(int i=0; i<10  ;i++)
	                   {
	  	                if(baffer_mtxchoose_first_ply[i-1]==select_ships)
	  	                  {
	  	                   flag=false;
	  	                   cout<<"ELENXOS EPILOGIS IDIOY SHIP  BALTE ALLO PLOIO "<<endl;
	  	                   break;
						  }
						else
						  {
						   //cout<<"OK ALL SHIP[S]"<<endl;
						   flag=true;	
						  }
				       }
		            }
		         else 
			       {
			     	select_ships=transformStrInput(buf_ch_select_ships);    //летатяопг STR аяихлым се INT
			     	if(select_ships>=1 && select_ships<=10)
		             {  
		         	  flag=true;
		         	  for(int i=0; i<10  ;i++)
	                   {
	  	                if(baffer_mtxchoose_first_ply[i-1]==select_ships)
	  	                  {
	  	                   flag=false;
	  	                   cout<<"ELENXOS EPILOGIS IDIOY SHIP  BALTE ALLO PLOIO "<<endl;
	  	                   break;
						  }
						else
						  {
						   //cout<<"OK ALL SHIP[S]"<<endl;
						   flag=true;	
						  }
				       }
				     }
				    else
				      {
				   	   cout<<"EPITREPOMENOI ARITHMOI 1-10"<<endl;
				       flag=false;
				      }
			       }
			     }        
            };
	    
//------------EPILEGMEN0 PLOIO SE PINAKA GIA THN EMFANISI KAI EPILOGI TOYS----------------------

	    
		for(int i=1; i<=ALL_SHIPS; i++)
		   {
			if(select_ships==i)
			   {
			   	baffer_mtxchoose_first_ply[i-1]=select_ships;          //pinakas epilogon ploion  protoy pexti 
			    break;
			   }
		   }
		   
//----------------------EMFANISI ARITHMON POION PLOION EPILEGI O PEKTIS--------------------------
	   
		cout<<"\n\t\tmy ships (NUMBER):"; 							   //EKTYPOSI PLOION POY EPILEGEI   ARITHMOI      //**NA GINEI SYNARTISIS     
        for(int i=1; i<=ALL_SHIPS;i++)
	       {
	   	    if(baffer_mtxchoose_first_ply[i-1]!=0 )
	   	      cout<<baffer_mtxchoose_first_ply[i-1]<<" ";
		   } 
		       
			     
	    for(int i=1; i<=ALL_SHIPS; i++) 					//KATAXORISI STOIXIOY POINAKA PLOION  SE BUFFER GIA METAFORA SE PINAKA PEDIOY
	       {	
	   	   if(select_ships==i)
	   	     {
	   	      baffer_ship=battleships[i-1];
	   	   	  baffer_ship.printShips();
	   	   	  cnt++;
	   	   	  break;
		     }
		    else if(cnt==CHOIS_SHIPS)
		      {
		      	cout<<"\tEPELEXES OLA SOY TA PLOIA"<<endl;
		      	i=ALL_SHIPS;
		      	system("PAUSE");
		      	break ;
			  } 
	        }
	        
//---------------EPILOGES SYNTETAGMENON GIA TOPOUETISI PLOION STON PINAKA PEDIOY MAXHS TOY PEKTI-------------
	       
        if(cnt<=CHOIS_SHIPS)
          {
             //eisadosgi dedomenon APO xristi  //TOPOTHETISI PLOION STO PEDIO
           do{ 
              flag=true;
              if(winner_zari==3 && (winner_zari==play_first) && (play_first!=play_second))
			    {
				 flag=inputGpsShip(&let_choice_1,&let_choice_2,&let_choice_3,&simeio_i,
                                &simeio_j,&posision,&sail_ship,baffer_ship,5,5);//topothetisi ploiy gps                               
                }
			   else 
			    {
			     flag=inputGpsShip(&let_choice_1,&let_choice_2,&let_choice_3,&simeio_i,
                                 &simeio_j,&posision,&sail_ship,baffer_ship,winner_zari,loser_zari);//topothetisi ploiy gps 	
			    }
           	  
              thesis=baffer_ship.get_in_ship_length();//MHKOS PLOIOY 
                
//-------------------ELENXOS AN SYMPIPTOY TA POLOIA EPILOGIS TOY PEXTI-------------------------- 

               if(flag==true)
				  {
  			       cout<<"\n\n\t- ELENXOS PLOION* -"<<endl;  							//EKTYPOSI PEDIOY DEFULT "ADEIO"
		          
				   cout<<"     "<<baffer_ship.get_in_name_ship()<<" MIKOS PLOIOY_"<<baffer_ship.get_in_ship_length(); 
			       for(int i=0; i<FLD_LIN; i++)
			          {
				      for(int j=0; j<FLD_COL; j++)
				        {
				         if(simeio_i==i && simeio_j==j && posision==1 && simeio_i+thesis>FLD_COL )  //ELENXOS AN XEPERNAEI TA ORIA TOY PINAKA KATHETA
					       {
					        cout<<"\n\n    XEPERASES TA OPRIA TOY PEDIOY"<<endl;
					        flag=false;
					         break;
						   }
					     else if(simeio_i==i && simeio_j==j && posision==1 && simeio_i+thesis<=FLD_COL ) 
						   {
						   	cout<<"\n\n   EISAI MESA STA OPRIA TOY PEDIOY"<<endl;
						   	flag=true;
						   	 break;
						    }	
				         else if(simeio_i==i && simeio_j==j && posision==2 && simeio_j+thesis>FLD_COL )  //ELENXOS AN XEPERNAEI TA ORIA TOY PINAKA ORIZONTIA
					       {
					        cout<<"\n\n    XEPERASES TA OPRIA TOY PEDIOY"<<endl;
					        flag=false;
					         break;
						   }
					     else if(simeio_i==i && simeio_j==j && posision==2 && simeio_j+thesis<=FLD_COL ) 
						   {
						   	cout<<"\n\n   EISAI MESA STA ORIA TOY PEDIOY"<<endl;
						   	flag=true;
						   	 break;
						    } 	
					      }
			           }
			           
			       for(int i=0; i<FLD_LIN; i++)
			          {
				       for(int j=0; j<FLD_COL; j++)
				         {
				          if(simeio_i==i && simeio_j==j && posision==1 )    //ELENXOS GIA SYGKROYSI PLOION  KATHETA
			   	            {  
			               for(int i=0; i<thesis; i++)
			                 {
				              for(int j=0; j<thesis; j++)
		                        {
		           	             if(matrix_Ships_player_first[(simeio_i)+i][(simeio_j)].get_in_name_ship()!="~~~~~~~~~")
								    {
								      cout<<"\n\n    PROSOXH SYGKROYSI PLOION"<<endl;
					                  flag=false;
		           	                   break;
									}
		                         }
							   break;	     
		                      }	
			               } 
			              else if(simeio_i==i && simeio_j==j && posision==2 )     //ELENXOS GIA SYGKROYSI PLOION  ORIZONTIA
			                {
			                 for(int i=0; i<thesis; i++)
			                   {
				                for(int j=0; j<thesis; j++)
		                          {
		                           if(matrix_Ships_player_first[(simeio_i)][(simeio_j)+j].get_in_name_ship()!="~~~~~~~~~")
								     {
								      cout<<"\n\n    PROSOXH SYGKROYSI PLOION"<<endl;
					                  flag=false;
		           	                   break;
									 }	
		                           }
								  break;      
		                         } 
			                  }
			              }
			           }
			        cout<<"\n"; 	 	
			      if(flag==true)
                    {
              	     cout<<"\n   EPITYXIS KATAXORISI..."<<endl;
			        }
			      else if(flag==false)
			        {
			         cout<<"\n  APOTYXIA-DOSE SOSTES SYNTETAGMENES "<<endl;
				    }
			   
                  }
		       }while(flag==false);
	      }
	      
	      
 //----------------------------------------------KATAXORISI EPILOGIS SYNTETAGMENIS KAI PLOIOY STON PINAKA --------------
    
	    //ARXIKOPOIISI SHIPS STO PINAKA PEDIOY 
	    for(int i=0; i<FLD_LIN; i++)     //katheti topothetisi
	      {
	   	   for(int j=0; j<FLD_COL; j++)
	   	      {
	   	       if(simeio_i==i && simeio_j==j && posision==1 )    //KATAXORISI SE PINAKA PEDIOY GIA KATHETA
	   	         {  
	              for(int i=0; i<thesis; i++)
	                 {
		              for(int j=0; j<thesis; j++)
                        {
           	             matrix_Ships_player_first[(simeio_i)+i][(simeio_j)+j]=baffer_ship;  //epilogi sigkekrimenis thesis ston pinaka
           	             break;
                        }    
                      }	
	              } 
	            else if(simeio_i==i && simeio_j==j && posision==2) //KATAXORISI GIA ORIZONTIA
	               {
	                for(int i=0; i<thesis; i++)
	                   {
		                for(int j=0; j<thesis; j++)
                          {
           	               matrix_Ships_player_first[(simeio_i)+j][(simeio_j)+i]=baffer_ship; //epilogi sigkekrimenis thesis ston pinaka
           	               break;
                          }    
                        }  	
	                }
	            if(posision==1)            // KATAXORISI SE PINAKA GPS STIGMA KATHETA
	              {
	              for(int i=0; i<thesis; i++)
	                 {
		             for(int j=0; j<thesis; j++)
                        {
           	             matx_gps_firstplayer[(simeio_i)+i][(simeio_j)+j]='X'; //epilogi sigkekrimenis thesis ston pinaka
           	             break;
                        }    
                      }	
	               } 
	            else if(posision==2)        // KATAXORISI SE PINAKA GPS STIGMA ORIZONTIA
	                 {
	                 for(int i=0; i<thesis; i++)
	                    {
		                for(int j=0; j<thesis; j++)
                           {
           	                matx_gps_firstplayer[(simeio_i)+j][(simeio_j)+i]='X'; //epilogi sigkekrimenis thesis ston pinaka
           	                break;
                           }    
                        }  	
	                 } 
		        } 
		    } 
		 
	    cout<<"\t\t\t\t\t\t\t\t\t";		 
        system("PAUSE");   
        system("CLS");
        
//---------------------------------TOPOTHETISI PLORIS PLOIOY ARISTERA H DEXEIA-----------------------
	  
	       for(int i=0; i<FLD_LIN; i++)
	          {
	   	       for(int j=0; j<FLD_COL; j++)
		          {
		           if(simeio_i==i && simeio_j==j && posision==1) //GIA EKTYPOSI OBJ PLORIS KATHETA
		             {
		              matrix_Ships_player_first[i][j].set_shipparts("^/-------",select_ships);
		             }
		          else if(sail_ship==1 && simeio_i==i && simeio_j==j && posision==2) //GIA EKTYPOSI OBJ PLORIS ARISTERA
		             {
		              matrix_Ships_player_first[i][j].set_shipparts("<|-------",select_ships);
		             }
		           else if(sail_ship==2 && simeio_i==i && (simeio_j+thesis-1)==j && posision==2) //GIA EKTYPOSI OBJ PLORIS DEXIA
		             {
				      matrix_Ships_player_first[i][j].set_shipparts("-------|>",select_ships);
		              }  
			      }   
	            cout<<"\n";   
	           }
	      
        if(meter<CHOIS_SHIPS)
          {
           system("CLS");	
       	   printLogo();
           printBattleShips(battleships,ALL_SHIPS);  //EKTYPOSI OLON TON DIATHESIMON PLOION PROS EPILOGI
	      }
    }while(meter<CHOIS_SHIPS);
	system("CLS");
	
//-------------------------------------------------//EKTYPOSI PLOION STO PEDIO------------------------------
	 
    printLogo();
    cout<<"\n\t-MAP MY BATTLESHIPS ALL -"<<endl;
	printPlayerFirst(winner_zari,player_A,player_B,player_PC); //ektyposi onomatos protoy pexti
	
	letter='A';
	cout<<"\n    "<<"\t  0"<<"\t     1"<<"\t        2"<<"\t   3"<<"\t      4"<<
		      "\t         5"<<"\t    6"<<"\t       7"<<"\t  8"<<"\t     9\n"<<endl;
	for(int i=0; i<FLD_LIN; i++)
	   {
	   	cout<<" "<<letter<<"  |";
	   	letter++;
	   	   for(int j=0; j<FLD_COL; j++)
			   cout<<"^"<<matrix_Ships_player_first[i][j].get_in_name_ship()<<"^"; 	 
	          
		 cout<<"\n";	
	    }
	    
    matxPrintShoots(matx_gps_firstplayer);//EKTIPOSI GPS PLOION PEKTI
    } 
	cout<<"\n\t\t\t\t\t\t\t\t\t";
    system("PAUSE");
    system("CLS");	
    
    
 //DEYTEROS PAIXTIS===============================================================================
 
    meter=0;
	cnt=0; 
    
    cout<<"\n\t\tEPELEXE "<<CHOIS_SHIPS<<" PLOIA APO TA PARAKATO"<<endl;
	cout<<"\t\t=============================================================================\n";
    
  if((loser_zari==play_second) && (play_first!=play_second))
    { 				      
	 printBattleShips(battleships,ALL_SHIPS);  					//EKTYPOSI OLON TON DIATHESIMON PLOION    
	
     //printMatrixDefult(shp);   								 //ektyposi pinaka defult ships

     matxinitializationShoots(matx_gps_secondplayer);//arxikopoihsh pinaka GPS PAIKTI DEYTEROY
    
     //arxikopihsi DEFULT PINAKA PLOION EPILOGIS PAIXTI
    do{
    	meter++;
    	
    	printPlayerSecond(loser_zari,player_A,player_B,player_PC); //ektyposi onomatos deyteroy pexti
    	
    	
//-----------------TOPOTHETISI DIATHESIMON PLOION SE PINAKA----------------------------     //**NA GINEI SYNARTISIS 
   	
    	cout<<"\n\t\tmy ships (NUMBER):";                        //EKTYPOSI PLOION POY EPILEGEI arithmoi            
        for(int i=1; i<=ALL_SHIPS;i++)
	       {
	   	    if(baffer_mtxchoose_second_ply[i-1]!=0 )
	   	      cout<<baffer_mtxchoose_second_ply[i-1]<<" ";
		   } 
    	
//-----------------EMFANISI PINAKA PEDIOY MAXHS --------------------------------------------- //**NA GINEI SYNARTISIS
   	
    	cout<<"\n\n\t-MAP MY BATTLESHIPS* -"<<endl;               //EKTYPOSI PEDIOY DEFULT "ADEIO" ^^~~~~~~~~~^^
	    letter='A';
	    cout<<"\n    "<<"\t  0"<<"\t     1"<<"\t        2"<<"\t   3"<<"\t      4"<<
		      "\t         5"<<"\t    6"<<"\t       7"<<"\t  8"<<"\t     9\n"<<endl;
	    for(int i=0; i<FLD_LIN; i++)
	       {
	   	    cout<<" "<<letter<<"  |";
	   	    letter++;
	   	
		    for(int j=0; j<FLD_COL; j++)
			    cout<<"^"<<matrix_Ships_player_second[i][j].get_in_name_ship()<<"^";
		    cout<<"\n";	
	       }
	       cout<<"\n";   
   
 	    flag=false;
 	    
//-----------------------------------ELENXOS ARITHMON EPILOGIS PLION APO XRISTI-------------   	
       /* cout<<"winzar"<<winner_zari<<endl;
        cout<<"playfirst"<<play_first<<endl;
        cout<<"playsec"<<play_second<<endl;
        cout<<"loozar"<<loser_zari<<endl;*/
        
	    while(flag==false){
			cout<<"\nepilogi "<<meter<<" ship: ";
			if(loser_zari==3 && (loser_zari==play_second) && (play_first!=play_second))
			 {
				cout<<"  i am robot  "<<endl;
				flag=true;
			 }
			else 
			 {
			   cin>>buf_ch_select_ships;
			   flag=checkInputNum(buf_ch_select_ships);  //екемвос циа пкгйтокоцисг ломо аяихлым    	
			 }
		   
			if(flag==false )
			  {
			   cout<<"LATHOS EPILOGI DOSE ARITHMO APO 1-10 "<<endl;	
		       cout<<"\t\t\t\t\t\t\t\t\t";		 
		       system("PAUSE");   
		       system("CLS");
		       cout<<"\nPaizeis deyteros :";
    		   cout<<"\n\t\tEPELEXE "<<CHOIS_SHIPS<<" PLOIA APO TA PARAKATO"<<endl;
	           cout<<"\t\t=============================================================================\n";
			   printBattleShips(battleships,ALL_SHIPS);                //EKTYPOSI OLON TON DIATHESIMON PLOION
			   
			   cout<<"\n\n\t-MAP MY BATTLESHIPS* -"<<endl;             //EKTYPOSI PEDIOY DEFULT "ADEIO"		//**NA GINEI SYNARTISIS
			    letter='A';
			    cout<<"\n    "<<"\t  0"<<"\t     1"<<"\t        2"<<"\t   3"<<"\t      4"<<
				      "\t         5"<<"\t    6"<<"\t       7"<<"\t  8"<<"\t     9\n"<<endl;
			    for(int i=0; i<FLD_LIN; i++)
			       {
			   	    cout<<" "<<letter<<"  |";
			   	    letter++;
			   	
				    for(int j=0; j<FLD_COL; j++)
					    cout<<"^"<<matrix_Ships_player_second[i][j].get_in_name_ship()<<"^";
				    cout<<"\n";	
			       }
			     cout<<"\n"; 	 	
			    }
			    
			else if(flag==true)
			    { 
				 if(loser_zari==3 && (loser_zari==play_second) && (play_first!=play_second))
			       {
				    select_ships=rand()%10;
				    for(int i=0; i<10  ;i++)
	                   {
	  	                if(baffer_mtxchoose_second_ply[i-1]==select_ships)
	  	                  {
	  	                   flag=false;
	  	                   cout<<"ELENXOS EPILOGIS IDIOY SHIP  BALTE ALLO PLOIO "<<endl;
	  	                   break;
						  }
						else
						  {
						   //cout<<"OK ALL SHIP[S]"<<endl;
						   flag=true;	
						  }
				       }
		            }
		         else 
			       {
			     	select_ships=transformStrInput(buf_ch_select_ships);    //летатяопг STR аяихлым се INT
			     	if(select_ships>=1 && select_ships<=10)
		             {  
		         	  flag=true;
		         	  for(int i=0; i<10  ;i++)
	                   {
	  	                if(baffer_mtxchoose_second_ply[i-1]==select_ships)
	  	                  {
	  	                   flag=false;
	  	                   cout<<"ELENXOS EPILOGIS IDIOY SHIP  BALTE ALLO PLOIO "<<endl;
	  	                   break;
						  }
						else
						  {
						   //cout<<"OK ALL SHIP[S]"<<endl;
						   flag=true;	
						  }
				       }
				     }
				    else
				      {
				   	   cout<<"EPITREPOMENOI ARITHMOI 1-10"<<endl;
				       flag=false;
				      }
			       }
			     }        
            };
	    
//------------EPILEGMEN0 PLOIO SE PINAKA GIA THN EMFANISI KAI EPILOGI TOYS----------------------
	    
		for(int i=1; i<=ALL_SHIPS; i++)
		   {
			if(select_ships==i)
			   {
			   	baffer_mtxchoose_second_ply[i-1]=select_ships;          //pinakas epilogon ploion  protoy pexti 
			    break;
			   }
		   }
		   
//----------------------EMFANISI ARITHMON POION PLOION EPILEGI O PEKTIS--------------------------	
	   
		cout<<"\n\t\tmy ships (NUMBER):"; 				  //EKTYPOSI PLOION POY EPILEGEI   ARITHMOI      //**NA GINEI SYNARTISIS     
        for(int i=1; i<=ALL_SHIPS;i++)
	       {
	   	    if(baffer_mtxchoose_second_ply[i-1]!=0 )
	   	      cout<<baffer_mtxchoose_second_ply[i-1]<<" ";
		   } 
		       
			     
	    for(int i=1; i<=ALL_SHIPS; i++) 					//KATAXORISI STOIXIOY POINAKA PLOION  SE BUFFER GIA METAFORA SE PINAKA PEDIOY
	       {	
	   	   if(select_ships==i)
	   	     {
	   	      baffer_ship=battleships[i-1];
	   	   	  baffer_ship.printShips();
	   	   	  cnt++;
	   	   	  break;
		     }
		    else if(cnt==CHOIS_SHIPS)
		      {
		      	cout<<"\tEPELEXES OLA SOY TA PLOIA"<<endl;
		      	i=ALL_SHIPS;
		      	system("PAUSE");
		      	break ;
			  } 
	        }
	        
//---------------EPILOGES SYNTETAGMENON GIA TOPOTHETISI PLOION STON PINAKA PEDIOY MAXHS TOY PEKTI-------------
	       
        if(cnt<=CHOIS_SHIPS)
          {
             //eisadosgi dedomenon APO xristi  //TOPOTHETISI PLOION STO PEDIO
           do{ 
              flag=true;
              if(loser_zari==3 && (loser_zari==play_second) && (play_first!=play_second))
			    {
				 flag=inputGpsShip(&let_choice_1,&let_choice_2,&let_choice_3,&simeio_i,
                                &simeio_j,&posision,&sail_ship,baffer_ship,5,5);//topothetisi ploiy gps
                                
                }
			  else 
			    {
			     flag=inputGpsShip(&let_choice_1,&let_choice_2,&let_choice_3,&simeio_i,
                                 &simeio_j,&posision,&sail_ship,baffer_ship,winner_zari,loser_zari);//topothetisi ploiy gps 	
			    }
              thesis=baffer_ship.get_in_ship_length();//MHKOS PLOIOY 
                
//-------------------ELENXOS AN SYMPIPTOY TA POLOIA EPILOGIS TOY PEXTI-------------------------- 

               if(flag==true)
				  {
  			       cout<<"\n\n\t- ELENXOS PLOION* -"<<endl;  							//EKTYPOSI PEDIOY DEFULT "ADEIO"
		          
				   cout<<"     "<<baffer_ship.get_in_name_ship()<<" MIKOS PLOIOY_"<<baffer_ship.get_in_ship_length(); 
			       for(int i=0; i<FLD_LIN; i++)
			          {
				      for(int j=0; j<FLD_COL; j++)
				        {
				         if(simeio_i==i && simeio_j==j && posision==1 && simeio_i+thesis>FLD_COL )  //ELENXOS AN XEPERNAEI TA ORIA TOY PINAKA KATHETA
					       {
					        cout<<"\n\n    XEPERASES TA OPRIA TOY PEDIOY"<<endl;
					        flag=false;
					         break;
						   }
					     else if(simeio_i==i && simeio_j==j && posision==1 && simeio_i+thesis<=FLD_COL ) 
						   {
						   	cout<<"\n\n   EISAI MESA STA OPRIA TOY PEDIOY"<<endl;
						   	flag=true;
						   	 break;
						    }	
				         else if(simeio_i==i && simeio_j==j && posision==2 && simeio_j+thesis>FLD_COL )  //ELENXOS AN XEPERNAEI TA ORIA TOY PINAKA ORIZONTIA
					       {
					        cout<<"\n\n    XEPERASES TA OPRIA TOY PEDIOY"<<endl;
					        flag=false;
					         break;
						   }
					     else if(simeio_i==i && simeio_j==j && posision==2 && simeio_j+thesis<=FLD_COL ) 
						   {
						   	cout<<"\n\n   EISAI MESA STA ORIA TOY PEDIOY"<<endl;
						   	flag=true;
						   	 break;
						    } 	
					      }
			           }
			           
			      for(int i=0; i<FLD_LIN; i++)
			         {
				      for(int j=0; j<FLD_COL; j++)
				        {
				         if(simeio_i==i && simeio_j==j && posision==1 )    //ELENXOS GIA SYGKROYSI PLOION  KATHETA
			   	           {  
			               for(int i=0; i<thesis; i++)
			                 {
				              for(int j=0; j<thesis; j++)
		                        {
		           	             if(matrix_Ships_player_second[(simeio_i)+i][(simeio_j)].get_in_name_ship()!="~~~~~~~~~")
								    {
								      cout<<"\n\n    PROSOXH SYGKROYSI PLOION"<<endl;
					                  flag=false;
		           	                   break;
									}
		                         }
							   break;	     
		                      }	
			               } 
			             else if(simeio_i==i && simeio_j==j && posision==2 )     //ELENXOS GIA SYGKROYSI PLOION  ORIZONTIA
			               {
			                for(int i=0; i<thesis; i++)
			                   {
				                for(int j=0; j<thesis; j++)
		                          {
		                           if(matrix_Ships_player_second[(simeio_i)][(simeio_j)+j].get_in_name_ship()!="~~~~~~~~~")
								     {
								      cout<<"\n\n    PROSOXH SYGKROYSI PLOION"<<endl;
					                  flag=false;
		           	                   break;
									 }	
		                           }
								  break;      
		                         } 
			                  }
			              }
			           }
			        cout<<"\n"; 	 	
			      if(flag==true)
                    {
              	     cout<<"\n   EPITYXIS KATAXORISI..."<<endl;
			        }
			      else if(flag==false)
			        {
			         cout<<"\n  APOTYXIA-DOSE SOSTES SYNTETAGMENES "<<endl;
				    }
			   
                  }
		       }while(flag==false);
	      }
	      
	      
 //----------------------------------------------KATAXORISI EPILOGIS SYNTETAGMENIS KAI PLOIOY STON PINAKA --------------
    
	    //ARXIKOPOIISI SHIPS STO PINAKA PEDIOY 
	    for(int i=0; i<FLD_LIN; i++)     //katheti topothetisi
	      {
	   	   for(int j=0; j<FLD_COL; j++)
	   	      {
	   	       if(simeio_i==i && simeio_j==j && posision==1 )    //KATAXORISI SE PINAKA PEDIOY GIA KATHETA
	   	         {  
	              for(int i=0; i<thesis; i++)
	                 {
		              for(int j=0; j<thesis; j++)
                        {
           	             matrix_Ships_player_second[(simeio_i)+i][(simeio_j)+j]=baffer_ship;  //epilogi sigkekrimenis thesis ston pinaka
           	             break;
                        }    
                      }	
	              } 
	            else if(simeio_i==i && simeio_j==j && posision==2) //KATAXORISI GIA ORIZONTIA
	               {
	                for(int i=0; i<thesis; i++)
	                   {
		                for(int j=0; j<thesis; j++)
                          {
           	               matrix_Ships_player_second[(simeio_i)+j][(simeio_j)+i]=baffer_ship; //epilogi sigkekrimenis thesis ston pinaka
           	               break;
                          }    
                        }  	
	                }
	            if(posision==1)            // KATAXORISI SE PINAKA GPS STIGMA KATHETA
	              {
	              for(int i=0; i<thesis; i++)
	                 {
		             for(int j=0; j<thesis; j++)
                        {
           	             matx_gps_secondplayer[(simeio_i)+i][(simeio_j)+j]='X'; //epilogi sigkekrimenis thesis ston pinaka
           	             break;
                        }    
                      }	
	               } 
	            else if(posision==2)        // KATAXORISI SE PINAKA GPS STIGMA ORIZONTIA
	                 {
	                 for(int i=0; i<thesis; i++)
	                    {
		                for(int j=0; j<thesis; j++)
                           {
           	                matx_gps_secondplayer[(simeio_i)+j][(simeio_j)+i]='X'; //epilogi sigkekrimenis thesis ston pinaka
           	                break;
                           }    
                        }  	
	                 } 
		        } 
		    } 
		 
	    cout<<"\t\t\t\t\t\t\t\t\t";		 
        system("PAUSE");   
        system("CLS");
        
//---------------------------------TOPOTHETISI PLORIS PLOIOY ARISTERA H DEXEIA H KATHETA-----------------------
	  
	       for(int i=0; i<FLD_LIN; i++)
	          {
	   	       for(int j=0; j<FLD_COL; j++)
		          {
		           if(simeio_i==i && simeio_j==j && posision==1) //GIA EKTYPOSI OBJ PLORIS KATHETA
		             {
		              matrix_Ships_player_second[i][j].set_shipparts("^/-------",select_ships);
		             }
		          else if(sail_ship==1 && simeio_i==i && simeio_j==j && posision==2) //GIA EKTYPOSI OBJ PLORIS ARISTERA
		             {
		              matrix_Ships_player_second[i][j].set_shipparts("<|-------",select_ships);
		             }
		           else if(sail_ship==2 && simeio_i==i && (simeio_j+thesis-1)==j && posision==2) //GIA EKTYPOSI OBJ PLORIS DEXIA
		             {
				      matrix_Ships_player_second[i][j].set_shipparts("-------|>",select_ships);
		              }  
			      }   
	            cout<<"\n";   
	           }
	      
        if(meter<CHOIS_SHIPS)
          {
           system("CLS");	
       	   printLogo();
           printBattleShips(battleships,ALL_SHIPS);  //EKTYPOSI OLON TON DIATHESIMON PLOION PROS EPILOGI
	      }
    }while(meter<CHOIS_SHIPS);
	system("CLS");
	
//-------------------------------------------------//EKTYPOSI PLOION STO PEDIO------------------------------
	 
    printLogo();
    cout<<"\n\t-MAP MY BATTLESHIPS ALL -"<<endl;
	printPlayerSecond(loser_zari,player_A,player_B,player_PC); //ektyposi onomatos protoy pexti
	
	letter='A';
	cout<<"\n    "<<"\t  0"<<"\t     1"<<"\t        2"<<"\t   3"<<"\t      4"<<
		      "\t         5"<<"\t    6"<<"\t       7"<<"\t  8"<<"\t     9\n"<<endl;
	for(int i=0; i<FLD_LIN; i++)
	   {
	   	cout<<" "<<letter<<"  |";
	   	letter++;
	   	   for(int j=0; j<FLD_COL; j++)
			   cout<<"^"<<matrix_Ships_player_second[i][j].get_in_name_ship()<<"^"; 	 
	          
		 cout<<"\n";	
	    }
	    
    matxPrintShoots(matx_gps_secondplayer);//EKTIPOSI GPS PLOION PEKTI
    } 
	cout<<"\n\t\t\t\t\t\t\t\t\t";
    system("PAUSE");
    system("CLS");	
    


 //EKTYPOSEIS MAP BATLLESHIPS  KAI GPS  BATLLESHIPS PAIKTON =============================================================
   
  do
   {
    printLogo();  //logo game 
    cout<<"\n\t\t           VISUAL MAPS              \n"<<endl;
    cout<<"\t     1.GPS MAP - 2.BATTLE MAP - 0.MAPS_EXIT >" ;
    cin>>visual_maps;
    cout<<endl;
	switch(visual_maps)
		  {
		    case 1:
		    	   printPlayerFirst(winner_zari,player_A,player_B,player_PC); //ektyposi onomatos protoy pexti
		           matxPrintShoots(matx_gps_firstplayer);
		           printPlayerSecond(loser_zari,player_A,player_B,player_PC); //ektyposi onomatos protoy pexti
                   matxPrintShoots(matx_gps_secondplayer);
				 break; 	
		    case 2:
		    	   letter='A';
		    	   cout<<"\n\t-MAP MY BATTLESHIPS ALL -"<<endl;
		    	   printPlayerFirst(winner_zari,player_A,player_B,player_PC); //ektyposi onomatos protoy pexti
		    	   cout<<"\n    "<<"\t  0"<<"\t     1"<<"\t        2"<<"\t   3"<<"\t      4"<<
		                  "\t         5"<<"\t    6"<<"\t       7"<<"\t  8"<<"\t     9\n"<<endl;
		           for(int i=0; i<FLD_LIN; i++)
	                  {
	   	               cout<<" "<<letter<<"  |";
	   	               letter++;
	   	              for(int j=0; j<FLD_COL; j++)
		                 {
			              cout<<"^"<<matrix_Ships_player_first[i][j].get_in_name_ship()<<"^"; 
	                      }
		               cout<<"\n";	
	                  }
	                  
	                letter='A';
		    	   cout<<"\n\t-MAP MY BATTLESHIPS ALL -"<<endl;
		    	   printPlayerSecond(loser_zari,player_A,player_B,player_PC); //ektyposi onomatos protoy pexti
		    	   cout<<"\n    "<<"\t  0"<<"\t     1"<<"\t        2"<<"\t   3"<<"\t      4"<<
		                  "\t         5"<<"\t    6"<<"\t       7"<<"\t  8"<<"\t     9\n"<<endl;
		           for(int i=0; i<FLD_LIN; i++)
	                  {
	   	               cout<<" "<<letter<<"  |";
	   	               letter++;
	   	              for(int j=0; j<FLD_COL; j++)
		                 {
						  cout<<"^"<<matrix_Ships_player_second[i][j].get_in_name_ship()<<"^"; 	 
	                      }
		               cout<<"\n";	
	                  }  
		         break; 
		    case 0:
		    	   cout<<"\t\t  >>EXODOS APO TO VISUAL MAPS"<<endl;
		    	   visual_maps==0;
			     break;
		    default:
	      		cout<<"\t\t >>EXEIS DOSEI LATHOS EPILOGI..."<<endl;		          
		  }
	cout<<"\n\t\t\t\t\t\t\t\t\t";	  
	system("PAUSE");	   
	system("CLS");
		  
   }while(visual_maps!=0);
    
    
//==============================to begin the naval battle===============================================

   matxinitializationShoots(matx_SHOOT_firstplayer);
   matxinitializationShoots(matx_SHOOT_secondplayer);
   int numShips_player_second=0;
   int numShips_player_firs=0;
   for(int i=0; i<FLD_LIN; i++)
	  {
	  for(int j=0; j<FLD_COL; j++)
		 {
		  if(matrix_Ships_player_second[i][j].get_in_name_ship()!= "~~~~~~~~~" )
		    {
		     matrix_Ships_player_second[i][j];
		     numShips_player_second++;
		     //cout<<"numsA"<<numShips_player_second<<endl;
			}	
	      }
       }
    for(int i=0; i<FLD_LIN; i++)
	  {
	  for(int j=0; j<FLD_COL; j++)
		 {
		  if(matrix_Ships_player_first[i][j].get_in_name_ship()!= "~~~~~~~~~" )
		    {
		     matrix_Ships_player_first[i][j];
		     numShips_player_firs++;
		     //cout<<"numsB"<<numShips_player_firs<<endl;
			}	
	      }
       }
  cout<<"\n\n\t\t-TO BEGGIN THE NAVAL BATTLE-\n"<<endl;
  cout<<"\t\t=============================\n"; 
  do
   {
  	shoot_cnt++;
    if((winner_zari==play_first) && (play_first!=play_second))
     {
  	  //do
  	   //{
  	   	flag=true;
  	   	printPlayerFirst(winner_zari,player_A,player_B,player_PC); //ektyposi onomatos protoy pexti
  	    cout<<"\n\tPLOIA STON ORIZONTA ()W "<<shoot_cnt<<".VOLI"<<endl;
  	    if(winner_zari==3 && (winner_zari==play_first) && (play_first!=play_second))
  	      {
  	       flag=inputshootsShip(&shoot_first_ply_voli_i,&simeio_i,&shoot_first_ply_voli_j, 5, 5);	
		  }
		else
		  {
		   flag=inputshootsShip(&shoot_first_ply_voli_i,&simeio_i,&shoot_first_ply_voli_j, winner_zari, loser_zari); 	
		  }  
	    int shoot_frst_vol_i=simeio_i;
	    for(int i=0; i<FLD_LIN; i++)
		  {
		   for(int j=0; j<FLD_COL; j++)
		     {  
			 if(shoot_frst_vol_i==i && shoot_first_ply_voli_j==j && matrix_Ships_player_second[i][j].get_in_name_ship()!= "~~~~~~~~~" &&
			    matrix_Ships_player_second[i][j].get_in_name_ship()!= "(x)TARGET") 
			    {
				 cout<<"\n\n\tTARGET LOCKED (x)wait..."<<endl;
				 matrix_Ships_player_second[i][j].printShips();
				 sleep(2);
				 matrix_Ships_player_second[i][j].set_mission(matrix_Ships_player_second[i][j].get_in_id_ship(),
				 matrix_Ships_player_second[i][j].get_in_name_ship(),
				 matrix_Ships_player_second[i][j].get_in_crew(),matrix_Ships_player_second[i][j].get_in_ammo(),
				 matrix_Ships_player_second[i][j].get_in_ship_length());
				 matrix_Ships_player_second[i][j].set_in_name_ship("(x)TARGET");
				 cout<<"\n\n\tTO PLOIO XTYPITHIKE"<<endl;
				 for(int i=0; i<FLD_LIN; i++)
		           {
		           for(int j=0; j<FLD_COL; j++)
		             {      
				     if(matrix_Ships_player_second[shoot_frst_vol_i][shoot_first_ply_voli_j].get_in_id_ship()==
				        matrix_Ships_player_second[i][j].get_in_id_ship()&&matrix_Ships_player_second[i][j].get_in_name_ship()!= "(x)TARGET")
				        {
					     matrix_Ships_player_second[i][j].set_mission(matrix_Ships_player_second[i][j].get_in_id_ship(),
					     matrix_Ships_player_second[i][j].get_in_name_ship(),
				         matrix_Ships_player_second[i][j].get_in_crew(),matrix_Ships_player_second[i][j].get_in_ammo(),
				         matrix_Ships_player_second[i][j].get_in_ship_length());
					   }    
				     }
			       }
				 cout<<"\n\tSUCCESSFUL GOAL "<<endl;
				 cout<<"\tDAMAGE TO THE SHIP :"; matrix_Ships_player_second[i][j].printShips();
				 // cout<<"\n\n\tO EPOMENOS PEKTIS XANEI THN SEIRA TOY"<<endl;
			     matx_SHOOT_firstplayer[shoot_frst_vol_i][shoot_first_ply_voli_j]='H'; 
				 flag=true;
				}
			 
			  else if(shoot_frst_vol_i==i && shoot_first_ply_voli_j==j && matrix_Ships_player_second[i][j].get_in_name_ship()== "~~~~~~~~~") //ELENXOS AN XEPERNAEI TA ORIA TOY PINAKA KATHETA
			   {
			   	 matx_SHOOT_firstplayer[shoot_frst_vol_i][shoot_first_ply_voli_j]='X'; 
				 cout<<"\n\n\tASTOXISES"<<endl;
				 flag=false;
				}
			if(winner_zari==1 && flag==true && matrix_Ships_player_second[i][j].get_in_name_ship()== "(x)TARGET")
			 {
			  player_A.set_in_total((matrix_Ships_player_second[i][j].get_in_crew()*10)+matrix_Ships_player_second[i][j].get_in_ammo()+1000);
			  total_sum_WN+=player_A.get_in_total();
              player_A.set_in_total(total_sum_WN);
			 } 
            else if(winner_zari==2 && flag==true && matrix_Ships_player_second[i][j].get_in_name_ship()== "(x)TARGET")
              {
               player_B.set_in_total((matrix_Ships_player_second[i][j].get_in_crew()*10)+matrix_Ships_player_second[i][j].get_in_ammo()+1000);
			   total_sum_WN+=player_B.get_in_total();
                player_B.set_in_total(total_sum_WN);
			  } 
	       else if(winner_zari==3 && flag==true && matrix_Ships_player_second[i][j].get_in_name_ship()== "(x)TARGET")
             {
              player_PC.set_in_total((matrix_Ships_player_second[i][j].get_in_crew()*10)+matrix_Ships_player_second[i][j].get_in_ammo()+1000);
		      total_sum_WN+=player_PC.get_in_total();
              player_PC.set_in_total(total_sum_WN);
			 }	
		    }
		   }
		matxPrintShoots(matx_SHOOT_firstplayer); 
		cout<<"\n==============================\n"; 
	   //}while(flag==true );
	   
      }
    cout<<"Please whait..."<<endl;  
    sleep(2);    
	system("PAUSE");   
    if((loser_zari==play_second) && (play_first!=play_second))
     { 
  	  //do
  	   //{
  	   	flag=true;
  	   	printPlayerSecond(loser_zari,player_A,player_B,player_PC); //ektyposi onomatos protoy pexti 
  	    cout<<"\n\tPLOIA STON ORIZONTA ()L "<<shoot_cnt<<".VOLI"<<endl;
  	    if(loser_zari==3 && (loser_zari==play_second) && (play_first!=play_second))
  	      {
  	       flag=inputshootsShip(&shoot_first_ply_voli_i,&simeio_i,&shoot_second_ply_voli_j,5,5);
  	      }
  	    else
  	      {
  	        flag=inputshootsShip(&shoot_second_ply_voli_i,&simeio_i,&shoot_second_ply_voli_j, winner_zari, loser_zari);
		  }
	    int shoot_second_vol_i=simeio_i;
	    for(int i=0; i<FLD_LIN; i++)
		  {
		   for(int j=0; j<FLD_COL; j++)
		     {  
			 if(shoot_second_vol_i==i && shoot_second_ply_voli_j==j && matrix_Ships_player_first[i][j].get_in_name_ship()!= "~~~~~~~~~" &&
			    matrix_Ships_player_first[i][j].get_in_name_ship()!= "(x)TARGET") 
			    {
				 cout<<"\n\n\tTARGET LOCKED (x)wait..."<<endl;
				 matrix_Ships_player_first[i][j].printShips();
				 sleep(2);
				 matrix_Ships_player_first[i][j].set_mission(matrix_Ships_player_first[i][j].get_in_id_ship(),
				 matrix_Ships_player_first[i][j].get_in_name_ship(),
				 matrix_Ships_player_first[i][j].get_in_crew(),matrix_Ships_player_first[i][j].get_in_ammo(),
				 matrix_Ships_player_first[i][j].get_in_ship_length());
				 matrix_Ships_player_first[i][j].set_in_name_ship("(x)TARGET");
				 cout<<"\n\n\tTO PLOIO XTYPITHIKE"<<endl;
				 for(int i=0; i<FLD_LIN; i++)
		           {
		           for(int j=0; j<FLD_COL; j++)
		             {      
				     if(matrix_Ships_player_first[shoot_second_vol_i][shoot_second_ply_voli_j].get_in_id_ship()==
				        matrix_Ships_player_first[i][j].get_in_id_ship()&&matrix_Ships_player_second[i][j].get_in_name_ship()!= "(x)TARGET")
				        {
					     matrix_Ships_player_first[i][j].set_mission(matrix_Ships_player_first[i][j].get_in_id_ship(),
					     matrix_Ships_player_first[i][j].get_in_name_ship(),
				         matrix_Ships_player_first[i][j].get_in_crew(),matrix_Ships_player_first[i][j].get_in_ammo(),
				         matrix_Ships_player_first[i][j].get_in_ship_length());
					   }    
				     }
			       }
				 cout<<"\n\tSUCCESSFUL GOAL "<<endl;
				 cout<<"\tDAMAGE TO THE SHIP ";matrix_Ships_player_first[i][j].printShips();
				 //cout<<"\n\n\tO EPOMENOS PEKTIS XANEI THN SEIRA TOY"<<endl;
			     matx_SHOOT_secondplayer[shoot_second_vol_i][shoot_second_ply_voli_j]='H'; 
				 flag=true;
				}
			  else if(shoot_second_vol_i==i && shoot_second_ply_voli_j==j && matrix_Ships_player_first[i][j].get_in_name_ship()== "~~~~~~~~~") //ELENXOS AN XEPERNAEI TA ORIA TOY PINAKA KATHETA
			   {
			   	 matx_SHOOT_secondplayer[shoot_second_vol_i][shoot_second_ply_voli_j]='X'; 
				 cout<<"\n\n\tASTOXISES"<<endl;
				 flag=false;
				 break;
				}
			if(loser_zari==1 && flag==true && matrix_Ships_player_first[i][j].get_in_name_ship()== "(x)TARGET")
			 {
			  player_A.set_in_total((matrix_Ships_player_first[i][j].get_in_crew()*10)+matrix_Ships_player_first[i][j].get_in_ammo()+1000);
			  total_sum_LS+=player_A.get_in_total();
              player_A.set_in_total(total_sum_LS);
			 }
            else if(loser_zari==2 && flag==true && matrix_Ships_player_first[i][j].get_in_name_ship()== "(x)TARGET")
             {
			  player_B.set_in_total((matrix_Ships_player_first[i][j].get_in_crew()*10)+matrix_Ships_player_first[i][j].get_in_ammo()+1000);
			  total_sum_LS+=player_B.get_in_total();
              player_B.set_in_total(total_sum_LS);
			 } 
	        else if(loser_zari==3 && flag==true && matrix_Ships_player_first[i][j].get_in_name_ship()== "(x)TARGET")
             {
			  player_PC.set_in_total((matrix_Ships_player_first[i][j].get_in_crew()*10)+matrix_Ships_player_first[i][j].get_in_ammo()+1000);
			  total_sum_LS+=player_PC.get_in_total();
              player_PC.set_in_total(total_sum_LS);
			 }
			//cout<<matrix_Ships_player_first[i][j].get_in_ship_length(); 
		    }
		   }
			matxPrintShoots(matx_SHOOT_secondplayer);
			cout<<"\n==============================\n"; 
			    
	   //}while(flag==true);
      }
    //ELENXOS PAIXNIDIOY 
	 int cntshipsA=0; 
     for(int i=0; i<FLD_LIN; i++)
	   {
	   for(int j=0; j<FLD_COL; j++)
		 {
		  if(matrix_Ships_player_second[i][j].get_in_name_ship()=="(x)TARGET" )
			{
			 cntshipsA++;
			// cout<<"---"<<cntshipsA<<endl;	
		    }
		 }
		    
       }
	if(numShips_player_second==cntshipsA)
	  {
		cout<<"\n\n\tTO PAIXNIDI TELEIOSE DEN YPARXOYN PLOIA STON ORIZONTA"<<endl;
		shoot_cnt=VOLES	;
	  } 
	// system("PAUSE"); 
    //ELENXOS PAIXNIDIOY 
	int cntshipsB=0;
      for(int i=0; i<FLD_LIN; i++)
		{
		for(int j=0; j<FLD_COL; j++)
		   {
		    if(matrix_Ships_player_first[i][j].get_in_name_ship()=="(x)TARGET" )
		      {
			   cntshipsB++;
			   //cout<<"---"<<cntshipsB<<endl;	
			  }			
		    }
		    
         }
    if(numShips_player_firs==cntshipsB)
	  {
		cout<<"\n\n\tTO PAIXNIDI TELEIOSE DEN YPARXOYN PLOIA STON ORIZONTA"<<endl;
		shoot_cnt=VOLES	;
	  } 
    system("PAUSE");  
    system("CLS");  
  }while(shoot_cnt<VOLES);  
	  
  system("CLS");
  
   //EKTYPOSEIS MAP BATLLESHIPS  KAI GPS  BATLLESHIPS PAIKTON =============================================================
   
  do
   {
    printLogo();  //logo game 
    cout<<"\n\t\t           VISUAL MAPS              \n"<<endl;
    cout<<"\t     1.GPS MAP - 2.BATTLE MAP - 0.MAPS_EXIT >" ;
    cin>>visual_maps;
    cout<<endl;
	switch(visual_maps)
		  {
		    case 1:
		    	   printPlayerFirst(winner_zari,player_A,player_B,player_PC); //ektyposi onomatos protoy pexti
		           matxPrintShoots(matx_SHOOT_firstplayer);
		           printPlayerSecond(loser_zari,player_A,player_B,player_PC); //ektyposi onomatos protoy pexti
                   matxPrintShoots(matx_SHOOT_secondplayer);
				 break; 	
		    case 2:
		    	   letter='A';
		    	   cout<<"\n\t-MAP MY BATTLESHIPS ALL -"<<endl;
		    	   printPlayerFirst(winner_zari,player_A,player_B,player_PC); //ektyposi onomatos protoy pexti
		    	   cout<<"\n    "<<"\t  0"<<"\t     1"<<"\t        2"<<"\t   3"<<"\t      4"<<
		                  "\t         5"<<"\t    6"<<"\t       7"<<"\t  8"<<"\t     9\n"<<endl;
		           for(int i=0; i<FLD_LIN; i++)
	                  {
	   	               cout<<" "<<letter<<"  |";
	   	               letter++;
	   	              for(int j=0; j<FLD_COL; j++)
		                 {
			              cout<<"^"<<matrix_Ships_player_first[i][j].get_in_name_ship()<<"^"; 
	                      }
		               cout<<"\n";	
	                  }
	                  
	               letter='A';
		    	   cout<<"\n\t-MAP MY BATTLESHIPS ALL -"<<endl;
		    	   printPlayerSecond(loser_zari,player_A,player_B,player_PC); //ektyposi onomatos protoy pexti
		    	   cout<<"\n    "<<"\t  0"<<"\t     1"<<"\t        2"<<"\t   3"<<"\t      4"<<
		                  "\t         5"<<"\t    6"<<"\t       7"<<"\t  8"<<"\t     9\n"<<endl;
		           for(int i=0; i<FLD_LIN; i++)
	                  {
	   	               cout<<" "<<letter<<"  |";
	   	               letter++;
	   	              for(int j=0; j<FLD_COL; j++)
		                 {
						  cout<<"^"<<matrix_Ships_player_second[i][j].get_in_name_ship()<<"^"; 	 
	                      }
		               cout<<"\n";	
	                  }  
		         break; 
		    case 0:
		    	   cout<<"\t\t  >>EXODOS APO TO VISUAL MAPS"<<endl;
		    	   visual_maps==0;
			     break;
		    default:
	      		cout<<"\t\t >>EXEIS DOSEI LATHOS EPILOGI..."<<endl;		          
		  }
	cout<<"\n\t\t\t\t\t\t\t\t\t";	  
	system("PAUSE");	   
	system("CLS");
		  
   }while(visual_maps!=0);	
	
	//APOTELESMATA NIKITI PAIXNIDIOY
	
	cout<<"\n\t\t          THE WINNER IS :"<<endl;
	
	if( player_A.get_in_total() > player_B.get_in_total())
	  {
	   	player_A.printPlayers();
	  }
	else if( player_A.get_in_total() < player_B.get_in_total())
	  {
	   	player_B.printPlayers(); 
	  }  
	else if( player_A.get_in_total() > player_PC.get_in_total())
	  {
	   	player_A.printPlayers(); 
	  }    
	else if( player_A.get_in_total() < player_PC.get_in_total())
	  {
	   	player_PC.printPlayers(); 
	  }    
	
	cout<<"\n\t\t\t\t\t\t\t\t\t";	  
	system("PAUSE");	 			        
	return 0;
}


