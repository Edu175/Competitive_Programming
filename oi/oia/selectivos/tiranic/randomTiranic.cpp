#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
mt19937 rng;
int radar(char borde, int i);
int ask(char borde, int i){return radar(borde,i+1);}
void tiranic(int n, int m, vector<int> &ans) {
	// cerr<<n<<" "<<m<<" n m\n";
	ll w=0;
	vv rows(n),cols(m);
	iota(ALL(rows),0);
	iota(ALL(cols),0);
	while(1){
		ll i,j;
		if(!w){ // rows
			ll idx=rng()%SZ(rows);
			i=rows[idx];
			rows.erase(rows.begin()+idx);
			j=ask('O',i);
		}
		else {
			ll idx=rng()%SZ(cols);
			j=cols[idx];
			cols.erase(cols.begin()+idx);
			i=ask('N',j);
		}
		// cerr<<w<<": "<<i<<","<<j<<"\n";
		if(i!=-1&&j!=-1){
			ans[0]=w?i:ask('N',j);
			ans[1]=ask('E',i);
			ans[2]=ask('S',j);
			ans[3]=!w?j:ask('O',i);
			return;
		}
		w^=1;
	}
}
