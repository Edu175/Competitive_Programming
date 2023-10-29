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
const ll MAXN=1e6+5;

vector<int> g[MAXN];
int wg[MAXN],dad[MAXN],dep[MAXN]; // weight,father,depth
void dfs1(int x){
	wg[x]=1;
	for(int y:g[x])if(y!=dad[x]){
		dad[y]=x;dep[y]=dep[x]+1;dfs1(y);
		wg[x]+=wg[y];
	}
}
int curpos,pos[MAXN],head[MAXN];
void hld(int x, int c){
	if(c<0)c=x;
	pos[x]=curpos++;head[x]=c;
	int mx=-1;
	for(int y:g[x])if(y!=dad[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(int y:g[x])if(y!=mx&&y!=dad[x])hld(y,-1);
}
void hld_init(){dad[0]=-1;dep[0]=0;dfs1(0);curpos=0;hld(0,-1);}

#define NEUT 0
#define CLEAR 0 // cleared lazy node
#define oper max
void acum(ll &a, ll v){ // accumulate lazy node
	a+=v;
}
ll calc(ll s, ll e, ll a, ll v){ // calculate STree range, a=previous value
	return a+v;
}

struct STree{
	vector<ll>st,lazy; ll n; vector<vector<ll>>bag;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n),bag(0){}
	STree(){}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v){
		upd(1,0,n,a,b,v);
		bag.pb({a,b,v});
	}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
	void reset(){
		//cout<<"reset"<<endl;
		//cout<<SZ(bag)<<endl;
		/*for(auto i:bag){
			imp(i);
		}*/
		fore(i,0,SZ(bag)){
			vector<ll>v=bag[i];
			upd(v[0],v[1],-v[2]);
		}
		bag.clear();
	}
};

STree st;

void upd(ll x, ll v){
	/*if(v==-1){
		cout<<x<<"-->"<<dad[x]<<"\n";
	}*/
	x=dad[x];
	while(x!=-1){
		st.upd(pos[head[x]],pos[x]+1,v);
		x=dad[head[x]];
	}
}

bool cmp(ll x, ll y){
	return dep[x]<dep[y];
}

int main(){FIN;
	ll t; cin>>t;
	fore(_,1,t+1){
		cout<<"Case #"<<_<<": ";
		//cout<<"\n";
		ll n; cin>>n;
		st=STree(n);
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		hld_init();
		vector<string> s[n];
		set<ll>w[n];
		map<string,ll>mp;
		fore(i,0,n){
			ll m; cin>>m; s[i].resize(m);
			fore(j,0,m)cin>>s[i][j],mp[s[i][j]]=-1;
		}
		ll k=0;
		for(auto &i:mp)i.snd=k++;//,cout<<i.fst<<" "<<k-1<<"\n";
		set<ll>inv[k];
		fore(i,0,n){
			fore(j,0,SZ(s[i])){
				ll v=mp[s[i][j]];
				w[i].insert(v);
				inv[v].insert(i);
			}
		}
		fore(i,0,n)if(SZ(g[i])==0)upd(i,1);
		st.bag.clear();
		/*fore(i,0,n){
			cout<<"st "<<i<<": "<<st.query(pos[i],pos[i]+1)<<"\n";
		}*/
		ll res=0;
		fore(c,0,k){
			//ll ans=res;
			vector<ll>nod;
			for(auto i:inv[c])nod.pb(i);
			sort(ALL(nod),cmp);
			reverse(ALL(nod));
			//imp(nod);
			for(auto x:nod){
				if(dad[x]!=-1&&st.query(pos[dad[x]],pos[dad[x]]+1))upd(x,-1);
			}
			/*cout<<c<<": "<<st.query(0,n)<<"\n";
			fore(i,0,n){
				cout<<"st "<<i<<": "<<st.query(pos[i],pos[i]+1)<<"\n";
			}*/
			if(st.query(0,n)<=1){
				if(!st.query(pos[0],pos[0]+1)||inv[c].count(0))res++;
			}
			st.reset();
			//cout<<res-ans<<"\n\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}//175 lineas 🥶🥶🥶
