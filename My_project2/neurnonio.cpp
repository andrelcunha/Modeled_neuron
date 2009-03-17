#include <iostream>
#include <math.h>
#include <cstdlib>
#include "neurnonio.h"
#include "my_random.h"

using namespace std;

Cneuron::Cneuron(int n, int * value ,float *weight, float limiar, int *S, float lamb){
	
	N = n + 1;				//N -> collums
	//matrix=new int*[];
	//for (int i=0; i < N
	for (int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if (j==0){
				values[i][j]=1;
			}else {
				values[i][j]=*value;
				value++;
			}
		}
	}
	for (int i=0;i<4;i++){
		if (S[i]==0)
			S_[i]=-1;
		else
			S_[i]=S[i];
	}
	for (int i=0; i<N; i++){
		if (i != 0){
			dendrites_i[i]=0;
			dendrites_w[i]=weight[i-1];
		}else {
			dendrites_i[i]=0;
			dendrites_w[i]=limiar*(-1);
		}
		
	}
	lambda = lamb;
	axon = 0;
}


void Cneuron::set_input(int dend_num,int value,int weight){
	if ( dend_num != 0){
		dendrites_i[dend_num]= value;
		dendrites_w[dend_num]= weight;
	}
}

int Cneuron::get_output(){
	return axon;
}

void Cneuron::teach(){
    bool with_error=1;
	int counter=0;
	while (with_error){
		for (int i=0;i<4;i++){
			with_error=0;
			dendrites_i[0]= values[i][0];
			dendrites_i[1]= values[i][1];
			dendrites_i[2]= values[i][2];
			if (ativation()!=S_[i]){
				learn(S_[i]);
				cout << "learn" <<endl;
				with_error=1;
			}
			counter ++;
			cout << "iteration " << counter <<endl;
		}
	}
	cout << "aprendi" << endl;
	generate_table(4);
	
}

void Cneuron::learn(int S){
	float *Wn = new float[N];
	for (int i=0;i<N;i++){
	//	cout << "W1 = W0(" << dendrites_w[i] << ") + lambda("<< lambda <<") * ["<< S << " - " << axon <<"] * x"<< i <<" " << dendrites_i[i] <<endl;
		Wn[i]=dendrites_w[i] + lambda*(S - axon)*dendrites_i[i];
	//	cout << "W0 " << dendrites_w[i] << "; W1 " << Wn[i] << endl;
		dendrites_w[i]=Wn[i];
		
	}
	
}

int Cneuron::ativation(){
	float temp=0;
	temp += int(dendrites_i[0]) * (dendrites_w[0]);
	temp += int(dendrites_i[1]) * dendrites_w[1];
	temp += int(dendrites_i[2]) * dendrites_w[2];
	
	if (temp < 0) {
		axon = -1;
	}
	else {
		axon = 1;
	}
	cout << "axon " << axon   <<endl;
	return axon;
}

void Cneuron::generate_table(int N){
	//int qtdd = pow(2,N);
	//TODO: to create dynamic tables and use the function below
}

float Cneuron::generate_random(){
	BasicLCG rng(time(NULL));
	int x1=rng.inRange(0, 100), x2=rng.inRange(0, 100); 
	int aux = (x1 - x2);
	float out = (float)aux / 100;
	return out;
}