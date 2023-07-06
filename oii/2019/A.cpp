#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	string s; cin>>s;
	ll n=SZ(s);
	vector<ii>a;
	ll c=0,fl=0;
	fore(i,0,n){
		if(s[i]=='x')c++,fl=1;
		else {
			if(c)a.pb({c,(s[i]=='p')});
			c=0;
		}
	}
	if(c)a.pb({c,0});
	if(!fl){
		cout<<"1\n"<<s<<"\n";
		return 0;
	}
	ll e=2*n;
	for(auto i:a)e=min(e,__builtin_ctzll(i.fst)+i.snd);
	cout<<e<<"\n";
	if(e==0){
		cout<<"NOSTRING\n";
		return 0;
	}
	string b1,b2; //g¹(s),g^e(s)
	ll k=1ll<<1;
	fore(i,0,n){
		b1.pb(s[i]);
		if(s[i]=='x'){
			if(i+1<n&&s[i+1]=='p')b1[SZ(b1)-1]='$';
			i++;
		}
	}
	k=1ll<<e;
	fore(i,0,n){
		b2.pb(s[i]);
		if(s[i]=='x'){
			ll p=i+(1ll<<(e-1));
			if(p<n&&s[p]=='p')b2[SZ(b2)-1]='$',i+=1ll<<(e-1);
			else i+=(1ll<<e)-1;
		}
	}
	cout<<min(b1,b2)<<"\n";
	return 0;
}
