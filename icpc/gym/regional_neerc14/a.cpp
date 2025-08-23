#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	
	#ifdef ONLINE_JUDGE
	freopen("alter.in","r",stdin);     freopen("alter.out","w",stdout);
	#endif
	
	JET
	
	ll n,m; cin>>n>>m;
	vector<array<ll,4>>a;
	
	fore(i,0,n)if(i&1)a.pb({i,0,i,m-1});
	fore(i,0,m)if(i&1)a.pb({0,i,n-1,i});
	
	cout<<SZ(a)<<"\n";
	for(auto i:a){
		for(auto j:i)cout<<j+1<<" ";
		cout<<"\n";
	}
	return 0;
	
}