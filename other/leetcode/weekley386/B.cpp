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
typedef pair<ll,ll> ii;

struct cuad{
	ll l,d,r,u;
	ll in(cuad c){
		ll li=max(l,c.l),ri=min(r,c.r);
		ll di=max(d,c.d),ui=min(u,c.u);
		ll s=min(ri-li,ui-di);
		if(s<0)return 0;
		return s*s;
	}
};

ll solve(vector<vector<int>>bl, vector<vector<int>>tr){
	ll n=SZ(bl);
	vector<cuad> a(n,cuad({0,0,0,0}));
	fore(i,0,n)a[i]=cuad({bl[i][0],bl[i][1],tr[i][0],tr[i][1]});
	ll res=0;
	fore(i,0,n)fore(j,i+1,n)res=max(res,a[i].in(a[j]));
	return res;
}

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        return solve(bl,tr);
    }
};
/*int main(){FIN;
	ll n; cin>>n;
	vector<vector<int>>bl(n,vector<int>(2)),tr(n,vector<int>(2));
	fore(i,0,n)cin>>bl[i][0]>>bl[i][1];
	fore(i,0,n)cin>>tr[i][0]>>tr[i][1];
	cout<<solve(bl,tr);
	return 0;
}*/
