#include <iostream>
#include "Distribuidora.h"
//#include "Factura.h"
//#include "Producto.h"
#include "Granel.h"
#include "Unitario.h"
using namespace std; 


void agregarFactura(Distribuidora *D){
	int opc,tipo;
	string rS,ruc,nF;
	string nombre,desc;
	int cantidad;
	float precio,sub=0,peso;
	
	cout<<"Ingresa la razon social: ";
	cin>>rS;
	cout<<endl<<"Ingresa el RUC: ";
	cin>>ruc;
	cout<<endl<<"Ingresa el numero de factura: ";
	cin>>nF;
	system("cls");
	Factura *f=new Factura(rS,ruc,nF);//hacer diamico
	do{
		cout<<"Desea agregar producto? (1:si/0:no): "<<endl;
		cin>>opc;
		
		if(opc==1){
			
			cout<<"Unitario = 1"<<endl;
			cout<<"Granel = 2"<<endl;
			cout<<"Ingresa la opcion: ";
			cin>>tipo;
			
			switch(tipo){
				case 1:
				
			
					
					cout<<endl<<"Unitario"<<endl;
					cout<<"Nombre del producto: ";
					cin>>nombre;
					cout<<"Descripcion del producto: ";
					cin>>desc;
					cout<<"Ingrese cantidad: ";
					cin>>cantidad;
					cout<<"Ingrese precio: ";
					cin>>precio; 
					{
						Unitario *U=new Unitario(nombre, desc, cantidad, precio);
						f->addItem(U);
						
					}
					 
					sub=sub+(cantidad*precio);
					
					
					
					break;	
				case 2://verificar si esto funciona bien xd
					cout<<endl<<"Granel"<<endl;
					cout<<"Nombre del producto: ";
					cin>>nombre;
					cout<<"Descripcion del producto: ";
					cin>>desc;
					cout<<"Ingrese peso en gramos: ";
					cin>>peso;
					cout<<"Ingrese precio: ";
					cin>>precio; 
					{
						Granel *G=new Granel(nombre,desc,peso,precio);
						
						sub=sub+((peso/1000)*precio);
						f->addItem(G);
						
					}
					break;
				default:
					break;
			}
		}
		
		
	}while(opc!=0);


	f->setSubTotal(sub);
	f->setTotal();
	D->guardaFactura(f);
	delete f;
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int opc;
	string nFactura;
	Distribuidora *D=new Distribuidora;
	do{
		cout<<"Menu"<<endl;
		cout<<"1.- Agregar factura"<<endl;
		cout<<"2.- Listar Facturas"<<endl;
		cout<<"3.- Imprimir Factura"<<endl;
		cout<<"0.- Salir"<<endl;
		cout<<"Ingrese opcion: "<<endl;
		cin>>opc;		
		system("cls");
		
		switch(opc){
			default:
				cout<<"Opcion no disponible"<<endl;
			case 0:
				break;
			case 1:
				cout<<"Agregar factura"<<endl;
				agregarFactura(D);
				break;
			case 2:
				D->listaFacturas();
				break;
			case 3:
				cout<<"Ingresa el numero de factura a buscar: ";
				cin>>nFactura;
				D->buscaFactura(nFactura);
				break;
				
		
		
		}
		
	}while(opc!=0);
	
	delete D;
	
	return 0;
}
