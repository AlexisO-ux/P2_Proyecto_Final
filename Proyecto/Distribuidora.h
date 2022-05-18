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
		cout<<facturas[i]->getRS();
		cout<<endl;
		cout<<facturas[i]->getRUC();
		cout<<endl;
		cout<<facturas[i]->getNFac();
		cout<<endl;
		cout<<facturas[i]->getSubT();
		cout<<endl;
		cout<<facturas[i]->getTotal();
		cout<<endl;
		facturas[i]->mostrar();
		cout<<endl;
	}
}

void Distribuidora::buscaFactura(string nF){//esto si
	
	for(int i=0;i<facturas.size();i++){
		if(facturas[i]->getNFac()==nF){
			
			cout<<facturas[i]->getRS();
			cout<<endl;
			cout<<facturas[i]->getRUC();
			cout<<endl;
			cout<<facturas[i]->getNFac();
			cout<<endl;
			cout<<facturas[i]->getSubT();
			cout<<endl;
			cout<<facturas[i]->getTotal();
			cout<<endl;
			return;
			
		}else{
			
			cout<<endl<<"No se encontro la factura";
			
		}
		
	}
	
}
//

