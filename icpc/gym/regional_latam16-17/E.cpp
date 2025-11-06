#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#define oper(a,b) ((a)+(b))
#define NEUT 0

int fjere(int n){
	assert(n);
   ll lg=__lg(n);
   return 1ll<<(2+lg);
}

struct STree{
    vector<int> st, L, R; int n,rt;
	vector<vector<ii>> nodes;
	vector<vv> ts; // ts[id]={t1, t2 ...} sorted t's by id
    STree(int N):st(1,NEUT), L(1,0),R(1,0),n(fjere(N)),rt(0),ts(4*n+5){
		nodes.pb(vector<ii>(__lg(n)+3));
	}
    int new_node(int v, int l, int r){
		int ks = SZ(st);
        st.pb(v);L.pb(l);R.pb(r);ts.pb({});
        return ks;
    }
	vector<ii> pa;
    int upd(int k, int id, int s, int e, int p, int v){
        int ks = new_node(st[k],L[k],R[k]);
		pa.pb({id,ks});
		ts[id].pb(SZ(nodes));
        if(s+1 == e){st[ks] += v;return ks;}
        int m = (s+e)/2, ps;
        if(p<m)ps = upd(L[ks],2*id,s,m,p,v),L[ks] = ps;
        else ps = upd(R[ks],2*id+1,m,e,p,v),R[ks] = ps;
        st[ks] = oper(st[L[ks]],st[R[ks]]);
        return ks;
    }
	ll find_node(ll j, ll id, ll t){ // )
		for(ll i=t-1;i>=0;i--){
			if(nodes[i][j].fst==id)return i;
		}
		return 0;
	}
    int query(int t, int j, int s, int e, int a, int b){
        auto [id,k]=nodes[t][j];
		if(e<=a || b<=s) return NEUT;
        if(a<=s && e<=b)return st[k];
        int m = (s+e)/2;
		ll Tl=t,Tr=t;
		if(nodes[t][j+1].fst==2*id+1)Tl=find_node(j+1,2*id,t);
		else Tr=find_node(j+1,2*id+1,t);
        return oper(query(Tl,j+1,s,m,a,b),
					query(Tr,j+1,m,e,a,b));
    }
    int upd(int k, int p, int v){
		pa.clear();
		rt = upd(k,1,0,n,p,v);
		nodes.pb(pa);
		return rt;
	}
    int upd(int p, int v){return upd(rt,p,v);} //update last root
    int query(int t, int a, int b){
		return query(t,0,0,n,a,b);
	};
	void sw(ll p){ // idx 1
		auto &u=nodes[p];
		auto &v=nodes[p+1];
		ll pos=
		fore(i,0,SZ(v)){
			if(u[i].fst!=v[i].fst)break;
			st[v[i].snd]--;
			st[u[i].snd]++;
		}
		swap(nodes[p],nodes[p+1]);
	}
	ll get(ll t, ll m){
		return query(t,0,m);
	}
};

int main(){
    JET
	ll n,q; cin>>n>>q;
	vv a(n);
	vector<ii>sd;
	fore(i,0,n)cin>>a[i],sd.pb({a[i],i});
	sort(ALL(sd));
	fore(i,0,n)a[sd[i].snd]=i;
	// for(auto i:a)cout<<i<<" ";;cout<<"\n";
	// cout<<endl;
	STree st(n);
	fore(i,0,n)st.upd(a[i],1);
	while(q--){
		char ty; cin>>ty;
		if(ty=='Q'){
			ll a,b,k; cin>>a>>b>>k; k--; a--;
			auto get=[&](ll m){return st.get(b,m)-st.get(a,m);};
			ll l=-1,r=n+5;
			while(r-l>1){
				ll m=(l+r)/2;
				if(get(m)<=k)l=m;
				else r=m;
			}
			ll p=l;
			// cerr<<a<<","<<b<<"\n";
			// cerr<<p<<": "<<get(p)<<"\n";
			cout<<sd[p].fst<<"\n";
			// cout<<endl;
		}
		else {
			ll p; cin>>p;
			st.sw(p);
		}
	}
    return 0;
}