#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size)
#define ALL(x) x.begin(),x.end
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

bool check(vector<ll>a){ //SZ(p)=3
	ll x=-a[0];
	a[0]+=x; a[1]-=x; a[2]+=x;
	return (!a[0]&&!a[1]&&!a[2]);
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	ll s[6]={};
	ll a[n],b[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i],s[i%6]+=a[i]-b[i];
	fore(_,0,q+1){
		if(_){
			ll l,r,x; cin>>l>>r>>x; l--;
			//upd s
			//cout<<_<<": ["<<l<<","<<r<<")\n";
			for(;l<r&&l%6!=0;l++)s[l%6]+=x;
			//cout<<"["<<l<<","<<r<<")\n";
			fore(i,0,6)s[i]+=x*(((r-l)/6)+(i<(r-l)%6));
			//,cout<<i<<"+="<<x<<"*"<<(((r-l)/6)+(i<(r-l)%6))<<"\n";
		}
		//imp(s);
		vector<ll>p(3);
		fore(i,0,3)p[i]=s[i]-s[i+3];
		if(check(p))cout<<"YES\n";
		else cout<<"NO\n";
		//cout<<"\n";
	}
	return 0;
}
