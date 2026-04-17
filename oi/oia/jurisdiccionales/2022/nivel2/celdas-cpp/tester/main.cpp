#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin,x.end
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto lol:v)cout<<lol<<" "; cout<<"\n"
typedef long long ll;
using namespace std;
const ll MAXN=1e4+5;
pair<ll,ll> operator+(pair<ll,ll>p1,pair<ll,ll>p2){
	return {p1.fst+p2.fst,p1.snd+p2.snd};
}
	
bool existeArchivo(string s)
{
    ifstream in(s.c_str());
    if(in.fail())
        return false;
    in.close();
    return true;
}

string nombre(int sub, int tc, string inout)
{
    stringstream ss;
    ss << "CASOS/SUB" << sub << "/S0" << sub << "E";
    if(tc < 10)
        ss << "0";
    ss << tc << "." << inout;
    string s;
    ss >> s;
    return s;
}

string nombre2(string inout, int tc)
{
    stringstream ss;
    ss << inout << "/" << inout;
    if(tc < 10)
        ss << "0";
    ss << tc << ".txt";
    string s;
    ss >> s;
    return s;
}

struct Solucion
{
	string pag[MAXN];
	map<string,ll> id;
	vector<ll>g[MAXN];
	set<ll>vis;
	ll n;
	pair<ll,ll> dfs(ll x,string pg){
		pair<ll,ll>ret;
		for(auto i:g[x]){
			if(!vis.count(i)){
				vis.insert(i);
				if(pag[i]==pg)ret.snd++;
				ret.fst++;
				ret=ret+dfs(i,pg);
			}
		}
		return ret;
	}

	void celdas(vector <string> &c, vector <int> &celdasTotal, vector <int> &celdasMismaHoja) {
		n=SZ(c);
		vector<pair<string,ll>>edges;
		fore(i,0,n){
			string a,pg, s=c[i];
			ll r=0;
			bool e=0;
			fore(j,0,SZ(s)){
				if(e){
					if(s[j]=='='){
						r=j+1;
						break;
					}
					pg.pb(s[j]);
				}
				if(s[j]=='!')e=1;
				a+=s[j];
			}
			id[a]=i;
			//cout<<"id["<<a<<"]="<<i<<"\n";
			pag[i]=pg;
			s.pb('+');
			string t;
			fore(k,r,SZ(s)){
				if(s[k]=='*'||s[k]=='+'||s[k]=='-'){
					if(t[0]<'0'||t[0]>'9'){
						edges.pb({t,i});
					}
					t.clear();
				}
				else t+=s[k];
			}
		}
		//cout<<"\n";
		for(auto i:edges){
			g[id[i.fst]].pb(i.snd);
			//cout<<i.fst<<" "<<id[i.fst]<<"->"<<i.snd<<"\n";
		}
		/*fore(i,0,n){
			cout<<i<<": ";
			imp(g[i]);
		}*/
		fore(i,0,n){
			pair<ll,ll> res=dfs(i,pag[i]);
			vis.clear();
			celdasTotal.pb(res.fst);
			celdasMismaHoja.pb(res.snd);
		}
	}
};

int main()
{
    for(int i=1; i<=7; i++)
    {
        int sub = i;
        int tc = 1;
        tc = 1;
        while(existeArchivo(nombre(sub, tc, "in")))
        {
            ifstream cin(nombre(sub, tc, "in").c_str());
            ifstream out(nombre(sub, tc, "out").c_str());

            ///Leo archivo de entrada
            int N;
            cin >> N;
            vector <string> c(N);
            for(int i=0; i<N; i++)
                cin >> c[i];

            ///Leo archivo de salida

            vector <int> a(N), b(N);

            for(int i=0; i<N; i++)
                out >> a[i];
            for(int i=0; i<N; i++)
                out >> b[i];

            vector <int> total, hoja;
            Solucion s;
            s.celdas(c, total, hoja);
/**
            ofstream salida(nombre(sub, tc, "out").c_str());
            for(int i=0; i<N; i++)
                salida << total[i] << " ";
            salida << endl;
            for(int i=0; i<N; i++)
                salida << hoja[i] << " ";
            salida << endl;
**/

            if(a == total && b == hoja)
            {
                cout << "CASO " << nombre(sub, tc, "in") << "   OK" << endl;
            }
            else
            {
                cout << "CASO " << nombre(sub, tc, "in") << "   ERROR!!!!!!" << endl;
            }


            tc++;
        }
    }
    /**
    tc = 1;
    while(existeArchivo(nombre(sub, tc, "in")))
    {
        ifstream cin(nombre(sub, tc, "in").c_str());
        ofstream cout(nombre2("input", tc).c_str());
        string s;
        while(getline(cin, s))
            cout << s << endl;
        tc++;
    }
    tc = 1;
    while(existeArchivo(nombre(sub, tc, "out")))
    {
        ifstream cin(nombre(sub, tc, "out").c_str());
        ofstream cout(nombre2("output", tc).c_str());
        string s;
        while(getline(cin, s))
            cout << s << endl;
        tc++;
    }
    **/

    return 0;
}
