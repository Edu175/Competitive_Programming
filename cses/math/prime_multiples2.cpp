#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef unsigned long long ll;

int main(){FIN;
	ll n,k;cin>>k>>n;
	vector<ll> a; 
	set<ll>st;
	ll res=0;
	fore(i,0,n){
		ll x; cin>>x;
		if(x==-1)
		if(!st.count(x))a.pb(x),st.insert(x);
	}
	n=SZ(a);
	sort(ALL(a));
	ll prod=1;
	for(auto i:a)prod*=i,res+=k/prod;
	pres;
	return 0;
}
