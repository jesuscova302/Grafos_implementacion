#ifndef GRAFO_H_
#define GRAFO_H_

#include <string.h>
#include "lista.h"
#include "cola.h"
#include "nodo_vertice.h"
#define  MAX 100
#define MAXDIST 32000 	//	MAXIMO VALOR ARCOS Q PEDE TOMAR  EL GRAFO

using namespace std;


typedef char cadena[10];  
typedef string VECTORCAD[MAX];  
typedef int VECTOR[MAX]; 


template <class	VERTICE>
class GRAFO
{
	/***ATRIBUTOS***/
	private:
		int cardinalidad;
		NODO_VERTICE<VERTICE> *g;
	    
	 private:
	 	//void GRAFO<VERTICE>::eliminarListaVertices( NODO_VERTICE<VERTICE> *&aptVert )
	 	static void eliminarListaVertices( NODO_VERTICE<VERTICE> *aptVert );
//		static void DFS_VICITAR(VERTICE u,VECTOR &pred,VECTOR &tdesc,VECTOR &tfinal,VECTORCAD color,int &tiempo);	
        void DFS_VICITAR(VERTICE u,VECTOR &pred,VECTOR &tdesc,VECTOR &tfinal,VECTORCAD &color ,int &tiempo);

	/***METODOS***/
	public:
		GRAFO<VERTICE>(): g(NULL),cardinalidad(0){};                                         //listo!          
		~GRAFO<VERTICE>();                                                  //listo!
		bool es_vacio(){return(g==NULL);}                                  //listo!
		void agregar_vertice(VERTICE v);                                  //listo!
        void agregar_vertice_al_principio(VERTICE v);
		void agregar_arco(VERTICE u,VERTICE v,float c);                  //listo!
		void eliminar_vertice(VERTICE v);								//listo!
		void eliminar_arco(VERTICE u,VERTICE v);					   //listo!			
		bool existe_vertice(VERTICE v);						          //listo!
		bool existe_arco(VERTICE u,VERTICE v);                       //listo!
		float costo_arco(VERTICE u,VERTICE v);                      //listo!
		int orden(){return(cardinalidad);}                                               //listo!
		LISTA<VERTICE> predecesores(VERTICE v);                   //listo! 
		LISTA<VERTICE> sucesores(VERTICE v);					 //listo!
		void BFS(VERTICE s, VECTOR &dist, VECTOR &pred );       //listo!
		void DFS(VECTOR &pred, VECTOR &tdesc,VECTOR &tfinal );
	//	void DFS_VICITAR(VERTICE u,VECTOR &pred,VECTOR &tdesc,VECTOR &tfinal,VECTORCAD &color ,int &tiempo);
};

 
template<class VERTICE> 
GRAFO<VERTICE>::~GRAFO()
{
	NODO_VERTICE<VERTICE> *vact;
	NODO_ADY<VERTICE> *act,*elim;
	bool encontrado;
	int pos =1;
	
	while(  g != NULL)
	{
		act = g->get_lst_adyacente();  
		while((act != NULL) )//!encontrado ES IGUAL A encontrado== false
		{
			elim = act;
			act = act->get_proximo_adyacente();
			delete (elim);
		}
		vact = g;
		g = g->get_proximo_vertice();
		delete (vact);
	}
	g =  NULL;
}
	
template <class VERTICE> 
void GRAFO<VERTICE>::agregar_vertice(VERTICE v)
{
	NODO_VERTICE<VERTICE> *ant,*sig,*nuevo;
	
	if ( !existe_vertice(v) )
	{
		nuevo = new NODO_VERTICE<VERTICE>(v,NULL,NULL);
		ant = NULL;
		sig = g;
		while( (sig != NULL) && (sig->get_info() < v))
		{
			ant = sig;
			sig = sig->get_proximo_vertice();
		}
		if(ant == NULL)
		{
			//nuevo->set_proximo_vertice(g);
			g = nuevo;		
		}else
		 {
			 ant->set_proximo_vertice(nuevo);
			 nuevo->set_proximo_vertice(sig);
		 }
		 cardinalidad++;
	}
}

template<class VERTICE> 
void GRAFO<VERTICE>::agregar_vertice_al_principio(VERTICE v)
{
	NODO_VERTICE<VERTICE> *nuevo;
	
	nuevo = new NODO_VERTICE<VERTICE>(v,NULL,NULL);
	nuevo->set_proximo_vertice( g );
	g = nuevo;
	
}



