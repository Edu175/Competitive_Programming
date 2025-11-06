#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long double LD;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;
// bs on dp value X=0 on H's turn at certain fixed scores
// artificial value starts lower than calculated value
// but calculated value grows slower (both continuously)
// (because H can opt out of that artificial situation, possibly lowering the score)
// so we can binary search equality
const ll MAXN=76;
// prob of p1 wining
// H is p0
// C is p1
ld dp0[MAXN][MAXN];
ld dp1[MAXN][MAXN];
// ld abs(ld x){return x<0?-x:x;}
int main(){ET
	fore(c,0,74){
		dp0[75][c]=dp1[75][c]=0;
		dp0[74][c]=dp1[74][c]=1;
	}
	fore(h,0,74){
		dp0[h][75]=dp1[h][75]=1;
		dp0[h][74]=dp1[h][74]=0;
	}
	ll wh[MAXN][MAXN][MAXN];
	for(ll h=73;h>=0;h--)for(ll c=73;c>=0;c--){
		auto doit=[&](ld m){ // assigns dp[h][c] and wh
			vector<ld> cur0(MAXN+10),cur1(MAXN+10);
			cur0[0]=m;
			dp0[h][c]=m;
			for(ll t=MAXN+9;t>=0;t--){
				auto &res=cur1[t];
				if(c+t>75){res=cur0[0];continue;}
				res=dp0[h][c+t];
				ld roll=cur0[0]; // 1
				fore(i,2,7)roll+=cur1[t+i];
				roll/=6;
				wh[h][c][t]=roll>res;
				res=max(res,roll);
			}
			dp1[h][c]=cur1[0];
			
			for(ll t=MAXN+9;t>=0;t--){
				auto &res=cur0[t];
				if(h+t>75){res=cur1[0];continue;}
				res=dp1[h+t][c];
				ld roll=cur1[0]; // 1
				fore(i,2,7)roll+=cur0[t+i];
				roll/=6;
				res=min(res,roll);
			}
			dp0[h][c]=cur0[0];
			
		};
		
		ld l=1e-4096l,r=1;
		fore(_,0,100){
			ld m=2*l<r?sqrtl(l*r):(l+r)/2;
			doit(m);
			if(m<=dp0[h][c])l=m;
			else r=m;
		}
		ld m=r;
		doit(m);
	}
	
	ll q; cin>>q;
	fore(_,0,q){
		ll c,h,t; cin>>c>>h>>t;
		cout<<"HC"[wh[h][c][t]]<<"\n";
	}
}