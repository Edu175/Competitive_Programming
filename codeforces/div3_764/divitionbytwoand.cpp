#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n; vector<ll>v(n);
		fore(i,0,n){
			cin>>v[i];
			while(v[i]>n)v[i]/=2;
		}
		/*for(auto i:v)cout<<i<<" ";
		cout<<"\n";*/
		ll x=0;
		fore(i,0,n){
		fore(i,0,n){
			if(v[i]==0){
				cout<<"NO\n";
				x=1;
				break;
			}
			if(count(ALL(v),v[i])>1)v[i]/=2;
			/*if(v[i]==0){
				cout<<"NO\n";
			}*/
		}if(x){
			break;
		}
		}if(x){
			continue;
		}
		cout<<"YES\n";
	}
	 return 0;
}

