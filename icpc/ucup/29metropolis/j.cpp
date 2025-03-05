#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
struct STree {
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,-1), lazy(4*n+5,-1), n(n) {}
	void push(int k, int s, int e){
		if(lazy[k]<0)return; // if neutral, nothing to do
		st[k]=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=lazy[k];
			lazy[2*k+1]=lazy[k];
		}
		lazy[k]=-1; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]|st[2*k+1]; // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)|query(2*k+1,m,e,a,b); // operation
	}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
};
const int MAXN=5e5+10, INF=1e9+10, B=710;
vector<int> g[MAXN];
int D[MAXN],S[MAXN],E[MAXN];
vv ord; ll cnt=0;
void dfs(ll x){
	S[x]=cnt++;
	for(auto y:g[x])dfs(y);
	E[x]=cnt;
	ord.pb(x);
}

int main(){FIN;
	int n,q; cin>>n>>q;

    vector<int> xx={0, INF};
    auto yy=xx;

    vector<pair<ii,ii>> v(n);
    v.pb({{0, INF}, {0,INF}});

    fore(i,0,n){
        int a,b,c,d; cin>>a>>b>>c>>d;
        xx.pb(a);
        xx.pb(c);
        yy.pb(b);
        yy.pb(d);
        v[i]={{a,c}, {b,d}};
    }

    sort(ALL(xx)); xx.erase(unique(ALL(xx)), xx.end());
    sort(ALL(yy)); yy.erase(unique(ALL(yy)), yy.end());
    for(auto &x:v) x.fst.fst=lower_bound(ALL(xx), x.fst.fst)-xx.begin();
    for(auto &x:v) x.fst.snd=lower_bound(ALL(xx), x.fst.snd)-xx.begin();
    for(auto &x:v) x.snd.fst=lower_bound(ALL(yy), x.snd.fst)-yy.begin();
    for(auto &x:v) x.snd.snd=lower_bound(ALL(yy), x.snd.snd)-yy.begin();

    vector<vector<ii>> ev(SZ(xx)+1);
    fore(i,0,n+1){
        ev[v[i].fst.fst].pb({i,1});
        ev[v[i].fst.snd+1].pb({i,-1});
    }

    vector<int> par(n+1,-1);
    STree st(SZ(yy));

    fore(i,0,SZ(xx)){
        for(auto e:ev[i]){
            int id=e.fst;
            if(e.snd==-1){
                st.upd(v[id].snd.fst, v[id].snd.snd+1, par[id]);
            }
        }

        for(auto e:ev[i]){
            int id=e.fst;
            if(e.snd==1){
                if(id!=n){
                    int my=v[id].snd.fst;
                    par[id]=st.query(my,my+1);
                    
                    //el padre es it->snd
                    g[par[id]].pb(id);
                    D[id]=D[par[id]]+1;
                    // lev[D[id]].pb(id);
                    assert(v[par[id]].snd.fst<= v[id].snd.fst && v[id].snd.snd<=v[par[id]].snd.snd);
                }

                st.upd(v[id].snd.fst, v[id].snd.snd+1, id);
            }
        }
    }
	
	// lo de arriba es completamente choreado
	// asumo que esta indexado de 1 y la raiz es 0
	n++;
	dfs(0);
	// reverse(ALL(ord));
	
	vector<ii> upds; // (t,x) de la bag
	
	vector<ii> qs; // tambien de la bag
	vv a(n),c(n); // states, accumulated
	fore(_,0,q){
		char ty; ll v; cin>>ty>>v;
		if(ty=='^')upds.pb({_,v});
		else qs.pb({_,v});
		if(_==q-1||SZ(upds)>=B){
			vv bad(n);
			vv lev[n]; // only bad nodes
			vv ans(n); // of each level, only good nodes
			vv ci(n);
			
			for(auto [sdjhf,x]:upds)a[x]^=1,bad[x]=1;
			for(auto x:ord){
				ci[x]+=a[x];
				ll p=par[x];
				if(p!=-1)ci[p]+=ci[x],bad[p]|=bad[x];
				if(!bad[x])ans[D[x]]++;
				else lev[D[x]].pb(x);
			}
			fore(i,0,n)reverse(ALL(lev[i]));
			
			sort(ALL(upds),[&](ii a, ii b){
				
			});
			
			upds.clear();
			qs.clear();
		}
	}
	
	return 0;
}
