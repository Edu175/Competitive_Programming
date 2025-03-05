#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(511,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(511,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
vector<int> constructSA(vv& s){ // O(n logn)
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
const ll SEP=350;
int main(){ET;
	ll n; cin>>n;
	ll sum=0;
	vector<vv> a(n);
	vv sums;
	vv S;
	fore(i,0,n){
		sums.pb(SZ(S));
		ll m; cin>>m;
		a[i].resize(m);
		fore(j,0,m)cin>>a[i][j],S.pb(a[i][j]);
		// reverse(ALL(a[i]));
		S.pb(SEP);
		sum+=m;
	}
	vv p(n);
	ll m=SZ(S);
	vv pos(m);
	auto sa=constructSA(S);
	fore(i,0,m)pos[sa[i]]=i;
	priority_queue<ii>pq;
	auto put=[&](ll i){
		pq.push({-pos[sums[i]+p[i]],i});
	};
	fore(i,0,n)put(i);
	ll res=0;
	for(ll d=sum;d;d--){
		auto [dkjfhg,i]=pq.top(); pq.pop();
		ll v=a[i][p[i]];
		p[i]++;
		if(p[i]!=SZ(a[i]))put(i);
		res=add(res,mul(v,fpow(365,d)));
		cerr<<v<<" ";
	}
	cerr<<"\n";
	cout<<res<<"\n";
}