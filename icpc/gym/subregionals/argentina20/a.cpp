#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5,SIZE=2*MAXN+100;

// ll dp[SIZE];
ld sp[SIZE];

int main(){
	JET
	ll n,a,b; cin>>n>>a>>b; b++;
	ll fg=a==0;
	if(fg)a=1;
	ld ult=0;
	for(ll i=n-1;i>=0;i--){
		ld p=1/ld(b-a+fg);
		ld cur=1+p*(sp[i+a]-sp[i+b]);
		if(fg)cur/=(1-p);
		ult=cur;
		sp[i]=cur+sp[i+1];
		// cout<<i<<": "<<cur<<" "<<sp[i]<<" "<<p<<"\n";
	}
	cout<<fixed<<setprecision(15)<<ult<<"\n";
	return 0;
}

