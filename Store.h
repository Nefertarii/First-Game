#ifndef STORE_H_
#define STORE_H_
#include "Weapon.h"
#include <iostream>
using namespace std;
//武器商店类
class WeaponStore{
public:
	virtual void Show()=0;		//武器信息展示
	virtual Weapon *CreatWeapon(int flag)=0;		//创建武器
	virtual ~WeaponStore(){}
};

class PistolWeaponStore:public WeaponStore{
public:
	void Show()
	{
		cout<<"1.Name:Rogue\tPrice:20\n"<<endl;
		cout<<"2.Name:M1911\tPrice:25\n"<<endl;
		cout<<"3.Name:Trank Gun\tPrice:25\n"<<endl;
		cout<<"4.Name:Dungeon Eagle\tPrice:30\n"<<endl;
	}
	Weapon *CreatWeapon(int flag)
	{
		switch(flag)
		{
		case 1:
			return new Rogue();break;
		case 2:
			return new M1911();break;
		case 3:
			return new Trank_Gun();break;
		case 4:
			return new Dungeon_Eagle();break;
		}
		return 0;
	}
	~PistolWeaponStore(){}
};

class ShotgunWeaponStore:public WeaponStore{
public:
	void Show()
	{
		cout<<"1.Name:Regular Shotgun\tPrice:25\n"<<endl;
		cout<<"2.Name:Winchester\tPrice:30\n"<<endl;
		cout<<"3.Name:Huntsman\tPrice:35\n"<<endl;
		cout<<"4.Name:Big Shotgun\tPrice:50\n"<<endl;
	}
	Weapon *CreatWeapon(int flag)
	{
		switch(flag)
		{
		case 1:
			return new Regular_Shotgun();break;
		case 2:
			return new Winchester();break;
		case 3:
			return new Huntsman();break;
		case 4:
			return new Big_Shotgun();break;
		}
		return 0;
	}
	~ShotgunWeaponStore(){}
};

class SniperWeaponStore:public WeaponStore{
public:
	void Show()
	{
		cout<<"1.Name:M1\tPrice:30\n"<<endl;
		cout<<"2.Name:A.W.P\tPrice:36\n"<<endl;
		cout<<"3.Name:Heaxgun\tPrice:40\n"<<endl;
		cout<<"4.Name:Railgun\tPrice:75\n"<<endl;
	}
	Weapon *CreatWeapon(int flag)
	{
		switch(flag)
		{
		case 1:
			return new M1();break;
		case 2:
			return new A_W_P();break;
		case 3:
			return new Heaxgun();break;
		case 4:
			return new Railgun();break;
		}
		return 0;
	}
	~SniperWeaponStore(){}
};

class BaseWeaponStore:public WeaponStore{
public:
	void Show(){}
	Weapon *CreatWeapon(int flag)
	{
		switch(flag)
		{
		case 1:{
			return new PilotGun();break;}
		case 2:{
			return new HunterGun();break;}
		case 3:{
			return new CriminalGun();break;}
		}
		return 0;
	}
	~BaseWeaponStore(){}
};
class StoreManager{
public:
    void Show(){
        std::cout << "1.Pistol\t2.Showgun\t3.Sniper";
    }
    WeaponStore *CreatWeaponStore(int name)
	{
		if(name==1)
            return new PistolWeaponStore();
        if(name==2)
			return new ShotgunWeaponStore();
		if(name==3)
			return new SniperWeaponStore();
		return 0;
    }
    ~StoreManager();
};

#endif
