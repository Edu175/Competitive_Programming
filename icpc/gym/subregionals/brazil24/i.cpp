#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXV=1e6+5,MOD=1e9+7;

short mu[MAXV] = {0,1};

void mobius(){
	fore(i,1,MAXV)if(mu[i])for(int j=i+i;j<MAXV;j+=i){
		mu[j]-=mu[i];
	}
}

int main(){
	JET
	mobius();
	ll n; cin>>n;
	vv a(n),oc(MAXV);
	fore(i,0,n)cin>>a[i],oc[a[i]]++;
	vv ocm(MAXV);
	fore(i,1,MAXV)for(ll j=i;j<MAXV;j+=i)ocm[i]+=oc[j];
	vv pot(n+5,1); fore(i,1,SZ(pot))pot[i]=pot[i-1]*2%MOD;
	vv ans(MAXV);
	fore(i,1,MAXV){
		for(ll j=i;j<MAXV;j+=i){
			ans[j]+=ocm[i]*mu[i];
		}
	}
	ll q; cin>>q;
	while(q--){
		ll x; cin>>x;
		ll res=ans[x];
		res=pot[res];
		cout<<res<<"\n";
	}
	return 0;
}