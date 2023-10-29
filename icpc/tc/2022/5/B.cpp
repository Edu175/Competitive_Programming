#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
typedef pair<pair<ll,ll>,pair<ll,ll>>lado;

int main(){FIN;
	ll w,h,n; cin>>w>>h>>n;
	set<lado>st;
	fore(i,0,n){
		pair<ll,ll> s,e;
		cin>>s.fst>>s.snd<<e.fst<<e.snd;
		st.insert(min(s,e),max(s,e));
	}
	vector<ll>res;
	return 0;
}
