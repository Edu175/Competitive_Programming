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
	ll res=n;
	ll div=n+1;
	bool flag=0;
	for(ll i=2;i<n+1;i++){
		//cout<<i<<" ";
		if(n%i==0){
			//cout<<"yes\n";
			div=min(div,i);
			ll count=0;
			while(n%i==0)n/=i,count++;
			if(count%2)flag=1;
		}
	}
	if(flag)pres;
	else cout<<res/div;
	return 0;
}
