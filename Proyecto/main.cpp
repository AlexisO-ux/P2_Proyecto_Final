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

	cout<<"Ingresa el numero de factura: ";
	cin>>nF;	
	cout<<"Ingresa la razon social: ";
	cin>>rS;
	cout<<"Ingresa el RUC: ";
	cin>>ruc;
	system("cls");
	Factura *f=new Factura(rS,ruc,nF);//hacer diamico
	do{
		cout<<"---------------------------------------"<<endl<<
			"|       DESEA AGREGAR PRODUCTO?        |"<<endl<<
			"---------------------------------------"<<endl;
			cout<<"1.- Si"<<endl;
			cout<<"0.- No"<<endl;
			cout<<"Ingresa la opcion: ";
			cin>>opc;
		
		if(opc==1){
		cout<<"---------------------------------------"<<endl<<
			"|           AGREGAR PRODUCTO            |"<<endl<<
			"---------------------------------------"<<endl;
			cout<<"1.- Unitario"<<endl;
			cout<<"2.- Granel"<<endl;
			cout<<"Ingresa la opcion: ";
			cin>>tipo;
			
			switch(tipo){
				case 1:
				
			
					cout<<"---------------------------------------"<<endl<<
							"|            PRODUCTO UNITARIO        |"<<endl<<
							"---------------------------------------"<<endl; 	
					
					cout<<"Nombre del producto: ";
					cin>>nombre;
					cout<<"Descripcion del producto: ";
					cin>>desc;
					cout<<"Ingrese cantidad: ";
					cin>>cantidad;
					cout<<"Ingrese precio: ";
					cin>>precio; 
					cout<<endl; 
					{
						Unitario *U=new Unitario(nombre, desc, cantidad, precio);
						f->addItem(U);
						
					}
					 
					sub=sub+(cantidad*precio);
					
					
					
					break;	
				case 2://verificar si esto funciona bien xd
					cout<<"---------------------------------------"<<endl<<
						"|            PRODUCTO A GRANEL         |"<<endl<<
						"---------------------------------------"<<endl; 
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
		
		system("cls");
		
	}while(opc!=0);


	f->setSubTotal(sub);
	f->setTotal();
	D->guardaFactura(f);
	//delete f;
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int opc;
	string nFactura;
	Distribuidora *D=new Distribuidora;
	do{
	cout<<"---------------------------------------"<<endl<<
		"|                MENU                 |"<<endl<<
		"---------------------------------------"<<endl;
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
				
			cout<<"---------------------------------------"<<endl<<
				"|           AGREGAR FACTURA            |"<<endl<<
				"---------------------------------------"<<endl; 
				agregarFactura(D);
				break;
			case 2:
				D->listaFacturas();
				system("pause");
				system("cls");
				break;
			case 3:
			cout<<"---------------------------------------"<<endl<<
				"|            BUSCAR FACTURA            |"<<endl<<
				"---------------------------------------"<<endl; 
				cout<<"Ingresa el numero de factura a buscar: ";
				cin>>nFactura;
				D->buscaFactura(nFactura);
				
				system("pause");
				system("cls");
				
				break;
				
		}
		
	}while(opc!=0);
	
	delete D;
	
	return 0;
}
