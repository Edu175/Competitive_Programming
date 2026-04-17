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
bool good(vv a){
	ll fg=1;
	for(auto i:a)fg&=i>=0;
	return fg;
}
ll res=0;

ll suma(ll n){
	return (n*(n+1))/2;
}

void go(vv &a){
	ll n=SZ(a);
	fore(i,0,n)if(a[i]<0){
		ll l=i,r=i,sum=-a[i];
		while(l>=0&&a[l]<0)sum+=a[l--];
		if(l==-1)fail();
		while(r<n&&a[r]<0)sum+=a[r++];
		if(r>=n)fail();
		a[l]+=sum; a[r]+=sum;
		fore(i,l+1,r)a[i]=-a[i];
		reverse(a.begin()+l+1,a.begin()+r);
		// rotate(a.begin()+l+1,a.begin()+l+2,a.begin()+r);
		// res+=2*(r-l-1)-1;
		res+=suma(r-l-1);
		// if(a[l-1]<0)i=l-2;
		i=l-1;
		cerr<<l<<" "<<r<<"\n";
	}
}

// void go(vv &a){
// 	ll n=SZ(a);
// 	fore(i,0,n)if(a[i]<0){
// 		if(i==0||i==n-1)fail();
// 		a[i-1]+=a[i];
// 		a[i+1]+=a[i];
// 		a[i]=-a[i];
// 		i=-1;
// 		res++;
// 		for(auto i:a)cerr<<i<<" ";;cerr<<"\n";
// 	}
// }

int main(){
    JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	for(auto i:a)cerr<<i<<" ";;cerr<<"\n";
	go(a);
	cout<<res<<"\n";
	// go(a);
	// while(1){
	// 	if(a[0]<0||a[n-1]<0)fail();
	// 	if(good(a)){
	// 		cout<<res<<"\n";
	// 		break;
	// 	}
	// 	go(a);
	// 	for(auto i:a)cerr<<i<<" ";;cerr<<"\n";
	// }
	// cout<<res<<"\n";
    return 0;
}