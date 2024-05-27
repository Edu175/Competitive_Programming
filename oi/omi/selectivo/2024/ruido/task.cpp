#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfkjhg:v)cout<<dfkjhg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector <int> filtrador_de_ruido_cosmico(string S, vector <int> a) {
	vector<ll>s;
	fore(i,0,SZ(S)){
		if(i&&S[i]==S[i-1]&&s[i-1]!=26)s.pb(26);
		else s.pb(S[i]-'a');
	}
//	cout<<"filtra "<<S<<" "; imp(s);
	for(ll b=SZ(a);b>0;b--){
		vector<int>res;
		ll c=0,j=0;
		fore(i,0,SZ(a)){
			if(a[i]%27==s[j])res.pb(a[i]),c++;
			if(j<SZ(s)-1&&c>=b&&a[i]%27==s[j+1]){
				res.pb(a[i]);
				c=1;
				j++;
			}
		}
//		cout<<b<<": "<<j<<","<<c<<endl;
		if(j==SZ(s)-1&&c>=b)return res;
	}
	assert(0);
}
string mensaje_para_jp(vector <int> c) {
	// Implementa la función.
	string s;
	fore(i,0,SZ(c))if(!i||c[i]%27!=c[i-1]%27){
		s.pb('a'+c[i]%27);
	}
	fore(i,0,SZ(s)){
		if(i&&s[i]=='z'+1)s[i]=s[i-1];
	}
	return s;
}

	/* 
	* La siguiente función es un evaluador de prueba. Si tu le pasas
	* una palabra P, simulará el proceso que el jurado lleva a cabo
	* al evaluar tus envíos. Recuerda que el evaluador del jurado 
	* corre dos veces tu código, por lo que no se preservan las
	* variables globales.
	*/

/*mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool evaluador(string P) {
	vector<int> A(6000);
	for (auto &e : A) e = (rng()%1000000000) + 1;
	vector<int> B = filtrador_de_ruido_cosmico(P, A);
	vector<int> C;
	for (auto e : B) if (rng()&1) C.push_back(e);
	auto res=mensaje_para_jp(C);
	cerr<<P<<"\n"<<res<<"\n";
	return (P == res);
}

int main(){FIN;
	string s; cin>>s;
	ll flag=evaluador(s);
	if(flag)cout<<"OK\n";
	else cout<<"FAILED\n";
	return 0;
}*/
