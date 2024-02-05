#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll pot[19];
ll ones(ll n){// > 0
	n++;
	string s=to_string(n);
	reverse(ALL(s));
	ll res=0;
	fore(i,0,SZ(s)){
		if(i)res+=pot[i-1]*i*(s[i]-'0');
		if(s[i]>'1')res+=pot[i];
		if(s[i]=='1')res+=(n%pot[i+1])-pot[i];
	}
	return res;
}

int main(){FIN;
	pot[0]=1;
	fore(i,1,19)pot[i]=pot[i-1]*10;
	//cout<<ones(1000000000000000000);
	
	ll n; cin>>n;
	ll l=1,r=1e18;
	while(l<=r){
		ll m=(l+r)/2;
		if(ones(m)<=n)l=m+1;
		else r=m-1;
	}
	cout<<r<<"\n";
	return 0;
}
