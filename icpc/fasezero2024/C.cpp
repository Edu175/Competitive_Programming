#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

ll mn[MAXN],mx[MAXN],hayl[MAXN];

ll f(ll i, ll b, ll r){
	if(b&&i>=r)return 0;
	ll &res=dp[i][b];
	if(res!=-1)return res;
	if(i==n)return res=0;
	if(b&&hayl)
	res=f(i+1,b,r);
	if(i<r)
}

int main(){FIN;
	cin>>n; n--;
	fore(i,0,n)mx[i]=n;
	mset(mn,-1);
	vector<pair<ii,ll>>ev[n];
	ll m; cin>>m;
	fore(i,0,m){
		ll l,r; cin>>l>>r; r--;
		hayl[l]=1;
		ev[l].pb({{r,i},1});
		ev[r].pb({{r,i},-1});
	}
	fore(x,0,n){
		for(auto [r,b]:ev[x]){
			if(b==-1)st.erase(r);
			else st.insert(r);
		}
		if(SZ(st))mn[x]=st.begin()->fst,mx=prev(st.end())->fst;
	}
	
	return 0;
}
