#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
vector<string> days={"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
int main(){FIN;
	string a,b,c,d; cin>>a>>b>>c>>d;
	ll l=find(ALL(days),a)-days.begin();
	ll r=find(ALL(days),c)-days.begin();
	ll res=(r-l)*24*60;
	ll lm=stoll(b.substr(0,2));
	ll rm=stoll(d.substr(0,2));
	res+=(rm-lm)*60;
	ll ls=stoll(b.substr(3));
	ll rs=stoll(d.substr(3));
	res+=(rs-ls);
	if(res<=0)res+=7*24*60;
	vv ts;
	ts.pb(res%60); res/=60;
	ts.pb(res%24); res/=24;
	ts.pb(res);
	reverse(ALL(ts));
	ll cnt=0;
	for(auto i:ts)cnt+=i>0;
	ll q=0;
	vector<string> comp={"days","hours","minutes"};
	fore(i,0,3){
		ll t=ts[i];
		if(!t)continue;
		if(q){
			if(cnt==2)cout<<" and ";
			else cout<<", ";
		}
		string cur=comp[i];
		if(t==1)cur.pop_back();
		cout<<t<<" "<<cur;
		q++;
	}
	cout<<"\n";
	return 0;
}
