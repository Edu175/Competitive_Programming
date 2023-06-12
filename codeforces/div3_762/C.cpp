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

ll pot10(ll x){
	ll res=1;
	fore(i,0,x)res*=10;
	return res;
}

ll dig(ll x,ll a){
	return (a/pot10(x))%10;
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,s; cin>>a>>s;
		ll flag=1;
		ll b=0;
		for(ll i=0,j=0,ji=0; j<=ll(log10(s)) || i<=ll(log10(a)); i++,j++){
			ll num=dig(i,a);
			ll num1=dig(j,s);
			ll num2=dig(j,s)+dig(j+1,s)*10;
			if(num1-num>=0)b+=(num1-num)*pot10(j-ji);
			else if(num2-num<10&&num2-num>=0)b+=(num2-num)*pot10(j-ji), j++,ji++;
			else flag=0;
			//cout<<num<<" "<<num1<<" "<<num2<<" "<<b<<"\n";
		}
		if(flag)cout<<b<<"\n";
		else cout<<-1<<"\n";
	}
	return 0;
}
