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

bool cmp(ii a, ii b){
	return a.snd<b.snd;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	sort(ALL(a),cmp);
	ll res=0,e=0;
	for(auto [l,r]:a){
		if(l>=e)res++,e=r;
	}
	cout<<res<<"\n";
	return 0;
}
