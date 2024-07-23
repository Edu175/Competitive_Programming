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
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#define imp(v) {for(auto fdkhg:v)cout<<fdkhg<<" ";cout<<"\n";}
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
string cv(vector<ll>a){
	string ret="{ ";
	for(auto i:a)ret+=to_string(i)+" ";
	ret+="}";
	return ret;
}
const ll MAXN=605,MAXM=2005;

ull P=1777771,PI=506001883681557571;
struct Hash{
	vector<ull> h,pi;//,pt;
	Hash(){}
	string s;
	Hash(string &_s){
		s=_s;
		assert(P*PI==1);
		h.resize(SZ(s)+1); pi.resize(SZ(s)+1); //pt.resize(SZ(s)+1);
		h[0]=0;pi[0]=1;//pt[0]=1;
		ull p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+p*s[i-1]);
			pi[i]=pi[i-1]*PI;
			p=p*P;
			// pt[i]=p;
		}
	}
	ull get(ll s, ll e){
		return (h[e]-h[s])*pi[s];
	}
	bool les(ll s0, ll e0, ll s1, ll e1){
		ll l=0,r=min(e0-s0,e1-s1);
		while(l<=r){
			ll m=(l+r)/2;
			if(get(s0,s0+m)==get(s1,s1+m))l=m+1;
			else r=m-1;
		}
		if(r==e0-s0)return 1;
		if(r==e1-s1)return 0;
		return s[s0+r]<s[s1+r];
	}
};
Hash ha;
string S;
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
		auto [s0,e0]=ca[i];
		auto [s1,e1]=cb[i];
		if(ha.get(s0,e0)!=ha.get(s1,e1)){
			return ha.les(s0,e0,s1,e1);
		}
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
	ha=Hash(S);
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