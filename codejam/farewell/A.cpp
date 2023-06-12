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
	ll t; cin>>t;
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		ll n; cin>>n;
		string a[n];
		fore(i,0,n)cin>>a[i];
		sort(ALL(a[0]));
		ll flag=1;
		//cout<<"\n";
		fore(i,1,n){
			ll res=-1,m0=SZ(a[i-1]),m1=SZ(a[i]);
			multiset<char>st;
			for(auto j:a[i])st.insert(j);
			//cout<<i<<":\n";
			fore(j,0,m1+1){
				//cout<<j<<" "<<": ";
				//imp(st);
				if(j==m0){res=j;break;}
				//cout<<a[i-1][j]<<": ";
				auto upp=st.lower_bound(a[i-1][j]+1);
				if(upp!=st.end())res=j;
				//,cout<<".\n";
				auto low=st.lower_bound(a[i-1][j]);
				if(low!=st.end()&&*low==a[i-1][j])st.erase(low);
				else break;
			}
			//cout<<res<<"\n";
			if(res==-1){
				flag=0;
				break;
			}
			//cout<<"reset st\n";
			st.clear(); for(auto j:a[i])st.insert(j);
			a[i].clear();
			//cout<<"l\n";
			fore(j,0,res)a[i].pb(a[i-1][j]),st.erase(st.lower_bound(a[i-1][j]));
			//cout<<"m\n";
			if(res<m0){
				auto upp=st.lower_bound(a[i-1][res]+1);
				a[i].pb(*upp);
				st.erase(upp);
			}
			//cout<<"r\n";
			for(auto j:st)a[i].pb(j);
		}
		if(!flag){
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		cout<<"POSSIBLE\n";
		imp(a);
	}
	return 0;
}
// NO FAREWELL: KEEP GOOGLE COMPETITIONS ALIVE
