#include"Knight.h"
#include"Weapon.h"
#include<vector>
#include<iostream>
using namespace std;

  Knight::Knight( string n, int s)
: name( n ), stam( s )
{

  hale = true;
  mounted = true;
  armed = false;
}


string Knight::getName(){

  return name;
}

int Knight::getStam(){

  return stam;
}

bool Knight::getArmed(){

  return armed;
}

void Knight::setArmed(){
  
  armed = true;
}

void Knight::display(){

  cout << name << endl;
  cout << "Stamina: " << stam << endl;
  if(mounted)
    cout << "Horsed" << endl;
  if(hale)
    cout << "Hale" << endl << endl;

}

void Knight::displayArms(){

  if( rhand != NULL ){
    cout << name << " wields in their right hand:" << endl;
    rhand -> display();
  }

  if( lhand != NULL ){
    cout << name << " wields in their left hand:" << endl;
    lhand -> display();
  }

  if( ( rhand == NULL ) && ( lhand == NULL) ){

    cout << name << " is unarmed! The coward!" << endl;
  }

}

bool Knight::joust(){

  bool result1 = false, result2 = false;
  bool shatter1 = false, shatter2 = false;
  
  shatter1 = rhand -> shatter();
  shatter2 = lhand -> shatter();

  //Break chance before hit, so weapon can't hit and shatter.
  if( shatter1 ){
    cout << rhand -> getName() << " shatters!!!" << endl;
    rhand = NULL;
  }
  if( shatter2 ){
    cout << lhand -> getName() << " shatters!!!" << endl;
    lhand = NULL;
  }

  //Swings with non-empty hands
  if( rhand != NULL )
    result1 = rhand -> swing();
  if( lhand != NULL )
    result2 = lhand -> swing();
  //Used in main to forfeit
  if( (rhand == NULL) && (lhand == NULL) )
    armed = false;

  if( result1 || result2 )
    return true;
  else
    return false;
}

bool Knight::block(){

  bool result1 = false, result2 = false;

  //Blocks with non-empty hands. Weapons with no block chance cannot succeed.
  if( rhand != NULL )
    result1 = rhand -> blockAttack();
  if( lhand != NULL )
    result2 = lhand -> blockAttack();

  //Break chance after successful block. Weapons can block and shatter.
  //Weapons with no block cannot shatter this way.
  if( result1 ){
    if( rhand -> shatter() ){
      cout << rhand -> getName() << " shatters!!!" << endl;
      rhand == NULL;
    }
  }
  if( result2 ){
    if( lhand -> shatter() ){
      cout << lhand -> getName() << " shatters!!!" << endl;
      lhand == NULL;
    }
  }

  if( result1 || result2 )
    return true;
  else
    return false;
}

bool Knight::tire(){

  stam = stam - (rhand -> speak()) - (lhand -> speak());

  if( stam <= 0 ){
    hale = false; // important only for the display() function
    return true; // information sent to main() to stop loop
  }else
    return false; 
}

//double-check to see if I've got this already
void Knight::reset(){

  mounted = true;
  hale = true;
}

void Knight::unhorse(){

  mounted = false; 
}

//vector<Weapon> or just Weapon?
void Knight::grabWeapon( Weapon &weap1, Weapon &weap2 ){

  rhand = &weap1; 
  lhand = &weap2; 
}
