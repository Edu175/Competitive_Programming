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
const ll MAXN=2e5+5;
ll n,m,k;
ll c[MAXN],a[2*MAXN];
ll cost(ll x){
	return min(k,c[x]);
}
set<ll>st;
multiset<ll>ms;
ll res=0,r=0;
void go(ll i){
	while(r<n+i&&SZ(st)<m){
		if(!st.count(a[r]))st.insert(a[r]),res+=cost(a[r]);
		ms.insert(a[r]);
		r++;
	}
}

int main(){FIN;
	cin>>n>>m>>k;
	fore(i,0,n){
		cin>>a[i];
		a[i+n]=a[i];
		c[a[i]]++;
	}
	go(0);
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
