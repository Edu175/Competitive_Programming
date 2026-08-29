#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool check(string s){
	ll c=0;
	for(auto i:s){
		if(i=='(')c++;
		else c--;
		if(c<0)return 0;
	}
	return c==0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string a,b; cin>>a>>b;
		ll od=0;
		fore(i,0,n)if(a[i]!=b[i]){
			if((a[i]>b[i])^od)swap(a[i],b[i]);
			od^=1;
		}
		if(check(a)&&check(b))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
