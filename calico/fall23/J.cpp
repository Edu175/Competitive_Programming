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

ll put(multiset<ll>&st, ll x){
	auto it=st.find(x);
	if(it!=st.end())st.erase(it);
	return x;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		vector<ll>a(36);
		multiset<ll>st;
		fore(i,0,36)cin>>a[i],st.insert(a[i]);
		sort(ALL(a));
		ll did=0;
		fore(x1,2,31)fore(x2,x1+1,31)fore(x3,x2+1,31)fore(x4,x3+1,31){
			if(did)break;
			ll h[6][6];
			multiset<ll>sti=st;
			h[0][0]=put(sti,a[0]);
			h[0][1]=put(sti,a[1]);
			h[0][2]=put(sti,a[x1]);
			h[0][3]=put(sti,a[x2]);
			h[0][4]=put(sti,a[x3]);
			h[0][5]=put(sti,a[x4]);
			fore(i,1,6){
				h[i][0]=put(sti,*sti.begin());
				fore(j,1,6)h[i][j]=put(sti,h[i][j-1]+h[i-1][j]-h[i-1][j-1]);
			}
			if(!SZ(sti)){
				vector<ll>c(6),d(6);
				c[0]=1;
				d[0]=h[0][0]-c[0];
				fore(i,1,6)d[i]=d[i-1]+h[0][i]-h[0][i-1];
				fore(i,1,6)c[i]=c[i-1]+h[i][0]-h[i-1][0];
				imp(c);
				imp(d);
				did=1;
				break;
			}
		}
		if(!did)cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
