#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll K=20,MAXV=1ll<<K;
int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n),s(MAXV);
	fore(i,0,n)cin>>a[i],s[a[i]]++;
	//imp(s);
	auto sup=s,sub=s;
	fore(k,0,K)fore(x,0,MAXV){
		if((x>>k)&1)sub[x]+=sub[x^(1ll<<k)];
	}
	fore(k,0,K)for(ll x=MAXV-1;x>=0;x--){
		if(!((x>>k)&1))sup[x]+=sup[x^(1ll<<k)];
	}
	for(auto x:a){
		cout<<sub[x]<<" "<<sup[x]<<" "<<n-sub[x^(MAXV-1)]<<"\n";
	}
	return 0;
}

