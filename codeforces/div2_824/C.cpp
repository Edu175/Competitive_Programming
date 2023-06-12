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
const ll MAXN=28;
vector<vector<ll>>comp(MAXN);
vector<ll> id(MAXN);

void uf_init(ll n){fore(i,0,n)comp[i]={i},id[i]=i;}
bool uf_join(ll a, ll b){
	if(id[a]==id[b])return false;
	ll ida=id[a], idb=id[b];
	if(SZ(comp[ida])>SZ(comp[idb]))swap(ida,idb);
	for(auto i:comp[ida]){
		comp[idb].pb(i);
		id[i]=idb;
	}
	return true;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll c[28];
		mset(c,-1);
		uf_init(26);
		ll n; cin>>n;
		string s; cin>>s;
		ll a[n]; fore(i,0,n)a[i]=s[i]-'a';
		//imp(a);
		set<ll>used;
		fore(i,0,n){
			if(c[a[i]]>=0)continue;
			fore(j,0,26){
				if(used.count(j))continue;
				
				if(uf_join(a[i],j)||SZ(comp[id[a[i]]])==26){
					//cout<<SZ(comp[a[i]])<<"\n";
					c[a[i]]=j;
					used.insert(j);
					//cout<<j<<"\n";
					break;
				}
			}
		}
		string res;
		fore(i,0,n){
			res.pb('a'+c[a[i]]);
		}
		//imp(c);
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
