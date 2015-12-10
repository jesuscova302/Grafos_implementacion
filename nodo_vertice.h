#ifndef NODO_VERTICE_H_
#define NODO_VERTICE_H_
#include "nodo_ady.h"

template <class	VERTICE >
class NODO_VERTICE
{
	/***ATRIBUTOS***/
	private:
		VERTICE info;
		NODO_VERTICE<VERTICE> *prox;
		NODO_ADY<VERTICE> *lst_ady;
	    
	    
	/***METODOS***/
	public:
		NODO_VERTICE<VERTICE>(): prox(NULL),lst_ady(NULL){};
		NODO_VERTICE<VERTICE>(NODO_VERTICE<VERTICE> *p,NODO_ADY<VERTICE> *p_ady): prox(p),lst_ady(p_ady){};
		NODO_VERTICE<VERTICE>(VERTICE inf,NODO_VERTICE<VERTICE> *p,NODO_ADY<VERTICE> *p_ady): info(inf),prox(p),lst_ady(p_ady){};
		
		VERTICE get_info(){return(info);}
		NODO_VERTICE<VERTICE> *get_proximo_vertice(){return(prox);}
		NODO_ADY<VERTICE> *get_lst_adyacente(){return(lst_ady);}	 

		void set_info(VERTICE inf){info = inf;}
		void set_proximo_vertice(NODO_VERTICE<VERTICE> *p){ prox = p  ;}
		void set_lst_adyacente(NODO_ADY<VERTICE> *pr){lst_ady = pr;} 
};

#endif

	