template<class VERTICE> 
void GRAFO<VERTICE>::agregar_arco(VERTICE v,VERTICE w, float c)
{
	NODO_VERTICE<VERTICE> *origen;
	NODO_ADY<VERTICE> *ant,*sig,*nuevo;
		
	if ( existe_vertice(v) && existe_vertice(w) )
	{
		nuevo = new NODO_ADY<VERTICE>(w,c,NULL);
		origen = g;
		//while( (origen->get_info() < v)) //PENDIENTE CON "<", PÍAODRÍA SER "!="
		while( (origen->get_info() != v)) 
		{
			origen = origen->get_proximo_vertice();
		}
		ant = NULL;
		sig = origen->get_lst_adyacente();
		//while((sig != NULL) && (sig->get_info() != w))//PENDIENTE CON "!=", PÍAODRÍA SER "<"
		while((sig != NULL) && (sig->get_info() < w))
		{
			ant = sig;
			sig = sig->get_proximo_adyacente();
		}
		
		if(ant == NULL)
		{
			nuevo->set_proximo_adyacente(sig);
			origen->set_lst_adyacente(nuevo);
		}else
		{
			 ant->set_proximo_adyacente(nuevo);
			 nuevo->set_proximo_adyacente(sig);
		}
	}
}

template<class VERTICE> 
LISTA<VERTICE> GRAFO<VERTICE>::predecesores(VERTICE v)
{
	NODO_VERTICE<VERTICE> *vact;
	NODO_ADY<VERTICE> *act;
	LISTA<VERTICE> L;
	bool encontrado;
	//~ int pos =1;
	
	//~ L.construir();
	vact = g;
	while( vact != NULL)
	{
		act = vact->get_lst_adyacente();  
		encontrado = false;
		while((act != NULL) && (!encontrado))//!encontrado ES IGUAL A encontrado== false
		{
			if(act->get_info() == v)
			{
				L.insertar_al_final( vact->get_info() );//implementar este metodo en la clase lista
				//~ L.insertar_por_pos(vact->get_info(),pos);
				//~ pos++;
				encontrado = true;
			
			}else	act = act->get_proximo_adyacente();
		}
		vact = vact->get_proximo_vertice();
	}
	return(L);
}


template<class VERTICE>
LISTA<VERTICE> GRAFO<VERTICE>::sucesores(VERTICE v)
{
	int i,j;
	NODO_VERTICE<VERTICE> *otro;
	LISTA<VERTICE> L;
	NODO_ADY<VERTICE> *aux,*aux1;
	
	//~ L.construir();
	otro = g;
	while( (otro->get_info() != v) && (otro !=NULL) )
	{
		 otro = otro->get_proximo_vertice();
	}
	if(otro !=NULL )
	{
		aux1 = otro->get_lst_adyacente();
		//j=1;
		while( aux1 != NULL)
		{	
			//~ L.insertar_por_pos(aux1->get_info(),j);
			L.insertar_al_final( aux1->get_info() );
			aux1 = aux1->get_proximo_adyacente();
			//~ j++;
		}
	 }
	return(L);		
}
template<class VERTICE>
//void GRAFO<VERTICE>::eliminarListaVertices( NODO_VERTICE<VERTICE> *&aptVert )
void GRAFO<VERTICE>::eliminarListaVertices( NODO_VERTICE<VERTICE> *aptVert )
{
	NODO_ADY<VERTICE> *adys,*aux;

    adys = aptVert->get_lst_adyacente();
	while( adys != NULL )
	{
	    aux = adys;
	    adys = adys->get_proximo_adyacente();
	    delete aux;
	}
	 delete aptVert;
   // aptVert = NULL;
}

template<class VERTICE>
void GRAFO<VERTICE>::eliminar_vertice(VERTICE v)
{
	NODO_VERTICE<VERTICE>  *vant,*vact,*origen,*sig;
	NODO_ADY<VERTICE> *adys,*aux,*ant;
	bool band;
	if( !es_vacio())
	{
		if ( existe_vertice(v) )
		{
			//vant = NULL;
			origen = g;
			if (origen->get_info( ) == v)
			{
                g = origen->get_proximo_vertice();
				eliminarListaVertices( origen ); //PROCEDIMIENTO PRIVADO QUE ELIMINA UN NODO VERTICE Y SUS ADYACENCTES
				origen = g;
            }  
			while(  origen != NULL )
			{
				adys = origen->get_lst_adyacente();
				if ( origen->get_info( ) == v )
				{
					vact = origen;
					origen = origen->get_proximo_vertice();
					vant->set_proximo_vertice( origen ); 
					eliminarListaVertices( vact );
					vact = NULL;
				}else
				{
					band = true;
					ant = NULL;
					while( (adys != NULL) && band )
					{
						if ( adys->get_info() == v ) band = false;
						else
						{
							ant = adys;
							adys = adys->get_proximo_adyacente();
						}
					}
					if( ant == NULL && !band )
					{
						origen->set_lst_adyacente( adys->get_proximo_adyacente() );
						delete adys;				
					}else
					{
						if( ant != NULL && !band )
						{
							ant->set_proximo_adyacente(adys->get_proximo_adyacente() );
							delete adys;
						}
					}
					vant = origen;
					origen = origen->get_proximo_vertice();
				}			
			}
			//origen = adys =  aux = ant = NULL;
			cardinalidad--;
		}
	}
}
	


