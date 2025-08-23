#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	
	ll n,m; cin>>n>>m;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	
	vector<array<ll,3>>b(n-1);
	fore(i,0,n-1){
		b[i]={a[i+1].fst-a[i].snd,a[i+1].snd-a[i].fst+1,i};
	}
	sort(ALL(b),[&](array<ll,3> a, array<ll,3> b){
		return a[1]<b[1];
	});
	multiset<ii>st; // bridges
	fore(i,0,m){
		ll h; cin>>h;
		st.insert({h,i});
	}
	vv ans(n-1);
	ll fg=1;
	for(auto [l,r,i]:b){
		// cout<<l<<","<<r<<" "<<i<<"\n";
		auto it=st.lower_bound({l,-1});
		if(it==st.end()||it->fst>=r)fg=0;
		else {
			ans[i]=it->snd;
			// cout<<"hay "<<it->fst<<","<<it->snd<<"\n";
			st.erase(it);
		}
	}
	if(!fg)cout<<"No\n";
	else {
		cout<<"Yes\n";
		for(auto i:ans)cout<<i+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}

