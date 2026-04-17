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

int main(){FIN;
	ll p;
	srand(ll(&p));
	p=rand()%ll(1e2)+1;
	ll f=rand()%5000+1,c=rand()%5000+1;
	cout<<p<<" "<<f<<" "<<c<<"\n\n";
	fore(i,0,f){
		cout<<rand()%ll(1e1)+1<<" "<<rand()%ll(1e1)+1<<"\n";
	}
	cout<<"\n";
	fore(i,0,c){
		cout<<rand()%ll(1e1)+1<<" "<<rand()%ll(1e1)+1<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
