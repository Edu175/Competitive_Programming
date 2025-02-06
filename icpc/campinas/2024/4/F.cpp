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
typedef long double ld;
typedef pair<ll,ll> ii;

struct pt{
	ll x,y;
};
bool cmpx(pt a, pt b){
	return a.x<b.x;
}
bool operator<(pt a, pt b){
	return a.y<b.y;
}
ld dis(pt a, pt b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
ll dis2(pt a, pt b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,1,n)a[i]+=a[i-1];
	vector<pt>p;
	fore(i,0,n)p.pb(pt({i,a[i]}));
	ld d=dis(p[0],p[1]);
	ll res=dis2(p[0],p[1]);
	set<pt>st={p[0],p[1]};
	ll s=0;
	fore(i,2,n){
		while(s<n&&i-s>=(d+1))st.erase(p[s++]);
		for(auto it=st.upper_bound(pt({0,p[i].y-(d+1)}));
		it!=st.end()&&it->y-p[i].y<(d+1);it++){
			d=min(d,dis(p[i],*it));
			res=min(res,dis2(p[i],*it));
		}
		st.insert(p[i]);
	}
	cout<<res<<"\n";
	return 0;
}
