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
	Weapon(int price=0,int atk=0,int ammo=0,int now_ammo=0,char rank='N',std::string name="none"){
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
	std::string Get_Name() { return Name; }
	virtual ~Weapon(){}
};

class Pistol1:public Weapon{
public:
	Pistol1(int price = 100, int atk = 10, int ammo = 50,int now_ammo = 50,
	        char rank = 'C', std::string name = "Pistol1") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Pistol1(){}
};
class Pistol2:public Weapon{
public:
	Pistol2(int price = 200, int atk = 20, int ammo = 80,int now_ammo = 80,
	        char rank = 'B', std::string name = "Pistol2") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Pistol2(){}
};
class Pistol3:public Weapon{
public:
	Pistol3(int price = 300, int atk = 30, int ammo = 100,int now_ammo = 100,
	        char rank = 'A', std::string name = "Pistol3") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Pistol3(){}
};
class Pistol4:public Weapon{
public:
	Pistol4(int price = 400, int atk = 40, int ammo = 120,int now_ammo = 120,
	        char rank = 'S', std::string name = "Pistol4") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Pistol4(){}
};
class Shotgun1:public Weapon{
public:
	Shotgun1(int price = 100, int atk = 10, int ammo = 50,int now_ammo = 50,
	        char rank = 'C', std::string name = "Shotgun1") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Shotgun1(){}
};
class Shotgun2:public Weapon{
public:
	Shotgun2(int price = 100, int atk = 10, int ammo = 50,int now_ammo = 50,
	        char rank = 'C', std::string name = "Shotgun2") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Shotgun2(){}
};
class Shotgun3:public Weapon{
public:
	Shotgun3(int price = 100, int atk = 10, int ammo = 50,int now_ammo = 50,
	        char rank = 'C', std::string name = "Shotgun3") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Shotgun3(){}
};
class Shotgun4:public Weapon{
public:
	Shotgun4(int price = 100, int atk = 10, int ammo = 50,int now_ammo = 50,
	        char rank = 'C', std::string name = "Shotgun4") : Weapon(price,atk,ammo,now_ammo,rank,name) {}
	~Shotgun4(){}
};

#endif
