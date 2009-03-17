#ifndef NULL
#define NULL    0
#endif

#ifndef NEURNONIO_H_INCLUDED
#define NEURNONIO_H_INCLUDED

class Cneuron
{
    public:
        //Cneuron(){};
        Cneuron(int n, int *valor,float peso[], float, int S[], float ); //set number of dentrites
	~Cneuron(){};
        void set_input(int,int,int); 
		int get_output();
		void teach();

    private:
        // TODO (luiscunha#1#): Fazer um update_neuron - atualiza valor de entrada
		int N ; //number of dentrites
		float L;
		int values[4][3];
		int dendrites_i[3]; //array of values of each dentrite
		float dendrites_w[3]; //array of weight of each dentrite
		int S_[4];
		float lambda;
		int ativation();
		void learn(int );
        int axon;
		void generate_table(int);
		float generate_random();

    };


#endif // NEURNONIO_H_INCLUDED
