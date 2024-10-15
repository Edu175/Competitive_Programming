#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;

int main(){ET
	string s; cin>>s;
	ll n=SZ(s);
	vector<ll>pr(2*n);
	for(ll i=2*n-1;i>=0;i--){
		ll cur=2*n;
		if(s[i%n]=='E')cur=i;
		pr[i]=cur;
		if(i<2*n-1)pr[i]=min(pr[i],pr[i+1]);
	}
	ll k; cin>>k;
	ll res=0;
	fore(i,0,n){
		ll q=i+k-pr[i];
		if(q>=0)res+=q;
	}
	cout<<res<<"\n";
}