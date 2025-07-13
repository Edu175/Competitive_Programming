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
	ll t; cin>>t;
	while(t--){
		ll m,k; cin>>m>>k;
		vv res={};
		if(m==k)res=vv(m),iota(ALL(res),0);
		else if(k&1)res=vv(k/2+1),iota(ALL(res),0);
		else if(k>=6)res=vv(k/2),iota(res.begin()+1,res.end(),2);
		else if(k==2){
			if(m%2==0)res={0,m/2};
		}
		else { assert(k==4);
			if(m%4==0)res={0,m/4,m/2};
			// if(m%3==0)res={0,m/3,2*m/3}; // does k=3
		}
		if(!SZ(res))cout<<"No\n";
		else {
			cout<<"Yes\n"<<SZ(res)<<"\n";
			imp(res)
		}
	}
	return 0;
}
