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
typedef long double ld;
typedef pair<ll,ll> ii;
ld dp[105][64][8][8];
int main(){FIN;
	ll n; cin>>n;
	//cout<<fixed<<setprecision(2);
	fore(k,0,64){
		//cout<<"robot "<<k<<" ("<<k/8<<","<<k%8<<"):\n";
		dp[0][k][k/8][k%8]=1;
		fore(l,0,n){
			auto p=dp[l][k];
			auto pi=dp[l+1][k];
			fore(i,0,8)fore(j,0,8){
				ld c=(i>0)+(j>0)+(j<7)+(i<7);
				if(i)pi[i-1][j]+=p[i][j]/c;
				if(j)pi[i][j-1]+=p[i][j]/c;
				if(i<7)pi[i+1][j]+=p[i][j]/c;
				if(j<7)pi[i][j+1]+=p[i][j]/c;
			}
			//fore(i,0,8){imp(p[i]);}cout<<"\n";
		}
	}
	ld res=0;
	fore(i,0,8)fore(j,0,8){
		ld resi=1;
		fore(k,0,64)resi*=1-dp[n][k][i][j];
		res+=resi;
	}
	//cout<<res<<"\n";
	string s=to_string(res);
	cout<<s<<"\n";
	return 0;
}
