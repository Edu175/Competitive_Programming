#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;//,INF=1e13;
ll a[MAXN];
ii NEUT2={0,0};
ii oper2(ii a, ii b){
	return {a.fst+b.fst,max(a.snd,b.snd)};
}
struct STree2{
	int n; vector<ii>t;
	STree2(int n):n(n),t(2*n+5,NEUT2){}
	void upd(int p, ii v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper2(t[p],t[p^1]);
	}
	ii query(int l, int r){
		ii res=NEUT2;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper2(res,t[l++]);
			if(r&1)res=oper2(res,t[--r]);
		}
		return res;
	}
};
STree2 info(0);
struct node{
	ll res,s,e; vector<ll>h;
	node(ll i):res(-1),s(i),e(i+1),h(1,i){}
};
string str(auto x){return to_string(x);}
string cv(node a){
	string ret="["+str(a.s)+","+str(a.e)+"{";
	for(auto i:a.h)ret+=str(i)+",";
	if(SZ(a.h))ret.pop_back();
	ret+="}"+str(a.res)+"]";
	return ret;
}
node NEUT(-1);
node oper(node &lhs, node &rhs){
	if(lhs.s==-1)return rhs;
	if(rhs.s==-1)return lhs;
	node c=lhs;
	c.res=max(c.res,rhs.res);
	c.e=rhs.e;
	ll s=c.s,e=c.e;
	auto &h=c.h;
	for(auto i:rhs.h)h.pb(i);
	vector<ll>hi;
	auto get=[&](ll i)->ii{
		auto v=a[h[i]];
		ll mx=v;
		ll lft=s,rgt=e;
		fore(j,i,SZ(h)){
			mx=max(mx,a[h[j]]);
			if(mx!=v){rgt=h[j];break;}
		}
		mx=v;
		for(ll j=i;j>=0;j--){
			mx=max(mx,a[h[j]]);
			if(mx!=v){lft=h[j]+1;break;}
		}
		auto rq=info.query(lft,rgt);
		auto ret=rq.fst-rq.snd>rq.snd;
		// cout<<"get "<<i<<" "<<s<<","<<e<<": "<<lft<<","<<rgt<<": "<<ret<<"\n";
		if(ret)return {lft,rgt};
		return {-1,-1};
	};
	ll rb=-1;
	fore(i,0,SZ(h))if(h[i]>=rb){
		auto [l,r]=get(i);
		rb=max(rb,r);
		if(l==-1)hi.pb(h[i]);
		else {
			c.res=max(c.res,r-l);
			while(SZ(hi)&&hi.back()>=l)hi.pop_back();
		}
	}
	h=hi;
	// fore(i,0,SZ(h)){
	// 	c.res=max(c.res,h[i]-(i?h[i-1]:s-1)-1);
	// }
	// c.res=max(c.res,e-(SZ(h)?h.back():s-1)-1);
	// cout<<"h tmp: "; imp(h);
	vector<ll>aux,auxr;
	ll mx=-1;
	for(auto i:h){
		mx=max(mx,a[i]);
		if(mx==a[i])aux.pb(i);
	}
	reverse(ALL(h));
	mx=-1;
	for(auto i:h){
		mx=max(mx,a[i]);
		if(mx==a[i])auxr.pb(i);
	}
	if(SZ(auxr))auxr.pop_back();
	reverse(ALL(auxr));
	for(auto i:auxr)aux.pb(i);
	h=aux;
	if(!SZ(h))c.res=e-s;
	// cout<<"oper "<<cv(lhs)<<" "<<cv(rhs)<<" = "<<cv(c)<<"\n";
	return c;
}

struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p){ // update array a first
		for(p+=n,t[p]=node(p-n);p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
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
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		fore(i,0,n)cin>>a[i];
		info=STree2(n);
		fore(i,0,n)info.upd(i,{a[i],a[i]});
		STree st(n);
		fore(i,0,n)st.upd(i);
		while(q--){
			ll ty,l,r; cin>>ty>>l>>r; l--;
			if(ty==1){
				ll res=st.query(l,r).res;
				if(res<=0)res=-1;
				// cout<<"                   QUERY ";
				cout<<res<<"\n";
			}
			else {
				a[l]=r;
				info.upd(l,{r,r});
				st.upd(l);
			}
			
		}
	}
	return 0;
}