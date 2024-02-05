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
const ll MAXN=105;

ll a[MAXN];
ll n;

bool can(ll k){
	ll l=0,r=n-1;
	fore(i,0,k){
		while(r>=l&&a[r]>k-i)r--;
		if(l<=r)r--;
		else return 0;
		l++;
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		ll res=0;
		fore(i,0,n+3){
			if(can(i))res=max(res,i);
		}
		cout<<res<<"\n";
	}
	return 0;
}
