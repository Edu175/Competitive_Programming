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
const ll MAXQ=8e6,B=32;

string bin(ll x){
	string s;
	while(x)s.pb('0'+x%2),x/=2;
	s+="b0";
	reverse(ALL(s));
	return s;
}
ll qidx=1;
ll tr[MAXQ][2];
ll p[MAXQ];
ll add(ll x, ll b){
	ll &res=tr[x][b];
	if(res!=-1)return res;
	return res=qidx++;
}
int main(){FIN;
	mset(tr,-1);
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll>xp(n+1);
	fore(i,1,n+1)xp[i]=xp[i-1]^a[i-1];
	fore(i,0,n+1){
		ll x=0;
		for(ll j=B-1;j>=0;j--){
			ll d=(xp[i]>>j)&1;
			x=add(x,d);
		}
		p[x]=xp[i];
	}
	//imp(xp);
	ll res=0;
	fore(i,0,n+1){
		ll x=0;
		//cout<<i<<": "<<bin(xp[i])<<"\n";
		for(ll j=B-1;j>=0;j--){
			ll d=(xp[i]>>j)&1;
			if(tr[x][d^1]!=-1)x=tr[x][d^1];
			else assert(tr[x][d]!=-1),x=tr[x][d];
		}
		//cout<<bin(x)<<" "<<bin(x^xp[i])<<"\n\n";
		res=max(res,p[x]^xp[i]);
	}
	cout<<res<<"\n";
	return 0;
}
