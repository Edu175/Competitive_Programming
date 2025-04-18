#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ii> g[MAXN];
ll sw[MAXN],w[MAXN],fa[MAXN],sz[MAXN]; //init w0=0,f0=-1

void dfs(ll x){
    sz[x]=1;
    sw[x]=w[x];
    if(fa[x]!=-1)sw[x]+=sw[fa[x]];
    for(auto [y,p]:g[x])if(y!=fa[x]){
        w[y]=p;
        fa[y]=x;
        dfs(y);
        sz[x]+=sz[y];
    }
}
ll pos[MAXN],ipos[MAXN],head[MAXN],qidx=0;

void dfs2(ll x, ll f=-1){
    if(f==-1)f=x;
    head[x]=f;
    pos[x]=qidx,ipos[qidx]=x; qidx++;
    ll mx=-1;
    for(auto [y,sus]:g[x])if(y!=fa[x]){
            if(mx==-1||sz[y]>sz[mx])mx=y;
    }
    if(mx==-1)return;
    dfs2(mx,f);
    for(auto [y,sus]:g[x])if(y!=fa[x]&&y!=mx)dfs2(y);
}
void hld_init(){
	w[0]=0; fa[0]=-1;
	dfs(0); dfs2(0);
}
ll oper(ll a, ll b, ll t){
    if(t)return max(a,b);
    return a+b;
}

ll calc(ll s, ll e, ll a, ll v, ll t){ //need pos y ipos
    if(t)return a+v;
    ll x=ipos[s],y=ipos[e-1];
    ll sum=sw[y];
    if(x)sum-=sw[fa[x]];
    return a+sum*v;
} 

struct STree{
    ll n,t; vector<ll>st, lazy;
    STree(ll n, ll t):n(n),t(t),st(4*n+5),lazy(4*n+5){}
    STree(){}
    void push(ll k, ll s, ll e){
        st[k]=calc(s,e,st[k],lazy[k],t);
        if(s+1!=e){
            lazy[2*k]+=lazy[k];
            lazy[2*k+1]+=lazy[k];
        }
        lazy[k]=0;
    }
    void upd(ll k, ll s, ll e, ll a, ll b, ll v){
        push(k,s,e);
        if(e<=a||b<=s)return;
        if(a<=s&&e<=b){
            lazy[k]+=v;
            push(k,s,e);
            return;
        }
        ll m=(s+e)/2;
        upd(2*k  ,s,m,a,b,v);
        upd(2*k+1,m,e,a,b,v);
        st[k]=oper(st[2*k],st[2*k+1],t);
    }
    ll query(ll k, ll s, ll e, ll a, ll b){
        push(k,s,e);
        if(e<=a||b<=s)return 0;
        if(a<=s&&e<=b)return st[k];
        ll m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b),t);
    }
    //find
    ll find(ll k, ll s, ll e, ll x){
    	push(k,s,e);
    	if(s+1==e)return ipos[s];
<<<<<<< HEAD
    	ll m=(s+e)/2;
    	push(2*k,s,m); push(2*k+1,m,e);
=======
<<<<<<< HEAD
    	push(2*k,s,e); push(2*k+1,s,e);
    	ll m=(s+e)/2;
=======
    	ll m=(s+e)/2;
    	push(2*k,s,m); push(2*k+1,m,e);
>>>>>>> varios
>>>>>>> fecbcadd7b6a52170a327f9d98f27f3ce044c342
    	if(st[2*k+1]>x){return find(2*k+1,m,e,x);}
    	return find(2*k,s,m,x);
    }
    void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
<<<<<<< HEAD
    ll query(ll a, ll b){return query(1,0,n,a,b);}
=======
<<<<<<< HEAD
    ii query(ll a, ll b){return query(1,0,n,a,b);}
=======
    ll query(ll a, ll b){return query(1,0,n,a,b);}
>>>>>>> varios
>>>>>>> fecbcadd7b6a52170a327f9d98f27f3ce044c342
    ll find(ll x){assert(t==1); return find(1,0,n,x);}
};

ll n,t[MAXN],tot=0; //MCH
STree cnt,bs;

<<<<<<< HEAD
ll query(ll x, STree& st){
    ll res=0;
=======
<<<<<<< HEAD
ii query(ll x, STree& st){
    ii res=0;
=======
ll query(ll x, STree& st){
    ll res=0;
>>>>>>> varios
>>>>>>> fecbcadd7b6a52170a327f9d98f27f3ce044c342
    while(x!=-1){
        res=oper(st.query(pos[head[x]],pos[x]+1),res,st.t);
        x=fa[head[x]];
    }
    return res;
}
void upd(ll x, ll v){
	while(x!=-1){
<<<<<<< HEAD
=======
<<<<<<< HEAD
		//cout<<x<<" "<<v<<": "<<pos[head[x]]<<","<<pos[x]+1<<": ["<<head[x]<<","<<x<<"] += "<<v<<"\n";
=======
>>>>>>> varios
>>>>>>> fecbcadd7b6a52170a327f9d98f27f3ce044c342
        cnt.upd(pos[head[x]],pos[x]+1,v);
        bs.upd(pos[head[x]],pos[x]+1,v);
        x=fa[head[x]];
    }
}
void init(int N, std::vector<int> U, std::vector<int> V, std::vector<int> W, std::vector<int> T) {
	n=N;
	fore(i,0,n){
		if(i<n-1){
			g[U[i]].pb({V[i],W[i]});
			g[V[i]].pb({U[i],W[i]});
		}
		t[i]=T[i];
	}
	hld_init();
	cnt=STree(n,0),bs=STree(n,1);
	upd(0,1); tot++;
<<<<<<< HEAD
=======
<<<<<<< HEAD
	/*fore(i,0,n){
		cout<<"head "<<i<<": "<<head[i]<<"\n";
	}*/
=======
>>>>>>> varios
>>>>>>> fecbcadd7b6a52170a327f9d98f27f3ce044c342
	fore(i,0,n){
		upd(i,t[i]);
		tot+=t[i];
	}
	return;
}

long long max_time(int x, int v) {
	v=-t[x]+v;
	t[x]+=v;
	tot+=v;
	upd(x,v);
<<<<<<< HEAD
	ll res=cnt.query(0,n);
	ll p=bs.find(tot/2);
	res=res-2*query(p,cnt)+tot*sw[p];
=======
<<<<<<< HEAD
	/*fore(i,0,n)cout<<t[i]<<" ";
	cout<<"\n";
	cout<<"cnt\n";
	fore(i,0,n)cout<<i<<" ("<<ipos[i]<<"): "<<cnt.query(i,i+1)<<"\n";*/
	ll res=cnt.query(0,n);
	ll p=bs.find(tot/2);
	/*fore(i,0,4*n+5){
		cout<<i<<": "<<bs.st[i]<<" "<<bs.lazy[i]<<"\n";
	}
	cout<<"bs\n";
	fore(i,0,n)cout<<i<<" ("<<ipos[i]<<"): "<<bs.query(i,i+1)<<"\n";
	cout<<tot/2<<" "<<p<<"\n";*/
	res=res-2*query(p,cnt)+tot*sw[p];
	//cout<<res<<"-2*"<<query(p,cnt)<<"+"<<tot<<"*"<<sw[p]<<" = "<<res<<"\n";
	//cout<<"\n";
=======
	ll res=cnt.query(0,n);
	ll p=bs.find(tot/2);
	res=res-2*query(p,cnt)+tot*sw[p];
>>>>>>> varios
>>>>>>> fecbcadd7b6a52170a327f9d98f27f3ce044c342
	return res*2;
}
