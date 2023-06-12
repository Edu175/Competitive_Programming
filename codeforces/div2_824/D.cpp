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

vector<ll> trixor(vector<ll>v,vector<ll>w){
	vector<ll>ret;
	fore(i,0,SZ(v)){
		ret.pb((v[i]+w[i])%3);
	}
	return ret;
}
vector<ll>opu(vector<ll>v){
	vector<ll>ret;
	for(auto i:v)ret.pb((3-i)%3);
	return ret;
}

map<vector<ll>,ll>mp;
int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll> a[n];
	set<vector<ll>>st;
	fore(i,0,n){
		vector<ll>add(k);
		fore(j,0,k){
			cin>>add[j];
		}
		a[i]=add;
		st.insert(add);
	}
	vector<ll>check={0,0,1,0};
	fore(i,0,n){
		fore(j,i+1,n){
			mp[trixor(a[i],a[j])]++;
			}
		}
	}
	
	ll res=0;
	for(auto i:mp){
		if(st.count(opu(i.fst))){
			res+=(i.snd*(i.snd-1))/2;
		}
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
