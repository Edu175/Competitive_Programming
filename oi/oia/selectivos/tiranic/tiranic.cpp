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

int radar(char borde, int i);
int ask(char borde, int i){return radar(borde,i+1);}
void tiranic(int n, int m, vector<int> &ans) {
	// cerr<<n<<" "<<m<<" n m\n";
	ll h=0,w=0,val=n+m;
	fore(i,0,n+1){
		ll j=i?99/i:m;
		ll cur=n/(i+1) + m/(j+1);
		if(cur<val)h=i,w=j,val=cur;
	}
	// cerr<<val<<"\n";
	// cerr<<h<<" "<<w<<": "<<val<<"\n";
	h++,w++;
	vv rows; for(ll i=h-1;i<n;i+=h)rows.pb(i);
	vv cols; for(ll j=w-1;j<m;j+=w)cols.pb(j);
	ll t=0;
	while(1){
		ll i,j;
		assert(SZ(rows)||SZ(cols));
		if(!t&&!SZ(rows))t=1;
		if(t&&!SZ(cols))t=0;
		if(!t){ // rows
			i=rows.back(); rows.pop_back();
			j=ask('O',i);
		}
		else {
			j=cols.back(); cols.pop_back();
			i=ask('N',j);
		}
		// cerr<<w<<": "<<i<<","<<j<<"\n";
		if(i!=-1&&j!=-1){
			ans[0]=t?i:ask('N',j);
			ans[1]=ask('E',i);
			ans[2]=ask('S',j);
			ans[3]=!t?j:ask('O',i);
			// cerr<<"found "<<i<<","<<j<<"\n";
			return;
		}
		t^=1;
	}
}
