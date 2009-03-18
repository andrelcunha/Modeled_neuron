#ifndef NULL
#define NULL    0
#endif

#ifndef NEURNONIO_H_INCLUDED
#define NEURNONIO_H_INCLUDED

class Cneuron
{
    public:
        //Cneuron(){};
        Cneuron(int n, int S[], float lambda); //set number of dentrites
        ~Cneuron();
	void set_debug(bool deb){Debugging=deb;};
		bool get_debug(){return Debugging;};
		int get_output();
		void teach();

    private:
        // TODO (luiscunha#1#): Fazer um update_neuron - atualiza valor de entrada
		bool Debugging;
		int N, rows ; //number of dentrites
		int *dendrites_i; //array of values of each dentrite
		int *S0, **matrix;
		float *W, lambda;
		int activation();
		void learn(int );
        int axon;
		void generate_table();
		float generate_random();
		void populate_W();
		


    };


#endif // NEURNONIO_H_INCLUDED
