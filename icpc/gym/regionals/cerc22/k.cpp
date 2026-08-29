#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e7+5;

ll a,b;
ii tarda(ll p, ll q){
	p+=a,q+=b;
	ll c=2;
	while(p!=q&&p<INF){
		c++;
		if(p<q)p+=a;
		else q+=b;
	}
	return {p,c};
}

int main(){
	JET
	ll n; cin>>a>>b>>n;
	ii op1=tarda(-1,0);
	ii op2=tarda(0,-1);
	ii op3=tarda(0,0);
	 // 1 index
	vv dp(n+2); // assuming same place (and they shouldnt)
	for(ll i=n;i>=0;i--){
		auto &res=dp[i]; res=INF;
		ll w=0;
		for(auto [d,c]:{op1,op2,op3}){
			if(i&&w==2)continue;
			ll cur;
			if(i+d>n){
				ll p=i,q=i;
				if(w==0)p--;
				else if(w==1)q--;
				cur=0;
				cur+=(n-p)/a;
				cur+=(n-q)/b;
			}
			else cur=dp[i+d]+c;
			res=min(res,cur);
			w++;
		}
	}
	cout<<dp[0]<<"\n";
	return 0;
}