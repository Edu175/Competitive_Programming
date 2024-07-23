#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#define imp(v) {for(auto fdkhg:v)cout<<fdkhg<<" ";cout<<"\n";}
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
string cv(deque<ll>a){
	string ret="{ ";
	for(auto i:a)ret+=to_string(i)+" ";
	ret+="}";
	return ret;
}
const ll MAXN=605,MAXM=2005;
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
const ll K=20;
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
string S;
vector<int>sa,lcp,pos;
void SA_compare_init(string _s){
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
ll ls[MAXM],rs[MAXM];
// abc < abcd
bool les(deque<ll>&a, deque<ll>&b){ // aristas
	// cout<<"\n\nles "<<cv(a)<<" "<<cv(b)<<"\n";
	deque<ii>ra,rb;
	for(auto i:a)ra.pb({ls[i],rs[i]});
	for(auto i:b)rb.pb({ls[i],rs[i]});
	// for(auto i:ra)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	// for(auto i:rb)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	// cout<<"-->>\n";
	vector<ii>ca,cb;
	auto tam=[&](ii r){return r.snd-r.fst;};
	while(SZ(ra)||SZ(rb)){
		while(SZ(ra)&&tam(ra[0])==0)ra.pop_front();
		while(SZ(rb)&&tam(rb[0])==0)rb.pop_front();
		if(!SZ(ra)&&!SZ(rb))break;
		if(!SZ(ra)){cb.pb(rb[0]);break;}
		if(!SZ(rb)){ca.pb(ra[0]);break;}
		if(tam(ra[0])<=tam(rb[0])){
			ca.pb(ra[0]);
			ll k=rb[0].fst+tam(ra[0]);
			cb.pb({rb[0].fst,k});
			rb[0].fst=k;
			ra.pop_front();
		}
		else {
			cb.pb(rb[0]);
			ll k=ra[0].fst+tam(rb[0]);
			ca.pb({ra[0].fst,k});
			ra[0].fst=k;
			rb.pop_front();
		}
	}
	// for(auto i:ca)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	// for(auto i:cb)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	ll m=max(SZ(ca),SZ(cb));
	fore(i,0,m){
		if(i>=SZ(ca))return 1;
		if(i>=SZ(cb))return 0;
		auto eq=compare(ca[i],cb[i]);
		if(eq)return eq==-1;
	}
	return 0;
}

vector<ii>g[MAXN];

vector<ll>ord;
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vis[y])dfs(y);
	ord.pb(x);
}

int main(){JET
	ll n,m,D,s; cin>>n>>m>>D>>s; s--;
	cin>>S;
	S.pb('_');
	SA_compare_init(S);
	fore(i,0,m){
		ll u,v,l,r,len; cin>>u>>v>>l>>len; u--,v--,l--;
		r=l+len;
		// cout<<u<<","<<v<<" "<<l<<","<<r<<endl;
		ls[i]=l,rs[i]=r;
		g[u].pb({v,i});
	}
	dfs(s);
	// reverse(ALL(ord));
	deque<ll>ans[n];
	fore(t,0,n){
		// cout<<t<<" t\n";
		deque<ll> dp[n];  // aristas
		vector<ll>is(n);
		deque<ll> cam[n]; // nodos
		ll did=0;
		for(auto x:ord){
			did|=x==t;
			if(!did)continue;
			if(x==t){cam[x]={x};continue;}
			for(auto [y,i]:g[x])if(SZ(cam[y])){
				auto tmp=dp[y]; tmp.push_front(i);
				if(!is[x]||les(tmp,dp[x]))
					dp[x]=tmp,cam[x]=cam[y];
				is[x]=1;
			}
			if(SZ(cam[x]))cam[x].push_front(x);
			// cout<<x<<": "; imp(cam[x])
			
		}
		ans[t]=cam[s];
	}
	// fore(x,0,n){
	// 	cout<<x<<" dp: ";
	// 	for(auto i:dp[x])cout<<i+1<<" ";
	// 	cout<<"\n";
	// }
	// cout<<" =============\n";
	fore(x,0,n){
		cout<<SZ(ans[x])<<" ";
		for(auto i:ans[x])cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}