/*
template<class VERTICE>
void GRAFO<VERTICE>::eliminar_vertice(VERTICE v)
{
	NODO_VERTICE<VERTICE>  *ant,*origen,*sig;
	NODO_ADY<VERTICE> *adys,*aux;
	
	if( !es_vacio())
	{
		ant = NULL;
		origen = g;
		while( (origen->get_info() != v) && (origen != NULL))
		{
			ant = origen;
			origen = origen->get_proximo_vertice();
		}
		if( origen != NULL )
		{
			adys = origen->get_lst_adyacente();
			while( adys != NULL )
			{
				aux  = adys;
				adys = adys->get_proximo_adyacente();
				delete aux;
			}
			if( ant != NULL )
		    {
				sig = origen->get_proximo_vertice();
				ant->set_proximo_vertice(sig);
				delete origen;
			}else
			{
				delete origen;
			}
		}
		cardinalidad--;
	}
	
}*/

template<class VERTICE>
void GRAFO<VERTICE>::eliminar_arco(VERTICE u,VERTICE v)
{
	VERTICE prim,seg;
	NODO_VERTICE<VERTICE> *origen;
	NODO_ADY<VERTICE> *aux,*ant_ady;
	
	if ( !es_vacio() )
	{
	   
		//~ if( existe_arco(u,v) || existe_arco(v,u) )
		if( existe_arco(u,v)  )
		{ 
			origen = g;
			while( (origen->get_info() != u) )
			{
				origen = origen->get_proximo_vertice();
			}

			ant_ady = NULL;
			aux = origen->get_lst_adyacente();
			while( (aux->get_info() != v) )
			{
				ant_ady = aux;
				aux = aux->get_proximo_adyacente();
			}

			if ( ant_ady == NULL )
			{
				cout<<"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee1 "<<endl;
				origen->set_lst_adyacente( aux->get_proximo_adyacente() );
				//origen->set_lst_adyacente( aux );

				delete aux;	
			}else
			{
				cout<<"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee2 "<<endl;				
				ant_ady->set_proximo_adyacente( aux->get_proximo_adyacente() );
				//ant_ady->set_proximo_adyacente(aux);
			    delete aux;	
			}
			
			
			/*origen = g;
			//while( (origen->get_info() != u) && (origen != NULL))
			while( (origen->get_info() != u) && (origen->get_info() != v) )
			{
				origen = origen->get_proximo_vertice();
			}
			if(origen->get_info() == u)
			{
				 prim = u;
				 seg  = v;
			}else
			{
				prim = v;
				seg  = u;
			}
			ant_ady == NULL;
			aux = origen->get_lst_adyacente();
			while( (aux->get_info() != seg) && (aux != NULL) )
			{
				ant_ady = aux;
				aux = aux->get_proximo_adyacente();
			}
			
			if( (ant_ady != NULL) )
			{
				ant_ady->set_proximo_adyacente(aux->get_proximo_adyacente());
				delete aux;
			}else
			{
				
				origen->set_lst_adyacente(aux->get_proximo_adyacente());
				delete aux;
			}*/
				
		}
	}
}

//En el pre{: v pertenece al grafo
template <class VERTICE>
bool GRAFO<VERTICE>::existe_vertice(VERTICE v)
{
	NODO_VERTICE<VERTICE> *origen;
	bool existe = false;
	
	if( !es_vacio() )
	{
		origen = g;
		while( (!existe ) && (origen != NULL) )
		{
			if( origen->get_info() == v )
			{
				existe = true;
			}else
			{
				origen = origen->get_proximo_vertice();
			}
		}
	}	
	return(existe);		
}


template<class VERTICE>
bool GRAFO<VERTICE>::existe_arco(VERTICE u,VERTICE v)
{
	NODO_VERTICE<VERTICE> *origen;
	NODO_ADY<VERTICE> *aux;
	bool existe = false,listo = false;
	
	if( !es_vacio() )
	{	
		if( existe_vertice(u) && existe_vertice(v) )
		{	
			origen = g;								
			while(  (origen->get_info() != u) )
			{
				origen = origen->get_proximo_vertice();
			}
			aux = origen->get_lst_adyacente();
			while(  (aux != NULL) && (!existe) )
			{
				if( aux->get_info() == v)
				{
					existe = true;				
				}else
				{
					aux = aux->get_proximo_adyacente();
				}			
			}
			//return(existe);	
		}///else return(false);
	}	
	return(existe);	
}



