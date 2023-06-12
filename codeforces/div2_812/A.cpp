#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll maxx=0, maxy=0, minx=0, miny=0;
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			if(x<0)minx=min(minx,x);
			if(y<0)miny=min(miny,y);
			if(x>0)maxx=max(maxx,x);
			if(y>0)maxy=max(maxy,y);
		}
		cout<<(maxx+maxy+abs(minx)+abs(miny))*2<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
