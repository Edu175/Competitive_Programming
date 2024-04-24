#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,INF=1e10;

bool has(vector<ll>a){
	fore(i,0,n)if(a[i]<=0)return 1;
	return 0;
}
vector<ll> go(vector<ll>a, ll p=0){
	fore(i,p,SZ(a))a[(i+1)%SZ(a)]-=a[i];
	return a;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>s(2),in(n);
		vector<ll>a(n);
		fore(i,0,n){
			cin>>a[i];
			in[i]=s[i&1]-s[(i+1)&1];
			s[i&1]+=a[i];
		}
		if(a==vector<ll>(n,0)){
			cout<<"0\n\n";
			continue;
		}
		if(has(go(a))){
			a=go(a);
		}
		else {
			ll mn=-1,q=INF;
			fore(i,0,n){
				ll sum=-(s[i&1]-s[(i+1)&1]),
				c=(sum<=0?INF:(a[i]+in[i]+sum-1)/sum);
				if(c<q)mn=i,q=c;
			}
			assert(mn!=-1);
			ll sum=-(s[mn&1]-s[(mn+1)&1]), c=(a[mn]+in[mn]+sum-1)/sum;
			fore(i,0,n){
				if(i<=mn)a[i]+=in[i]+c*(s[mn&1]-s[(mn+1)&1]);
				else a[i]+=(c-1)*(s[mn&1]-s[(mn+1)&1]);
			}
			a=go(a,mn);
		}
		imp(a);
		s=vector<ll>(2,0);
		fore(i,0,n)
	}
	return 0;
}
