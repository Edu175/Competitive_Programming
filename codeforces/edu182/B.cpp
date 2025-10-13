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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vv oc(n);
		ll cnt=0;
		fore(i,0,n){
			cin>>a[i],a[i]--;
			if(a[i]!=-1)oc[a[i]]++;
			else cnt++;
		}
		if(cnt==1){
			ll x=-1;
			fore(i,0,n)if(!oc[i])x=i;
			fore(i,0,n)if(a[i]==-1)a[i]=x;
		}
		ll l=-1,r=-1;
		fore(i,0,n){
			if(l==-1&&a[i]!=i)l=i;
			if(a[i]!=i)r=i;
		}
		ll res=r-l+1;
		if(l==-1)res=0;
		cout<<res<<"\n";
	}
	return 0;
}
