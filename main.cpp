#include "Armor.h"
#include "Character.h"
#include "Map.h"
#include "Store.h"
#include "Weapon.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
void Create_Charcter();
void Main_choose();
using namespace std;
int main(){
    Generate_Map();
    cout << "Welcome.";
    cout << "\nChoose your Character.\n";
    WeaponStore *My_weaponStore = nullptr;
    StoreManager *Total_Store = nullptr;
    Weapon *My_Weapon = nullptr;
    Character *player1 = nullptr;
    PistolWeaponStore *Pistol_Store = nullptr;
    ShotgunWeaponStore *Shotgun_Store = nullptr;
    SniperWeaponStore *Sniper_Store = nullptr;
    CreatCharacter My_CreatCharacter;
    int choose;
    while (1) //input;
    {
		cin>>choose;
		if(!cin)						
		{
			cin.clear();				
			cin.sync();					
			cout<<"Input error,please enter again!\n"<<endl;
			continue;
		}
		if(choose!=1&&choose!=2&&choose!=3)
			cout<<"Input error,please enter again!\n";
		else
			break;
	}
    player1 = My_CreatCharacter.creatcharacter(choose);
    player1->Show_Character(); 
    int Int_choose;
    string String_choose;
    while(1)			//为了能退到上一级，即选择攻击或买武器等，需要这个循环
		{
			cout<<"Please select an action: "<<"\n1.Move\n2.Buy Weapon(if have store)\n3.attack\n4.back"<<endl;
			while(1)
			{
				cin>>Int_choose;
				if(!cin)						
				{
					cin.clear();				
					cin.sync();					
					cout<<"Input error,please enter again!\n"<<endl;
					continue;
				}
				if(Int_choose!=1&&Int_choose!=2&&Int_choose!=3&&Int_choose!=4)
					cout<<"Input error,please enter again!"<<endl;
				else
					break;
			}
			switch(Int_choose)
			{
			case 1:{                          //Move
                int ch;
                while( (ch=getch())!=27 )
                {  // Press ESC to quit... 
                    switch(ch)
                    {
                    case 224:
                        switch(ch=getch()){
                           case 72:  printf("UP\n"); break;
                           case 80:  printf("DOWN\n"); break;
                           case 75:  printf("LEFT\n"); break;
                           case 77:  printf("RIGHT\n"); break;
                           default:
                               break;
                        }
                        break;
                    default:
                       break;
                    }
                }
            }
			case 2:{			//买武器
                Total_Store->Show();
                cout<<"\t0.Back"<<endl;
                bool quit = false;
                while(quit!=true){
					cout<<"Choose "<<endl;
                    cin >> Int_choose;
                    if(!cin){
						cin.clear();				
						cin.sync();					
						cout<<"Not this type weapon!\n"<<endl;
						continue;
					}
					if(Int_choose!=0&&Int_choose!=1&&Int_choose!=2&&Int_choose!=3&&Int_choose!=4)
						cout<<"Not this type weapon!\n"<<endl;
                    else switch(Int_choose){
                        case 1:{
                            PistolWeaponStore Pistol;
                            Pistol.Show();
                            cout<<"Choose "<<endl;
                            int Temp_choose;
                            cin >> Temp_choose;
                            if(!cin){
						    cin.clear();				
						    cin.sync();					
						    cout<<"Not this type weapon!\n"<<endl;
						    continue;
					        }  
                            {
                                My_Weapon = Pistol.CreatWeapon(Temp_choose);
                                player1->GetWeapon(My_Weapon);
                                player1->Show_Character(); 
                                break;
                            }
                            quit = true;
                            break;
                        };
                        case 2:{
                            ShotgunWeaponStore Shotgun;
                            Shotgun.Show();cout<<"Choose "<<endl;
                            int Temp_choose;
                            cin >> Temp_choose;
                            if(!cin){
						    cin.clear();				
						    cin.sync();					
						    cout<<"Not this type weapon!\n"<<endl;
						    continue;
					        }  
                            {
                                My_Weapon = Shotgun.CreatWeapon(Temp_choose);
                                player1->GetWeapon(My_Weapon);
                                player1->Show_Character(); 
                                break;
                            }
                            quit = true;
                            break;
                        };
                        case 3:{
                            SniperWeaponStore Sniper;
                            Sniper.Show();cout<<"Choose "<<endl;
                            int Temp_choose;
                            cin >> Temp_choose;
                            if(!cin){
						    cin.clear();				
						    cin.sync();					
						    cout<<"Not this type weapon!\n"<<endl;
						    continue;
					        }  
                            {
                                My_Weapon = Sniper.CreatWeapon(Temp_choose);
                                player1->GetWeapon(My_Weapon);
                                player1->Show_Character(); 
                                break;
                            }
                            quit = true;
                            break;
                        };
                        default:{
                            cout << "Enter error.\nNow back to previous choose.\n";
                            break;
                        }
                    }
				if(Int_choose==0)
					break;
                else{
			    player1->GetWeapon(My_Weapon);
				break;
                }}
            }
			case 3:				//attack
				break;
			case 4:			//?? back
                break;
            }
			if(Int_choose!=0)
				break;
		}
}
//player1weaponStore=storeManager.CreatWeaponStore(player1->GetName());