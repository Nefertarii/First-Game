#include "Armor.h"
#include "Character.h"
#include "Store.h"
#include "Weapon.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
int Max_Round = rand() % 100 + 50;
int Max_Monster = rand() % 5 + 10;//10
int Max_Case = 2;//2
int Max_Store = 1;//1
int Empty_Room=rand() % 1 + 2;//3
int Round = 0;
int Met_EmptyRoom = 0;
int Met_Monster = 0;
int Met_Case = 0;
int Met_Store = 0;
int Int_choose = 0;
int Count = 0;
bool Game_Over = false;
bool Have_store = false;
bool CanFire = true;
StoreManager *Total_Store = nullptr;
Weapon *My_Weapon = nullptr;
Character *player1 = nullptr;
CreatCharacter My_CreatCharacter;
int choose;
int Rand(){
    srand((unsigned)time(0));
    int happen = rand() % 10;
    return happen;
}
int Monster_Rand(){
    srand((unsigned)time(0));
    int Monster = rand() % 5 + 5;
    return Monster;
}
void Fight(){
    Character *Monster = nullptr;
    CreatMonster Monster_CreatCharacter;
    Monster = Monster_CreatCharacter.creatmonster(Monster_Rand());
    cout << "This is its property:\n";
    Monster->Show_Monster();
    int Fight_choose = 0;
    cout << "\n1.Attack\t2.Move\n"
    <<"*(If you move while the monster is attacking will not loss of health).\nYour choose: ";
    while(Monster->Get_Health()>0){
    while (1){
	    cin>>Fight_choose;
	    if(!cin)						
	    {
	        cin.clear();				
		    cin.sync();					
		    cout<<"Don't do this, face him\n"<<endl;
		    continue;
	    }
	    if(choose!=1&&choose!=2&&choose!=3)
	        cout<<"Don't do this, face him\n";
	    else
	     	break;
    }
    switch (Fight_choose){
    case 1:{
        if(My_Weapon->Get_Now_AMMO()==0){
            CanFire = false;
            cout << "Not Ammo,must reaload.\n";
            if (Monster_Rand() == 5){
                player1->TakeAttack(Monster->Get_ATK());
                cout << "You taking " << Monster->Get_ATK() << " Damege!";
                cout << "Yout health: " << player1->Get_Health();
                cout << endl;
            }
        }
        Monster->TakeAttack(player1->Get_ATK());
        cout << "You used " << My_Weapon->Get_Name() << " caused " << player1->Get_ATK() << " Damage.";
        cout << Monster->Get_Character() << " have " << Monster->Get_Health() << " health.";
        cout << endl;
        if (Monster_Rand() == 5){
            player1->TakeAttack(Monster->Get_ATK());
            cout << "You taking " << Monster->Get_ATK() << " Damege!";
            cout << "Yout health: " << player1->Get_Health();
            cout << endl;
        }
        My_Weapon->Fire();
        cout << "Next choose: ";
        break;
    }
    case 2:{
        if (Monster_Rand() == 5)
        {
            cout << "You dodge the attack!\tVery nice.\n";
        }
        else
            cout << "Nothing is happen.\tThe monster did not attack.\n";
        cout << "Next choose: ";
        break;
    }
    case 3:{
        cout << "Readload now..." << endl;
        CanFire = true;
        My_Weapon->Reaload();
    }
    default:{
        cout << "Don't do this\n";
        break;
    }
    Round++;
    Met_Monster++;
    }//fight choose
    cout << "Battle is end."
         << "You kill: " << Monster->Get_Character()
         << endl;
    int Get = rand() % 5;
    cout << "Monster dorp " <<Get<<" Money "<< endl;
    player1->Get_Money(Get);
    cout << "The game has been played for " << Round << " rounds." << endl;
    cout << "Please ESC to quit.Use the arrow keys to operate.\n";
    delete Monster;
    }
}
void WeaponStore(){
        Total_Store->Show();
        cout<<"\t0.Back"<<endl;
        bool quit = false;
        while(quit!=true){
		cout<<"Choose: "<<endl;
        cin >> Int_choose;
        if(!cin){
			cin.clear();				
			cin.sync();					
			cout<<"Not this type weapon!\n"<<endl;
			continue;
		}
		if(Int_choose!=1&&Int_choose!=2&&Int_choose!=3)
		cout<<"Not this type weapon!\n"<<endl;
        else switch(Int_choose){
        case 0:{
            break;
        }
        case 1:{
            PistolWeaponStore Pistol;
            PistolStore:Pistol.Show();
            cout<<"Choose "<<endl;
            int Temp_choose;
            cin >> Temp_choose;
            if(!cin){
						    cin.clear();				
						    cin.sync();					
						    cout<<"Not this type weapon!\n"<<endl;
						    continue;
					        }
            if(player1->Get_Money()>=(Pistol.CreatWeapon(Temp_choose))->Get_Price()) 
            {
                My_Weapon = Pistol.CreatWeapon(Temp_choose);
                player1->GetWeapon(My_Weapon);
                player1->Show_Character(); 
                break;
            }
            else{
                cout << "Not enough Money.";
                cout << "Now you have " << player1->Get_Money() << endl;
                goto PistolStore;
            }
            quit = true;
            Have_store = false;
            break;
        };
        case 2:{
            ShotgunWeaponStore Shotgun;
            ShotgunStore:Shotgun.Show();
            cout<<"Choose "<<endl;
            int Temp_choose;
            cin >> Temp_choose;
            if(!cin){
						    cin.clear();				
						    cin.sync();					
						    cout<<"Not this type weapon!\n"<<endl;
						    continue;
					        }
            if(player1->Get_Money()>=(Shotgun.CreatWeapon(Temp_choose))->Get_Price())  
            {
                My_Weapon = Shotgun.CreatWeapon(Temp_choose);
                player1->GetWeapon(My_Weapon);
                player1->Show_Character(); 
                break;
            }
            else{
                cout << "Not enough Money.";
                cout << "Now you have " << player1->Get_Money() << endl;
                goto ShotgunStore;
            }
            quit = true;
            Have_store = false;
            break;
        };
        case 3:{
            SniperWeaponStore Sniper;
            SniperStore:Sniper.Show();
            cout<<"Choose "<<endl;
            int Temp_choose;
            cin >> Temp_choose;
            if(!cin){
						    cin.clear();				
						    cin.sync();					
						    cout<<"Not this type weapon!\n"<<endl;
						    continue;
					        }
            if(player1->Get_Money()>=(Sniper.CreatWeapon(Temp_choose))->Get_Price())  
            {
                My_Weapon = Sniper.CreatWeapon(Temp_choose);
                player1->GetWeapon(My_Weapon);
                player1->Show_Character(); 
                break;
            }
            else{
                cout << "Not enough Money.";
                cout << "Now you have " << player1->Get_Money() << endl;
                goto SniperStore;
            }
            quit = true;
            Have_store = false;
            break;
        };
        default:{
            cout << "Enter error.\nNow back to main menu.\n";
            break;
        }
        break;
        }
		if(Int_choose==0)
			break;
        else{
			    player1->GetWeapon(My_Weapon);
        Have_store = false;
        break;
    }
    }
}
void Game_Judge(){
    cout << "The game has been played for " << Round << " rounds." << endl;
    if(Round==Max_Round)
    Game_Over = true;
    else if (player1->Get_Health()==0)
        Game_Over = true;
}
using namespace std;
int main(){
    cout << "Welcome.";
    cout << "Game Max round is:" << Max_Round << endl;
    cout << "1.Pilot, health = 10, Weaponatk = 5\n";
    cout << "2.Hunter, health = 10, Weaponatk = 5\n";
    cout << "3.Criminal, health = 10, Weaponatk = 5\n";
    cout << "Choose your Character:\a";
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
    BaseWeaponStore Base;
    My_Weapon = Base.CreatWeapon(choose);
    int Int_choose;
    string String_choose;
    while(Game_Over!=true){
	cout<<"Gamecontinue! "<<"\n1.Move\n2.Show\n3.quit"<<endl;
    cout << "The game has been played for " << Round << " rounds." << endl;
	while(1){
			cin>>Int_choose;
			if(!cin){
				cin.clear();				
				cin.sync();					
				cout<<"Input error,please enter again!\n"<<endl;
				continue;
			}
			if(Int_choose!=1&&Int_choose!=2&&Int_choose!=3)
                cout << "Input error,please enter again!" << endl;
            else
                break;
    }
	switch(Int_choose){
	case 1:{          //Move
    int ch;
    cout << "Please ESC to quit.Use the arrow keys to operate.\n";
    while( (ch=getch())!=27 ){  
            switch(ch)
            {
            case 224:
    switch(ch=getch()){
           case 72:{
               cout << ("UP\n");
               int Temp = Rand();
               if(Temp==1||Temp==2||Temp==3||Temp==4){
                   if(Met_Monster==Max_Monster){
               goto Empty_Up;
                   }
                   cout << "You met a monster!\n";
                   Fight();
                }
               else if(Temp==5){
                   if(Met_Store==Max_Store){
               goto Empty_Up;
                   }
                   cout << "You met a Weapon dealer!\n";
                   Have_store = true;
                   WeaponStore();
                   Met_Store++;
                   Round++;
                   Game_Judge();
                   break;
               }
               else if(Temp==6||Temp==7||Temp==8){
                   Round++;
                   Empty_Up:cout << "It's a empty room.\n go next.\n";
                   Game_Judge();
                   break;
               }
               else{
                   if(Met_Case==Max_Case){
               goto Empty_Up;
                   }
                   cout << "It's a Room .\nThere a case in the room!\n";
                   Met_Case++;
                   Round++;
                   Game_Judge();
               }
               break;
            }

           case 80:{
                cout<<("DOWN\n");
                int Temp = Rand();
                if(Temp==1){
                   cout << "You met a monster!\n";
                   Fight();
               }
               else if(Temp==5){
                   if(Met_Store==Max_Store){
               goto Empty_Down;
                   }
                   cout << "You met a Weapon dealer!\n";
                   WeaponStore();
                   Met_Store++;
                   Round++;
                   Game_Judge();
                   break;
               }
               else if(Temp==6||Temp==7||Temp||8){
                   Round++;
                   Empty_Down:cout << "It's a empty room.\n go next.\n";
                   Game_Judge();
                   break;
               }
               else{
                   if(Met_Case==Max_Case){
               goto Empty_Down;
                   }
                   cout << "It's a Room .\nThere a case in the room!\n";
                   Met_Case++;
                   Round++;
                   Game_Judge();
               }
               break;
            }
           case 75:{  
               cout<<("LEFT\n");
               int Temp = Rand();
               if(Temp==1){
                   cout << "You met a monster!\n";
                   Fight();
               }
               else if(Temp==5){
                   if(Met_Store==Max_Store){
               goto Empty_Left;
                   }
                   cout << "You met a Weapon dealer!\n";
                   WeaponStore();
                   Met_Store++;
                   Round++;
                   Game_Judge();
                   break;
               }
               else if(Temp==6||Temp==7||Temp||8){
                   Round++;
                   Empty_Left:cout << "It's a empty room.\n go next.\n";
                   Game_Judge();
                   break;
               }
               else{
                   if(Met_Case==Max_Case){
               goto Empty_Left;
                   }
                   cout << "It's a Room .\nThere a case in the room!\n";
                   Met_Case++;
                   Round++;
                   Game_Judge();
               }
               break;
            }
           case 77:{  
               cout<<("RIGHT\n");
               int Temp = Rand();
               if(Temp==1){
                   cout << "You met a monster!\n";
                   Fight();
               }
               else if(Temp==5){
                   if(Met_Store==Max_Store){
               goto Empty_Right;
                   }
                   cout << "You met a Weapon dealer!\n";
                   WeaponStore();
                   Met_Store++;
                   Round++;
                   Game_Judge();
                   break;
               }
               else if(Temp==6||Temp==7||Temp||8){
                   Round++;
                   Empty_Right:cout << "It's a empty room.\n go next.\n";
                   Game_Judge();
                   break;
               }
               else{
                   if(Met_Case==Max_Case){
               goto Empty_Right;
                   }
                   cout << "It's a Room .\nThere a case in the room!\n";
                   Met_Case++;
                   Round++;
                   Game_Judge();
               }
               break;
            }

           default:
               break;
    }
    break;
            default:
               break;
            }
    }
    break;
    }		
    case 2:{			//?? back
    player1->Show_Character();
    break;
    }
    case 3:{
        string temp;
        cout<<"Are you sure to quit?\nInput (Yes) to quit.";
    if(temp=="Yes"||temp=="yet")
        Game_Over = true;
    break;
    }//case 3
    }//switch(Int_choose)
    }//while(Game_Over!=true)
    cout << "\n\n\nGame is Over.\nThanks for play.";
    system("pause");
}