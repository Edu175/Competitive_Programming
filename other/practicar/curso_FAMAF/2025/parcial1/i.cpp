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

const ll K=18,MAXN=2e5+5;

int main(){FIN;
	vector<vv> sp(K,vv(MAXN+1));
	fore(k,0,K)fore(i,1,MAXN){
		sp[k][i+1]=sp[k][i]+!(i>>k&1);
	}
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r; r++;
		ll mn=MAXN;
		fore(k,0,K)mn=min(mn,sp[k][r]-sp[k][l]);
		cout<<mn<<"\n";
	}
	return 0;
}