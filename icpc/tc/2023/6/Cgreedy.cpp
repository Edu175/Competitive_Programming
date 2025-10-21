#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll k;

char C(char c, ll sig){
	ll p=c-'a';
	p=(p+sig+k)%k;
	c='a'+p;
	return c;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		string a; cin>>a;
		auto get=[&](ll i)-> char {
			char ret='a'+k+5;
			if(i==n)return ret;
			ret=min({a[i],C(a[i],1),C(a[i],-1)});
			return ret;
		};
		fore(i,0,n){
			if(a[i]=='a')continue;
			if(i+1<n&&a[i+1]=='a'){
				swap(a[i],a[i+1]);
				continue;
			}
			auto L=get(i), R=get(i+1);
			ll mn=min(L,R);
			if(i+2<n&&a[i+2]<mn){
				swap(a[i+1],a[i+2]);
				swap(a[i+1],a[i]);
				a[i+1]=L;
				i+=2;
			}
			else if(L<=R)a[i]=L;
			else {
				assert(i+1<n);
				a[i+1]=a[i];
				a[i]=R;
				i++;
			}
		}
		cout<<a<<"\n";
	}
	return 0;
}
