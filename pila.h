#ifndef PILA_H_
#define PILA_H_
#define MAX 32000
//#include "nodo.h"
#include "lista.h"

template <class E>
class PILA 
{
	/**ATRIBUTOS**/
	private:
		NODO<E> *tope;
	
	private:
		static void ElemMinPila(NODO<E> *ptr,E &min );
		
	
	/**METODOS**/
	public:
		/**CONSTRUCTORES**/	
		PILA<E>(): tope(NULL){};
		PILA<E>(const PILA<E> &pil);
		PILA<E> copiar(PILA<E> pil);
		~PILA();
		  
		/**VERIFICADORES**/
       	 E get_tope(){ return(this->tope->get_elemento()); }; 
		 bool es_vacia() {return (this->tope == NULL); }
		
		 void operator=(const PILA<E> &P2);
		 bool operator==(const PILA<E> &P2);		
	 
	    /**MODIFICADORES**/
		void apilar(E elem);
		void desapilar();
		
		int ElementoMinimoPila( );
						
};


/******************************/
/**IMPLEMENTACIO DE LA PILA***/
/****************************/
template <class E>
void PILA<E>::apilar(E elem)
{
	NODO<E> *nuevo;	
	
	nuevo = new NODO<E>(elem,NULL);
    nuevo->set_proximo(tope);
    tope = nuevo;
}

template <class E>
void PILA<E>::desapilar()
{
	NODO<E> *aux;	
	
	aux = tope;
	tope = tope->proximo();
	delete aux;
	aux = NULL;
}



template <class E>
PILA<E>::~PILA()
{
	NODO<E> *aux;
	if( this->tope != NULL )
	{
	
		while(this->tope != NULL)
		{
			aux=this->tope;
			this->tope = this->tope->proximo();
			delete(aux);
		}
		this->tope = aux = NULL;
	}
}

/**CONSTRUCTOR COPIA**/
template <class E>
PILA<E>::PILA(const PILA<E> &pil)
{
	NODO<E> *aux, *nuevo, *insertar;

    if(pil.tope != NULL)
    {
		tope = new NODO<E>(pil.tope->get_elemento(), NULL);
		aux = pil.tope->proximo();
		insertar = tope;
		while( aux != NULL )
		{
			nuevo = new NODO<E> (aux->get_elemento(), NULL);
			aux = aux->proximo();
			insertar->set_proximo(nuevo);
			insertar = insertar->proximo();
	    }
	}else { tope = NULL; }
}

/**PROCEDIMIENTO QUE COPIA UNA PILA EN OTRA USANDO EL CONSTRUCTOR COPIA**/
template <class E>
PILA<E> PILA<E>::copiar(PILA<E> pil)
{
	PILA<E> p_copia(pil);
		return(p_copia);
}

/**SOBRECARGA DEL OPERADOR DE ASIGNACION DE LA PILA**/
template <class E>
void PILA<E>::operator=(const PILA<E> &P2)
{
	NODO<E> *aux, *nuevo, *insertar;

    if(P2.tope != NULL)
    {
		tope = new NODO<E>(P2.tope->get_elemento(), NULL);
		aux = P2.tope->proximo();
		insertar = tope;
		while( aux != NULL )
		{
			nuevo = new NODO<E> (aux->get_elemento(), NULL);
			aux = aux->proximo();
			insertar->set_proximo(nuevo);
			insertar = insertar->proximo();
	    }
	}else { tope = NULL; }
}

/**SOBRECARGA DEL OPERADOR DE IGUALDAD DE LA PILA**/
template <class E>
bool PILA<E>::operator==(const PILA<E> &P2)
{
	NODO<E> *aux1,*aux2,*rpd;
    bool band=true;
     
    aux1 = this->tope;
	aux2 = P2.tope; 
	if( (aux1 == NULL) && (aux2 == NULL) )
	{
		return (true);
	}else
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

template <class E>
//~ void PILA<E>::ElemMinPila(NODO<E> ptr,E &min )
void PILA<E>::ElemMinPila(NODO<E> *ptr,E &min )
{
 	if( ptr != NULL )
	{
		if( ptr->get_elemento() < min )
		{
			min = ptr->get_elemento() ;
		}
		ElemMinPila(ptr->proximo(),min );
	}
}

template <class E>
int PILA<E>::ElementoMinimoPila( )
{
	int min =MAX ; //MAX DEBERÌA SER EL MAXIMO ENTERO REPRESENTABLE
	
	ElemMinPila(this->tope,min );
	return(min);
	
}
#endif
