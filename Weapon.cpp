#include"Weapon.h"
#include"Random.h"
using namespace std;

  Weapon::Weapon( string n, int s, int h, int b )
: name( n ), stam( s ), hit( h ), block( b )
{
}

bool Weapon::swing(){

  int result;

  Random r( 1, 100 );
  result = r.get();

  if( result <= hit )
    return true;
  else 
    return false;
}

bool Weapon::blockAttack(){

  int result;

  Random r( 1, 100 );
  result = r.get();

  if( result <= block )
    return true;
  else 
    return false;
}

bool Weapon::shatter(){

  int result;

  Random r( 1, 100);
  result = r.get();

    if( result <= 2 )
      return true;
    else
      return false;

}

string Weapon::getName(){

  return name;
}

int Weapon::speak(){

  return stam;
}

void Weapon::display(){

  cout << name << endl;
  cout << "Stamina: " << stam << endl;
  cout << "Hit Chance: " << hit << "%" << endl;
  cout << "Block Chance: " << block << "%" << endl << endl;
}

int Weapon::getHit(){

  return hit;
}

int Weapon::getBlock(){

  return block;
}
