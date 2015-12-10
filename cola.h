#ifndef COLA_H_
#define COLA_H_

#include "nodo.h"

template <class E>
class COLA
{
	/**ATRIBUTOS**/
	private:
		NODO<E> *frente,*final;
		
	/**METODOS**/
	public:
		COLA<E>():frente(NULL),final(NULL){};	
		COLA<E>(const COLA<E> &col);

		//COLA<E>(E elem_fr,E elem_fin, NODO<E> *frent,NODO<E> *fin);
		//COLA<E>(NODO<E> *frent,NODO<E> *fin):frente(frent), final(fin){};
        /**VERIFICADORES**/ 
        E get_frente(){ return( frente->get_elemento() );}
		E get_final(){return( final->get_elemento() );} 
		bool es_vacia() {return(this->frente == NULL);}
		bool operator==(const COLA<E> &C2);
		
        /**MODIFICADORES**/
        COLA<E> copiar(COLA<E> C2);
        void operator=(const COLA<E> &C2);
		void encolar(E elem);
		void desencolar();		
		~COLA<E>();
		
				
};



template <class E>
void COLA<E>::encolar(E elem)
{
	NODO<E> *nuevo;
	
	nuevo = new NODO<E>();
	nuevo->set_elemento(elem);
	if(this->frente == NULL)
	{
		frente = final  = nuevo;
	}else
	{
		final->set_proximo(nuevo);	
		final=nuevo;
	}				
}

template <class E>
void COLA<E>::desencolar()
{
	NODO<E> *aux;

	aux = frente;
	frente = frente->proximo();
	delete (aux);	
		
}


template <class E>
COLA<E>::~COLA()
{
	NODO<E> *aux;
	
	while(this->frente != NULL)
	{
		aux = frente;
		this->frente = this->frente->proximo();
		delete(aux);
		frente = frente = NULL;
	}
}

template <class E>
COLA<E> COLA<E>::copiar(COLA<E> C2) // le alta, resltado malo
{
     COLA<E> c_copia =C2;
		return (c_copia);
}


template <class E>
COLA<E>::COLA(const COLA<E> &col)
{
	NODO<E> *aux, *nuevo, *insertar;

    if(col.frente != NULL)
    {
		frente = new NODO<E>(col.frente->get_elemento(), NULL);
		aux = col.frente->proximo();
		insertar = frente;
		while( aux != NULL )
		{
			nuevo = new NODO<E> (aux->get_elemento(), NULL);
			insertar->set_proximo(nuevo);
			insertar = insertar->proximo();
			aux = aux->proximo();
			
	    }
	     final = insertar;
	}else { frente = final = NULL; }
}

template <class E>
void COLA<E>::operator=(const COLA<E> &C2)
{
	NODO<E> *aux, *nuevo, *insertar;

    if(C2.frente != NULL)
    {
		frente = new NODO<E>(C2.frente->get_elemento(), NULL);
		aux = C2.frente->proximo();
		insertar = C2.frente;
		while( aux != NULL )
		{
			nuevo = new NODO<E> (aux->get_elemento(), NULL);
			aux = aux->proximo();
			insertar->set_proximo(nuevo);
			insertar = insertar->proximo();
	    }
	     final = insertar;
	}else { frente = final = NULL; }
}


template <class E>
bool COLA<E>::operator==(const COLA<E> &C2)
{
    NODO<E> *aux1,*aux2,*rpd;
    bool band=true;

	aux1 = this->frente;
	aux2 = C2.frente;
	if( (aux1 == NULL)  && (aux1 == NULL) ) return (true);
  	else
	{   
    	while( (aux1 != NULL) && (aux2 != NULL) && band )
		{
			if(aux1->get_elemento() != aux2->get_elemento())
			{
				band = false;
			}else
			{
				aux1 = aux1->proximo();
				aux2 = aux2->proximo();
			}	
	    }
		if( (aux1 == NULL) && (aux2 == NULL) && band )
			{
				return (true);
			}else { return (false); }
	}	
}

#endif
