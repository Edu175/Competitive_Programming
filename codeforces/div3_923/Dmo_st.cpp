#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
int n,sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,id;};
qu qs[MAXN];
ll a[MAXN],c[MAXN];
set<ll>st;
void init(){
	st.clear();
	fore(i,0,n)c[i]=0;
}
void add(ll i){
	c[a[i]]++;
	if(c[a[i]]==1)st.insert(a[i]);
}
void remove(ll i){
	c[a[i]]--;
	if(c[a[i]]==0)st.erase(a[i]);
}
vector<ll> get_ans(){
	if(SZ(st)<2)return {-2,-2};
	return {*st.begin(),*prev(st.end())};
	
}
vector<ll> ans[MAXN]; // ans[i] = answer to ith query
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void mos(){
	init();
    fore(i,0,nq)qs[i].id=i;
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    fore(i,0,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans();
    }
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		map<ll,ll>mp;
		fore(i,0,n)cin>>a[i],mp[a[i]]=-1;
		ll j=0;
		for(auto &i:mp)i.snd=j++;
		fore(i,0,n)a[i]=mp[a[i]];
		//fore(i,0,n)cout<<a[i]<<" ";;cout<<"\n";
		cin>>nq;
		fore(i,0,nq)cin>>qs[i].l>>qs[i].r,qs[i].l--;
		mos();
		fore(i,0,nq)cout<<ans[i][0]+1<<" "<<ans[i][1]+1<<"\n";
	}
	return 0;
}
