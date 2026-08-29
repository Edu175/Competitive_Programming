#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void mensaje(const char *msg)
{
    cout << msg << endl;
    exit(0);
}

int evaluador_M, evaluador_N;
int evaluador_datos[4];
int evaluador_total_usos = 0;

int radar(char borde, int i)
{
    evaluador_total_usos++;
    if (borde == 'N' || borde == 'S')
    {
        if (i < 1 || i > evaluador_N)
            mensaje("Mal uso del radar: Posicion del radar fuera de rango");
        if (evaluador_datos[3]+1 <= i && i <= evaluador_N-evaluador_datos[1])
        {
            if (borde == 'N')
                return evaluador_datos[0];
            else
                return evaluador_datos[2];
        }
        else
            return -1;
    }
    else if (borde == 'E' || borde == 'O')
    {
        if (i < 1 || i > evaluador_M)
            mensaje("Mal uso del radar: Posicion del radar fuera de rango");
        if (evaluador_datos[0]+1 <= i && i <= evaluador_M-evaluador_datos[2])
        {
            if (borde == 'E')
                return evaluador_datos[1];
            else
                return evaluador_datos[3];
        }
        else
            return -1;
    }
    else
    {
        mensaje("Mal uso del radar: Direccion invalida");
        return -1000;
    }
}

void tiranic(int m, int n, vector<int> &distancias);

int main()
{
    
    cin >> evaluador_M >> evaluador_N;
    if (evaluador_M < 1 || evaluador_N < 1)
        mensaje("La grilla debe tener dimensiones positivas");
    
    for (int i=0;i<4;i++)
    {
        cin >> evaluador_datos[i];
        if (evaluador_datos[i] < 0)
            mensaje("La distancia del barco al borde no puede ser negativa");
    }
    if (evaluador_datos[0] + evaluador_datos[2] >= evaluador_M || evaluador_datos[1] + evaluador_datos[3] >= evaluador_N)
        mensaje("Las mediciones deben corresponder a una posicion valida del barco dentro de la grilla");
    vector<int> distancias(4);
    tiranic(evaluador_M, evaluador_N, distancias);
    if (int(distancias.size()) != 4)
        mensaje("El vector resultado debe tener 4 elementos");
    cerr << "Se realizaron " << evaluador_total_usos << " mediciones." << endl;
    cout << "Distancias al barco:";
    for (int i=0;i<4;i++) cout << " " << distancias[i];
    cout << endl;
	
	for (int i=0;i<4;i++){
		int out=distancias[i];
		int ans=evaluador_datos[i];
		if(out!=ans){
			cout<<"WRONG ANSWER!!\n";
			cout<<"expected "<<ans<<", found "<<out<<"\n";
			return 0;
		}
	}
	cout<<"AC\n";
    return 0;
}
