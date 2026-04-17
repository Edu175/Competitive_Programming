#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=105,MAXN2=15;

bool goodB(vv a, ll s){
	bitset<MAXN> dp; dp[0]=1;
	for(auto i:a)dp|=dp<<i;
	return !dp[s/2];
}
bool goodS(vv a, ll s){
	bitset<MAXN2> dp; dp[0]=1;
	for(auto i:a)dp|=dp<<i;
	return !dp[s/2];
}

bool good(vv a){ // good es no splittable
	ll s=accumulate(ALL(a),0ll);
	if(s&1)return 1;
	assert(s<MAXN);
	if(s<MAXN2)return goodS(a,s);
	return goodB(a,s);
}

int main(){
    JET
	ll n; cin>>n;
	auto _n=n;
	
	vv res;
	ll goated=0;
	ll pot=100;
	for(ll i=2;i>=0;i--){
		ll m=n/pot;
		vv b;
		ll is=0;
		fore(c5,0,m/5+1){
			vv a(c5,5);
			ll sum=c5*5;
			while(sum+2<=m)sum+=2,a.pb(2);
			while(sum+1<=m)sum+=1,a.pb(1);
			ll cur=good(a);
			if(cur){
				is=1;
				b=a;
			}
			else if(!is)b=a;
		}
		n-=pot*m;
		goated|=is;
		for(auto i:b)res.pb(i*pot);
		pot/=10;
	}
	if(!goated){
		cout<<"splittable\n";
		return 0;
	}
	assert(accumulate(ALL(res),0ll)==_n);
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i<<" ";;cout<<"\n";
	return 0;
}