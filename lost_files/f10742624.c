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
	if(n<=3){
		if(n==1)cout<<1<<"\n";
		else cout<<"NO SOLUTION\n";
		return 0;
	}
	for(int i=2;i<=n;i+=2){
		cout<<i<<" ";
	}
	for(int i=1;i<=n;i+=2){
		cout<<i<<" ";
	}
	return 0;
}
