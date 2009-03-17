#include <iostream>
#include "neurnonio.h"
#define N 2


using namespace std;

int main(int argc, char * argv)
{
	 
    //populating neuron
    int value[8]=
	{0 , 0 , 0 , 1 , 1 , 0 , 1 , 1 };
	float weight[N]={-0.5 , -0.1};
	float limiar = -0.5;
	int S[]={0,0,0,1};
	float lambda = 0.3;
	
	Cneuron My_neuron ( N , value, weight, limiar, S , lambda );
    for (int i=0;i<N;i++){
		//cout << array[i][0] <<" , "<< array[i][1] << endl;
        //My_neuron.set_input(i,array[i][0],array[i][1]);
    }
    My_neuron.teach();
    My_neuron.~Cneuron();
	return 0;
}
