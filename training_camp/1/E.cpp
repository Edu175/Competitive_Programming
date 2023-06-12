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

int main(){FIN;
	ll n; ll k; cin>>n>>k;
	bool a[n][k];
	bool allz=0;
	bool flag=0;
	set<vector<ll>>st;
	fore(i,0,n){
		vector<ll>vi(k);
		fore(j,0,k){
			cin>>a[i][j];
			vi[j]=a[i][j];
			if(a[i][j])allz=1;
		}
		st.insert(vi);
		if(!allz)flag=1;
		else allz=0;
	}
	for(auto i:st){
		for(auto j:st){
			bool flagi=1;
			fore(h,0,k){
				if(i[h])if(j[h])flagi=0;
			}
			if(flagi)flag=1;
		}
	}
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
