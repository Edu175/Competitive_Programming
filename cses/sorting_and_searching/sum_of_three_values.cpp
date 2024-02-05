#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll>a(n);
	vector<ii>b(n);
	fore(i,0,n)cin>>a[i],b[i]={a[i],i};
	sort(ALL(a));
	sort(ALL(b));
	vector<ll>res;
	fore(i,0,n)fore(j,i+1,n){
		ll v=k-a[i]-a[j];
		ll p=lower_bound(ALL(a),v)-a.begin();
		for(;p<n&&a[p]==v;p++)if(p!=i&&p!=j){
			res={i,j,p};
			goto out;
		}
	}
	out:
	if(!SZ(res))cout<<"IMPOSSIBLE\n";
	else {
		for(auto i:res)cout<<b[i].snd+1<<" ";
		cout<<"\n";
	}
	return 0;
}
