#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "Weapon.h"
#include <iostream>	
class Character{
protected:
	std::string CharacterName;
	int Health;
	int ATK;
	int DEF;
	int Money;
	Weapon *Equie_Weapon;
public:
	Character(std::string character="none",int health=100,int atk=0,int def=0,int money=0){
		CharacterName=character;
		Health=health;
		ATK=atk;
		DEF=def;
		Money=money;
		Equie_Weapon = new Weapon();
	}
	std::string Get_Character() { return CharacterName; }
	int Get_Health() { return Health; }
	int Get_ATK() { return ATK; }
	int Get_DEF() { return DEF; }
	int Get_Money() { return Money; }
	Weapon* Get_Weapon(){return Equie_Weapon;}
	void GetWeapon(Weapon *Now){		
		Money-=Now->Get_Price() - Equie_Weapon->Get_Price();		//金币减少
		ATK+=Now->Get_ATK() - Equie_Weapon->Get_ATK();				//攻击力上升
		Equie_Weapon=Now;							
	}
	void Show_Character(){
		using namespace std;
		cout << "\nCharacter: " << CharacterName << endl;
		cout << "Health: " << Health << endl;
		cout << "ATK: " << ATK << "  DEF:  " << DEF << " Money: " << Money << endl;
		cout << "\tWeapon\n";
		cout << "Name: " << Equie_Weapon->Get_Name() << "\tAttack: " << ATK;
		cout << "\nWeapon Rank: " << Equie_Weapon->Get_Rank() << std::endl;
		cout << "Ammo: " << Equie_Weapon->Get_Now_AMMO() << "/" << Equie_Weapon->Get_AMMO() << std::endl;
	}
	void TakeAttack(int Damage){
		if(Damage>DEF)
			Health=Health-Damage+DEF;
		if(Health<0)
			Health=0;
	}
	virtual ~Character(){
		if(!Equie_Weapon)
			delete Equie_Weapon;
	}
};

class Pilot:public Character{
public:
    Pilot(std::string character = "Pilot", int health = 100, int atk = 5, int def = 0, int money = 0) : Character(character, health, atk, def, money){}
    ~Pilot() {}
};
class Pilot1:public Character{
public:
	Pilot1(std::string character = "Pilot", int health = 100, int atk = 5, int def = 0, int money = 0) : Character(character, health, atk, def, money){}
	~Pilot1(){}
};
class Pilot2:public Character{
public:
	Pilot2(std::string character = "Pilot", int health = 100, int atk = 5, int def = 0, int money = 0) : Character(character, health, atk, def, money){}
	~Pilot2(){}
};

class CreatCharacter{
public:
	Character *creatcharacter(int choose)
	{
		switch(choose)
		{
		case 1:
			return new Pilot();
			break;
		case 2:
			return new Pilot1();
			break;
		case 3:
			return new Pilot2();
			break;
		}
	}
};

#endif