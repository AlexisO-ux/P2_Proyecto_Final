#include <vector>
#include "Factura.h"
#include "Producto.h"



using namespace std; 

class Distribuidora
{
	protected: 
		vector<Factura *> facturas; //tipo de dato vector de puteros llamado facturas 
	public:
		Distribuidora(){
			
		}
		~Distribuidora(){
			cout<<"Destructor de distribuidora..."<<endl; 
		}
	
		void guardaFactura(Factura *f);
		//void guardaFactura(vector<Factura*> f);  //NO IMPLEMENTAR
	
		void listaFacturas();
		void imprimeFactura(string numFactura);
		//Factura* buscaFactura(string numFactura);
		void buscaFactura(string numFactura);

};

void Distribuidora::guardaFactura(Factura *f){
	facturas.push_back(f);
}

void Distribuidora::listaFacturas(){
	for(int i=0;i<facturas.size();i++){
	cout<<endl<<"-------------------------------------------"<<endl<<
		  "              FACTURA  "<<facturas[i]->getNFac()<<endl<<
		  "-------------------------------------------"<<endl<<
		  "     Num. Factura     |"<<"     "<<facturas[i]->getNFac()<<endl<< 
		  "     Razon Social     |"<<"     "<<facturas[i]->getRS()<<endl<< 
		  "         RUC          |"<<"     "<<facturas[i]->getRUC()<<endl<< 
		  "       SubTotal       |"<<"     "<<facturas[i]->getSubT()<<endl<< 
		  "         Total        |"<<"     "<<facturas[i]->getTotal()<<endl<<
		  "-------------------------------------------"<<endl; 
		facturas[i]->mostrar();
		cout<<endl;
	}
}

void Distribuidora::buscaFactura(string nF){//esto si
	
	for(int i=0;i<facturas.size();i++){
		if(facturas[i]->getNFac()==nF){
			
	cout<<endl<<"-------------------------------------------"<<endl<<
		  "|                FACTURA                  | "<<endl<<
		  "-------------------------------------------"<<endl<<
		  "     Num. Factura     |"<<"     "<<facturas[i]->getNFac()<<endl<< 
		  "     Razon Social     |"<<"     "<<facturas[i]->getRS()<<endl<< 
		  "         RUC          |"<<"     "<<facturas[i]->getRUC()<<endl<< 
		  "       SubTotal       |"<<"     "<<facturas[i]->getSubT()<<endl<< 
		  "         Total        |"<<"     "<<facturas[i]->getTotal()<<endl<<
		  "-------------------------------------------"<<endl; 
			return;
			
		}
		else{
			
			cout<<endl<<"No se encontro la factura";
			
		}
		
	}
	
}
//

