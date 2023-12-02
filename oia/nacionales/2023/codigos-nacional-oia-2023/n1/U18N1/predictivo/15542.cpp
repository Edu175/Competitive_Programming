#include <string>
#include <vector>

using namespace std;
 // Note to self and those, poor ones that shall see this bullcrap. None of this works, only the part that finds the so called palabra.
string encontrar(vector <string> palabra, string texto){
	string found_this;
	for (unsigned i=0 ; i<palabra.size() ; i++){
		size_t pos = texto.find(palabra[i]);
		if (pos != string::npos){
			for (unsigned j=0 ; j<=palabra[i].size() ; j++){
					found_this += palabra[i][pos + j];
			}
			cout <<" found this: "<< found_this << " " << endl;
			return found_this;
		}
	}
	return found_this="nothing";
}
	/*string found_this;
	size_t pos = texto.find(palabra);
	if (pos != string::npos){
		for (unsigned int i=0 ; i<texto.size() ; i++)
			found_this += palabra[pos + i];
			return found_this;}
	return found_this="nothing";
}*/

int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
//	cout << endl;
	//for (unsigned j=0 ; j<texto.size() ; j++)
	/*
		for (unsigned i=0 ; i<texto.size() ; i++){
				if (encontrar(r1[i], texto) == "nothing" && encontrar(r2[i], texto) == "nothing"){
//				cout << "3 " << r3[i] ;
				if (encontrar(r3[i], texto) == r3[i])
					return 1;}
			else if (encontrar(r3[i], texto) == "nothing" && encontrar(r1[i], texto) == "nothing"){
				//return r2[i];
//			cout << "2 " << r2[i];
				if (encontrar(r2[i], texto) == r2[i])
					return 1;}
			else if (encontrar(r2[i], texto) == "nothing" && encontrar(r3[i], texto) == "nothing"){
			//return r1[i];
//			cout << "1 " << r1[i];
				if (encontrar(r1[i], texto) == r1[i])
					return 1;}
	}
	return 0;
	*/
	/*
	for (unsigned r1i=0 ; r1i<r1.size() ; r1i++)
			for (unsigned r2i=0 ; r2i<r2.size() ; r2i++)
		if (r1[r1i] == "nothing" && r2[r2i] == "nothing") //3
			return 0;
			else return 1;
	for (unsigned r3i=0 ; r3i<r1.size() ; r3i++)
			for (unsigned r1i=0 ; r1i<r1.size() ; r1i++)
		if (r3[r3i] == "nothing" && r1[r1i] == "nothing") //2
			return 0;
			else return 1;

	for (unsigned r2i=0 ; r2i<r1.size() ; r2i++)
			for (unsigned r3i=0 ; r3i<r3.size() ; r3i++)
		if (r3[r3i] == "nothing" && r2[r2i] == "nothing") // 1
			return 0;
			else return 1;
	return 0;
	*/
	// Esto recibo: vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto
	if (encontrar(r1, texto) == "nothing" && encontrar(r2, texto) == "nothing" && encontrar(r3, texto) != "nothing")
		return 1; // encontro r3
	else if (encontrar(r1, texto) == "nothing" && encontrar(r3, texto) == "nothing" && encontrar(r2, texto) != "nothing")
		return 1; // encontro r2
	else if (encontrar(r2, texto) == "nothing" && encontrar(r3, texto) == "nothing" && encontrar(r2, texto) != "nothing")
		return 1; // encontro r1
	else
		return 0;
	return 0;
}
