#include "grafo.h"

using namespace std;

int main()
{
	int i,j,ind ;
	GRAFO<int > grafo1,grafo2,grafo3;
	LISTA<int> list_suc,list_pre;	
//	LISTA<int> dist,pred;
	VECTOR dist,pred;
	VECTOR predDFS,tdescDFS,tfinalDFS;

    cout<<"-----------------------------1----------------------------------- "<<endl;
	if( grafo1.es_vacio() ) cout<<"EL grafo1 ESTA VACIO"<<endl;
	else cout<<"EL grafo1 NO ESTA VACIO"<<endl;
    
    cout<<"-----------------------------2----------------------------------- "<<endl;
	for(i=0;i<=10;i++)
	{
		grafo1.agregar_vertice(i);
	}
	for(i=0;i<=10;i++)
	{
		grafo2.agregar_vertice(i);
	}
	cout<<"EL orden del grafo1 ="<<grafo1.orden()<<endl;
	
	cout<<"-----------------------------3----------------------------------- "<<endl;
	for(i=0;i<10;i++)
	{
		grafo1.agregar_arco(i,i+1,i*1.2);
	}
	for(i=0;i<10;i++)
	{
		grafo2.agregar_arco(i,i+1,i*1.2);
	}
	cout<<"COSTO DE 2 A 3 ="<<grafo1.costo_arco(2,3)<<endl;
	
	//if( grafo1.existe_vertice(20) ) cout<<"EL 3 EXISTE EN EL grafo1 "<<endl;
	//else cout<<"EL 3 EXISTE NO EN EL grafo1 "<<endl;
    
    cout<<"-----------------------------4----------------------------------- "<<endl;

//    grafo1.eliminar_vertice(1);
    cout<<"EL orden del grafo1 ="<<grafo1.orden()<<endl;
     cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
	if( grafo1.existe_arco(1,2) ) cout<<"SI EXISTE ARCO DE 1 A 2 EN EL grafo1 "<<endl;
	else cout<<"NO EXISTE ARCO DE 1 A 2 EN EL grafo1 "<<endl;

    cout<<"-----------------------------5----------------------------------- "<<endl;
	if( grafo1.existe_arco(5,6) ) cout<<"SI EXISTE ARCO DE 5 A 6 EN EL grafo1 "<<endl;
	else cout<<"NO EXISTE ARCO DE 5 A 6 EN EL grafo1 "<<endl;

	cout<<"-----------------------------6----------------------------------- "<<endl;
//    grafo1.eliminar_arco(5,6);
	cout<<"despues de eliminar arco "<<endl;
	if( grafo1.existe_arco(5,6) ) cout<<"SI EXISTE ARCO DE 5 A 6 EN EL grafo1 "<<endl;
	else cout<<"NO EXISTE ARCO DE 5 A 6 EN EL grafo1 "<<endl;
	for(j=4;j<=10;j++)
    {
	 	grafo1.agregar_arco(2,j,j*10.1);
	}
//	grafo1.eliminar_arco(2,7);
	if( grafo1.existe_arco(2,7) ) cout<<"SI EXISTE ARCO DE 2 A 7 EN EL grafo1 "<<endl;
	else cout<<"NO EXISTE ARCO DE 2 A 7 EN EL grafo1 "<<endl;
	
	cout<<"-----------------------------7----------------------------------- "<<endl;
	cout<<"***APLICANDO BFS SOBRE EL grafo1***"<<endl;
	j=0;
	grafo1.BFS(1,dist,pred );
	cout<<" DISTANCIA HASTA ANTES:"<<dist[7]<<endl;
	cout<<" PREDECESOR DE 7:"<<pred[7]<<endl;
	while(j<= 10)
    {
		cout<<" DISTANCIA HASTA :"<<j<<"=="<<dist[j]<<endl;
		cout<<" PREDECESOR :"<<pred[j]<<endl;
		cout<<"----------------------------"<<endl;
		j++;
	}	
	cout<<"************************************************"<<endl;
	cout<<"-----------------------------8----------------------------------- "<<endl;
	cout<<"***APLICANDO DFS SOBRE EL grafo1***"<<endl;
/*
	grafo2.DFS(predDFS,tdescDFS,tfinalDFS);

   cout<<"innnnnndddd=="<<predDFS[0]<<endl;
   cout<<"ssssssssssssss=="<<tdescDFS[0]<<endl;
   cout<<"ssssssssssssss=="<<tfinalDFS[0]<<endl;
    ind = 0;
	while( predDFS[ind] != '\0') 
	{
		cout<<"innnnnndddd=="<<ind;
		cout<<"predDFS"<<"en "<<ind<<"=="<<predDFS[ind] <<endl;
		ind++;

	}
*/
	for(i=0;i<6;i++)
	{

		grafo3.agregar_vertice(i);
	}
/*
	grafo3.agregar_arco(0,1,1.1);
	grafo3.agregar_arco(0,2,1.1);
	grafo3.agregar_arco(2,3,1.1);
	grafo3.agregar_arco(3,4,1.1);
	grafo3.agregar_arco(3,5,1.1);
	grafo3.agregar_arco(4,5,1.1);*/

	grafo3.DFS(predDFS,tdescDFS,tfinalDFS);
	ind = 0;
	while( ind < 6) 
	{
		cout<<"==============================================================="<<ind<<endl;
		cout<<"predDFS"<<"en "<<ind<<"=="<<predDFS[ind] <<endl;
		cout<<"tdescDFS"<<"en "<<ind<<"=="<<tdescDFS[ind] <<endl;
		cout<<"tfinalDFS"<<"en "<<ind<<"=="<<tfinalDFS[ind] <<endl;
		cout<<"==============================================================="<<endl;
		ind++;

	}

/*	list_suc = grafo1.sucesores(2);
	cout<<"LOS sucesores DE 2 SON :"<<endl;
	for(j=1;j<=list_suc.longitud();j++)
    {
		cout<<" "<< list_suc.consultar_por_pos(j)<<",";
	}
	cout<<endl;
/*/
/*	if( grafo1.existe_arco(2,5)) cout<<"---EXISTE ARCO DE 2 A 5 = :"<<endl;
	else cout<<"---NO EXISTE ARCO DE 2 A 5 = :"<<endl;
	cout<<"DESPES DE ELIMINAR EL ARCO DE 2 A 5 = :"<<endl;
	grafo1.eliminar_arco(2,5);
	if( grafo1.existe_arco(2,5)) cout<<"---EXISTE ARCO DE 2 A 5 = :"<<endl;
	else cout<<"---NO EXISTE ARCO DE 2 A 5 = :"<<endl;

	grafo1.eliminar_vertice(9);
//	if( grafo1.existe_vertice(9)) cout<<"---EXISTE EL VERTICE 9:"<<endl;
//	else cout<<"---NO EXISTE EL VERTICE 9:"<<endl;

	list_pre = grafo1.predecesores(10);
	cout<<"LOS predecesores DE 10 SON :"<<endl;
	for(j=1;j<=list_pre.longitud();j++)
    {
		cout<<" "<< list_pre.consultar_por_pos(j)<<",";
	} 
*/
    grafo1.~GRAFO();
    cout<<"-------------------destructor como ultima accion------------------------------------ "<<endl;
	if(grafo1.es_vacio()) cout<<"EL grafo1 ESTA VACIO"<<endl;
	else cout<<"EL grafo1 NO ESTA VACIO"<<endl;
   
   return(0);
}
