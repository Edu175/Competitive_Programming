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

ll n;
vv rew;

ll f(string a);
ll mv(string a, ll l, ll r){
	if(a[l]=='#'||a[r]=='#')return -1;
	ll did=0;
	fore(i,l,r)did|=a[i]=='#',a[i]='.';
	if(!did)return -1;
	return rew[l]+rew[r]+f(a);
}

map<string,ll> dp;

ll f(string a){
	if(dp.count(a))return dp[a];
	auto &res=dp[a];
	res=0;
	fore(l,0,n)fore(r,l+1,n)res=max(res,mv(a,l,r));
	return res;
}

int main(){FIN;
	cin>>n;
	string a; cin>>a;
	rew.resize(n);
	fore(i,0,n)cin>>rew[i];
	ll res=f(a),cnt=0;
	fore(l,0,n)fore(r,l+1,n)cnt+=mv(a,l,r)==res;
	cout<<cnt<<"\n";
	return 0;
}
