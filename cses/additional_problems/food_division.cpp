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
typedef pair<ll,ll> ii;

ll cost(vector<ll>a, ll z){
	ll res=abs(z);
	ll n=SZ(a);
	a[0]+=z;
	fore(i,0,n-1)res+=abs(a[i]),a[i+1]+=a[i];
	//cout<<"cost "<<z<<" = "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n),b(n),c(n);
	ll sum=0;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	fore(i,0,n)cin>>b[i];
	fore(i,0,n)c[i]=a[i]-b[i];
	ll l=-sum-5,r=sum+5;
	while(10<=r-l){
		//cout<<l<<" "<<r<<endl;
		ll m=(l+r)/2;
		if(cost(c,m)>=cost(c,m+1))l=m+1;
		else r=m-1;
	}
	ll res=cost(c,l);
	//cout<<l<<" "<<r<<"\n";
	fore(i,l-5,r+6)res=min(res,cost(c,i));
	cout<<res<<"\n";
	return 0;
}
