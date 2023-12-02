#include <string>
#include <vector>

using namespace std;

string palabra(int indice, string texto);
int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto)
{
	if(palabra(0, texto) == r1[0] && palabra(1, texto) == r2[0] && palabra(2, texto) == r3[0])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

string palabra(int indice, string texto)
{
	// Retorna la palabra indice del string texto. 
	int espacios = 0;
	string buffer;
	for(int i = 0; i < texto.length(); i++)
	{
		if(espacios == indice)
		{
			while(texto[i] != ' ' && texto[i] != '\0')
			{
				buffer.push_back(texto[i]);
				i++;
			}
			return buffer;
		}
		if(texto[i] == ' ')
		{
			espacios++;
		}
	}
	return "";
	
}
