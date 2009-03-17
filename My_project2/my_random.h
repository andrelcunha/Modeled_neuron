/*
 *  my_random.h
 *  My_project
 *
 *  Modificated by Andre Luis da Cunha on 17/03/09.
 *  
 *
 */

/**********************************************
 /*   A Basic Linear Congruential Generator
 /*  ---------------------------------------
 /*  Program By: NickDMax for Dreamincode.net
 /*  02/23/2007
 /*
 /*  You may use this code as you see fit
 /**********************************************/
#include <iostream>
#include <ctime>

//This class will give satisfy basic
// random number considerations for
// games an general apps.
// WARNING: Not for Cryprographic use
//   Not for statistical methods.
class BasicLCG {
    
private:
	unsigned long iCurrent;
public:
	BasicLCG();
	BasicLCG(unsigned long);
	void seed(unsigned long iSeed);
	unsigned long nextNumber(); //get the next random number
	unsigned short int nextInt();
	unsigned char nextChar();
	int nextBit();
	double nextDouble();
	int inRange(int min, int max);
};

//Just a little test code to print some numbers
/*
void main()
{
    BasicLCG rng(time(NULL));
    int i;
    //Lets see some bits...
    for( i=1; i<81; i++) {
        cout << rng.nextBit() <<"\t";
    }
    cout <<"\n";
    for( i=1; i<41; i++) {
        cout << (int)rng.nextChar() <<"\t";
    }
    cout <<"\n";
    for( i=1; i<41; i++) {
        cout << rng.nextInt() <<"\t";
    }
    cout <<"\n";
    for( i=1; i<41; i++) {
        cout << rng.nextNumber() <<"\t";
    }
    cout <<"\n\n";
    for( i=1; i<41; i++) {
        cout << rng.nextDouble() <<"\t";
    }
    cout <<"\n\n";
    for( i=1; i<41; i++) {
        cout << rng.inRange(10, 5) <<"\t";
    }
	
    return;
}
*/

