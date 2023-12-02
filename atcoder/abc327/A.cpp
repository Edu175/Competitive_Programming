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
	ll flag=0;
	ll n; cin>>n;
	string s; cin>>s;
	fore(i,0,n-1)if((s[i]=='a'&&s[i+1]=='b')||(s[i]=='b'&&s[i+1]=='a'))flag=1;
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
