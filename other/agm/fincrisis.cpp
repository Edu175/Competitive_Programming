//notes https://github.com/Edu175/padalustro/blob/master/padalustro.cpp
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7,MAXF=1e4;
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=fc[i-1]*i%MOD;
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=fci[i+1]*(i+1)%MOD;
}
ll nCr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

int main(){FIN;
	factorials();
	ll m,k; cin>>m>>k;
	ll n; cin>>n;
	map<ii,ll>mp;
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		mp[{x,y}]++;
	}
	vector<ii>a;
	for(auto [p,c]:mp){
		auto [x,v]=p;
		if(c&&v==k){
			a.pb({c,MOD});
			//cout<<x<<": "<<v<<","<<k-v<<": "<<c<<","<<MOD<<"\n";
		}
		else if(c&&v*2==k){
			a.pb({c,MOD+1});
		}
		else if(c&&mp[{x,k-v}]){
			a.pb({c,mp[{x,k-v}]});
			//cout<<x<<": "<<v<<","<<k-v<<": "<<c<<","<<mp[{x,k-v}]<<"\n";
			mp[{x,k-v}]=mp[p]=0;
			
		}
	}
	//for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	n=SZ(a);
	vector<vector<ll>>dp(n+5,vector<ll>(m+5));
	fore(v,0,m+5)dp[n][v]=(v==m);
	for(ll i=n-1;i>=0;i--)fore(v,0,m+2){
		fore(x,0,min(a[i].fst,a[i].snd)+1){
			if(v+x<=m)
				dp[i][v]=add(dp[i][v],
				mul(dp[i+1][v+x],
				mul(nCr(a[i].fst,(a[i].snd==MOD+1?2*x:x)),
				(a[i].snd<MOD?nCr(a[i].snd,x):1)
				//nCr(a[i].snd,x%MOD)
				)));
		}
		//if(dp[i][v])cout<<i<<" "<<v<<": "<<dp[i][v]<<"\n";
	}
	cout<<dp[0][0]<<"\n";
	return 0;
}
