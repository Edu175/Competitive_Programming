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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		set<ii>st;
		ll p=0;
		fore(i,0,n)if(a[i]>a[p])p=i;
		fore(i,0,p)st.insert({a[i],i});
		ll i=p-1;
		ll res=0;
		while(SZ(st)){
			ll q=prev(st.end())->snd;
			while(i>=q){
				//cout<<"<- "<<i<<" "<<q<<"\n";
				st.erase({a[i],i});
				res+=a[q];
				i--;
			}
		}
		fore(i,p,n)st.insert({a[i],i});
		i=p;
		while(SZ(st)){
			ll q=prev(st.end())->snd;
			while(i<=q){
				//cout<<"-> "<<i<<" "<<q<<"\n";
				st.erase({a[i],i});
				res+=a[q];
				i++;
			}
		}
		cout<<res<<"\n";
		
	}
	return 0;
}
