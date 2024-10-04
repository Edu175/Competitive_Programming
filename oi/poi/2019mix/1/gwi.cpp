#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,skopul=b;i<skopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,s; cin>>n>>s;
	s--;
	vector<ll>dif;
	vector<ll>dir;
	ll pi=n,pd=n;
	ll res=0;
	fore(i,0,n-1){
		ll l,r; cin>>l>>r;
		if(l<r)dir.pb(0),pi=min(pi,i);
		else dir.pb(1),pd=min(pd,i);
		dif.pb(abs(l-r));
		res+=min(l,r);
	}
	// cout<<res<<"\n";
	if(pi>n-s-1){
		ll mn=dif[0],p=0;
		fore(i,0,n-s){
			mn=min(mn,dif[i]);
			if(mn==dif[i])p=i;
		}
		dir[p]^=1;
		res+=mn;
	}
	if(pd>s){
		ll mn=dif[0],p=0;
		fore(i,0,s+1){
			mn=min(mn,dif[i]);
			if(mn==dif[i])p=i;
		}
		dir[p]^=1;
		res+=mn;
	}
	vector<ii>go;
	ll q=0;
	fore(i,0,n-1){
		q++;
		if(i==n-2||dir[i]!=dir[i+1])go.pb({dir[i],q}),q=0;
	}
	ll l=0,r=n-1;
	vector<ll>ans={s};
	for(auto [d,q]:go){
		vector<ll>ansi;
		if(d){
			while(q--){
				if(r==s)r--;
				ansi.pb(r--);
			}
		}
		else {
			while(q--){
				if(l==s)l++;
				ansi.pb(l++);
			}
		}
		reverse(ALL(ansi));
		for(auto i:ansi)ans.pb(i);
	}
	cout<<res<<"\n";
	for(auto i:ans)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}