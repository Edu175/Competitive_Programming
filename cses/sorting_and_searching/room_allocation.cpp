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

int main(){FIN;
	ll n; cin>>n;
	vector<ii>a(n);
	vector<vector<ll>>ev;
	fore(i,0,n){
		ll l,r; cin>>l>>r; l--;
		ev.pb({l,1,i});
		ev.pb({r,0,i});
		a[i]={l,r};
	}
	vector<ll>b(n);
	set<ll>st;
	fore(i,0,n)st.insert(i+1);
	ll res=0;
	sort(ALL(ev));
	for(auto sus:ev){
		ll v=sus[0],is=sus[1],i=sus[2];
		//cout<<v<<" "<<is<<" "<<i<<": ";
		//imp(st);
		if(!is)st.insert(b[i]);
		else {
			b[i]=*st.begin();
			st.erase(b[i]);
			res=max(res,b[i]);
		}
	}
	cout<<res<<"\n";
	imp(b);
	return 0;
}

