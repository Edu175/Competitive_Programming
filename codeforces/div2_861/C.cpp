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

string l,r;
ll n;
ll dp[20][12][12][3][3][3];
ll f(ll i, ll mx,ll mn, ll s, ll e, ll z){
	ll &res=dp[i][mx][mn][s][e][z];
	if(res!=-1)return res;
	if(i==n)return mx-mn;
	res=20;
	fore(j,0,10){
		ll d='0'+j;
		if(s&&l[i]>d)continue;
		if(e&&r[i]<d)break;
		ll mxi=mx,mni=mn;
		if(z||j)mxi=max(mxi,j),mni=min(mni,j);
		res=min(res,f(i+1,mxi,mni,(s&&d==l[i]),(e&&d==r[i]),z||j));
	}
	return res;
}
string ans;
void build(ll i, ll mx,ll mn, ll s, ll e, ll z){
	ll &res=dp[i][mx][mn][s][e][z];
	if(i==n)return;
	fore(j,0,10){
		ll d='0'+j;
		if(s&&l[i]>d)continue;
		if(e&&r[i]<d)break;
		ll mxi=mx,mni=mn;
		if(z||j)mxi=max(mxi,j),mni=min(mni,j);
		if(res==f(i+1,mxi,mni,(s&&d==l[i]),(e&&d==r[i]),z||j)){
			ans.pb(d);
			build(i+1,mxi,mni,(s&&d==l[i]),(e&&d==r[i]),z||j);
			break;
		}
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		mset(dp,-1);
		ans.clear();
		ll s,e; cin>>s>>e;
		string w=to_string(s); r=to_string(e);
		l.clear();
		l.resize(SZ(r)-SZ(w),'0');
		l+=w;
		n=SZ(r);
		//cout<<l<<" "<<r<<"\n";
		//cout<<f(0,0,10,1,1,0)<<"\n";
		f(0,0,10,1,1,0);
		build(0,0,10,1,1,0);
		ll z=0;
		for(auto i:ans){
			if((i-'0'))z=1;
			if(z||(i-'0'))cout<<i;
		}
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
