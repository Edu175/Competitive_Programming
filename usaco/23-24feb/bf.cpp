#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,usaco=b;i<usaco;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asdf:v)cout<<asdf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

void transf(vector<ll>&a){
	ll n=SZ(a);
	ll mn=0;
	fore(i,0,n)if(a[i]<=a[mn])mn=i;
	vector<ll>b(n);
	fore(i,0,n)b[(i+n-1-mn+4*n)%n]=a[i];
	a=b;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	transf(a);
	imp(a);
	vector<ll>r(n,n);
	for(ll i=n-1;i>=0;i--)for(r[i]=i+1;r[i]!=n&&a[r[i]]>=a[i];r[i]=r[r[i]]);
	//imp(r);
	vector<ll>res(n+1);
	fore(i,0,n){
		ll x=i;
		while(r[x]<n){
			res[r[x]-i]-=a[x]-a[r[x]];
			cout<<i<<"i "<<x<<"x "<<r[x]<<"rx : "<<r[x]-i<<"+="<<a[x]-a[r[x]]<<"\n";
			x=r[x];
		}
	}
	ll sum=0;
	fore(i,0,n)sum+=a[i];
	fore(i,1,n+1){
		sum+=res[i];
		cout<<sum<<"\n";
	}
	return 0;
}
