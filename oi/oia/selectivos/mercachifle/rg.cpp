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
	ll N,V; srand((ll)&N); cin>>N>>V;
	ll n=rand()%N+1;
	ll a[2]; a[0]=rand()%n+1,a[1]=n-a[0];
	fore(h,0,2){
		cout<<a[h]<<"\n";
		fore(i,0,a[h]){
			ll l=rand()%V+1,r=rand()%V+1;
			if(l>r)swap(l,r);
			cout<<l<<" "<<r<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

