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
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ull a,b; cin>>a>>b;
		if(b==1){
			cout<<"0\n";
			continue;
		}
		if(a%2==0||b%2==0){
			ull pot=1;
			ll res=-1;
			fore(i,0,67){
				if(pot==b){res=i;break;}
				pot=pot*a;
			}
			if(res==-1)cout<<"broken message\n";
			else cout<<res<<"\n";
			continue;
		}
		ull x=0,ax=1,ord=1,pord=a;
		bool bad=0;
		fore(k,1,64){
			auto m=[&](ull x){
				if(k+1==64)return x;
				return x&((1ull<<(k+1))-1);
			};
			// ull mod=1ull<<(k+1);
			if(m(pord)!=1){
				// cerr<<k<<": "<<ord<<" "<<pord<<": "<<m(pord)<<"=="<<(1ull<<k)+1<<"\n";
				assert(m(pord)==(1ull<<k)+1);
				if(m(ax)!=m(b)){ // uso los ord pord viejos
					ax*=pord;
					x+=ord;
				}
				pord*=pord;
				ord+=ord;
			}
			assert(m(pord)==1);
			if(m(ax)!=m(b)){
				bad=1;
				break;
			}
		}
		if(bad)cout<<"broken message\n";
		else cout<<x<<"\n";
	}
	return 0;
}
