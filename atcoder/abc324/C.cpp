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
	ll n; cin>>n;
	string s; cin>>s;
	string a[n];
	vector<ll>res;
	ll m=SZ(s);
	fore(i,0,n){
		cin>>a[i];
		if(SZ(a[i])==m){
			ll c=0;
			fore(j,0,m){
				if(s[j]!=a[i][j])c++;
			}
			if(c<=1)res.pb(i);
		}
		else if(SZ(a[i])==m-1){
			ll p=0,c=0;
			fore(j,0,m){
				if(s[j]!=a[i][p])c++;
				else p++;
			}
			if(c<=1)res.pb(i);
		}
		else if(SZ(a[i])==m+1){
			ll p=0,c=0;
			fore(j,0,m){
				if(p>=SZ(a[i]))break;
				if(s[j]!=a[i][p])c++,j--;
				p++;
			}
			if(c<=1)res.pb(i);
		}
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i+1<<" ";; cout<<"\n";
	return 0;
}
