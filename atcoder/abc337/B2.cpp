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
	string s; cin>>s;
	/*string t=s;
	sort(ALL(t));*/
	ll flag=1;
	fore(i,0,SZ(s)-1)if(s[i+1]<s[i])flag=0;
	if(flag)cout<<"Yes\n";
	else cout<<"N0\n";
	return 0;
}
