#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<vv>col(m,vv(26)),row(n,vv(26));
	fore(i,0,n)fore(j,0,m){
		char c; cin>>c;
		row[i][c-'A']++;
		col[j][c-'A']++;
	}
	priority_queue<ii>pr,pc;
	auto val=[&](ll i, ll w){
		ll mx=0;
		fore(j,0,26)mx=max(mx,(w?col:row)[i][j]);
		return mx;
	};
	fore(i,0,n)pr.push({val(i,0),i});
	fore(i,0,m)pc.push({val(i,1),i});
	vector<pair<char,pair<ll,char>>> ret;
	while(SZ(pr)&&SZ(pc)){
		if(pr.top().fst==m){
			auto [v,i]=pr.top(); pr.pop();
			ll mx=0;
			fore(j,0,26)if(row[i][j]==v)mx=j;
			ret.pb({'R',{i,'A'+mx}});
			priority_queue<ii>pci;
			while(SZ(pc)){
				auto [sdkjf,i]=pc.top(); pc.pop();
				col[i][mx]--;
				pci.push({val(i,1),i});
			}
			swap(pc,pci);
			n--;
		}
		else {
			assert(pc.top().fst==n);
			auto [v,i]=pc.top(); pc.pop();
			ll mx=0;
			fore(j,0,26)if(col[i][j]==v)mx=j;
			ret.pb({'K',{i,'A'+mx}});
			priority_queue<ii>pri;
			while(SZ(pr)){
				auto [sdkjf,i]=pr.top(); pr.pop();
				row[i][mx]--;
				pri.push({val(i,0),i});
			}
			swap(pr,pri);
			m--;
		}
	}
	reverse(ALL(ret));
	cout<<SZ(ret)<<"\n";
	for(auto [ty,snd]:ret){
		cout<<ty<<" "<<snd.fst+1<<" "<<snd.snd<<"\n";
	}
	return 0;
}