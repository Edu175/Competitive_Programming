#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXS=130;

string S;
ll dp[16][MAXS][MAXS][MAXS][2];
ll pot[16];
ll f(ll p, ll r, ll s, ll m, ll b){
	ll &res=dp[p][r][s][m][b];
	if(res!=-1)return res;
	if(p==15){
		if(r==0&&s==0)res=1;
		else res=0;
		//cout<<p<<" "<<r<<" "<<s<<" "<<m<<" "<<b<<": "<<res<<"\n";		
		return res;
	}
	ll e=10;
	if(b)e=S[p]-'0'+1;
	res=0;
	fore(j,0,e){
		if(s-j>=0)res+=f(p+1,(r+pot[14-p]*j)%m,s-j,m,b&&(j==e-1));
	}
	//cout<<p<<" "<<r<<" "<<s<<" "<<m<<" "<<b<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	mset(dp,-1);
	ll n; cin>>n;
	S=to_string(n);
	S=string(15-SZ(S),'0')+S;
	pot[0]=1;
	fore(i,1,16)pot[i]=pot[i-1]*10;
	ll res=0;
	fore(s,1,9*14){
		//cout<<s<<": "<<f(0,0,s,s,1)<<"\n";
		res+=f(0,0,s,s,1);
	}
	cout<<res<<"\n";
	return 0;
}
