#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define foru(i,a,b) for(ll i=b-1; i>=a;i--)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(s) ((ll)s.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto kdjf:v)cout<<kdjf<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#define oper min
const ll K=13;
int st[K][1<<K];  // K such that 2^K>n
void st_init(vector<int>&a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
string s;
vector<int>sa,lcp,pos;
void SA_compare_init(string &_s){
	s=_s;
	sa=constructSA(s);
	lcp=computeLCP(s,sa);
	pos.resize(SZ(sa));
	fore(i,0,SZ(sa))pos[sa[i]]=i;
	st_init(lcp);
}
ll get_lcp(ll i, ll j){
	if(i==j)return SZ(s)-1-i;
	ll l=pos[i],r=pos[j];
	if(l>r)swap(l,r);
	return st_query(l+1,r+1);
}

int main(){JET
	int t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cin>>s;
		s.pb('_');
		// fore(l,0,n){
		// 	cout<<"| ";
		// 	fore(r,l+1,n+1)cout<<s.substr(l,r-l)<<" ";
		// }
		// cout<<"\n";
		sa=constructSA(s);
		lcp=computeLCP(s,sa);
		// imp(sa); 
		// imp(lcp);
		st_init(lcp);
		// n++;
		pos.resize(n+1);
		fore(i,0,n+1)pos[sa[i]]=i;
		// imp(pos);
		vector<ll>dp(n);
		ll ans=0;
		for(ll i=n-1;i>=0;i--){
			fore(j,i+1,n){
				ll v=n-j-get_lcp(i,j);
				// cout<<i<<"->"<<j<<": "<<pos[i]<<"<"<<pos[j]<<"\n";
				if(pos[i]<pos[j])dp[i]=max(dp[i],dp[j]+v);
			}
			ans=max(ans,dp[i]+n-i);
			// cout<<i<<": "<<dp[i]<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}