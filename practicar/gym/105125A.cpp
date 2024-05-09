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
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>c(n);
		//m par
		fore(i,0,m){
			set<ll>st;
			fore(i,0,3){
				ll x; cin>>x; x--;
				st.insert(x);
			}
			for(auto x:st)c[x]^=1;
		}
		if(m&1){
			cout<<"YES\n";
			fore(i,0,n)cout<<"1 ";;cout<<"\n";
			continue;
		}
		vector<ll>res(n,1);
		ll flag=0;
		fore(i,0,n)if(c[i]){
			flag=1;
			res[i]=0;
			break;
		}
		if(flag){
			cout<<"YES\n";
			imp(res);
		}
		else cout<<"NO\n";
	}
	return 0;
}

