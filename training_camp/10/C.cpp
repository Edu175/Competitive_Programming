#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	char dir[n];
	ll a[n];
	ll flag=0;
	ll res=1e9+5;
	fore(i,0,n)cin>>dir[i];
	fore(i,0,n){
		cin>>a[i];
		if(i&&dir[i]=='L'&&dir[i-1]=='R')res=min(res,(a[i]-a[i-1])/2),flag=1;
	}
	if (flag)pres;
	else cout<<-1;
	return 0;
}
