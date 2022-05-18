#include <iostream>
#include "Unitario.h"
#ifndef PRODUCTO_H
#define PRODUCTO_H

using namespace std; 

class Producto
{
	protected:
		string nombre; 
		string descripcion;
	public: 
		Producto(string _nombre,string _descripcion){
			nombre=_nombre; 
			descripcion=_descripcion;	
		} 
		~Producto(){
			cout<<"Destructor producto..."<<endl; 
		} 
		virtual	void mostrar(){
			cout<<endl<<"Producto: "<<nombre<<" Descripcion: "<<descripcion<<endl; 
		} 
		
		string getNombre(){
			return nombre;
		}
		
		string getDesc(){
			return descripcion;
		}

};

#endif

