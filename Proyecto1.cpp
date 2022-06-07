//Maria Elizabeth Cuaya Padilla 	19110132 	2°G2
//PROYECTO: LISTA DE REPRODUCCIÓN
//-------------------------------------------------------------------------------------------------------
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
//-------------------------------------------------------------------------------------------------------
class nodo{
	public:
		nodo(int n, string t, nodo *sig=NULL, nodo *ant=NULL):num(n), texto(t), siguiente(sig), anterior(ant)	{ }
		
	private:
	int num;
	string texto;
	nodo *siguiente;
	nodo *anterior;
	
	friend class lista;		
};

typedef nodo *pnodo;

class lista{
	public:
		lista() : plista(NULL)	{ }
		~lista();
		
		void Agregar(int a);
		void Mostrar_todo();
		void Buscar (int b);
		void Borrar(int b);
		void Siguiente();
		void Anterior();		
		void Primero(); 		
		void Ultimo();
		int Lista_vacia()	{return plista==NULL;}
		int Actual()	{return plista !=NULL;}
		string Texto_actual()	{return plista -> texto;}
		
	private:
		pnodo plista;
};

lista::~lista(){
	pnodo aux;	
	Primero();
	while(plista){
		aux = plista;
		plista = plista->siguiente;
		delete aux;
	}
}
//-----------------------------------------------------------------------------------------------
void lista::Agregar(int a){
	string titulo, artista, album;
	ofstream archivo;
	archivo.open("reprod.txt",ios::app);

	if(archivo.fail()){
		cout<<"\t\t\tLo sentimos, No se encontro esa lista de reproduccion\n"<<endl;
	exit(1)	;}
	cout<<"Numero: "<<a;
	archivo<<a<<endl;
	cout<<"Nombre de la cancion: ";
	cin>>titulo;
	archivo<<titulo<<endl;
	cout<<"Nombre del artista(s): ";
	cin>>artista;
	archivo<<artista<<endl;
	cout<<"Album al que pertenece: ";
	cin>>album;
	archivo<<album<<endl;
	cout<<endl;
	archivo.close();
}

void lista::Mostrar_todo(){
	string texto;
	ifstream archivo;
	archivo.open("reprod.txt",ios::in);
	
	if(archivo.fail()){
		cout<<"\t\t\tLo sentimos\n\t\t\tNo se encontro esa lista de reproduccion\n"<<endl;
	exit(1)	;}
	
	while(!archivo.eof()){

	getline(archivo,texto);
		cout<<texto<<endl;
		cout<<endl;
	}	
	
	archivo.close();
}

void lista::Borrar(int b){
	pnodo nodo;

	nodo = plista;	
	
	if(!nodo||nodo-> num !=b){
		cout<<"\nDato "<<b<<" no encontrado...\n";
		return;
	}
	
	if(nodo ->anterior)
		nodo ->anterior ->siguiente = nodo->siguiente;
	if(nodo ->siguiente)
		nodo ->siguiente->anterior = nodo->anterior;
	delete nodo ;
	cout<<"\nBorrado exitoso de "<<b<<endl;
}

void lista::Buscar(int b){
	pnodo nodo;
	
	
	if(!nodo || nodo-> num !=b){
			cout<<"\nDato "<<b<<" no existe...\n";
		return;
	}
	else{
		cout<<b<<" cancion en reproduccion\n"<<endl;
	}
}

void lista::Siguiente(){
	if(plista) plista = plista->siguiente;
}

void lista::Anterior(){
	if(plista) plista = plista->anterior;
}

void lista::Primero(){
	while(plista && plista->siguiente) plista= plista->siguiente;	
}

void lista::Ultimo(){
	while(plista && plista->siguiente) plista= plista->siguiente;
}

//--------------------------------------------------------------------------------------------
int main(){
	int opcion, a=1, n;
	string busqueda, borrado;
	lista Lista;

do{
	cout<<"\tPLAYLIST"<<endl;
	cout<<"\tBienvenido\nQue accion deseas realizar?"<<endl;
	cout<<"\n1)Agregar musica\n2)Mostrar lista completa\n3)Mostrar lo ultimo agregado\n4)Buscar en tu lista\n5)Borrar musica de tu lista\n6)Salir\n";	
	cin>>opcion;
	cout<<endl;
	switch(opcion){
		case 1:
			system("CLS");
			Lista.Agregar(a);
			system("CLS");
			a++;
		break;
		
		case 2:
			system("CLS");
			Lista.Mostrar_todo();
			system("PAUSE");
			system("CLS");
		break;
		
		case 3:
			system("CLS");
			Lista.Ultimo();
			cout<<"\tUltimo agregado\n"<<Lista.Texto_actual();
			cout<<endl;
		break;
		
		case 4:
			system("CLS");
			cout<<"\nBuscar: ";
			cin>>n;
			Lista.Buscar(n);
			cout<<endl;
			
		break;
		
		case 5:
			system("CLS");
			cout<<"\nCancion que deseas borrar: ";
			cin>>n;
			Lista.Borrar(n);
			cout<<endl;
		break;
		
		case 6:
			system("CLS");
			cout<<"\n\t\tSaliste del programa\n\t\tVuelve pronto...";
		break;
		
		default:
			cout<<"\n\t\tOpcion no valida\n\t\tIntentalo de nuevo...";
		break;									
	}
	
}while(opcion!=6);	
	
	return 0;
}
