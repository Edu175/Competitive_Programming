#include <bits/stdc++.h>
#define  fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define imp(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e15; // 7e12

int main(){
	ET
	ll n; cin>>n;
	vv sail(n+1),val(n+2),fix(n+1);
	fore(i,1,n)cin>>sail[i];
	vv sp(SZ(sail)+1); fore(i,1,SZ(sp))sp[i]=sp[i-1]+sail[i-1];
	fore(i,1,n+1)cin>>val[i];
	fore(i,0,n+1)cin>>fix[i];
	n+=2;
	vector<vector<vv>>dp(n,vector<vv>(n,vv(2))),opt=dp;
	auto cost=[&](ll l, ll r, ll fg, ll m){ // l < m < r
		ll fij=val[m];
		if(fg)fij+=sp[r]-sp[m];
		else fij+=sp[m]-sp[l];
		ll dbg0=l==0&&r==4&&fg==0;
		ll dbg1=l==0&&r==5&&fg==0;
		if(dbg0||dbg1){
			if(dbg0)cerr<<"dbg0: "<<m<<": ";
			else cerr<<"dbg1 "<<m<<": ";
			cerr<<fij<<" fij, "<<dp[l][m][1]<<" "<<dp[m][r][0]<<"\n";
		}
		ll res=max(dp[l][m][1],dp[m][r][0]);
		res+=fij;
		return res;
	};
	for(ll l=n;l--;)fore(r,l+1,n)fore(fg,0,2){
		auto &res=dp[l][r][fg],&bst=opt[l][r][fg];
		bst=-1;
		if(r-l==1){res=fix[l];continue;}
		res=INF;
		ll s=-1,e=-1;
		if(s==-1)s=l+1;
		if(e==-1)e=r-1;
		vv b;
		ll prev=-1,did=0;
		fore(i,s,e+1){
			ll resi=cost(l,r,fg,i);
			if(resi<res)res=resi,b.clear();
			if(resi==res)b.pb(i);
			if(prev!=-1){
				if(prev<=resi)did=1;
				else assert(!did);
			}
			prev=resi;
		}
		cerr<<l<<" "<<r<<" "<<fg<<": "<<res<<": "; imp(b)
	}
	ll res=dp[0][n-1][0];
	cout<<res<<"\n";
}