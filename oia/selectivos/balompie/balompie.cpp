#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi.fst<<","<<messi.snd<<" ";
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree
<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update>
indexed_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k
//less_equal for repeated elements (erase only with pointer)
const ll MAXN=1005;
indexed_set st[2];
map<ii,ll>mp;
ll deg[MAXN],maxd[MAXN];

double t=1e15;
ll simulated_annealing(){
	ll sd; srand((ll)&sd);
	ll res=0,best=0;
	do{
		ll y=rand()+2,x=rand()%(y-1)+1;
		ll w=(double)SZ(st[1])/(SZ(st[1])+SZ(st[0]))>=(double)x/y;
		//(double(rand())+1)/(double(RAND_MAX)+1);
		//cout<<res<<" "<<w<<": ";
		//cout<<" { "; imp(st[0]); cout<<"} { "; imp(st[1]); cout<<"} "<<endl;
		ll c=0;
		//while(!SZ(st[w]));
		ii e=*st[w].find_by_order(rand()%SZ(st[w]));
		if(w)c=mp[e];
		else c=min(maxd[e.fst]-deg[e.fst],maxd[e.snd]-deg[e.snd]);
		//cout<<e.fst<<","<<e.snd<<" "<<c;
		if(c==0){st[w].erase(e);continue;}
		ll k=rand()%c+1,add=(w?-1:1)*k,resi=res+add;
		x=rand()%y;
		best=max(best,resi);
		//cout<<k<<": "<<resi<<endl;
		if(resi>res||exp((resi-res)/t)>=(double)x/y){//accept
			res=resi;
			st[w^1].insert(e);
			if(c==k)st[w].erase(e);
			mp[e]+=add;
			deg[e.fst]+=add;
			deg[e.snd]+=add;
			/*if(!w){
				mp[e]+=k;
				if(c==k)st[0].erase(e);
				st[1].insert(e);
				deg[e.fst]+=k;
				deg[e.snd]+=k;
			}
			else {
				mp[e]-=k;
				if(c==k)st[1].erase(e);
				st[0].insert(e);
				deg[e.fst]-=k;
				deg[e.snd]-=k;
			}*/
		}
		t*=0.999999;
	}
	while(clock()/CLOCKS_PER_SEC<=9.99);
	//cout<<"t "<<t<<"\n";
	return best;
}

int main(){FIN;
	ifstream cin;   cin.open("balompie.in", ios::in);
	ofstream cout; cout.open("balompie.out", ios::out);
	ll n,m; cin>>n>>m;
	fore(i,0,n)cin>>maxd[i];
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		if(u>v)swap(u,v);
		st[0].insert({u,v});
	}
	ll res=simulated_annealing();
	cout<<res<<"\n";
	//cout<<(double(rand())+1)/(double(RAND_MAX)+1)<<"\n";
	return 0;
}

