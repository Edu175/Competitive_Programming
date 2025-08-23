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
	vector<ii> rta,rtb;
	fore(i,0,n)fore(j,0,m){
		if((i+j)%2==1) rta.pb({i+1,j+1});
		else rtb.pb({i+1,j+1});
	}
	if(SZ(rta)>SZ(rtb))swap(rta,rtb);
	cout<<SZ(rta)<<"\n";
	for(auto [a,b]:rta)cout<<a<<" "<<b<<" "<<a<<" "<<b<<"\n";
	
	return 0;
	
}