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

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	vector<ll>a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	sort(ALL(a)); sort(ALL(b));
	ll res=0,p=0;
	fore(i,0,n){
		//if(b[p]-a[i]>k)continue;
		while(p<m&&a[i]-b[p]>k)p++;
		if(p>=m)break;
		if(abs(a[i]-b[p])<=k)res++,p++;
	}
	cout<<res<<"\n";
	return 0;
}
