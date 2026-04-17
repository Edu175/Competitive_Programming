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
	vector<vector<ll>> olds;
    STree(int N):st(1,NEUT), L(1,0),R(1,0),n(fjere(N)),rt(0){
		nodes.pb(vector<ii>(__lg(n)+3));
		olds.pb(vector<ll>(__lg(n)+3));
	}
    int new_node(int v, int l, int r){
		int ks = SZ(st);
        st.pb(v);L.pb(l);R.pb(r);
        return ks;
    }
	vector<ii> pa;
	vv old;
    int upd(int k, int id, int s, int e, int p, int v){
        int ks = new_node(st[k],L[k],R[k]);
		pa.pb({id,ks});
		old.pb(k);
        if(s+1 == e){st[ks] += v;return ks;}
        int m = (s+e)/2, ps;
        if(p<m)ps = upd(L[ks],2*id,s,m,p,v),L[ks] = ps;
        else ps = upd(R[ks],2*id+1,m,e,p,v),R[ks] = ps;
        st[ks] = oper(st[L[ks]],st[R[ks]]);
        return ks;
    }
    int query(int k, int s, int e, int a, int b){
        if(e<=a || b<=s) return NEUT;
        if(a<=s && e<=b)return st[k];
        int m = (s+e)/2;
        return oper(query(L[k],s,m,a,b), query(R[k],m,e,a,b));
    }
    int upd(int k, int p, int v){
		pa.clear();
		old.clear();
		rt = upd(k,1,0,n,p,v);
		nodes.pb(pa);
		olds.pb(old);
		return rt;
	}
    int upd(int p, int v){return upd(rt,p,v);} //update last root
    int query(int k, int a, int b){return query(k,0,n,a,b);};
	
	void sw(ll p){ // idx 1
		cerr<<"op\n";
		ll j=-1;
		auto &u=nodes[p];
		auto &v=nodes[p+1];
		fore(i,0,SZ(v)){
			if(u[i].fst!=v[i].fst){
				j=i;
				break;
			}
			
			st[v[i].snd]--;
			st[u[i].snd]++;
		}
		assert(j>0);
		j--;
		cerr<<j<<" j\n";
		ll x=u[j].snd;
		ll y=v[j].snd;
		if(L[y]==u[j+1].snd){
			L[y]=olds[p][j+1];
			assert(R[x]==olds[p+1][j+1]);
			R[x]=v[j+1].snd;
			cerr<<"R "<<x<<" := "<<v[j+1].snd<<"\n";
			cerr<<"pingaa\n";
		}
		else {
			// cerr<<u[j].fst<<" "<<v[j].fst<<"\n";
			// cerr<<u[j+1].fst<<" "<<v[j+1].fst<<" id j+1\n";
			
			// cerr<<u[j].fst<<" "<<v[j].fst<<"\n";
			// cerr<<u[j].snd<<" "<<v[j].snd<<endl;
			// cerr<<olds[p+1][j]<<" "<<x<<" =\n";
			// cerr<<L[x]<<" "<<R[x]<<"\n";
			// cerr<<L[y]<<","<<R[y]<<" L R\n";
			// cerr<<u[j+1].snd<<"\n";
			cerr<<"R "<<y<<" == "<<u[j+1].snd<<"\n";
			
			assert(R[y]==u[j+1].snd);
			R[y]=olds[p][j+1];
			assert(L[x]==olds[p+1][j+1]);
			L[x]=v[j+1].snd;
		}
		fore(i,0,j+1){
			olds[p+1][i]=olds[p][i];
			olds[p][i]=v[i].snd;
		}
		if(p+2<SZ(nodes)){
			fore(i,0,j+1){
				if(olds[p+2][i]==v[i].snd)olds[p+2][i]=u[i].snd;
				ll y=nodes[p+2][i].snd;
				ll m=nodes[p+1][i].snd;
				ll x=nodes[p][i].snd;
				if(L[y]==m)L[y]=x;
				if(R[y]==m)R[y]=x;
			}
		}
		swap(nodes[p],nodes[p+1]);
		swap(olds[p],olds[p+1]);
	}
	
	ll get(ll t, ll m){ // [0,i)
		ll k=nodes[t][0].snd;
		return query(k,0,m);
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
	for(auto i:a)cout<<i<<" ";;cout<<"\n";
	cout<<endl;
	STree st(n);
	fore(i,0,n)st.upd(a[i],1);
	while(q--){
		char ty; cin>>ty;
		if(ty=='Q'){
			ll a,b,k; cin>>a>>b>>k; k--; a--;
			ll l=-1,r=n+5;
			while(r-l>1){
				ll m=(l+r)/2;
				if(st.get(b,m)-st.get(a,m)<=k)l=m;
				else r=m;
			}
			ll p=l;
			cout<<sd[p].fst<<"\n";
			cout<<endl;
		}
		else {
			ll p; cin>>p;
			st.sw(p);
		}
	}
    return 0;
}