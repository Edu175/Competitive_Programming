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
	ll n,m; cin>>n>>m;
	vv a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	vv l(n),r(n),is(n);
	ll j=0;
	fore(i,0,n){
		l[i]=j;
		if(j<m&&a[i]==b[j])is[i]=1,j++;
	}
	j=0;
	reverse(ALL(b));
	for(ll i=n-1;i>=0;i--){
		r[i]=j;
		if(j<m&&a[i]==b[j])j++;
	}
	ll res=0;
	fore(i,0,n)if(is[i]&&l[i]+r[i]>=m)res=1;
	if(res)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
