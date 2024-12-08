#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll mod=1e9+7;
ll addm(ll a, ll b){
	a+=b;
	return a<mod?a:a-mod;
}
ll subm(ll a,ll b){
	a-=b;
	return a<0?a+mod:a;
}
int main(){
	ET
	ll k,l; cin>>k>>l;
	ll t[k][k];
	
	fore(i,0,k)fore(j,0,k) cin>>t[i][j];
	
	ll n; cin>>n;
	
	ll s[n-1];
	fore(i,0,n-1) cin>>s[i];
	
	ll p[n][k];
	mset(p,0);
	
	fore(i,0,k) p[0][i]=1ll;
	
	ll sl[k+1]; mset(sl,0);
	
	fore(i,0,n-1){
		fore(j,0,k){
			ll j1=lower_bound(t[j],t[j]+k,s[i]-l)-t[j];
			ll j2=upper_bound(t[j],t[j]+k,s[i]+l)-t[j];
			//cout<<s[i]<<"\n";
			//cout<<t[j][j2]<<"\n";
			//cout<<"estamos en "<<i<<" "<<j<<"\n";
			//cout<<j1<<" "<<j2<<"\n";
			sl[j1]=addm(sl[j1],p[i][j]);
			sl[j2]=subm(sl[j2],p[i][j]);
		}
		ll cnt=0;
		fore(j,0,k){
			cnt=addm(cnt,sl[j]);
			p[i+1][j]=addm(p[i+1][j],cnt);
		}
		mset(sl,0);
	}
	ll res=0;
	fore(i,0,k){
		res=addm(p[n-1][i],res);
	}
	cout<<res<<"\n";
	
}