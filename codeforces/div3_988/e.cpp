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

ll ask(ll l, ll r){
	l++;
	cout<<"? "<<l<<" "<<r<<endl;
	ll ret; cin>>ret;
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv qs(n+1);
		fore(i,0,n-1)qs[i]=ask(i,n);
		vv ans(n);
		fore(i,0,n){
			if(qs[i]==qs[i+1])ans[i]=1;
		}
		ll p=-1;
		fore(i,0,n)if(!ans[i])p=i;
		if(p==-1){
			assert(qs[0]==0);
			cout<<"! IMPOSSIBLE"<<endl;
			continue;
		}
		ll c=qs[p];
		fore(i,p+1+c,n)ans[i]=0;
		cout<<"! ";
		for(auto i:ans)cout<<i;
		cout<<endl;
	}
	return 0;
}
