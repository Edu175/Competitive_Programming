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

template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll k; cin>>k;
		string a; cin>>a;
		ll n=SZ(a);
		vector<pair<char,ll>>st;
		ll p[n]; // ) -->
		mset(p,-1);
		fore(i,0,n){
			/*cout<<i<<": ";
			for(auto j:st)cout<<j.fst<<","<<j.snd<<" ";
			cout<<"\n";*/
			if(a[i]==')'&&SZ(st)&&st.back().fst=='(')p[i]=st.back().snd,st.pop_back();
			else st.pb({a[i],i});
		}
		vector<ll>b;
		fore(i,0,n)if(p[i]!=-1)b.pb((abs(i-p[i])-1)/2);
		sort(ALL(b)); reverse(ALL(b));
		ll res=0;
		fore(i,k,SZ(b))res+=b[i];
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
