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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),pre(n),suf(n);
		fore(i,0,n){
			cin>>a[i];
		}
		set<ll>st;
		fore(i,0,n+1)st.insert(i);
		fore(i,0,n){
			st.erase(a[i]);
			pre[i]=*st.begin();
		}
		fore(i,0,n+1)st.insert(i);
		for(ll i=n-1;i>=0;i--){
			st.erase(a[i]);
			suf[i]=*st.begin();
		}
		ll p=-1;
		fore(i,0,n-1){
			if(pre[i]==suf[i+1])p=i;
		}
		if(p==-1)cout<<"-1\n";
		else {
			cout<<"2\n1 "<<p+1<<"\n"<<p+2<<" "<<n<<"\n";
		}
	}
	return 0;
}
