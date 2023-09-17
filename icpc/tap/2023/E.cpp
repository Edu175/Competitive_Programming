#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef __int128 ll;
typedef long long LL;
typedef pair<ll,ll> ii;

const ll MAXV=1e5+5;

vector<ll>divs[MAXV];
void divisores(){
	fore(i,1,MAXV)for(int j=i;j<MAXV;j+=i)divs[j].pb(i);
}

ll fs(ll a0, ll d, ll n){
	return (a0+a0+d*(n-1))*n/2;
}

ll fn(ll a0, ll d, ll s){
	ll l=0,r=1e5+5;
	while(l<=r){
		ll m=(l+r)/2;
		if(fs(a0,d,m)<s)l=m+1;
		else r=m-1;
	}
	if(fs(a0,d,l)!=s)return -1;
	return l;
}
ll an(ll a0, ll d, ll n){
	return a0+d*(n-1);
}



int main(){FIN;
	divisores();
	LL a,s,l,r; cin>>a>>s>>l>>r;
	if(s<a){
		cout<<"0\n";
		return 0;
	}
	if(s==a){
		cout<<"1\n";
		return 0;
	}
	LL res=0;
	fore(a0,l,a){
		vector<ll> D=divs[a-a0];
		for(auto d:D){
			ll n=fn(a0,d,s);
			//cout<<a0<<" "<<d<<" "<<n<<": ";
			//if(n!=-1)cout<<an(a0,d,n)<<"\n";
			//else cout<<"-\n";
			if(n!=-1&&an(a0,d,n)<=r&&an(a0,d,n)>=a)res++;
		}
	}
	fore(d,1,1e5+5){
		ll n=fn(a,d,s);
		//cout<<a<<" "<<d<<" "<<n<<": ";
		//if(n!=-1)cout<<an(a,d,n)<<"\n";
		//else cout<<"-\n";
		if(n!=-1&&an(a,d,n)<=r&&an(a,d,n)>=a)res++;
	}
	cout<<res<<"\n";
	return 0;
}
