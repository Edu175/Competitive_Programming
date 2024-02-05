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
	ll n,k; cin>>n>>k;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	set<ll>st;
	map<ll,ll>mp;
	ll p=0,res=0;
	fore(i,0,n){
		//cout<<i<<":\n";
		while(p<n&&SZ(st)<=k){
			mp[a[p]]++;
			st.insert(a[p]);
			//cout<<p<<": ";imp(st);
			p++;
		}
		//cout<<p<<"\n\n";
		res+=p-i-(SZ(st)>k);
		mp[a[i]]--;
		if(mp[a[i]]==0)st.erase(a[i]);
	}
	cout<<res<<"\n";
	return 0;
}
