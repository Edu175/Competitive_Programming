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

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	set<ll>st;
	st.insert(0);
	fore(i,0,n){
		for(auto p=st.begin();p!=st.end();p++){
			//if(*p+a[i]>=*st.end())break;
			//imp(st);
			ll x=*p;
			//cout<<x<<"\n";
			//cout<<"insert\n";
			st.insert(*p+a[i]);
			//imp(st);
			//cout<<"erase\n";
			auto l=st.end();
			l--;
			if(SZ(st)>k+1)st.erase(l);
			//cout<<"lwb\n";
			p=st.lower_bound(x);
		}
	}
	auto l=st.end(); l--;
	cout<<*l<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
