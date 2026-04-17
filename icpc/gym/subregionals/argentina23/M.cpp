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
typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld;

vector<ld>a[2];
ld v[2];
ld p[2]={},m[2]={},s=0;

ld vel(ll w){
	return v[w]/(SZ(a[w])-p[w]);
}

ld sec(ll w){
	return (a[w][p[w]]-m[w])/vel(w);
}

int main(){FIN;
	ll n,t; cin>>n>>t;
	fore(i,0,n){
		char c; cin>>c;
		ll x; cin>>x;
		a[c=='N'].pb(x);
	}
	fore(i,0,2)sort(ALL(a[i]));
	v[0]=(ld)t*(3.0/4.0); v[1]=(ld)t*(1.0/4.0);
	cout<<fixed<<setprecision(15);
	while(p[0]<SZ(a[0])||p[1]<SZ(a[1])){
		ll w=0,flag=0;
		fore(i,0,2){
			if(p[i]==SZ(a[i])){
				w=i^1;
				v[i^1]=t;
				flag=1;
			}
		}
		if(!flag&&sec(1)<sec(0))w=1;
		//cout<<s<<":\n";
		//imp(p);
		//cout<<w<<"\n";
		ld add=sec(w);
		if(!flag)fore(i,0,2)m[i]+=add*vel(i);
		else m[w]+=add*vel(w);
		p[w]++;
		s+=add;
		//cout<<add<<"\n\n";
	}
	cout<<s<<"\n";
	return 0;
}
