#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

void imp(vector<ll>a){
	for(auto i:a){
		if(i>1e5)cout<<"- ";
		else cout<<i<<" ";
	}
	cout<<"\n";
}
	
int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll>a(n+1);
	fore(i,1,n)cin>>a[i];
	vector<ll>h(n+1);
	h[0]=a[n]=1e9+5;
	ll l=0,r=1;
	while(r<=n){
		if(r-l>k)l++;
		//cout<<l<<" "<<r<<"\n";
		//imp(a); imp(h);
		while(l<r&&a[r]){
			while(l<r&&!h[l])l++;
			//cout<<l<<" "<<r<<"\n";
			//imp(a); imp(h);
			if(l==r)break;
			ll x=min(a[r],h[l]);
			a[r]-=x,h[r]+=x,h[l]-=x;
		}
		r++;
	}
	cout<<h[n]<<"\n";
	return 0;
}
