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

ll po(vector<ll>a){
	sort(ALL(a));
	ll sum=0;
	fore(i,1,SZ(a)-1)sum+=a[i];
	return sum;
}

int main(){FIN;
	ll n,x; cin>>n>>x;
	vector<ll>a(n-1);
	fore(i,0,n-1)cin>>a[i];
	fore(p,0,101){
		vector<ll>ai=a;
		ai.pb(p);
		if(po(ai)>=x){
			cout<<p<<"\n";
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}
