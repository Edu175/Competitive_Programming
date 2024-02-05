#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

bool cmp(ii a, ii b){
	return a.fst+a.snd>b.fst+b.snd;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst,a[i].fst--;
		fore(i,0,n)cin>>a[i].snd,a[i].snd--;
		sort(ALL(a),cmp);
		ll res=0;
		fore(i,0,n){
			if(i%2==0)res+=a[i].fst;
			else res-=a[i].snd;
		}
		cout<<res<<"\n";
	}
	return 0;
}
