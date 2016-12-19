#ifndef KNIGHT_H_
#define KNIGHT_H_
#include<iostream>
#include<vector>
#include"Weapon.h"
using namespace std;

class Knight{

  private:
    Weapon *rhand, *lhand;

    string name;
    int stam;
    bool mounted, hale, armed;

  public:
    Knight( string n, int s );

    string getName();
    int getStam();
    bool getArmed();
    void setArmed();

    void display();
    void displayArms();
    bool joust();
    bool block();
    void unhorse();
    bool tire();
    void reset();

    void grabWeapon( Weapon &weap1, Weapon &weap2 );
    //void dropWeapon( int hand );
    

};
#endif
