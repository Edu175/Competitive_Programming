#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef short int ll;
typedef short int LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll n,k;
map<vector<ll>,ll>dp;
LL f(vector<ll>a){
	if((n-SZ(a))/2>=k)return 0;
	if(dp.count(a))return dp[a];
	ll d=0;
	vector<ll>c;
	fore(i,0,SZ(a)-1){
		ll nd=a[i+1]-a[i];
		if(nd>d)d=nd,c={i};
		else if(nd==d)c.pb(i);
	}
	ll &res=dp[a];
	for(auto p:c){
		vector<ll>b;
		fore(i,0,SZ(a))if(i!=p&&i!=p+1){
			b.pb(a[i]);
		}
		res=max(res,f(b));
	}
	res+=d;
	return res;
}

int main(){
	JET
	cin>>n>>k;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	/*ll res=0;
	fore(_,0,k){
		ll d=0,p=-1;
		fore(i,0,SZ(a)-1){
			ll nd=a[i+1]-a[i];
			if(nd>d)d=nd,p=i;
		}
		for(auto i:a)cout<<i<<" ";;cout<<" | "<<d<<"\n";
		res+=d;
		a.erase(a.begin()+p);
		a.erase(a.begin()+p);
	}*/
	cout<<f(a)<<"\n";
}