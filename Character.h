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
	Character(std::string character="none",int health=30,int atk=0,int def=0,int money=0){
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
	int Get_Money(int number) { return Money += number; }
	Weapon* Get_Weapon(){return Equie_Weapon;}
	void GetWeapon(Weapon *Now){
		Money -= Now->Get_Price() - Equie_Weapon->Get_Price();
		ATK += Now->Get_ATK() - Equie_Weapon->Get_ATK();
		Equie_Weapon=Now;							
	}
	void Show_Character(){
		using namespace std;
		cout << "\nCharacter: " << CharacterName << endl;
		cout << "Health: " << Health << endl;
		cout << "ATK: " << ATK << "\tMoney: " << Money << endl;
		cout << "\tWeapon\n";
		cout << "Name: " << Equie_Weapon->Get_Name() << "\tAttack: " << ATK;
		cout << "\nWeapon Rank: " << Equie_Weapon->Get_Rank() << std::endl;
		cout << "Ammo: " << Equie_Weapon->Get_Now_AMMO() << "/" << Equie_Weapon->Get_Magazine() << std::endl;
	}
	void Show_Monster(){
		using namespace std;
		cout << "\nCharacter: " << CharacterName << endl;
		cout << "Health: " << Health << "\tAttack: " << ATK;
	}
	void TakeAttack(int Damage){
		Health -= Damage;
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
    Pilot(std::string character = "Pilot", int health = 30, int atk = 5, int def = 0, int money = 0) : Character(character, health, atk, def, money){}
    ~Pilot() {}
};
class Hunter:public Character{
public:
	Hunter(std::string character = "Hunter", int health = 30, int atk = 5, int def = 0, int money = 0) : Character(character, health, atk, def, money){}
	~Hunter(){}
};
class Criminal:public Character{
public:
	Criminal(std::string character = "Criminal", int health = 30, int atk = 5, int def = 0, int money = 0) : Character(character, health, atk, def, money){}
	~Criminal(){}
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
			return new Hunter();
			break;
		case 3:
			return new Criminal();
			break;
		}
		return 0;
	}
};


class Bullet_Kin:public Character{
public:
	Bullet_Kin(std::string character = "Bullet Kin", int health = 25, int atk = 5, int def = 0, int money = 0) : Character(character, health, atk, def, money){}
	~Bullet_Kin(){}
};
class ShootGun_Kin:public Character{
public:
	ShootGun_Kin(std::string character = "ShootGun Kin", int health = 40, int atk = 5, int def = 0, int money = 0) : Character(character, health, atk, def, money){}
	~ShootGun_Kin(){}
};
class Sniper_shell:public Character{
public:
	Sniper_shell(std::string character = "Sniper shell", int health = 25, int atk = 10, int def = 0, int money = 0) : Character(character, health, atk, def, money){}
	~Sniper_shell(){}
};
class Pinhead:public Character{
public:
	Pinhead(std::string character = "Pinhead", int health = 20, int atk = 20, int def = 0, int money = 0) : Character(character, health, atk, def, money){}
	~Pinhead(){}
};
class Gun_Nut:public Character{
public:
	Gun_Nut(std::string character = "Gun Nut", int health = 80, int atk = 5, int def = 0, int money = 0) : Character(character, health, atk, def, money){}
	~Gun_Nut(){}
};
class CreatMonster{
public:
	Character *creatmonster(int choose)
	{
		switch(choose)
		{
		case 5:
			return new Bullet_Kin();
			break;
		case 6:
			return new ShootGun_Kin();
			break;
		case 7:
			return new Sniper_shell();
			break;
		case 8:
			return new Pinhead();
			break;
		case 9:
			return new Gun_Nut();
			break;
		}
		return 0;
	}
};

#endif