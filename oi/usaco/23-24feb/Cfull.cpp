#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,usaco=b;i<usaco;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asdf:v)cout<<asdf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
ll p[MAXN],s[MAXN];
#define bint __int128
bint eval(ll i, ll x){
	bint v=s[i]*(x/2);
	bint pos[2];
	pos[0]=p[i];
	pos[1]=((i&1)?-1:1)*s[i]+p[i];
	return bint(((x+i)&1)?1:-1)*v+pos[x&1];
}

ii meet(ll i, ll j){ // i < j
	ll b=!(i&1);
	
	ll l=0,r=1e15+5;
	while(l<=r){
		ll m=(l+r)/2;
		if(eval(i,m*2+b)<eval(j,m*2+b))l=m+1;
		else r=m-1;
	}
	//return {2*l+b,eval(j,l*2+b)-eval(i,l*2+b)};
	return {2*l+b,abs(i-j)};
}
/*ii meet_official(int a, int b) {
    ll dist = p[b] - p[a], speed_sum = s[a] + s[b];
    return {2 * ((dist + speed_sum - 1) / speed_sum) - (a % 2 == 0),abs(a-b)};
}*/
ii neg(ii a){return {-a.fst,-a.snd};}
pair<ii,ii> give(ll i, ll j){
	return {neg(meet(i,j)),{i,j}};
}
/*void find(){
	ll T,N,V; srand((ll)&T); cin>>T>>N>>V;
	fore(_,0,T){
		ll n=rand()%N+2;
		fore(i,0,n)p[i]=rand()%V;
		fore(i,0,n)s[i]=rand()%V+1;
		sort(p,p+n);
		fore(i,1,n)if(p[i]<=p[i-1])p[i]=p[i-1]+1;
		fore(__,0,n){
			ll i=rand()%n,j=rand()%n;
			if(i>=j)swap(i,j);
			if(i%2==j%2){
				if(i)i--;
				else if(j)j--;
				else j++;
			}
			if(meet(i,j)!=meet_official(i,j)){
				fore(i,0,n)cout<<p[i]<<" ";;cout<<"\n";
				cout<<"FAILED!!!\n";
				cout<<i<<","<<j<<": "<<p[i]<<","<<s[i]<<" "<<p[j]<<","<<s[j]<<": "<<meet(i,j).fst<<" "<<meet_official(i,j).fst<<"\n";
				exit(0);
			}
			//cout<<"ok "<<__+1<<"\n";
		}
		cout<<"ok case "<<_+1<<"\n\n";
	}
}*/
int main(){FIN;
	/*find();
	exit(0);*/
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		//assert(n==2);
		fore(i,0,n)cin>>p[i];
		fore(i,0,n)cin>>s[i];
		/*fore(i,0,n){
			cout<<i<<": ";
			fore(j,0,10)cout<<eval(i,j)<<" ";
			cout<<"\n";
		}*/
		priority_queue<pair<ii,ii>>pq;
		fore(i,0,n-1){
			pq.push(give(i,i+1));
		}
		vector<ll>res(n);
		set<ll>st;
		fore(i,0,n)st.insert(i);
		while(SZ(pq)){
			auto [pa,pai]=pq.top(); pq.pop(); pa=neg(pa);
			auto [w,d]=pa;
			auto [i,j]=pai;
			if(res[i]||res[j])continue;
			res[i]=res[j]=w;
			st.erase(i); st.erase(j);
			auto p=st.lower_bound(i);
			//imp(st);
			//cout<<i<<endl;
			if(p!=st.begin()&&p!=st.end())pq.push(give(*prev(p),*p));
		}
		fore(i,0,n){
			if(i)cout<<" ";
			cout<<res[i];
		}
		cout<<"\n";
	}
	return 0;
}
