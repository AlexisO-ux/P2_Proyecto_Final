#ifndef GRANEL_H
#define GRANEL_H

#include "Producto.h"

class Granel : public Producto
{
		float gramos;
		float precio; 
	public:
		Granel(string _nombre,string _descripcion ,float _gramos, float _precio) : Producto(_nombre, _descripcion){
			gramos=_gramos; 
			precio=_precio; 
		}
		~Granel(){
			cout<<endl<<"Destructor producto a granel..."<<endl; 
		}
		float setSubtotal(){
			float subtotal; 
			subtotal=(gramos/1000)*precio; 
			return subtotal; 
		}
		void mostrar(){
			cout<<"PRODUCTO: "<<nombre<<" DESCRIPCION: "<<descripcion<<" GRAMOS: "<<gramos<<" SUBTOTAL: "<<setSubtotal()<<endl;  
		}
		
};

#endif
