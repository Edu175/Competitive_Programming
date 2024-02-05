#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) cout<<"{ "; for(auto edu:v)cout<<edu<<" "; cout<<"} "
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	vector<ll>a(n);
	fore(i,0,n){
		cin>>a[i];
	}
	cout<<res<<"\n";
	fore(i,1,n){
		//cout<<i<<": ";imp(ms); imp(st); cout<<r<<" "<<res<<endl;
		ms.erase(ms.find(a[i-1]));
		if(ms.count(a[i-1])==0)st.erase(a[i-1]),res-=cost(a[i-1]);
		go(i);
		cout<<res<<"\n";
	}
	return 0;
}
