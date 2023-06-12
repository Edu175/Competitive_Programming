#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"| "
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

vector<vector<ll>> av, bv;
bool can(ll k){
	vector<vector<ll>> avi, bvi;
	fore(i,0,SZ(av)){
		vector<ll> &ai=av[i], &bi=bv[i];
		queue<ll> q[2];
		for(auto j:bi){
			ll nd=((j&(1ll<<k))==(1ll<<k));
			q[nd].push(j);
		}
		vector<ll> adda[2],addb[2];
		for(auto j:ai){
			ll x=(((j&(1ll<<k))==(1ll<<k))^1);
			//cout<<j<<":"<<x<<" ";
			if(!SZ(q[x]))return 0;
			adda[x].pb(j);
			addb[x].pb(q[x].front());
			q[x].pop();
		}
		//cout<<"\n";
		avi.pb(adda[0]), avi.pb(adda[1]);
		bvi.pb(addb[0]), bvi.pb(addb[1]);
	}
	av=avi;
	bv=bvi;
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n),b(n);
		ll maxi=0;
		fore(i,0,n)cin>>a[i],maxi=max(maxi,a[i]);
		fore(i,0,n)cin>>b[i],maxi=max(maxi,b[i]);
		if(maxi==0){
			cout<<0<<"\n";
			continue;
		}
		ll bit=log2(maxi);
		av.clear();
		bv.clear();
		av.pb(a);
		bv.pb(b);
		ll res=0;
		while(bit>=0){
			//cout<<bit<<"\n";
			ll c=can(bit);
			//cout<<"\n";
			//cout<<c<<"\n";
			res+=(c<<bit);
			/*for(auto i:av){
				imp(i);
			}
			cout<<"\n";*/
			/*for(auto i:bv){
				imp(i);
			}
			cout<<"\n";*/
			bit--;
		}
		pres;
		//cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
