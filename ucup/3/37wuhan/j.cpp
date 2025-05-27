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

typedef ll tn; // node type
typedef ll tl; // lazy type
// #define NEUT 0
ll NEUT=0;
#define CLEAR -1 // cleared lazy node
tn oper(tn a, tn b){
	return a+b;
}
void acum(tl &a, tl v){ // accumulate lazy node
	a=v;
}
tn calc(int s, int e, tn a, tl v){ // calculate STree range, a=previous value
	if(v==-1)return a;
	a=(e-s)*v;
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; int n;
	STree(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
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
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};

#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
vector<int> constructSA(string& s){ // O(n logn)
	int n=s.size(),rank;
	vector<int> sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0);
		t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	return sa;
}
vector<int> computeLCP(string& s, vector<int>& sa){
	int n=s.size(),L=0;
	vector<int> lcp(n),plcp(n),phi(n);
	phi[sa[0]]=-1;
	fore(i,1,n)phi[sa[i]]=sa[i-1];
	fore(i,0,n){
		if(phi[i]<0){plcp[i]=0;continue;}
		while(s[i+L]==s[phi[i]+L])L++;
		plcp[i]=L;
		L=max(L-1,0);
	}
	fore(i,0,n)lcp[i]=plcp[sa[i]];
	return lcp; // lcp[i]=LCP(sa[i-1],sa[i])
}
const ll INF=4e5+5;
struct STree2{
	typedef ll tn; // node type
	typedef ll tl; // lazy type
	ll NEUT=INF;
	// ll  CLEAR -1 // cleared lazy node
	tn oper(tn a, tn b){
		return min(a,b);
	}
	void acum(tl &a, tl v){ // accumulate lazy node
		a=v;
	}
	tn calc(int s, int e, tn a, tl v){ // calculate STree range, a=previous value
		assert(s|e|1); // useless, it's only to avoid compiler warning
		if(a==-1)return a;
		a=v;
		return a;
	} 
	vector<tn>st; vector<tl>lazy; int n;
	STree2(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
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
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		s.pb('.');
		ll n=SZ(s);
		auto sa=constructSA(s);
		vv pos(n);
		fore(i,0,n)pos[sa[i]]=i;
		STree st(n),igu(n-1);
		STree2 ls(n-1);
		auto lcp=computeLCP(s,sa);
		fore(i,0,n){
			st.upd(i,i+1,n-1-sa[i]);
			if(i<n-1){
				igu.upd(i,i+1,lcp[i+1]);
				ls.upd(i,i+1,lcp[i+1]);
			}
		}
		// imp(sa)
		ll res=0;
		ll q; cin>>q;
		// fore(i,0,n)cout<<st.query(i,i+1)<<" ";;cout<<"\n";
		while(q--){
			ll l,r; cin>>l>>r; l--;
			ll p=pos[l];
			ll z=r-l;
			if(z>st.query(p,p+1)){
				cout<<res<<" ";
				continue;
			}
			ll lhs=0,rhs=p;
			while(lhs<=rhs){
				ll mid=(lhs+rhs)/2;
				if(ls.query(mid,p)>=z)rhs=mid-1;
				else lhs=mid+1;
			}
			ll s=lhs;
			lhs=p,rhs=n-1;
			while(lhs<=rhs){
				ll mid=(lhs+rhs)/2;
				if(ls.query(p,mid)>=z)lhs=mid+1;
				else rhs=mid-1;
			}
			ll e=lhs;
			// cout<<l<<","<<r<<": "<<p<<" "<<s<<","<<e<<" rango\n";
			ll resi=st.query(s,e)-igu.query(s,e-1)-z+1;
			// cout<<"sum "<<st.query(s,e)<<" igu "<<igu.query(s,e-1)<<" z "<<z<<"\n";
			res+=resi;
			st.upd(s,e,z-1);
			igu.upd(s,e-1,z-1);
			ls.upd(s,e-1,z-1);
			// cerr<<resi<<",";
			cout<<res<<" ";
			// cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
