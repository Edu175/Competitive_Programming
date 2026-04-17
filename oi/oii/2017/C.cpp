#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e4+5,MAXM=105;
ll m;
struct node{
	vector<ll>oc;
	node(ll v):oc(m){oc[v]=1;}
	node():oc(MAXM){}
};
node oper(node a, node b){
	fore(i,0,m)a.oc[i]+=b.oc[i];
	return a;
}
node oper_inv(node a, node b){
	fore(i,0,m)a.oc[i]-=b.oc[i];
	return a;
}
//node NEUT;
vector<node> ft(MAXN+1);
void upd(int p, node v){
	for(int i=p+1;i<MAXN;i+=i&-i)ft[i]=oper(ft[i],v);
}
node get(int p){
	node res;
	for(int i=p+1;i;i-=i&-i)res=oper(res,ft[i]);
	return res;
}
node query(int l, int r){//[l,r)
	return oper_inv(get(r),get(l));
}
/*struct STree{
	vector<node>t; ll n;
	STree(ll n):t(2*n+5),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=node(v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(ll l, ll r){
		node res;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};*/

int main(){FIN;
	ll n,q; cin>>n>>m>>q;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll sp[n+1]={};
	fore(i,1,n+1)sp[i]=(sp[i-1]+a[i-1])%m;
	//STree st(n+1);
	fore(i,0,n+1)upd(i,node(sp[i]));
	while(q--){
		ll l,r; cin>>l>>r; l--,r++;
		vector<ll>oc=query(l,r).oc;
		ll res=0;
		fore(i,0,m)res+=oc[i]*(oc[i]-1)/2;
		cout<<res<<"\n";
	}
	return 0;
}
