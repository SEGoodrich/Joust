#include<iostream>
#include<stdio.h>
#include<fstream>
#include<vector>
#include"Knight.h"
using namespace std;

void clear(){

  for( int i =0; i < 50; i++ ){

    cout << endl;
  }
}

Weapon* findWeapon( int wChoice, vector<Weapon> &Weapons ){

  for( int i =0; i < Weapons.size(); i++ ){

    if( i == (wChoice-1) )
      return &Weapons[i];
  }
  return NULL;
}

Knight* findKnight( int kChoice, vector<Knight> &Knights ){

  for( int i =0; i < Knights.size(); i++ ){

    if( i == (kChoice-1) )
      return &Knights[i];
  }
  return NULL;
}

void download( vector<Knight> &Knights, vector<Weapon> &Weapons ){

  string file;
  ifstream winf, kinf;

  bool kload, wload;

  string name, wname;
  int stam;
  int wstam, hit, block;

  file = "knights.txt";
  kinf.open( file.c_str() );
  if( !kinf.is_open() ){

    cout << "\nBeg pardon m'lady--our scribes have forgotten the scroll of participants." << endl;
    cout << "They are being beheaded as we speak." << endl;
    cout << "However, we need warriors foolish enough to partake in the festivities today." << endl;
    cout << "\nAny fool or knave will do, really." << endl;
    cout << "(Please enter in at least two participants.)" << endl;

    kload = false;
  }else{

    while( !kinf.eof() ){

      //pushback loop
      getline(kinf, name, '|');
      kinf >> stam;
      kinf.ignore();

      Knights.push_back( Knight ( name, stam ));
    }

    kload = true;
  }
  kinf.close();

  //Upload Weapons
  file = "weapons.txt";
  winf.open( file.c_str() );
  if( !winf.is_open() ){

    cout << "\nBeg pardon m'lady--our scribes have forgotten the scroll of participants." << endl;
    cout << "They are being beheaded as we speak." << endl;
    cout << "However, we need warriors foolish enough to partake in the festivities today." << endl;
    cout << "\nAny fool or knave will do, really." << endl;
    cout << "(Please enter in at least two participants.)" << endl;

    wload = false;

  }else{

    while( !winf.eof() ){

      //pushback loop
      getline(winf, wname, '|');
      winf >> wstam >> hit >> block;
      winf.ignore();

      Weapons.push_back( Weapon ( wname, wstam, hit, block ));
    }

    wload = true;
  }
  winf.close();
  //Check Vector<Knights> size > 2
}

//Deletes old file and uploads vectors into new file of same name.
//Is there a smarter way to do this?
//Check line-by-line on file, only add new members?
//Note which ones had been added this session?
void upload( vector<Knight> &Knights, vector<Weapon> &Weapons ){

  ofstream koutf;

  string name;
  int stam;
  int hit, block;

  if( remove( "knights.txt" ) !=0)
    cerr << "Error adding new Knights" << endl;
  else
    cout << "Knights successfully updated" << endl;

  koutf.open( "knights.txt");
  for( int n =0; n < Knights.size(); n++ ){

    name = Knights[n].getName();
    stam = Knights[n].getStam();

    koutf << name << "| " << stam << endl;
  }
  koutf.close();



  ofstream woutf;
  //Rewrites weapons.txt
  if( remove( "weapons.txt" ) !=0)
    cerr << "Error adding new Weapons" << endl;
  else
    cout << "Weapons successfully updated" << endl;

  woutf.open( "weapons.txt");
  for( int n =0; n < Weapons.size(); n++ ){

    name = Weapons[n].getName();
    stam = Weapons[n].speak();
    hit = Weapons[n].getHit();
    block = Weapons[n].getBlock();

    woutf << name << "| " << stam << " " << hit << " " << block << endl;
  }
  woutf.close();
}



//Possible new class to set-up knights and weapons?
//WeaponRack.h: armKnight(vector<Weapon>), download(), upload(), newKnight(), newWeapon()

