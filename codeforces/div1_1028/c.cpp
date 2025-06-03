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
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXM=4005,MAXH=405,MAXN=23;

ld mem[MAXM][MAXM];

ld comb(ll n, ll k){
	if(n<k||n<0||k<0)return 0;
	auto &res=mem[n][k];
	if(res>-0.5)return res;
	if(n==0)return res=1;
	return res=comb(n-1,k-1)+comb(n-1,k);
}
ld fpow(ld b, ll e){
	if(e<0)return 0;
	ld res=1;
	while(e){
		if(e&1)res*=b;
		b*=b,e>>=1;
	}
	return res;
}
ld dp[MAXM][MAXN][MAXH]; // m, sum, mn

int main(){FIN;
	fore(i,0,MAXM)fore(j,0,MAXM)mem[i][j]=-1;
	
	ll t; cin>>t;
	while(t--){
		ll n,m,pp; cin>>n>>m>>pp;
		ld p=ld(pp)/100.0;
		// cout<<p<<" p\n";
		ll mnn=MAXH;
		ll sum=0;
		fore(i,0,n){
			ll h; cin>>h; h--;
			mnn=min(mnn,h);
			sum+=h;
		}
		sum-=mnn*n;
		// cout<<sum<<" "<<mnn<<" sum mnn\n";
		fore(sum,0,n)fore(mn,0,mnn+1)dp[m][sum][mn]=mn==0&&sum==0;
		for(ll r=m-1;r>=0;r--)fore(sum,0,n)fore(mn,0,mnn+1){
			auto &res=dp[r][sum][mn];
			ld does=p*dp[r+1][sum][max(mn-1,0ll)]; // shinea
			
			ll sumi,mni;
			if(sum>0)sumi=sum-1,mni=mn;
			else sumi=n-1,mni=max(mn-1,0ll);
			
			ld doesnt=(1-p)*max(dp[r+1][sumi][mni],dp[r+1][sum][mn]);
			res=does+doesnt;
		}
		ld res=0;
		fore(l,0,m+1){
			ld prob=(!l?!sum:comb(l-1,sum-1))*fpow(1-p,sum)*fpow(p,l-sum);
			// cout<<"prob: "<<(!l?!sum:comb(l-1,sum-1))<<" * "<<fpow(1-p,sum)<<"*"<<fpow(p,l-sum)<<"\n";
			ld resi=prob*dp[l][0][max(0ll,mnn-(l-sum))];
			// cout<<l<<": "<<prob<<": "<<dp[l][0][max(0ll,mnn-(l-sum))]<<": "<<resi<<"\n";
			res+=resi;
		}
		
		cout<<fixed<<setprecision(15)<<res<<"\n";
		
	}
	return 0;
}
