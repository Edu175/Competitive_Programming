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

bool cmp(ll a, ll b){
	ii c={a%2,a},d={b%2,b};
	return c<d;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x,y; cin>>n>>x>>y;
		vector<ll>a(x),d;
		fore(i,0,x)cin>>a[i];
		sort(ALL(a));
		ll res=x-2;
		fore(i,0,x){
			ll dif=(a[(i+1)%x]-a[i]+n)%n;
			if(dif>1)d.pb(dif);
		}
		sort(ALL(d),cmp);
		ll old=res;
		for(auto v:d){
			ll c=min(y,(v-1)/2);
			//cout<<v<<" "<<y<<" , "<<c<<": ";
			res+=2*c;
			y-=c;
			if(v%2==0&&c>=(v-1)/2)res++;//,cout<<"++";
			//	cout<<res-old<<"\n";
			//	old=res;
		}
		cout<<res<<"\n";
	}
	return 0;
}
