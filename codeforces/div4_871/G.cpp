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
const ll MAXN=1e6+5;

ll sum[MAXN];
void sum_init(){
	fore(i,1,MAXN)sum[i]=sum[i-1]+(i-1)*(i-1);
}
int main(){FIN;
	sum_init();
	vector<ll>tr;
	while(!SZ(tr)||tr.back()<1e6)tr.pb(SZ(tr)*(SZ(tr)+1)/2);
	ll t; cin>>t;
	while(t--){
		ll x; cin>>x;
		ll f=0; fore(i,0,SZ(tr))if(tr[i]<x)f=i;
		ll res=0;
		ll l=x,r=x;
		while(f>=0){
			//cout<<f<<": "<<l<<" "<<r<<"\n";
			res+=sum[r+1]-sum[l];
			ll pl=tr[f-1]+l-tr[f];	//padre der
			if(l!=tr[f]+1)pl--;
			l=pl;
			ll pr=tr[f-1]+r-tr[f];	//padre der
			if(r==tr[f+1])pr--;
			r=pr;
			f--;
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
