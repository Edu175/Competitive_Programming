#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll>a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	sort(ALL(a));
	sort(ALL(b));
	ll p=0,res=0,flag=1;
	fore(i,0,m){
		while(p<n&&a[p]<b[i])p++;
		if(p>=n){flag=0;break;}
		res+=a[p++];
	}
	if(!flag)cout<<"-1\n";
	else cout<<res<<"\n";
	return 0;
}
