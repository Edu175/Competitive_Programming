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

ull ord(ull a){
	assert(a>1);
	ll res=1,pot=a;
	while(pot!=1)res+=res,pot*=pot;
	return res;
}
ull fpow(ull a, ll b){
	ull r=1;
	while(b){if(b&1)r*=a; b>>=1; a*=a;}
	return r;
}
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
		if(a==1){
			cout<<"broken message\n";
			continue;
		}
		cerr<<ord(a)<<" "<<ord(b)<<"\n";
		ll x=ord(a)-ord(b);
		ll good=0;
		if(x>=0){
			ull num=fpow(a,x);
			if(num==b)good=1;
			cout<<x<<" "<<num<<" x num\n";
		}
		else cout<<"<0\n";
		if(!good)cout<<"broken message\n";
		else cout<<x<<"\n";
	}
	return 0;
}
