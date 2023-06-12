#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}	
int main(){FIN;
	ll n,m; cin>>n>>m;
	char b[n][m];
	ll a[n][m];
	fore(i,0,n)fore(j,0,m){
		cin>>b[i][j],a[i][j]=b[i][j]-'0';
	}
	fore(i,0,n){
		ll maxp=0;
		vector<ll>mk(m/2,0); fore(i,0,m/4)mk.pb(1);
		do{
			ll p=0,resi=0;
			fore(j,0,SZ(mk)){
				if(mk[j])resi+=a[i][p]|a[i][p+1],p++;
				else resi+=a[i][p];
				p++;
			}
			//cout<<resi<<"\n";
			maxp=max(maxp,resi);
		}
		while(next_permutation(ALL(mk)));
		cout<<maxp<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
