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
	ll n;cin>>n;
	set<ll>st;
	fore(i,0,n){
		ll x;
		cin>>x;
		st.insert(x);
	}
	cout<<SZ(st)<<"\n";
	for(auto i:st)cout<<i<<" ";
	cout<<"\n";
	st.erase(5);
	cout<<SZ(st)<<"\n";
	for(auto i:st)cout<<i<<" ";
	cout<<"\n";
	if(st.count(3))cout<<"HAY UN TRES"<<"\n";
	 return 0;
}
