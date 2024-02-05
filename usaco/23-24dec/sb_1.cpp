#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,usaco=b;i<usaco;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

/*ll eval(ll x, ii a){
	return x*a.fst+a.snd;
}

ll tech(ll a, ll b){
	if(a<0&&b<0)a=-a,b=-b;
	if(b==0)return -1;
	return a/b+1;
}

ll in(ii a, ii b){
	return tech(b.snd-a.snd,a.fst-b.fst);
}

const ll V=5e3;*/

int main(){FIN;
	ll __; cin>>__;
	while(__--){
		//cout<<"====================\n";
		ll n; cin>>n;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].snd;
		fore(i,0,n)cin>>a[i].fst;
		vector<ll>p(n);
		fore(i,0,n)cin>>p[i],p[i]=n-1-p[i];
		if(n==1){cout<<"0\n";continue;}
		if(p[0])swap(a[0],a[1]);
		if(a[0].snd<a[1].snd)cout<<"0\n";
		else {
			if(a[1].fst<=a[0].fst){
				cout<<"-1\n";
				continue;
			}
			cout<<(a[0].snd-a[1].snd)/(a[1].fst-a[0].fst)+1<<"\n";
		}
	}
	return 0;
}
