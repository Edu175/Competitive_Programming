#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll c; cin>>c;
	ll dp[c+1];
	auto val=[&](ll i)->bool{
		if(i>c)return 1;
		return dp[i];
	};
	for(ll i=c;i>=0;i--){
		dp[i]=0;
		if(!val(i+1))dp[i]=1;
		if(!val(2*i))dp[i]=1;
	}
	fore(i,0,c+1){
		
		cout<<i<<": "<<(dp[i]?'W':'L')<<"\n";
	}
	return 0;
}