#pragma once
class Projectile
{
public:
	Projectile(int x,int y,int daune,int efect_special,char caracter);

	int getDamage();
	int getSpecialEffect();
	char getLook();
	void getCoords(int& x, int& y);
	void updateX();

private:
	char look;
	int damage, special_effect,X,Y;

};

