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
		ll n;cin>>n;vector<ll>v(n);
		vector<ll>res;
		fore(i,0,n)cin>>v[i];
		//while(SZ(v)){
			set<ll>st;
			fore(i,0,SZ(v))st.insert(v[i]);
			ll temp=-1;
			ll c;
			for(auto i:st){
				if(i-temp==1)temp=i,c++;
				else break;
			}
			set<ll> sy;
			fore(i,0,c)sy.insert(i);
			res.pb(c);
			ll p;
			for(ll i=0;i<SZ(v)||SZ(sy);i++)sy.erase(v[i]),p=i;
			//cout<<p<<"\n";
			//v.erase(v.begin(),v.begin()+p);
			//fore(i,0,p+1)v.erase(v.begin());
			cout<<p<<"\n";
			for(auto i:v)cout<<i<<" ";
			cout<<"\n";
		//}
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	 return 0;
}