template<class VERTICE>
float GRAFO<VERTICE>::costo_arco(VERTICE u,VERTICE v)
{
	NODO_VERTICE<VERTICE> *origen;
	NODO_ADY<VERTICE> *aux;
	
	if( existe_arco(u,v) )
	{	
		origen = g;
		while(  origen->get_info() != u )
		{
			origen = origen->get_proximo_vertice();
		}
		aux = origen->get_lst_adyacente();
		while(  aux->get_info() != v)
		{
			aux = aux->get_proximo_adyacente();
		}
		return( aux->get_costo() );			
	}else 
		return(-1.1);	//si no existe un arco de u a v devuenve este centinela
}

/*
template<class VERTICE>
int GRAFO<VERTICE>::orden()
{
	int cont = 0;
	NODO_VERTICE<VERTICE> *origen;

	origen= g;
	while(origen != NULL)
	{
		origen = origen->get_proximo_vertice();
		cont++;
	}
	return(cont);
}*/
	

template<class VERTICE>
void GRAFO<VERTICE>::BFS(VERTICE s, VECTOR &dist, VECTOR &pred )
{

	if ( existe_vertice(s) )
	{
		int i;
		VECTORCAD color;
	//	LISTA<char> color;
		VERTICE u,v;
		COLA<VERTICE> C;
		LISTA<VERTICE> L;
		
		for (i=0;i<this->orden();i++)
		{
	//		color.insertar_por_pos('b',i);
			color[i] = "blanco";
			dist[i]	 = MAXDIST;
			pred[i]  = 0;	
		}
	//	color.insertar_por_pos('g',s);
		color[s] = "gris";
		dist[s]  = 0;
		C.encolar(s);
		while(!C.es_vacia())	
		{
			u = C.get_frente();
			C.desencolar();
			L = this->sucesores(u);
			while(!L.es_vacia())
			{
				v = L.consultar_por_pos(1);
				L.eliminar_por_pos(1);
				if(color[v] == "blanco")
	//			if(color.consultar_por_pos(v) == 'b')	
				{				
					color[v] = "gris";
	//				color.insertar_por_pos('g',v);				
					dist[v]	 = dist[u]+1;
					pred[v]  = u;
					C.encolar(v);	
				}
			}
	//		color.insertar_por_pos('n',u);
			color[u] = "negro";
		}
	}
}


//BUSQUEDA EN AMPLITUD
template<class VERTICE>
void GRAFO<VERTICE>::DFS(VECTOR &pred, VECTOR &tdesc,VECTOR &tfinal )
{
	VECTORCAD color;
//	LISTA<char> color;
	VERTICE u;
	int tiempo,cant_vertices;

	cant_vertices = this->orden();
	for (u=0; u<cant_vertices; u++)  //for (u=0; u<=cant_vertices; u++) (ultima modificacion 08/12/2015)
	{
		color[u] = "blanco";
//		color.insertar_por_pos('b',u);
		pred[u]  = -1;	
	}

	tiempo = 0;	
	for (u=0; u<=cant_vertices; u++)   //for (u=0; u<=cant_vertices; u++) (ultima modificacion 08/12/2015)
	{
		if(color[u] == "blanco")	
//		if(color.consultar_por_pos(u) == 'b')
		{
//			//color[v] = "gris";
			DFS_VICITAR(u,pred,tdesc,tfinal,color,tiempo);	
		}	
	}
}

template<class VERTICE>
void GRAFO<VERTICE>::DFS_VICITAR(VERTICE u,VECTOR &pred,VECTOR &tdesc,VECTOR &tfinal,VECTORCAD &color,int &tiempo)	
{
	if ( existe_vertice(u) )
	{
	
		cout<<"ENTRANDO AL DFS"<<endl;
		LISTA<VERTICE> L;
		VERTICE v;
		
		color[u] = "gris";
	//	color.insertar_por_pos('g',u);
		tiempo    = tiempo+1;
		tdesc[u]  = tiempo;
		L = sucesores(u); 
		while(!L.es_vacia())
		{
			v = L.consultar_por_pos(1); // POR QuE EN LOS METODOS ESTATICOS NO PUEDEN USAR EL OPERADOR (this)?
			L.eliminar_por_pos(1);
			if(color[v] == "blanco")
	//		if(color.consultar_por_pos(v) == "b")
			{
				pred[v] = u;
				DFS_VICITAR(v,pred,tdesc,tfinal, color,tiempo);	
			}	
			color[u] = "negro";
	//		color.insertar_por_pos('n',u);
			tiempo = tiempo+1;
			tfinal[u] = tiempo;
			cout<<"DFS FINAL"<<endl;
		}
	}	
}

#endif

