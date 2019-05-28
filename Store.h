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
		cout<<"1."<<endl;
		cout<<"2."<<endl;
		cout<<"3."<<endl;
		cout<<"4."<<endl;
	}
	Weapon *CreatWeapon(int flag)
	{
		switch(flag)
		{
		case 1:
			return new Pistol1();break;
		case 2:
			return new Pistol2();break;
		case 3:
			return new Pistol3();break;
		case 4:
			return new Pistol4();break;
		}
	}
	~PistolWeaponStore(){}
};

class ShotgunWeaponStore:public WeaponStore{
public:
	void Show()
	{
		cout<<"1."<<endl;
		cout<<"2."<<endl;
		cout<<"3."<<endl;
		cout<<"4."<<endl;
	}
	Weapon *CreatWeapon(int flag)
	{
		switch(flag)
		{
		case 1:
			return new Shotgun1();break;
		case 2:
			return new Shotgun2();break;
		case 3:
			return new Shotgun3();break;
		case 4:
			return new Shotgun4();break;
		}
	}
	~ShotgunWeaponStore(){}
};

class SniperWeaponStore:public WeaponStore{
public:
	void Show()
	{
		cout<<"1."<<endl;
		cout<<"2."<<endl;
		cout<<"3."<<endl;
		cout<<"4."<<endl;
	}
	Weapon *CreatWeapon(int flag)
	{
		switch(flag)
		{
		case 1:
			return new Pistol1();break;
		case 2:
			return new Pistol2();break;
		case 3:
			return new Pistol3();break;
		case 4:
			return new Pistol4();break;
		}
	}
	~SniperWeaponStore(){}
};
class StoreManager{
public:
    void Show(){
        std::cout << "1.Pistol\t2.Showgun\t3.Sniper";
    }
    WeaponStore *CreatWeaponStore(string name)
	{
		if(name=="Pistol"||"1")
            return new PistolWeaponStore();
        if(name=="Shotgun"||"2")
			return new ShotgunWeaponStore();
		if(name=="Sniper"||"3")
			return new SniperWeaponStore();
    }
    ~StoreManager();
};
#endif
