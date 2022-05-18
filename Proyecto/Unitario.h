#ifndef UNITARIO_H
#define UNITARIO_H

#include "Producto.h"
using namespace std;

class Unitario : public Producto
{
		int cantidad;
		float precio;
	public: 
		Unitario(string _nombre, string _descripcion, int _cantidad, float _precio): Producto(_nombre, _descripcion){
		
			cantidad=_cantidad;
			precio=_precio; 
		
		};
		~Unitario(){
			cout<<endl<<"Destructor producto unitario..."<<endl; 	
		} ;
		float setSubtotal(){
			float subtotal; 
			subtotal=cantidad*precio; 
			return subtotal; 
		};
		
		void mostrar(){
			cout<<"PRODUCTO: "<<nombre<<" DESCRIPCION: "<<descripcion<<" CANTIDAD: "<<cantidad<<" PRECIO UNITARIO: "<<precio<<" SUBTOTAL: "<<setSubtotal()<<endl; 
		};
	
};

#endif
