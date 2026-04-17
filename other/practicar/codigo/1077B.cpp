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

int main(){FIN;
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	ll res=0;
	fore(i,0,n-2){
		if(a[i]&&!a[i+1]&&a[i+2])a[i+2]=0,res++;
	}
	cout<<res<<"\n";
	return 0;
}
