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

bool disjoint(ii a, ii b){
	if(a.fst==b.fst||a.fst==b.snd)return 0;
	if(a.snd==b.fst||a.snd==b.snd)return 0;
	return 1;
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
	sort(ALL(a));
	vector<ii>b;
	for(auto i:a){
		ll c=0;
		fore(j,max(0,SZ(b)-4),SZ(b))c+=b[j].fst==i.fst;
		if(c<4)b.pb(i);
	}
	//for(auto i:b)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	vector<pair<ll,ii>>c;
	ll m=SZ(b);
	fore(i,0,m)fore(j,i+1,m)c.pb({b[i].fst+b[j].fst,{i,j}});
	sort(ALL(c));
	//for(auto i:c)cout<<i.fst<<"("<<i.snd.fst<<","<<i.snd.snd<<") ";;cout<<"\n";
	vector<ll>res;
	for(auto [s,id]:c){
		pair<ll,ii> v={k-s,{-1,-1}};
		ll p=lower_bound(ALL(c),v)-c.begin();
		//cout<<s<<"("<<id.fst<<","<<id.snd<<") "<<v.fst<<": ";
		for(;p<SZ(c)&&c[p].fst==v.fst;p++){
			//cout<<c[p].fst<<"("<<c[p].snd.fst<<","<<c[p].snd.snd<<") ";
			if(disjoint(id,c[p].snd)){
				res={id.fst,id.snd,c[p].snd.fst,c[p].snd.snd};
				goto out;
			}
			
		}
		//cout<<"\n";
	}
	out:
	if(!SZ(res))cout<<"IMPOSSIBLE\n";
	else {
		for(auto i:res)cout<<b[i].snd+1<<" ";
		cout<<"\n";
	}
	return 0;
}
