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
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
struct tn{
	ll mx,idx,cant,val; // val only makes sense with sz 1
	string cv(){
		string ret;
		ret+=to_string(mx<-1000?-1000:mx)+',';
		ret+=to_string(idx)+',';
		ret+=to_string(cant)+',';
		ret+=to_string(val<-1000?-1000:val);
		return ret;
	}
};
typedef ll tl; // lazy type
const ll INF=1e17;
tn NEUT({-INF,-1,0,-INF});
tl CLEAR=0; // cleared lazy node
tn oper(tn a, tn b){
	if(a.mx<b.mx)a.mx=b.mx,a.idx=b.idx;
	a.cant+=b.cant;
	a.val=max(a.val,b.val);
	return a;
}
void acum(tl &a, tl v){ // accumulate lazy node
	a+=v;
}
tn calc(int s, int e, tn a, tl v){ // calculate STree range, a=previous value
	assert(s|e|1); // useless, it's only to avoid compiler warning
	a.mx+=v;
	a.val+=v;
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; int n;
	STree(int n):st(4*n+5,{0,0,0,0}),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s, int e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int k, int s, int e, int p, tn v){ // assign v to position p
		push(k,s,e);
		if(e<=p||p<s)return;
		if(e-s==1&&s==p){
			push(k,s,e);
			st[k]=v;
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,p,v),upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int p, tn v){upd(1,0,n,p,v);}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};
tn unit(ll val, ll p){
	return {val<0?val:-INF,p,val<0,val};
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		STree st(n-1);
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll sumneg=0;
		auto upd=[&](ll p, ll v){
			ll val=st.query(p,p+1).val;
			if(val<0)sumneg-=val;
			val+=v;
			st.upd(p,unit(val,p));
			if(val<0)sumneg+=val;
			return;
		};
		
		fore(i,0,n-1)upd(i,a[i+1]-a[i]);
		
		auto updRange=[&](ll l, ll r, ll v){ // [,)
			assert(v>=0);
			st.upd(l,r,v);
			while(1){
				auto rq=st.query(l,r);
				if(rq.mx<0){
					sumneg+=v*rq.cant;
					break;
				}
				sumneg-=rq.mx-v;
				st.upd(rq.idx,{-INF,rq.idx,0,rq.mx});
			}
		};
		
		auto query=[&](){
			// imp(a)
			// fore(i,0,n-1)cout<<st.query(i,i+1).cv()<<" ";;cout<<"\n";
			// cout<<sumneg<<"\n";
			if(a[0]>=-sumneg)cout<<"YES\n";
			else cout<<"NO\n";
		};
		auto my_upd=[&](ll p, ll q, ll s, ll d){
			if(p)upd(p-1,s);
			else a[0]+=s;
			if(q<n-1)upd(q,-(s+(q-p)*d));
			updRange(p,q,d);
			// fore(i,p,q+1)if(i)a[i]+=s+d*(i-p);
		};
		
		query();
		while(k--){
			ll p,q,s,d; cin>>p>>q>>s>>d; p--,q--;
			my_upd(p,q,s,d);
			query();
		}
	}
	return 0;
}
