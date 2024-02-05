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
	ll n,q; cin>>n>>q;
	vector<ll>a(n),p(n);
	fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
	ll res=1;
	fore(i,1,n){
		res+=p[i]<p[i-1];
	}
	while(q--){
		ll i,j; cin>>i>>j; i--,j--;
		ll x=a[i],y=a[j];
		if(x)res-=p[x]<p[x-1];
		if(x<n-1)res-=p[x+1]<p[x];
		if(y&&y!=x+1)res-=p[y]<p[y-1];
		if(y<n-1&&y+1!=x)res-=p[y+1]<p[y];
		swap(a[i],a[j]);
		swap(p[x],p[y]);
		if(x)res+=p[x]<p[x-1];
		if(x<n-1)res+=p[x+1]<p[x];
		if(y&&y!=x+1)res+=p[y]<p[y-1];
		if(y<n-1&&y+1!=x)res+=p[y+1]<p[y];
		//imp(a); imp(p);
		cout<<res<<"\n";
	}
	return 0;
}
