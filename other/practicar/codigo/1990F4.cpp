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
	ll res,s,e; vector<ll>pre,suf;
	node(ll i):res(-1),s(i),e(i+1),pre(1,i),suf(1,i){}
};
string str(auto x){return to_string(x);}
string cv(node a){
	string ret="["+str(a.s)+","+str(a.e)+"|";//+"{";
	/*for(auto i:a.pre)ret+=str(i)+",";
	if(SZ(a.pre))ret.pop_back();
	ret+="}{";
	for(auto i:a.suf)ret+=str(i)+",";
	if(SZ(a.suf))ret.pop_back();*/
	ret+=/*"}"+*/str(a.res)+"]";
	return ret;
}
node NEUT(-1);
ll dbg=0;
node oper(node &lhs, node &rhs){
	if(lhs.s==-1)return rhs;
	if(rhs.s==-1)return lhs;
	node c=lhs;
	c.res=max(c.res,rhs.res);
	c.e=rhs.e;
	c.suf=rhs.suf;
	ll s=c.s,e=c.e;
	for(auto i:rhs.pre)if(info.query(s,i).fst<=a[i])c.pre.pb(i);
	for(auto i:lhs.suf)if(info.query(i+1,e).fst<=a[i])c.suf.pb(i);
	
	auto suf=lhs.suf;
	auto pre=rhs.pre;	
	reverse(ALL(pre));
	auto proba=[&](ll l, ll r){
		auto rq=info.query(l,r);
		auto ret= rq.snd<rq.fst-rq.snd;
		// cout<<"good "<<l<<","<<r<<": "<<ret<<"\n";
		if(ret)c.res=max(c.res,r-l);
	};
	while(SZ(pre)||SZ(suf)){
		ll le=SZ(suf)?suf.back()+1:s;
		ll ri=SZ(pre)?pre.back():e;
		proba(le,ri);
		// proba(le,e); proba(s,ri);
		ll go=0;
		if(!SZ(suf))go=1;
		else if(!SZ(pre))go=0;
		else go=a[pre.back()]<a[suf.back()];
		
		if(go)pre.pop_back();
		else suf.pop_back();
	}
	proba(s,e);
	if(dbg&&s<=140864&&140864<e)cout<<"oper "<<cv(lhs)<<" "<<cv(rhs)<<" = "<<cv(c)<<"\n";
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
		ll cnt=0;
		while(q--){
			ll ty,l,r; cin>>ty>>l>>r; l--;
			/*if(n==200000&&cnt<7){
				cout<<a[140864]<<" a[140864]\n";
			}*/
			if(ty==1){
				cnt++;
				if(n==200000&&cnt==7){
					dbg=1;
					/*cout<<l+1<<","<<r<<" query\n";
					fore(i,l,r)cout<<a[i]<<" ";;cout<<" subarray\n";*/
				}
				ll res=st.query(l,r).res;
				if(res<=0)res=-1;
				// cout<<"                   QUERY ";
				cout<<res<<"\n";
				dbg=0;
			}
			else {
				if(n==200000&&cnt==6){
					dbg=1;
					/*cout<<l+1<<","<<r<<" query\n";
					fore(i,l,r)cout<<a[i]<<" ";;cout<<" subarray\n";*/
				}
				a[l]=r;
				info.upd(l,{r,r});
				st.upd(l);
				dbg=0;
			}
			
		}
	}
	return 0;
}