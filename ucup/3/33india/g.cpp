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
const ll K=18; // K such that 2^k>n
#define oper min
ll st[K][1ll<<K];
void st_init(vector<int> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(int s, int e){
	int k=__lg(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
// compare substrings with suffix array
string S;
vector<int>sa,lcp,pos;
void SA_compare_init(string &_s){
	S=_s;
	sa=constructSA(S);
	lcp=computeLCP(S,sa);
	pos.resize(SZ(sa));
	fore(i,0,SZ(sa))pos[sa[i]]=i;
	st_init(lcp);
}
ll get_lcp(ll i, ll j){
	if(i==j)return SZ(S)-1-i;
	ll l=pos[i],r=pos[j];
	if(l>r)swap(l,r);
	return st_query(l+1,r+1);
}

ll compare(ii a, ii b){
	auto [i,i1]=a; auto [j,j1]=b; i1-=i,j1-=j;
	ll k=get_lcp(i,j);
	if(k>=i1&&k>=j1){
		if(i1==j1)return 0;
		return i1<j1?-1:1;
	}
	if(k>=i1)return -1;
	if(k>=j1)return 1;
	return S[i+k]<S[j+k]?-1:1;
}

struct STree{
	typedef ll node;
	#define NEUT 0
	ll oper(ll a, ll b){return max(a,b);}
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		string s; cin>>s; s.pb('.');
		SA_compare_init(s);
		vv p(n);
		fore(i,0,n-1)p[i]=get_lcp(i,i+1);
		vv is(n); is[n-1]=1;
		set<ll>st;
		fore(i,0,n-1){
			is[i]=pos[i]<pos[i+1];
			if(is[i])st.insert(i);
		}
		st.insert(n-1);
		STree seg(n);
		fore(i,0,n)seg.upd(i,p[i]+i);
		auto get=[&](ll p, ll v){ // first index >= v of seg
			ll l=p,r=n-1;
			while(l<=r){
				ll m=(l+r)/2;
				if(seg.query(p,m+1)>=v)r=m-1;
				else l=m+1;
			}
			return l;
		};
		while(q--){
			ll l,r; cin>>l>>r; l--;
			ll z=r-l-1;
			ll e=*st.lower_bound(l); // primer <
			// res es <= e
			ll p=get(l,z+l);
			ll res=min(p,e);
			cout<<res+1<<"\n";
		}
	}
	return 0;
}