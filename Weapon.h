#ifndef WEAPON_H_
#define WEAPON_H_
#include <iostream>
class Weapon{
protected:
	int Price;
	int ATK;//Attack
	int AMMO;
	int Now_AMMO;
	char Rank;
	std::string Name;

public:
	Weapon(int price=0,int atk=0,int ammo=120,int now_ammo=120,char rank='N',std::string name="Initial"){
		Price=price;
		ATK=atk;
		AMMO=ammo;
		Now_AMMO = now_ammo;
		Rank=rank;
		Name=name;
	}
	int Get_Price() { return Price; }
	int Get_ATK() { return ATK; }
	int Get_AMMO() { return AMMO; }
	int Get_Now_AMMO() { return Now_AMMO; }
	char Get_Rank() { return Rank; }
	int Fire() { return Now_AMMO -= 1; }
	std::string Get_Name() { return Name; }
	virtual ~Weapon(){}
};

class Rogue:public Weapon{//p
public:
	Rogue(int price = 20, int atk = 10, int ammo = 300,int now_ammo = 300,
	        char rank = 'C', std::string name = "Rogue") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Rogue(){}
};
class M1911:public Weapon{//p
public:
	M1911(int price = 25, int atk = 20, int ammo = 240,int now_ammo = 240,
	        char rank = 'B', std::string name = "M1911") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~M1911(){}
};
class Trank_Gun:public Weapon{//p
public:
	Trank_Gun(int price = 25, int atk = 30, int ammo = 150,int now_ammo = 150,
	        char rank = 'A', std::string name = "Trank Gun") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Trank_Gun(){}
};
class Dungeon_Eagle:public Weapon{//p
public:
	Dungeon_Eagle(int price = 30, int atk = 40, int ammo = 120,int now_ammo = 120,
	        char rank = 'S', std::string name = "Dungeon Eagle") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Dungeon_Eagle(){}
};
class Regular_Shotgun:public Weapon{//st
public:
	Regular_Shotgun(int price = 25, int atk = 5, int ammo = 120,int now_ammo = 120,
	        char rank = 'C', std::string name = "Regular Shotgun") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Regular_Shotgun(){}
};
class Winchester:public Weapon{//st
public:
	Winchester(int price = 30, int atk = 8, int ammo = 80,int now_ammo = 80,
	        char rank = 'B', std::string name = "Winchester") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Winchester(){}
};
class Huntsman:public Weapon{//st
public:
	Huntsman(int price = 35, int atk = 10, int ammo = 50,int now_ammo = 50,
	        char rank = 'A', std::string name = "Huntsman") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Huntsman(){}
};
class Big_Shotgun:public Weapon{//st
public:
	Big_Shotgun(int price = 50, int atk = 15, int ammo = 80,int now_ammo = 80,
	        char rank = 'S', std::string name = "Big Shotgun") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Big_Shotgun(){}
};
class M1:public Weapon{//sn
public:
	M1(int price = 30, int atk = 30, int ammo = 80,int now_ammo = 50,
	        char rank = 'B', std::string name = "M1") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~M1(){}
};
class A_W_P:public Weapon{//sn
public:
	A_W_P(int price = 34, int atk = 45, int ammo = 40,int now_ammo = 30,
	        char rank = 'B', std::string name = "A.W.P") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~A_W_P(){}
};
class Heaxgun:public Weapon{//sn
public:
	Heaxgun(int price = 42, int atk = 60, int ammo = 40,int now_ammo = 25,
	        char rank = 'A', std::string name = "Heaxgun") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Heaxgun(){}
};
class Railgun:public Weapon{//sn
public:
	Railgun(int price = 75, int atk = 100, int ammo = 50,int now_ammo = 50,
	        char rank = 'S', std::string name = "Railgun") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Railgun(){}
};


#endif
