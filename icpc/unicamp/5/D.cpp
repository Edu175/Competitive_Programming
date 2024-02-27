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
const ll MAXN=500;

ll neg(ll n){return MAXN-5-n;}
vector<ll> g[MAXN];
/*bool t[MAXN][MAXN], vis[MAXN];
ll rt;
ll dfs(ll x){
	t[rt][x]=1;
	for(auto y:g[x])if(!t[rt][y])dfs(y);
}*/
ll n;
ll cv(ll x){
	if(x>n)return neg(x);
	return x;
}
string r;
ll dfs(ll x){
	cout<<cv(x)<<" "<<(x>n)<<" "<<r<<"\n";
	if(r[cv(x)]!='.'){
		if((r[cv(x)]=='V')!=(x>n))return 0;
		return 1;
	}
	if(x>n)r[cv(x)]='V';
	else r[cv(x)]='C';
	ll res=1;
	for(auto y:g[x])res&=dfs(y);
	return res;
}
int main(){FIN;
	string al; cin>>al;
	ll k=SZ(al);
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; char c,d; cin>>u>>c>>v>>d; u--,v--;
		if(c=='V')u=neg(u);
		if(d=='V')v=neg(v);
		g[u].pb(v);
		g[neg(u)].pb(neg(v));
	}
	string s; cin>>s;
	//fore(i,0,n)dfs(i,i);
	ll flag=1;
	r=string(n,'.');
	/*fore(i,0,n){
		set<char>st;
		fore(j,s[i]-'a',k)st.insert(al[j]);
		if(SZ(st)==1){
			ll u=i;
			if(*st.begin()=='V')u=neg(u);
			g[u].pb(neg(u));
		}
	}*/
	fore(i,0,n){
		cout<<i<<": "; imp(g[i]);
		cout<<neg(i)<<": "; imp(g[neg(i)]);
	}
	string b(n,'.');
	ll ig=1;
	fore(i,0,n){
		ll did=0;
		cout<<i<<" "<<ig<<":\n";
		for(char c=(ig?s[i]:'a');c<'a'+k;c++){
			cout<<"try "<<c<<":\n";
			//if(r[i]!='.')continue; //mala reconstruccion
			ll u=i;
			if(al[c-'a']=='V')u=neg(u);
			string _r=r;
			if(r[i]=='.'||r[i]==al[c-'a']){
				if(dfs(u)){
					did=1;
					ig&=(c==s[i]);
					b[i]=c;
					break;
				}
				else r=_r;
			}
			cout<<"\n";
		}
		cout<<did<<"\n\n\n";
		flag&=did;
	}
	if(!flag)cout<<"-1\n";
	else cout<<b<<"\n";
	return 0;
}
