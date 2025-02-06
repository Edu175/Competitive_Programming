#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		vv c(2);
		fore(i,0,n){
			char a=s[i],b=s[(i+1)%n];
			if(a==b)c[a=='B']++;
		}
		if(c[1]){
			for(auto &i:s){
				if(i=='R')i='B';
				else i='R';
			}
		}
		ll flag=!(c[0]&&c[1]);
		c[0]=c[1]=0;
		ll q=0,did=0;
		vv vis(n);
		fore(i,0,3*n+5){
			q++; ll p=i%n;
			if(s[p]!=s[(i+1)%n]){
				if(did&&!vis[p]&&s[p]=='R')c[q&1]++,vis[p]=1;
				did=1;
				q=0;
			}
		}
		if(c[0]+c[1]<=1)flag&=1;
		else if(c[0]==1)flag&=1;
		else flag&=0;
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
