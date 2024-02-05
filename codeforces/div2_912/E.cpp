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

void voy(set<ll>&st){
	cout<<*st.begin()+1<<endl;
	st.erase(st.begin());
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n==-1)exit(0);
		ll x,y; cin>>x>>y;
		ll s=(x+y)%2;
		vector<ll>a(n);
		set<ll>st[2];
		fore(i,0,n){
			cin>>x>>y;
			a[i]=((x+y)%2)^s;
			st[a[i]].insert(i);
		}
		ll pl=0;
		if(SZ(st[0])>=SZ(st[1]))pl=0,cout<<"First"<<endl;
		else pl=1,cout<<"Second"<<endl;
		fore(i,0,n){
			if(i%2==pl){
				if(!SZ(st[0]))voy(st[1]);
				else if(!SZ(st[1]))voy(st[0]);
				else if(pl==0)voy(st[1]);
				else voy(st[0]);
			}
			else {
				ll j; cin>>j; j--;
				st[a[j]].erase(j);
			}
		}
	}
	return 0;
}
