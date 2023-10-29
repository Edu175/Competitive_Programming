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

ll k;
bool can(pair<ll,ll>a, pair<ll,ll>b){
	return (abs(a.fst-b.snd)%k==0&&abs(b.fst-a.snd)%k==0);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		ll a[n];
		fore(i,0,n)cin>>a[i],a[i]--;
		vector<pair<ll,ll>>v;
		fore(i,0,n){
			if(abs(a[i]-i)%k)v.pb({i,a[i]});
		}
		//for(auto i:v)cout<<i.fst<<
		if(SZ(v)>2){
			cout<<"-1\n";
			continue;
		}
		if(SZ(v)==2){
			if(abs(v[0].fst-v[1].snd)%k==0&&
			   abs(v[1].fst-v[0].snd)%k==0)cout<<"1\n";
			else cout<<"-1\n";
		}
		else if(SZ(v)==1){
			ll flag=0;
			fore(i,0,n)if(can({i,a[i]},v[0]))flag=1;
			if(flag)cout<<"1\n";
			else cout<<"-1\n";
		}
		else if(SZ(v)==0)cout<<"0\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
