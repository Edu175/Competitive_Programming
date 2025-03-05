#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(v,a) memset((v),(a),sizeof(v))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

void fail(){
	cout<<"-1\n";
	exit(0);
}

int main(){
    JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	// if(a[0]<0||a[n-1]<0)fail();
	vv b(n),vis(n);
	ll res=0;
	// una pasada
	fore(i,0,n)if(i&&i<n-1&&a[i-1]>=0&&a[i]<0&&a[i+1]>=0){
		auto doit=[&](ll &a, ll &b, ll &c, ll &d){
			ll sum=b+c;
			a+=b;
			b=c;
			c=-sum;
			d+=sum;
			res+=2;
		};
		if(a[i]+a[i-1]<0&&i-2>=0)doit(a[i+1],a[i],a[i-1],a[i-2]);
		else if(a[i]+a[i+1]<0&&i+2<n)doit(a[i-1],a[i],a[i+1],a[i+2]);
	}
	
	fore(i,0,n)if(a[i]<0){
		ll l=i,r=i,sum=-a[i];
		while(l>=0&&a[l]<=0)sum+=a[l--];
		if(l==-1)fail();
		while(r<n&&a[r]<=0)sum+=a[r++];
		if(r>=n)fail();
		vis[l]=vis[r]=1;
		b[l]+=sum; b[r]+=sum;
		res+=2*(r-l-1)-1;
		cerr<<l<<" "<<r<<"\n";
		i=r;
	}
	ll fg=1;
	fore(i,0,n)if(vis[i]&&a[i]+b[i]<0)fg=0;
	if(fg)cout<<res<<"\n";
	else cout<<"-1\n";
    return 0;
}