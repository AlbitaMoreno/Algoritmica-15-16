#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;


int main(int argc, char *argv[]){

	if(argc < 2){
		cout <<"Falta fichero de entrada\n";
		return -1;
	}
	string comentario;
	ifstream fentrada;
	int n_ciudades;
	fentrada.open(argv[1]);
	fentrada >> comentario;
	fentrada >> n_ciudades;
	double ciudad[n_ciudades][2];
	bool usados[n_ciudades];				// Vector de booleanos de ciudades ya usadas en el circuito(estará a 0 si no se ha insertado todavia)



	for(int i=0; i<n_ciudades; i++){
		fentrada >> comentario;
		fentrada >>ciudad[i][0];			// Almeceno la coordenada x en la primera columna
		fentrada >>ciudad[i][1];			// y la coordenada y en la segunda.
		usados[i]=0;		//Inicializo todo el vector a no usados.
	}

	fentrada.close();

	//ya tengo mi matriz con dos columnas, las coordenadas de las ciudades
	int este,oeste,norte;
	oeste = este = norte = 0;

	for(int i = 0; i < n_ciudades; i++){
	//lo que primero voy a hacer es la ciudad que hay más al oeste, el menor valor de X que hay

		if(ciudad[i][0] < ciudad[oeste][0])
				oeste = i;
			

		if(ciudad[i][0] > ciudad[este][0])
				este = i;
			

		if(ciudad[i][1] > ciudad[norte][2])
				norte = i;
	}


	usados[oeste]=1;			// Marco que están siendo usados puesto que forman parte del triangulo inicial.
	usados[este]=1;
	usados[norte]=1;

	for(int i=0; i<n_ciudades; i++){
		cout << "ciudad "<<(i+1)<<"= "<<usados[i]<<endl;
	}

	cout << endl;
	cout << "Ciudad más al este =  "<< (este+1) <<", con coordenadas: (" << ciudad[este][0]  << ", " << ciudad[este][1] <<")"<< endl;
	cout << "Ciudad más al oeste = "<< (oeste+1) <<", con coordenadas: (" << ciudad[oeste][0] << ", " << ciudad[oeste][1] <<")"<< endl;
	cout << "Ciudad más al norte = "<< (norte+1) <<", con coordenadas: ("<< ciudad[norte][0] << ", " << ciudad[norte][1] <<")"<< endl;

	double distancia[n_ciudades][n_ciudades];	//Matriz de las distancias entre ciudades.
		
	//Calculo de distancias
	for(int i=0; i < n_ciudades; i++){
		for(int j=0; j<n_ciudades; j++){
			distancia[i][j]= sqrt(pow((ciudad[j][0]-ciudad[i][0]),2)+pow((ciudad[j][1]-ciudad[i][1]),2));
		}
	}

	for(int i=0; i < n_ciudades; i++){				//MOSTRAR MATRIZ DE DISTANCIAS
		for(int j=0; j<n_ciudades; j++){
			cout << distancia[i][j]<<" ";
		}
		cout<<"\n";
	}


	double dis_min=999999, dis_aux;
	for(int i=0; i<n_ciudades; i++){
		if(!usados[i]){
			dis_aux = distancia[oeste][norte] + distancia[norte][i] + distancia[i][este] + distancia[este][oeste];
			if(dis_aux < dis_min)
				dis_min=dis_aux;
			dis_aux = distancia[oeste][i] + distancia[i][norte] + distancia[norte][este] + distancia[este][oeste];
			if(dis_aux < dis_min)
				dis_min=dis_aux;
			dis_aux = distancia[oeste][norte] + distancia[norte][este] + distancia[este][i] + distancia[i][oeste];
			if(dis_aux < dis_min)
				dis_min=dis_aux;
		}

	}
	cout<<"\n\n"<< dis_min;


}



