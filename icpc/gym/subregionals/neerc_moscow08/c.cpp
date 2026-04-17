#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n,m; cin>>n>>m;
	vv a(n*m);
	fore(i,0,n*m)cin>>a[i];
	sort(ALL(a)); reverse(ALL(a));
	// for(auto i:a)cout<<i<<" ";;cout<<"\n";
	if(n>m)swap(n,m);
	// if(n==1){
	// 	ll res=a[0];
	// 	fore(i,0,m)res+=a[i];
	// 	cout<<res*2<<"\n";
	// 	return 0;
	// }
	// cout<<n<<" "<<m<<"\n";
	ll r=0,c=0,res=0;
	while(r*c<n*m){
		res+=a[r*c];
		// cout<<r<<" "<<c<<": "<<r*c<<"\n";
		if(r<c&&r<n)r++;
		else c++;
	}
	// cout<<r<<" "<<c<<" ended\n";
	cout<<res*2<<"\n";
	return 0;
}



/*
bf
124

2 4 5 
6 7 8 
9 10 10 
9 10 10

my
126


*/