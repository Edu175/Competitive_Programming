#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a(n);
		ll c=2*(n-1);
		fore(i,0,n)cin>>a[i];
		if(n==1){
			if(a[0]>0)cout<<"NO\n";
			else {
				cout<<"YES\n";
			}
			continue;
		}
		vv fr;
		fore(i,0,n){
			if(a[i]==-1){
				fr.pb(i);
				continue;
			}
			if(a[i]==0)a[i]+=m;
			c-=a[i];
		}
		ll good=c>=0;
		if(!SZ(fr)&&good&&c>0){
			good&=c%m==0;
			a[0]+=c;
		}
		fore(i,0,SZ(fr)){
			if(i==SZ(fr)-1){
				good&=c>=1;
				a[fr[i]]=c;
			}
			else {
				a[fr[i]]=1;
				c--;
			}
		}
		if(!good){
			cout<<"NO\n";
			continue;
		}
		queue<ll> u,q;
		vector<ii> sa;
		fore(i,0,n)sa.pb({a[i],i});
		sort(ALL(sa));
		for(auto [val,i]:sa){
			if(val==1)u.push(i);
			else q.push(i);
		}
		vector<ii> ed;
		while(SZ(u)){
			auto x=u.front(); u.pop();
			if(SZ(q)){
				auto y=q.front();
				ed.pb({x,y});
				a[x]--; a[y]--;
				if(a[y]==1)q.pop(),u.push(y);
			}
			else {
				assert(SZ(u)==1);
				ll y=u.front(); u.pop();
				assert(a[y]==1);
				ed.pb({x,y});
				a[x]--; a[y]--;
			}
		}
		cout<<"YES\n";
		for(auto [x,y]:ed)cout<<x+1<<" "<<y+1<<"\n";
	}
	return 0;
}