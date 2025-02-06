#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;


int main(){
	JET
	ll n,q; cin>>n>>q;
	vv a(n),pos(n);
	fore(i,0,n)cin>>a[i],a[i]--,pos[a[i]]=i;
	vv dpl(n),dpr(n);
	set<ll> stl,str;
	fore(i,0,n){
		ll p=pos[i];
		// only last is necessary
		// dpr
		cout<<i<<" "<<p<<":\n";
		cout<<"dpr: ";
		for(auto it=str.lower_bound(p);it!=str.end();it=str.erase(it)){
			dpr[p]=max(dpr[p],1+dpl[*it]+dpr[*it]);
			cout<<*it<<" ";
		}
		cout<<"\n";
		str.insert(p);
		
		//dpl
		cout<<"dpl: ";
		vv pop;
		for(auto it=stl.lower_bound(p);it!=stl.begin();){
			it--;
			dpl[p]=max(dpl[p],1+dpr[*it]+dpl[*it]);
			pop.pb(*it);
			cout<<*it<<" ";
		}
		cout<<"\n\n";
		for(auto j:pop)stl.erase(j);
		stl.insert(p);
	}
	
	cout<<"dpl: ";; fore(i,0,n)cout<<dpl[i]<<" ";;cout<<"\n";
	cout<<"dpr: ";; fore(i,0,n)cout<<dpr[i]<<" ";;cout<<"\n";
	
	return 0;
}

/*

6 2
5 3 4 2 1 6
1 6
1 3

0 4:
dpr: 
dpl: 

1 3:
dpr: 4 
dpl: 

2 1:
dpr: 3 
dpl: 

3 2:
dpr: 
dpl: 1 

4 0:
dpr: 1 2 
dpl: 

5 5:
dpr: 
dpl: 4 3 2 0 

     4 2 3 1 0 5

dpl: 0 0 3 0 0 5 
dpr: 4 2 0 1 0 0 

*/