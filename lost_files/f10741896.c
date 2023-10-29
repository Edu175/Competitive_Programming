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
	ll x,a,d,n;
	cin>>x>>a>>d>>n;
	ll l=min(a,a+d*(n-1));
	ll r=max(a,a+d*(n-1));
	ll res;
	if(!d)res=abs(x-a);
	else{
		if(x>=l&&x<=r){
			res=abs((x-a)%d);
			//pres;
			res=min(res-0,abs(d)-res);
		}
		if(x<l)res=abs(l-x);
		if(x>r)res=abs(x-r);
	}
	pres;
	return 0;
}
