#include "Armor.h"
#include "Character.h"
#include "Map.h"
#include "Store.h"
#include "Weapon.h"
#include <iostream>
void Create_Charcter();
void Main_choose();
using namespace std;
int main(){
    Create_Charcter();
    Main_choose();
    //player1weaponStore=storeManager.CreatWeaponStore(player1->GetName());
}
void Create_Charcter(){
    cout << "Welcome.";
    cout << "\nChoose your Character.\n";
    CreatCharacter My_CreatCharacter;
    Character *player1 = 0;
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
    player1->Show_Character(); //End 角色创建success
}
void Main_choose(){
    WeaponStore *My_weaponStore = nullptr;
    StoreManager *Total_Store = nullptr;
    Weapon *My_Weapon = nullptr;
    Character *player1 = nullptr;
    PistolWeaponStore *Pistol = nullptr;
    ShotgunWeaponStore *Shotgun = nullptr;
    SniperWeaponStore *Sniper = nullptr;
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
			case 1:				//Move  Map
				break;
			case 2:				//买武器
                Total_Store->Show();
                cout<<"\t0.Back"<<endl;
				while(1)
				{
					cout<<"Choose "<<endl;
                    cin >> Int_choose;
                    if(!cin)						
					{
						cin.clear();				
						cin.sync();					
						cout<<"Not this type weapon!\n"<<endl;
						continue;
					}
					if(Int_choose!=0&&Int_choose!=1&&Int_choose!=2&&Int_choose!=3&&Int_choose!=4)
						cout<<"Not this type weapon!\n"<<endl;
                    else switch(Int_choose){
                        case 1:{
                            Pistol->Show();
                        };
                        case 2:{
                            Shotgun->Show();
                        };
                        case 3:{
                            Sniper->Show();
                        };
                        default:{
                            cout << "Enter error.\nNow back to previous choose.\n";
                            break;
                        }
                    }
					/*else
					{
                        Weapon *tempWeapon = My_weaponStore->CreatWeapon(Int_choose);
                        if(player1->Get_Money()<tempWeapon->Get_Price()-player1->Get_Weapon()->Get_Price())
						{
							cout<<"Not enough Money"<<endl;
							delete tempWeapon;
						}
						else
						{
							delete tempWeapon;
							break;
						}
					}*/
				}
				if(Int_choose==0)
					break;
				My_Weapon=My_weaponStore->CreatWeapon(Int_choose);
				player1->GetWeapon(My_Weapon);
				break;
			case 3:				//attack
				break;
			case 4:			//?? back
				break;
			}
			if(Int_choose!=0)
				break;
		}
}
/*
CreatCharacter My_CreatCharacter;
    WeaponStore* My_weaponStore=0;
    Weapon *My_Weapon=0;
    Character *player1 = 0;
    StoreManager storeManager;
    int Int_choose;
    string String_choose;
    


    while (1) //input;
    {
		cin>>Int_choose;
		if(!cin)						
		{
			cin.clear();				
			cin.sync();					
			cout<<"Input error,please enter again!\n"<<endl;
			continue;
		};
        if(Int_choose!=1||Int_choose!=2||Int_choose!=3){
            
        }
        else
            break;
    }
    getline(cin, String_choose);
    My_weaponStore = storeManager.CreatWeaponStore(String_choose);  //商店
    while(1)
	{
		cout<<"choose"<<endl;
		cin>>choose;
		if(!cin)						
		{
			cin.clear();				
			cin.sync();					
			cout<<"Input error,please enter again!\n"<<endl;
			continue;
		}
		if(choose!=0&&choose!=1&&choose!=2&&choose!=3&&choose!=4)
			cout<<"Input error,please enter again!"<<endl;
		else if(choose==0)
			break;
		else
		{
			Weapon* tempWeapon=My_weaponStore->CreatWeapon(choose);
			if(player1->Get_Money()<tempWeapon->Get_Price()-player1->Get_Weapon()->Get_Price())
			{
				cout<<"Not enough money."<<endl;
				delete tempWeapon;
				}
				else
			{
			 	delete tempWeapon;
				break;
			}
		}
	}
    My_Weapon = My_weaponStore->CreatWeapon(choose);
    player1->GetWeapon(My_Weapon);
    My_weaponStore->Show();
    player1->Show_Character(); 
    system("pause");
    */