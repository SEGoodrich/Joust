#ifndef WEAPON_H
#define WEAPON_H
#include<iostream>
#include"Random.h"
using namespace std;

class Weapon{

  private:
    string name;
    int stam, hit, block;

  public:
    Weapon( string n, int s, int h, int b );

    string getName();
    int getHit();
    int getBlock();

    void display();
    int speak();

    bool swing();
    bool blockAttack();
    bool shatter();

};
#endif
