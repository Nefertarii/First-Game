#ifndef ARMOR_H_
#define ARMOR_H_
#include <iostream>	
class Armor{
protected:
	int Price;
	int DEF;//defense
	char Rank;//'C'   'B'   'A'   'S'
	std::string Name;
public:
	Armor(int price=0,int def=0,char rank='N',std::string name="none"){
		Price=price;
		DEF=def;
		Rank=rank;
		Name=name;
	}
	int Get_Price() { return Price; }
	int Get_DEF() { return DEF; }
	char Get_Rank() { return Rank; }
	std::string Get_Name() { return Name; }
	void Show_Armor(){
		std::cout << "\tArmor\n";
		std::cout << "Name: " << Name << "\tDefense: " << DEF;
		std::cout << "\nArmor Rank: " << Rank << std::endl;
	}
	~Armor(){}
};

class Cloth:public Armor{
public:
	void Armor_Cloth (int price=0,int def=0,char rank='N',std::string name="none"){}
	void Armor_Cloth1(int price=1,int def=0,char rank='N',std::string name="none"){}
	void Armor_Cloth2(int price=2,int def=0,char rank='N',std::string name="none"){}
	void Armor_Cloth3(int price=3,int def=0,char rank='N',std::string name="none"){}
	~Cloth(){}
};
#endif