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
		string s; cin>>s;
		string a;
		fore(i,0,n){
			if(s[i]=='a'||s[i]=='e')a.pb('V');
			else a.pb('C');
		}
		vector<ll>p(n+1);
		ll pos=0;
		while(pos<n){
			if(n-pos<=3)break;
			if(a[pos+3]=='C')pos+=3;
			else pos+=2;
			p[pos]=1;
		}
		fore(i,0,n){
			if(p[i])cout<<".";
			cout<<s[i];
		}
		cout<<"\n";
	}
	return 0;
}
