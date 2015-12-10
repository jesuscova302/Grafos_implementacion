#ifndef NODO_ADY_H_
#define NODO_ADY_H_
#include <iostream>




template <class	VERTICE >
class NODO_ADY
{
	/***ATRIBUTOS***/
	private:
		VERTICE info;
		float costo;
		NODO_ADY<VERTICE> *prox_ady;

	/***METODOS***/
	public:
		NODO_ADY<VERTICE>(): prox_ady(NULL){};
		NODO_ADY<VERTICE>(NODO_ADY<VERTICE> *prox): prox_ady(prox){};
		//NODO_ADY<VERTICE>(float cost,NODO_ADY<VERTICE> *prox): costo(cost),prox_ady(prox){};
		NODO_ADY<VERTICE>(VERTICE inf,float cost,NODO_ADY<VERTICE> *prox): info(inf),costo(cost), prox_ady(prox){};			
		
		VERTICE get_info(){return(info);}
		float get_costo(){return(costo);}
		NODO_ADY<VERTICE> *get_proximo_adyacente(){return(prox_ady);}
	 
		void set_info(VERTICE inf){info = inf;}
		void set_costo(float cost){costo = cost ;}
		void set_proximo_adyacente(NODO_ADY<VERTICE> *prox){prox_ady = prox;} 
};

#endif

		
