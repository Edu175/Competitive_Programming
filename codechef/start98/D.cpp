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
//Sub-Array With Maximum Sum

struct node{
	/*ii l,r;
	ll fl; //puedo elegir? casi todo 1*/
	ll ans,pre,suf,sum;
	node(ii p,ll b):ans(0)/*l(p),r(p),fl(b)*/{
		ans=max({p.fst,p.snd,(ll)0});
		pre=max({(ll)0,p.fst,p.fst+p.snd});
		suf=max({(ll)0,p.snd,p.fst+p.snd});
		if(b)pre=max(pre,p.snd),suf=max(suf,p.fst);
		sum=p.fst+p.snd;
	}
	node(){}
	void prnt(){
		cout<<ans<<" "<<pre<<" "<<suf<<" "<<sum<<"\n";
	}
};

node oper(node a, node b){
	node r;
	r.ans=max({a.ans,b.ans,a.suf+b.pre});
	r.pre=max(a.pre,a.sum+b.pre);
	r.suf=max(b.suf,b.sum+a.suf);
	r.sum=a.sum+b.sum;
	return r;
}
node NEUT=node({0,0},1);
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	/*void init(vector<ll>&a){
		assert(SZ(a)>=n);
		fore(i,0,n)t[i+n]=node(a[i]);
		for(int s=1<<(32-__builtin_clz(n)),e=2*n;s>1;s>>=1,e=s<<1){
			for(int i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
		}
	}*/
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};

const ll INF=1e15;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		STree st(n);
		fore(i,0,n)st.upd(i,node({a[i],b[i]},1));
		//fore(i,0,n)st.query(i,i+1).prnt();
		ll res=INF;
		fore(i,0,n){
			st.upd(i,node({a[i],b[i]},0));
			res=min(res,st.query(0,n).ans);
			st.upd(i,node({b[i],a[i]},0));
			res=min(res,st.query(0,n).ans);
			st.upd(i,node({a[i],b[i]},1));
		}
		cout<<res<<"\n";
	}
	return 0;
}
