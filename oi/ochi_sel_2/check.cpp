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
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

indexed_set st;
void go(ll &pos, ll &dir, ll v){
	//cout<<"go "<<pos<<" "<<dir<<"  "<<v<<endl;
	ll ns=SZ(st);
	if(ns==1)return;
	while(v){
		ll vi=v;
		ll i=st.order_of_key(pos);
		if(dir==1)vi=min(v,ns-1-i); //der
		else vi=min(v,i); //izq
		pos=*st.find_by_order(i+vi*dir);
		if(i+vi*dir==0||i+vi*dir==ns-1)dir*=-1;
		v-=vi;
	}
}

int main(){FIN;
	ll n,b[2]; cin>>n>>b[0]>>b[1];
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll c[2]={0,0};
	ii p[2]={{0,1},{n-1,-1}};
	fore(i,0,n)st.insert(i);
	ll men=0;
	vector<ll>is(n,1);
	while(SZ(st)){
		//imp(st);
		ll ns=SZ(st);
		fore(w,0,2){
			ll &pos=p[w].fst;
			ll &dir=p[w].snd;
			if(ns>1){
				ll mod=2*(ns-1);
				ll v=(b[w]-men)%mod;
				go(pos,dir,v);
			}
			c[w]+=a[pos];
		}
		ll p0=p[0].fst,p1=p[1].fst;
		//cout<<"Mario "<<p[0].fst<<" "<<p[0].snd<<"\n";
		//cout<<"Bowser "<<p[1].fst<<" "<<p[1].snd<<"\n";
		fore(w,0,2)if(is[p[w].fst])ns--,is[p[w].fst]=0;
		fore(w,0,2)while(ns&&!is[p[w].fst]){
			go(p[w].fst,p[w].snd,1);
		}
		st.erase(p0);
		st.erase(p1);
		men=1;
		//cout<<"\n";
	}
	cerr<<c[0]<<" "<<c[1]<<"\n";
	if(c[0]>=c[1])cout<<"Mario\n";
	else cout<<"Bowser\n";
	return 0;
}
