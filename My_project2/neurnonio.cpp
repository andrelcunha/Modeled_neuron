#include <iostream>
#include <math.h>
#include <cstdlib>
#include "neurnonio.h"
#include "my_random.h"

using namespace std;
//****************************************************************************************************
Cneuron::Cneuron(int n, int *S, float lamb){

	N = n + 1;							//N -> collums
	rows=pow(2,(N-1));					//quantidade total de combinações
	generate_table();
	populate_W();
	dendrites_i = new int[rows];
    S0 = new int[rows];
	for (int i=0;i<rows;i++){
		if (S[i]==0)
			S0[i]=-1;
		else
			S0[i]=S[i];
	}
	lambda = lamb;
	axon = 0;
	
}
//****************************************************************************************************
Cneuron::~Cneuron(){
	delete  [ ]S0;
	S0 = NULL;
	delete  [ ]matrix;
	matrix = NULL;
	delete  [ ]W;
	W = NULL;
	delete [ ]dendrites_i;
	dendrites_i = NULL;
}
int Cneuron::get_output(){
	return axon;
}
//****************************************************************************************************
void Cneuron::teach(){
    bool with_error=0;
	int counter=0;
	do{
		for (int i=0;i<N;i++){
			with_error=0;
			for (int j=0; j<rows;j++){  
				dendrites_i[j]= matrix[i][j];				
			}
			if (activation()!=S0[i]){
					learn(S0[i]);
					cout << "learn" <<endl;
					with_error=1;
				}
			counter ++;
			cout << "iteration " << counter <<endl;
			if(counter==100)
				return;
			}
	}while (with_error);
	cout << "aprendi" << endl;
}
//****************************************************************************************************
void Cneuron::learn(int S){
	float *Wn = new float[N];
	for (int i=0;i<N;i++){
		if (Debugging)
			cout << "W1 = W0(" << W[i] << ") + lambda("<< lambda <<") * ["<< S << " - " << axon <<"] * x"<< i <<" " << dendrites_i[i] <<endl;
		Wn[i]=W[i] + lambda*(S - axon)*dendrites_i[i];
		//if (Debugging)
		//	cout << "W0 " << W[i] << "; W1 " << Wn[i] << endl;
		W[i]=Wn[i];

	}

}
//****************************************************************************************************
int Cneuron::activation(){                      //Verificar se está funcionando
	float temp=0;
	for (int i=0;i<N;i++){
        temp += (dendrites_i[N]) * int(W[N]);
		if(Debugging)
			cout << temp<<"+="<<dendrites_i[i]<<" * "<<W[N] << endl;
	}
	if (temp < 0) {
		axon = -1;
	}
	else {
		axon = 1;
	}
	cout << "axon " << axon   <<endl;
	return axon;
}
//****************************************************************************************************
void Cneuron::generate_table(){            //working fine -- verificar rows x qtdd
	matrix = new int*[N];
	for (int i=0;i<N;i++){
        matrix[i]= new int [rows];
	}
    for (int i=0;i<N;i++){
        int aux=0;
        for(int j=0;j<rows;j++){
                int variation=pow(2,(N-i-1));
                if(i==0){
                    matrix[i][j]=1;
                }
                else{
                    if(((j)%(variation))==0&&j!=0){
                        if(aux==0){
                            aux=1;
                        }else{
                            aux=0;
                        }
                    }
                    matrix[i][j]=aux;

                }
        }
    }
    /* Debugging*/
	if(Debugging){
		for (int j=0;j<rows;j++){
			//cout << i;
			for(int i=0;i<N;i++){
				//    cout << j << " ";
				cout << matrix[i][j] << " " ;
			}
			cout << endl;
		}/**/
	}
}
//****************************************************************************************************
void Cneuron::populate_W(){                     //working fine
    W = new float [N];
    for (int i=0;i<N;i++){
        W[i]=generate_random();
    }
}
//****************************************************************************************************
float Cneuron::generate_random(){               //working fine
	BasicLCG rng(time(NULL));
	int x1=rng.inRange(0, 100), x2=rng.inRange(0, 100);
	int aux = (x1 - x2);
	float out = (float)aux / 100;
	return out;
}
