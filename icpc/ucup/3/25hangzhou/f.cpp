#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

// cambiar aca
typedef ll node;
ll oper(ll a,ll b){
	return a+b;
}
ll NEUT=0;
//



struct STree{
	vector<node>t; ll n;
	STree(ll n):t(2*n+5),n(n){}
	void upd(ll p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(ll l, ll r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
const ll MAXN=2e5+5;
vector<int> g[MAXN];
int n, lw[MAXN],idx[MAXN], qidx,cmp[MAXN],qcmp;
stack<int>st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(int v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x;
		do{x=st.top();st.pop();cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
void scc(ll n){ // n = number of nodes
	fore(i,0,n)idx[i]=0;;qidx=0;
	fore(i,0,n)cmp[i]=-1;;qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll v1=0; 
		ll n,k,q; cin>>n>>k>>q;
		vv v;
		ll a[n];
		mset(a,-1);
		fore(i,0,k){
			ll y=-1;
			fore(j,0,n){
				ll x; cin>>x;
				x--;
				if(a[i]==-1) a[i]=x;
				// if(!i)compo.pb(x);
				if(y!=-1){
					g[y].pb(x);
				}
				y=x;
			}
		}
		// cout<<"arreglo \n";
		// fore(i,0,n) cout<<a[i]<<" ";
		// cout<<"\n";
		scc(n);
		STree st(n);
		ll ant=-1,sz=0,id=0;
		fore(i,0,n){
			// cout<<"componente de "<<i<<" es "<<cmp[i]<<" "<<ant<<"\n";
			if(cmp[a[i]]!=ant){
				if(ant!=-1){
					st.upd(id,sz*(sz-1)/2);
				}
				sz=0;
				id=i;
				v.pb(id);
			}
			sz++;
			ant = cmp[a[i]];
		}
		st.upd(id,sz*(sz-1)/2);
		// cout<<"stree\n";
		// fore(i,0,n){
		// 	cout<<st.query(i,i+1)<<" ";
		// }
		// cout<<"\n";
		fore(i,0,q){
			ll l,r,k; cin>>k>>l>>r;
			l = ((l+v1) % n);
			r = ((r+v1) % n)+1;
			ll x;
			auto it = lower_bound(ALL(v),l);
			if(it==v.end()){
				x = n;
			}
			else x= *it;
			ll y = *(upper_bound(ALL(v),r)-1);
			cout<<"ordenados "<<st.query(x,y)<<" x "<<x<<" y "<<y<<" "<<l<<" "<<r<<"\n\n";
			v1 = st.query(x,y)+(x-l)*(x-l-1)/2+(r-y)*(r-y-1)/2;
			cout<<v1<<"\n";
		}
		fore(i,0,n){
			g[i].clear();
		}
	}	
	return 0;
}