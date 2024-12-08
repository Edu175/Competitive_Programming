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
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ll T,N,V,S; cin>>T>>N>>V>>S;
	ll t=rng()%T+1; cout<<t<<"\n";
	while(t--){
		ll n=rng()%(N-1)+2;
		cout<<n<<" 2\n";
		fore(i,0,n){
			ll a=rng()%(V+1);
			ll b=rng()%(V+1);
			ll s=rng()%(S+1);
			if(a>b)swap(a,b);
			cout<<a<<" "<<b<<" "<<s<<"\n";
		}
		vv gr(n);
		vv h[2];
		fore(i,0,n)gr[i]=rng()&1;
		if(gr==vv(n,0))gr[rng()%n]=1;
		if(gr==vv(n,1))gr[rng()%n]=0;
		fore(i,0,n)h[gr[i]].pb(i);
		fore(k,0,2){
			cout<<SZ(h[k])<<" ";
			for(auto i:h[k])cout<<i+1<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
