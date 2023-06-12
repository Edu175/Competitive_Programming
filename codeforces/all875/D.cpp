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
typedef pair<ll,ll> ii;

template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}


ll fqrt(ll x){
	ll r=sqrt(x)-3;
	for(;r<0||r*r<=x;r++)if(r<0)continue;
	return r-1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll r=sqrt(2*n)+1; //<=
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll res=0;
		//cout<<"r "<<r<<"\n";
		fore(ai,0,r){
			vector<ll>c(n+1),d(n+1);
			fore(i,0,n)if(a[i]==ai)d[b[i]]++;
			//cout<<ai<<":\n"<<d<<"\n";
			fore(i,0,n){
				ll x=ai*a[i]-b[i];
				//cout<<i<<" "<<a[i]<<": "<<x<<" "<<c<<" = ";
				if(x>=0&&x<=n){
					if(a[i]<r)res+=c[x];//,cout<<c[x];
					else res+=d[x];//,cout<<d[x];
				}
				//cout<<"\n";
				if(a[i]==ai)c[b[i]]++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
