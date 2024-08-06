#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>per;
		per.pb(1);
		fore(i,2,n)per.pb(i);
		reverse(ALL(per));
		// shuffle(ALL(per),rng);
		
		vector<ll>h={rng()%n},vis(n);
		vis[h[0]]=1;
		ll flag=1;
		vector<ii>res;
		for(auto x:per){
			vector<ll>is(x,-1);
			for(auto i:h)is[a[i]%x]=1;
			ii ed={-1,-1};
			fore(i,0,n)if(!vis[i]&&is[a[i]%x]!=-1)
				ed={is[a[i]%x],i};
			if(ed.fst==-1){flag=0;break;}
			h.pb(ed.snd);
			vis[ed.snd]=1;
			res.pb(ed);
		}
		if(!flag){
			cout<<"NO\n";
		}
		else {
			cout<<"YES\n";
			for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
		}
	}
	return 0;
}
