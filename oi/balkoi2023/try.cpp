#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,balkoi=b;i<balkoi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdkj:v)cout<<sdkj<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

bool lis(vector<ll>&a){
	vector<ll>v;
	for(auto x:a){
		x=-x;
		ll p=lower_bound(ALL(v),x)-v.begin();
		if(p>=2)return 0;
		if(p>=SZ(v))v.pb(x);
		else v[p]=x;
	}
	return 1;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	/*vector<ll>p;
	fore(i,0,n)p.pb(i);
	set<vector<ll>>res;
	do{
		if(lis(p))res.insert(p);
	}
	while(next_permutation(ALL(p)));*/
	ll q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r; l--;
		vector<ll>b,c;
		fore(i,0,n){
			if(l<=i&&i<r)b.pb(a[i]);
			else c.pb(a[i]);
		}
		sort(ALL(c));
		ll res=0;
		do{
			vector<ll>d=b;
			for(auto i:c)d.pb(i);
			res+=lis(d);
		}
		while(next_permutation(ALL(c)));
		cout<<res<<"\n";
	}
	//cout<<SZ(res)<<"\n";
	//for(auto i:res){imp(i);}
	return 0;
}
