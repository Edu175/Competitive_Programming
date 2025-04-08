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
const ll INF=1e7+5;
ll get(ll a, ll b){
	if(b==0)return a==1?0:INF;
	return a/b+get(b,a%b);
}
string ans;
void build(ll a, ll b, char c){
	if(b==0)return;
	fore(i,0,a/b)ans.pb(c);
	build(b,a%b,c^1);
}
int main(){FIN;
	ll n; cin>>n; n+=2;
	ll res=INF,w=-1;
	fore(i,1,n){
		ll resi=get(n-i,i);
		if(resi<res)res=resi,w=i;
	}
	// cout<<res-1<<"\n";
	build(n-w,w,'0'); 
	ans.pop_back();
	assert(SZ(ans)==res-1);
	cout<<ans<<"\n";
	return 0;
}