//Have change weapon logic
//Have brawl logic
//Have tourney logic
int main(){

  //Knight info
  vector<Knight> Knights;
  string name;
  int stam;
  Knight *k1=NULL, *k2=NULL;

  //Weapon info
  vector<Weapon> Weapons;
  string wname;
  int wstam;
  int hit;
  int block;
  Weapon *w1=NULL, *w2=NULL;

  //Variables for loop control
  bool kload = true, wload = true;
  char rpt;
  bool repeat = false;
  bool kEdit, wEdit;

  clear();
  cout << "\nAhoy there, noble pardner!\n" << endl;
  cout << "Prepare ye-self t' joust fer yer life!" << endl;
  cout << "(Or at least pretend to do so" << endl;
  cout << "as you watch numbers show up on screen.)" << endl;
  cout << "\nForthwith, slugger, lest ye shiver me biscuits!\n" << endl;




  //Download Knights
  download( Knights, Weapons );

  //Obsolete; maybe useful?
  //Make new knights and weapons
  do{
    //Prompt for multiple run-throughs, letting user reset knights or weapons
    //For-loop: knights.reset()

    cout << "\nWould you like to create a new knight? (Y/N)" << endl;
    char k_ed =0;
    cin >> k_ed;

    if(( k_ed == 'y' )||( k_ed == 'Y' ))
      kEdit = true;
    else
      kEdit = false;

    cout << "\nWould you like to create more weapons? (Y/N)" << endl;
    char w_ed =0;
    cin >> w_ed;

    if(( w_ed == 'y' )||( w_ed == 'Y' ))
      wEdit = true;
    else
      wEdit = false;


    //Repeat function for naming these things?
    //Would let me make a brawl
    //I'd use random to assign a target to each knight each time
    //Need to declare vars each time. 
    //Maybe tick up by one in main? Maybe have new class save them as different?
    //Arrays?

    // Prompts the first time run, and if user desires.
    if( kEdit ){

      //Resets user input to avoid weird looping
      char k_ed =0;

      do{
        clear();
        cout << "\nName your knight.\n" << endl;
        cin >> name;
        cin.ignore();

        cout << "\nWhat is " << name << "'s stamina?\n" << endl;
        cin >> stam;

        Knights.push_back( Knight( name, stam ) );

        cout << "\nWould you like to make another knight?" << endl;
        cin >> k_ed;

      }while( k_ed == 'y' || k_ed == 'Y' );

    }

    if( wEdit ){ 

      char w_ed =0;

      do{
        //Edit
        clear();
        cout << "\nName your weapon.\n" << endl;
        cin >> wname;
        cin.ignore();

        cout << "\nHow hard is " << wname << " to wield?\n" << endl;
        cin >> wstam;

        cout << "\nHow likely is " << wname << " to hit?\n" << endl;
        cin >> hit;

        cout << "\nHow likely is " << wname << " to block?\n" << endl;
        cin >> block;

        Weapons.push_back( Weapon( wname, wstam, hit, block ) );

        cout << "\nWould you like to make another weapon?" << endl;
        cin >> w_ed;

      }while( w_ed == 'y' || w_ed == 'Y' );

    }

    int kChoice,wChoice;

    clear();
    cout << "\nWhich knight would you like to play?" << endl;
    cout << "Press enter when ready" << endl;
    getchar();
    cin.ignore();

    clear();
    for( int m =0; m < Knights.size(); m++ ){

      cout << "\n##### Knight #" << m+1 << " #####" << endl;
      Knights[m].display();
    }

    cout << "\nEnter in the number of the knight you'd like to play." << endl; 
    cin >> kChoice;
    k1 = findKnight( kChoice, Knights );

    cout << "\nNow enter in the number of the knight you'd like to play against." << endl; 
    cin >> kChoice;
    k2 = findKnight( kChoice, Knights );

    clear();
    cout << "\nNow you must arm your knight!" << endl;
    cout << "Press enter when ready" << endl;
    getchar();
    cin.ignore();

    clear();
    for( int m =0; m < Weapons.size(); m++ ){

      cout << "\n***** Weapon #" << m+1 << " *****" << endl;
      Weapons[m].display();
    }

    //User input to arm knights
    //I could put this on a for-loop to have many-armed knights, like Shiva
    cout << "Choose the number of " << k1->getName() << "'s main-hand weapon." << endl;
    cin >> wChoice;
    w1 = findWeapon( wChoice, Weapons );

    cout << "Choose the number of " << k1->getName() << "'s off-hand weapon." << endl;
    cin >> wChoice;
    w2 = findWeapon( wChoice, Weapons );

    k1 -> grabWeapon( *w1, *w2 );
    k1 -> setArmed();

    cout << "\nArm your opponent!" << endl << endl;

    cout << "Choose the number of " << k2->getName() << "'s main-hand weapon." << endl;
    cin >> wChoice;
    w1 = findWeapon( wChoice, Weapons );

    cout << "Choose the number of " << k2->getName() << "'s off-hand weapon." << endl;
    cin >> wChoice;
    w2 = findWeapon( wChoice, Weapons );

    k2 -> grabWeapon( *w1, *w2 );
    k2 -> setArmed();


    clear();
    //If brawl, will have to create a vector for those brawling
    cout << "################ COMBATANTS ################" << endl;
    k1 -> display();
    k1 -> displayArms();
    cout << "############################################" << endl;
    k2 -> display();
    k2 -> displayArms();
    cout << endl << "\nPress Enter to continue." << endl;
    getchar();
    cin.ignore();


    clear();
    cout << "\nThe squires are drunk, the horses are nervous," << endl;
    cout << "the maidens are being flogged, and it's about to rain!\n" << endl;
    cout << "The joust is about to begin!" << endl;
    getchar();
    cin.ignore();

    cout << "\nJoust!" << endl;

    //variables to store knight information relevant to jousts
    //Is there a better way to do this?
    bool k1_hit = false, k2_hit = false;
    bool k1_block = false, k2_block = false;
    bool k1_armed = true, k2_armed = true;
    bool k1_unhorsed = false, k2_unhorsed = false;
    bool k1_tired = false, k2_tired = false;
    //round counter
    int rd_ct = 0;



    do{

      ++rd_ct;
      cout << "********************" << endl;
      cout << endl << "\nRound " << rd_ct << endl << endl;
      cout << "********************" << endl;

      k1_hit = k1 -> joust();
      k2_hit = k2 -> joust();
      k1_armed = k1 -> getArmed();
      k2_armed = k2 -> getArmed();

      k1_tired = k1 -> tire(); // Subtracts Weapon stamina required from Knight stamina, then returns true if stamina <= 0
      k2_tired = k2 -> tire(); 

      //If joust = true, other knight may block
      //if so, don't unhorse
      if( k1_hit ){ 

        k2_block = k2 -> block();

        if( !k2_block ){
          k2 -> unhorse();
          k2_unhorsed = true;
        }
        if( k2_block ){
          cout << "\n" << k1 -> getName() << " hits, but is blocked!" << endl;
        }
      }
      if( k2_hit ){

        k1_block = k1 -> block();

        if( !k1_block ){
          k1 -> unhorse();
          k1_unhorsed = true;
        }
        if( k1_block ){
          cout << "\n" << k2 -> getName() << " hits, but is blocked!" << endl;
        }
      }

      k1 -> display();
      k2 -> display();

    }while( !k1_unhorsed && !k2_unhorsed && !k1_tired && !k2_tired && k1_armed && k2_armed );
    //End of joust loop



    if(k1_unhorsed)
      cout << k1 -> getName() << " was unhorsed!" << endl;
    if(k2_unhorsed)
      cout << k2 -> getName() << " was unhorsed!" << endl;
    if(k1_tired)
      cout << k1 -> getName() << " collapsed, exhuasted!" << endl;
    if(k2_tired)
      cout << k2 -> getName() << " collapsed, exhausted!" << endl;
    if(!k1_armed)
      cout << k1 -> getName() << " shattered both their weapons! They forfeit!" << endl;
    if(!k2_armed)
      cout << k2 -> getName() << " shattered both their weapons! They forfeit!" << endl;


    cout << "\nJoust over!" << endl;
    cout << "Joust lasted " << rd_ct << " rounds!\n" << endl;

    cout << "Would you like to joust again? (Y/N)" << endl;
    cin >> rpt;

    if(( rpt == 'y' )||( rpt == 'Y' ))
      repeat = true;
    else
      repeat = false;

  }while( repeat );
  //End of program

  upload( Knights, Weapons );

  return 0;
}
