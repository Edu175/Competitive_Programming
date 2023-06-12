#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<bits/stdc++.h>
#include<unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cerrno>

using namespace std;

void escr(string s){
	ofstream arch;
	arch.open(s,ios::out);
	arch<<"#include <bits/stdc++.h>\n#define pb push_back\n#define fst first\n#define snd second\n#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)\n#define SZ(x) ((int)x.size())\n#define ALL(x) x.begin(),x.end()\n#define mset(a,v) memset((a),(v),sizeof(a))\n#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)\n#define imp(v) for(auto edu:v)cout<<edu<<\" \"; cout<<\"\\n\"\nusing namespace std;\ntypedef long long ll;\ntypedef pair<ll,ll> ii;\n\nint main(){FIN;\n	ll t; cin>>t;\n	while(t--){\n		\n	}\n	return 0;\n}\n//\"¿Sabes qué es más genial que la magia? Matemáticas\". - Spider-Man: No Way Home\n//\"You know what's cooler than magic? Math\". - Spider-Man: No Way Home";
}

int main(){
	
	cout<<"Pagina: ";
	string pag; cin>>pag;
	if(chdir(pag.c_str())!=0)cout<<"Carpeta no existente\n";
	else {
		cout<<"Contest: ";
		string con; cin>>con;
		cout<<"Inicio: ";
		char a; cin>>a;
		cout<<"Fin: ";
		char b; cin>>b;
		if(b<='Z'&&a>='A'){
			ofstream arch;
			mkdir(con.c_str(),0777);
			chdir(con.c_str());
			cout<<"cd "<<pag<<"/"<<con<<" && ";
			for(char i=a;i<=b;i++){
				escr(string(1,i)+".cpp");
				if(i<b)cout<<"gedit "<<i<<".cpp && ";
				else cout<<"gedit "<<i<<".cpp && gedit in\n";
			}
			cout<<"python3\nfrom math import *\n";

		}else{
			cout<<"Rango invalido\n";
		}
	}
	return 0;
}
