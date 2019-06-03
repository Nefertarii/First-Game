#include "Character.h"
#include "Store.h"
#include "Weapon.h"
#include "Define.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
StoreManager *Total_Store = nullptr;
PistolWeaponStore Pistol;
SniperWeaponStore Sniper;
ShotgunWeaponStore Shotgun;
Weapon *My_Weapon = nullptr;
Character *player1 = nullptr;
Character *Monster = nullptr;
CreatCharacter My_CreatCharacter;
int choose;
int Input(){
    
    return Int_choose;
}
int Random(){
    int happen = rand() % 10;
    return happen;
}
int Monster_Random(){
    int Monster = rand() % 5 + 5;
    return Monster;
}
void Monster_Attack(){
    if(Monster_Random() == 5){
    player1->TakeAttack(Monster->Get_ATK());
    cout << "You taking " << Monster->Get_ATK() << " Damege!";
    cout << "Yout health: " << player1->Get_Health() << endl;
    cout << endl;
    }
}
void Fight(int numbers){
    CreatMonster Monster_CreatCharacter;
    if(numbers==10){
        Monster = Monster_CreatCharacter.creatmonster(10);
    }
    Monster = Monster_CreatCharacter.creatmonster(Monster_Random());
    cout << "This is its property:\n";
    Monster->Show_Monster();
    cout << "\n1.Attack\t2.Move\n"
    <<"*(If you move while the monster is attacking will not loss of health).\nYour choose: ";
    while(Monster->Get_Health()!=0){
        //Input
        while (1){
            cin >> Int_choose;
            if(!cin){
	    	cin.clear();				
	    	cin.sync();					
	    	cout<<"Input error,please enter again!\n"<<endl;
	    	continue;
	    	}
	    	if(Int_choose!=1&&Int_choose!=2&&Int_choose!=3)
	    		cout<<"Input error,please enter again!\n";
	    	else
	    		break;
	    }
        switch (Int_choose){
        case 1:{
            if(My_Weapon->Get_Now_AMMO()>0){
                Monster->TakeAttack(player1->Get_ATK());
                cout << "You used \"" << My_Weapon->Get_Name() << "\" caused " << My_Weapon->Get_ATK() << " Damage.";
                cout << Monster->Get_Character() << " now have " << Monster->Get_Health() << " health.\n";
                //enemy attack
                Monster_Attack();
                if (player1->Get_Health() == 0){
                    Game_Over = true;
                    goto Gameover;
                }
                cout << endl;
                My_Weapon->Fire();
                cout << "Next choose: ";
            }
            else{
                cout << "Not Ammo.\n";
                if(Monster_Random() == 5){
                player1->TakeAttack(Monster->Get_ATK());
                cout << "You taking " << Monster->Get_ATK() << " Damege!";
                cout << "Yout health: " << player1->Get_Health() << endl;
                cout << endl;
                } 
            }
            break;
        }
        case 2:{
            if (Monster_Random() == 5){
                cout << "You dodge the attack!\tVery nice.\n";
            }
            else
                cout << "Nothing is happen.\tThe monster did not attack.\n";
            cout << "Next choose: ";
            break;
        }
        case 3:{
            My_Weapon->Reload();
            Monster_Attack();
            if (player1->Get_Health() == 0){
                Game_Over = true;
                goto Gameover;
            }
            else
                continue;
        }
        }
        if(player1->Get_Health()==0){
            Gameover:break;
    }
    }//battle end
    if(player1->Get_Health()==0){
        cout << "\n\n\nYou died.\n";
        Game_Over = true;
    }
    if(Game_Over==true){
        system("cls");
        cout << "Your health is 0!\n"
             << Monster->Get_Character() << " kill you.\n";
        cout << "Enter Esc to quit.\n";
    }
    else{
    cout << "\n\t\tBattle is end."
         << "You kill: " << Monster->Get_Character()
         << endl;
    int Drop = rand() % 5;
    cout << "Monster dorps " <<Drop<<" Money "<< endl;
    player1->Get_Money(Drop);
    Round++;
    Met_Monster++;
    cout << "The game has been played for " << Round << " rounds." << endl;
    cout << "Please ESC to quit.Use the arrow keys to operate.\n";
    }
}
void WeaponStore(){
    Total_Store->Show();
    cout<<"\t0.Back"<<endl;
    bool quit = false;
    while(quit!=true){
	cout<<"Choose: "<<endl;
    while (1){
        cin >> Int_choose;
        if(!cin){
		cin.clear();				
		cin.sync();					
		cout<<"Input error,please enter again!\n"<<endl;
		continue;
		}
		if(Int_choose!=0&&Int_choose!=1&&Int_choose!=2&&Int_choose!=3)
		cout<<"Not this type weapon!\n"<<endl;
        else
            break;
    }
        switch(Int_choose){
        case 0:{
            cout<<"Not this type Store!\n"<<endl;
            break;
        }
        case 1:{
            Pistol.Show();
            cout<<"Choose: "<<endl;
            int Temp_choose;
            while (1){
                cin >> Temp_choose;
                if(!cin){
		    	cin.clear();				
		    	cin.sync();					
		    	cout<<"Input error,please enter again!\n"<<endl;
		    	continue;
	    	    }
		        if(Temp_choose!=0&&Temp_choose!=1&&Temp_choose!=2&&Temp_choose!=3&&Temp_choose!=4)
		        cout<<"Not this type weapon!\n"<<endl;
                if(Temp_choose==0){
                    cout << "Quit.\n";
                    goto Quit;
                }
                else
                    break;
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
                break;
            }
            quit = true;
            break;
        };
        case 2:{
            Shotgun.Show();
            cout<<"Choose "<<endl;
            int Temp_choose;
            cin >> Temp_choose;
            while (1){
                cin >> Temp_choose;
                if(!cin){
		    	cin.clear();				
		    	cin.sync();					
		    	cout<<"Input error,please enter again!\n"<<endl;
		    	continue;
	    	    }
		        if(Temp_choose!=0&&Temp_choose!=1&&Temp_choose!=2&&Temp_choose!=3&&Temp_choose!=4)
		        cout<<"Not this type weapon!\n"<<endl;
                if(Temp_choose==0){
                    cout << "Quit.\n";
                    goto Quit;
                }
                else
                    break;
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
                break;
            }
            quit = true;
            break;
        };
        case 3:{

            Sniper.Show();
            cout<<"Choose "<<endl;
            int Temp_choose;
            while (1){
                cin >> Temp_choose;
                if(!cin){
		    	cin.clear();				
		    	cin.sync();					
		    	cout<<"Input error,please enter again!\n"<<endl;
		    	continue;
	    	    }
		        if(Temp_choose!=0&&Temp_choose!=1&&Temp_choose!=2&&Temp_choose!=3&&Temp_choose!=4)
		        cout<<"Not this type weapon!\n"<<endl;
                if(Temp_choose==0){
                    cout << "Quit.\n";
                    goto Quit;
                }
                else
                    break;
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
                break;
            }
            quit = true;
            break;
        };
        }
        Quit:break;
    }
}
void Game_Judge(){
    cout << "The game has been played for " << Round << " rounds." << endl;
    if(Round==Max_Round)
    Game_Over = true;
    else if (player1->Get_Health()==0)
        Game_Over = true;
}
void Start(){
    cout << "Welcome.";
    cout << "Game Max round is:" << Max_Round << endl;
    cout << "1.Pilot, health = 30, Weaponatk = 5\n";
    cout << "2.Hunter, health = 30, Weaponatk = 5\n";
    cout << "3.Criminal, health = 30, Weaponatk = 5\n";
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
    BaseWeaponStore Base;
    My_Weapon = Base.CreatWeapon(choose);
    player1->GetWeapon(My_Weapon);
    player1->Show_Character(); 
}
void Case(){
    if(Random()==5){
        player1->TakeAttack(-10);
    }
    else if(Random()==6||Random()==7){
        player1->Get_Money(Random());
    }
    else if(Random()==8){
        cout << "Oh this is a Box Monster";
        Fight(10);
    }
    else {
        cout << "It's a empty case.";
    }
}
using namespace std;
int main(){
    Start();
    int Int_choose;
    string String_choose;
    while(Game_Over!=true){
	cout<<"Game continue! "<<"\n1.Move\n2.Show\n3.quit"<<endl;
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
        if(Game_Over==true){
            ch = 27;
            cout << "Enter Esc to quit.\n";
            break;
        }
    switch(ch=getch()){
           case 72:{
               cout << ("UP\n");
               int Temp = Random();
               if(Temp==1||Temp==2||Temp==3||Temp==4){
                   if(Met_Monster==Max_Monster){
               goto Empty_Up;
                   }
                   cout << "You met a monster!\n";
                   Fight(0);
                }
               else if(Temp==5){
                   if(Met_Store==Max_Store){
               goto Empty_Up;
                   }
                   cout << "You met a Weapon dealer!\n";
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
                   Case();
                   Round++;
                   Game_Judge();
               }
               break;
            }

           case 80:{
                cout<<("DOWN\n");
                int Temp = Random();
                if(Temp==1){
                   cout << "You met a monster!\n";
                   Fight(0);
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
                   Case();
                   Round++;
                   Game_Judge();
               }
               break;
            }
           case 75:{  
               cout<<("LEFT\n");
               int Temp = Random();
               if(Temp==1){
                   cout << "You met a monster!\n";
                   Fight(0);
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
                   Case();
                   Round++;
                   Game_Judge();
               }
               break;
            }
           case 77:{  
               cout<<("RIGHT\n");
               int Temp = Random();
               if(Temp==1){
                   cout << "You met a monster!\n";
                   Fight(0);
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
                   Case();
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
        getline(cin, temp);
        if (temp == "Yes" || temp == "yes")
            Game_Over = true;
        break;
    }//case 3
    }//switch(Int_choose)
    }//while(Game_Over!=true)
    system("cls");
    cout << "Game is Over.Thanks for play.\n";
    system("pause");
}