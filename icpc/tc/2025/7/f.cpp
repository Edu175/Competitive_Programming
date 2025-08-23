#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const int maxn=int(2e6)+10;
#define neg(x) (maxn-x-1)
vector<ii> g[maxn];
vector<ll> pad[maxn];
bitset<maxn> vis;
void dfs(ll v){
	vis[v]=1;
	// cout<<v<<endl;
	// cout<<maxn<<endl;
	for(auto [u,i]:g[v]){
		if(!(--pad[u][i]) && !vis[u]) dfs(u); 
	}
}
int main(){
	JET
	ll n,m; cin>>n>>m;
	swap(n,m);
	string s;
	vv acum;
	vv aux;
	cin.ignore();
	while(m--){
		getline(cin,s); 
		bool f=0;
		for(ll i=SZ(s)-1; i>=0; i--) {
			if(s[i]=='>') {f=1;break;}
		}
		if(!f){
			if(s[0]=='!'){
				s.erase(s.begin());
				// cout<<s<<" VAA"<<endl;
				ll x=stoll(s);
				x--;
				acum.pb(neg(x));
			}
			else{
				// cout<<s<<" AAA"<<endl;
				ll x=stoll(s);
				x--;
				acum.pb(x);
			}
		}
		else{
			ll x=0;
			f=0;
			fore(i,0,SZ(s)){
				if(s[i]==' '){
					aux.pb(x-1);x=0; continue;
				}
				if(s[i]=='-'){
					x=0;
					while(++i<SZ(s)){
						if(s[i]=='!') f=1;
						if(s[i]<'0' || s[i]>'9') continue;
						x*=10;
						x+=s[i]-'0';
						
					}
					x--;
					if(f) x=neg(x);
					pad[x].pb(SZ(aux));
					for(auto v:aux){
						g[v].pb((ii){x,SZ(pad[x])-1});
					}
					aux.clear();
					break;
				}
				x*=10;
				x+=s[i]-'0';
			}
		}
	}
	for(auto v: acum)if(!vis[v]) dfs(v);
	bool f=0;
	fore(i,0,n){
		if(vis[i] && vis[neg(i)]){f=1; break;}
	}
	if(f){cout<<"conflict\n"; return 0;}
	fore(i,0,n) cout<<(vis[i]?'T':'F');
	cout<<"\n";
	return 0;
}