#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "neurnonio.h"



using namespace std;
int main(int argc, char * argv[]){
    bool deb=false;
	if (argc == 2)
		if (atoi(argv[1])==1)
			deb=true;
	/*forcing debug mode*/   // deb=true;
	int N, aux;
    if(deb)
        cout << "##DEBUGGING MODE##" << endl;

    float lambda;
    //populating neuron
    cout << "Informe a quantidade de entradas" << endl;
    cin >> N;
	aux = pow(2,N);
	if(deb)
        cout << "aux: " << aux << endl;
    cout << "Informe o valor de Lambda" << endl;
    cin >> lambda;
    int * S = new int[aux];
    for (int i=0;i<aux;i++){
        bool flag_ok=false;
        while (!flag_ok){
            cout << "Digite a saida #" << (i+1) << endl;
            cin >> S[i];
            if ((S[i]==1)||(S[i]==0)){
                flag_ok=true;
            }
            else{cout << "Valor inválido!" << endl;}
        }
    }
	Cneuron My_neuron (N, S, lambda);
  	My_neuron.set_debug(deb);
    My_neuron.teach();
    My_neuron.~Cneuron();
	return 0;
}
