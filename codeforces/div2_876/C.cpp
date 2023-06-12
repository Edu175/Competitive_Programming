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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		if(a[n-1]){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		ll c=a[0],x=1;
		vector<pair<ll,ll>>op;
		fore(i,1,n){
			if(a[i]==a[i-1]){
				x++;
				continue;
			}
			if(c){
				op.pb({1,x});
				if(i<n-1)c=a[i+1],x=1,i++;
				else c=-1;
			}
			else op.pb({0,x}),c=a[i],x=1;
		}
		if(c!=-1)op.pb({0,x});
		/*for(auto i:op)cout<<i.fst<<","<<i.snd<<" ";
		cout<<"\n";*/
		vector<ll>res;
		for(ll i=SZ(op)-1;i>=0;i--){
			fore(j,0,op[i].snd)res.pb(0);
			if(op[i].fst)res.pb(op[i].snd);
		}
		imp(res);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
