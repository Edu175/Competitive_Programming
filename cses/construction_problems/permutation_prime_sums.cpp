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
const ll MAXV=1e5+5;
int cr[MAXV]; // -1 if prime, some non trivial divisor if not
void init_sieve(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
	cr[0]=cr[1]=1;
}

vv solve(ll n){
	if(n==0)return {};
	ll p=-1;
	fore(i,n+1,2*n+1)if(cr[i]==-1){p=i;break;}
	ll k=p-n;
	auto r=solve(k-1);
	ll x=n;
	while(SZ(r)<n)r.pb(x--);
	return r;
}

int main(){FIN;
	init_sieve();
	ll n; cin>>n;
	auto r=solve(n);
	fore(i,1,n+1)cout<<i<<" ";;cout<<"\n";
	imp(r);
	return 0;
}