#include <vector>
#include "Producto.h"
#include <iostream>
#ifndef FACTURA_H
#define FACTURA_H

using namespace std; 

class Factura
{
	protected: 
		string razonSocial;
		string RUC; //Registro Unico de Contribuyentes 
		string numeroFactura;
	double subTotal;
	double IVA;
	double total;
	vector<Producto *> items;
	public:
		Factura(){
			razonSocial=" ";
			RUC=" ";
			numeroFactura=" ";
			subTotal=0;
			IVA=0.16; 
			total=0;
		}
	    Factura(string _razonSocial, string _RUC, string _numeroFactura){
	    	razonSocial=_razonSocial;
	    	RUC=_RUC; 
	    	numeroFactura=_numeroFactura; 
	    	subTotal=0;
			IVA=0.16; 
			total=0;
		}
		~Factura(){
			cout<<"Destructor de Factura..."<<endl; 
		}

		void addItem(Producto *p){
			items.push_back(p);
			
		}
		
		string getRS(){
			
			return razonSocial;
		}
		
		string getRUC(){
			
			return RUC;
		}
		
		string getNFac(){
			
			return numeroFactura;
		}
		
		double getSubT(){
			
			return subTotal;
		}
		
		double getTotal(){
			
			return total;
		}
		
		double setSubTotal(float sub){
			subTotal=sub;
		}
		
		void setTotal(){
			total=subTotal+(subTotal*IVA);
		}
		
		void mostrar(){
			cout<<"---Productos---"<<endl;
			for(int i=0;i<items.size();i++){
				cout<<endl;
				cout<<items[i]->getNombre();
			}
		}
		
		 

};

#endif
