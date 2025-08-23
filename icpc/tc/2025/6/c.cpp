#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll steps=30;

map<pair<vv,ii>,ll> dp;

ll f(vv a, ll p, ll d){
	// cout<<"f "<<p<<" "<<d<<"\n";
	if(dp.count({a,{p,d}}))return dp[{a,{p,d}}];
	auto &res=dp[{a,{p,d}}];
	ll fg=1,n=SZ(a);
	fore(i,0,n)fg&=a[i]==i;
	if(fg)return res=0;
	if(d>=steps)return res=1;
	if(!fg){
		res=1;
		fore(i,0,n)fore(j,i+1,n){
			auto b=a;
			swap(b[i],b[j]);
			res&=f(b,p^1,d+1);
		}
	}
	else {
		res=0;
		fore(i,0,n-1){
			auto b=a;
			swap(b[i],b[i+1]);
			res|=f(b,p^1,d+1);
		}
	}
	cout<<"f "<<p<<" "<<d<<": "<<res<<"\n";
	return res;
}

vector<string> players={"Alice","Bob"};

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; string s; cin>>n>>s;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		if(n<5){
			cout<<players[f(a,s==players[1],0)]<<"\n";
		}
	}
	return 0;
}