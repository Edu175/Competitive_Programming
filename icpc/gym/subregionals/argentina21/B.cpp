#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#define RB(x) (x<n?r[x]:0)
void csort(vv& sa, vv& r, int k){
	int n=sa.size(),sum=0; vv f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
vv constructSA(string& s){ //O(n logn)
	int n=s.size(),rank; vv sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0); t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	return sa;
}
vv computeLCP(string& s, vv& sa){
	int n=s.size(),L=0; vv lcp(n),plcp(n),phi(n);
	phi[sa[0]]=-1;
	fore(i,1,n)phi[sa[i]]=sa[i-1];
	fore(i,0,n){
		if(phi[i]<0){plcp[i]=0;continue;}
		while(s[i+L]==s[phi[i]+L])L++;
		plcp[i]=L; L=max(L-1,0);
	}
	fore(i,0,n)lcp[i]=plcp[sa[i]];
	return lcp; // lcp[i]=LCP(sa[i-1],sa[i])
}
const ll K=19; // K such that 2^k>n
#define oper min
ll st[K][1ll<<K];
void st_init(vector<ll> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(int s, int e){
	int k=__lg(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
vv lcp;
ll get_lcp(ll i, ll j){
	assert(i<j);
	return st_query(i+1,j+1);
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	string s; cin>>s;
	string txt=s+s+"$";
	ll C=SZ(txt);
	fore(i,0,m){
		string tmp; cin>>tmp; txt+=tmp+"$";
	}
	auto sa=constructSA(txt);
	vv pos(SZ(sa));
	fore(i,0,SZ(sa))pos[sa[i]]=i;
	lcp=computeLCP(txt,sa);
	st_init(lcp);
	vv le(n);
	set<ll> st;
	fore(i,0,SZ(sa))if(sa[i]>=C)st.insert(i);
	fore(i,0,n){
		ll p=pos[i];
		auto it=st.lower_bound(p);
		auto &res=le[i];
		if(it!=st.end())res=max(res,get_lcp(p,*it));
		if(it!=st.begin())res=max(res,get_lcp(*(--it),p));
	}
	auto can=[&](ll k)->bool {
		vv b(n);
		ll hay=0;
		fore(i,0,n)hay|=(b[i]=le[i]>k);
		if(!hay)return 1;
		fore(i,0,n)b.pb(b[i]);
		ll q=0;
		fore(i,0,2*n){
			if(!b[i])q++;
			else {
				if(q>=n-k)return 1;
				q=0;
			}
		}
		return 0;
	};
	ll l=-1,r=n;
	while(r-l>1){
		ll m=(l+r)/2;
		if(can(m))r=m;
		else l=m;
	}
	ll res=r;
	cout<<res<<"\n";
	return 0;
}
