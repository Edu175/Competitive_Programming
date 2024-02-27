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
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
int n,sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,id;};
qu qs[MAXN];
ll a[MAXN],c[MAXN],dif=0,sum[MAXN];
deque<ll> pos[MAXN];
void init(){
	dif=0;
	fore(i,0,n)c[i]=sum[i]=0,pos[i].clear();
}
void add(ll i, ll w){
	c[a[i]]++;
	sum[a[i]/sq]++;
	if(!w)pos[a[i]].push_front(i);
	else pos[a[i]].pb(i);
	//cout<<"add "<<i<<" ai"<<a[i]<<": c"<<c[a[i]]<<" bl"<<a[i]/sq<<" sum"<<sum[a[i]/sq]<<"\n";
}
void remove(ll i, ll w){
	c[a[i]]--;
	sum[a[i]/sq]--;
	if(!w)pos[a[i]].pop_front();
	else pos[a[i]].pop_back();
	//cout<<"remove "<<i<<" ai"<<a[i]<<": c"<<c[a[i]]<<" bl"<<a[i]/sq<<" sum"<<sum[a[i]/sq]<<"\n";
}
vector<ll> get_ans(){
	vector<ll>ret;
	for(int i=0;i<n;i+=sq){
		if(SZ(ret)>=2)break;
		if(sum[i/sq]){
			fore(j,i,min(n,i+sq)){
				if(SZ(ret)>=2)break;
				if(c[j])ret.pb(pos[j].front());
			}
		}
	}
	if(SZ(ret)<2)ret={-2,-2};
	return ret;
	
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
        while(l>q.l)add(--l,0);
        while(r<q.r)add(r++,1);
        while(l<q.l)remove(l++,0);
        while(r>q.r)remove(--r,1);
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
