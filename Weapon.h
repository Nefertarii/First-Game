#ifndef WEAPON_H_
#define WEAPON_H_
#include <iostream>
class Weapon{
protected:
	int Price;
	int ATK;
	int AMMO;
	int Now_AMMO;
	int Magazine;
	char Rank;
	std::string Name;

public:
	Weapon(int price=0,int atk=5,int ammo=120,int now_ammo=6,char rank='N',std::string name="Initial",int magazine=6){
		Price=price;
		ATK=atk;
		AMMO=ammo;
		Now_AMMO = now_ammo;
		Rank=rank;
		Name=name;
		Magazine = magazine;
	}
	int Get_Price() { return Price; }
	int Get_ATK() { return ATK; }
	int Get_AMMO() { return AMMO; }
	int Get_Now_AMMO() { return Now_AMMO; }
	int Get_Magazine() { return Magazine; }
	char Get_Rank() { return Rank; }

	void Show(){
		std::cout << "\nWeapon Name: " << Name << std::endl;
		std::cout << "Rank: " << Rank << std::endl;
		std::cout << "ATK: " << ATK << "\tPrice: " << Price << std::endl;
		std::cout << "Ammo: " << Magazine << "/" << Magazine << std::endl;
	}
	void ShowAmmo(){
		std::cout << "Ammo: ";
		if (Magazine>20){
			for (int i = 0; i < Now_AMMO;i++){
				std::cout << "-";
			}
		}
		else{ 
		        for (int i = 0; i < Now_AMMO;i++){
		         	std::cout << "I";
		        }
		}
		std::cout <<"/" << Magazine << "\tTotal Ammo:" << AMMO << std::endl;
	}
	std::string Get_Name() { return Name; }
	int Fire() { return (Now_AMMO -= 1, AMMO -= 1); }
	int Reload() {
		std::cout << "Reload!\n";
		return Now_AMMO = Magazine;
	}
	virtual ~Weapon(){}
};

class Rogue:public Weapon{//p
public:
	Rogue(int price = 20, int atk = 10, int ammo = 300,int now_ammo = 10,
	        char rank = 'C', std::string name = "Rogue",int magazine=10) : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~Rogue(){}
};
class M1911:public Weapon{//p
public:
	M1911(int price = 25, int atk = 20, int ammo = 240,int now_ammo = 9,
	        char rank = 'B', std::string name = "M1911",int magazine=9) : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~M1911(){}
};
class Trank_Gun:public Weapon{//p
public:
	Trank_Gun(int price = 25, int atk = 30, int ammo = 150,int now_ammo = 150,
	        char rank = 'A', std::string name = "Trank Gun",int magazine=10) : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~Trank_Gun(){}
};
class Dungeon_Eagle:public Weapon{//p
public:
	Dungeon_Eagle(int price = 30, int atk = 40, int ammo = 120,int now_ammo = 7,
	        char rank = 'S', std::string name = "Dungeon Eagle",int magazine=7) : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Dungeon_Eagle(){}
};
class Regular_Shotgun:public Weapon{//st
public:
	Regular_Shotgun(int price = 25, int atk = 5, int ammo = 120,int now_ammo = 6,int magazine=6,
	        char rank = 'C', std::string name = "Regular Shotgun") : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~Regular_Shotgun(){}
};
class Winchester:public Weapon{//st
public:
	Winchester(int price = 30, int atk = 8, int ammo = 80,int now_ammo = 8,int magazine=8,
	        char rank = 'B', std::string name = "Winchester") : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~Winchester(){}
};
class Huntsman:public Weapon{//st
public:
	Huntsman(int price = 35, int atk = 10, int ammo = 50,int now_ammo = 5,int magazine=5,
	        char rank = 'A', std::string name = "Huntsman") : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~Huntsman(){}
};
class Big_Shotgun:public Weapon{//st
public:
	Big_Shotgun(int price = 50, int atk = 15, int ammo = 80,int now_ammo = 8,int magazine=8,
	        char rank = 'S', std::string name = "Big Shotgun") : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~Big_Shotgun(){}
};
class M1:public Weapon{//sn
public:
	M1(int price = 30, int atk = 30, int ammo = 80,int now_ammo = 8,int magazine=8,
	        char rank = 'B', std::string name = "M1") : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~M1(){}
};
class A_W_P:public Weapon{//sn
public:
	A_W_P(int price = 34, int atk = 45, int ammo = 50,int now_ammo = 10,int magazine=10,
	        char rank = 'B', std::string name = "A.W.P") : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~A_W_P(){}
};
class Heaxgun:public Weapon{//sn
public:
	Heaxgun(int price = 42, int atk = 60, int ammo = 40,int now_ammo = 5,int magazine=5,
	        char rank = 'A', std::string name = "Heaxgun") : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~Heaxgun(){}
};
class Railgun:public Weapon{//sn
public:
	Railgun(int price = 75, int atk = 100, int ammo = 50,int now_ammo = 1,int magazine=1,
	        char rank = 'S', std::string name = "Railgun") : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~Railgun(){}
};
class PilotGun:public Weapon{//base
public:
	PilotGun(int price = 0, int atk = 5, int ammo = 999,int now_ammo = 6,int magazine=6,
	        char rank = 'N', std::string name = "Rogue Special") : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~PilotGun(){}
};
class HunterGun:public Weapon{//base
public:
	HunterGun(int price = 0, int atk = 5, int ammo = 999,int now_ammo = 8,int magazine=8,
	        char rank = 'N', std::string name = "Rusty Sidearm") : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~HunterGun(){}
};
class CriminalGun:public Weapon{//base
public:
	CriminalGun(int price = 0, int atk = 5, int ammo = 999,int now_ammo = 12,int magazine=10,
	        char rank = 'N', std::string name = "Budget Revolver") : Weapon(price,atk,ammo,now_ammo,rank,name,magazine) {}
	~CriminalGun(){}
};

#endif
