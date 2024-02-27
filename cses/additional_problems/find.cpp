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
const ll INF=1e4;

bool done(string a){
	ll B=0,fl=1;
	fore(i,0,SZ(a)){
		if(a[i]=='B')B=1;
		if(a[i]=='A'&&B)fl=0;
	}
	//cout<<"done "<<a<<"? "<<fl<<endl;
	return fl;
}
map<string,string> pa;
string bfs(string s){
	queue<string>q;
	q.push(s);
	pa[s]="END";
	while(SZ(q)){
		auto a=q.front(); q.pop();
		ll p=-1;
		fore(i,0,SZ(a)){
			if(a[i]=='.'&&p==-1)p=i;
		}
		if(done(a))return a;
		fore(i,0,SZ(a)-1)if(a[i]!='.'&&a[i+1]!='.'){
			s=a;
			swap(s[i],s[p]);
			swap(s[i+1],s[p+1]);
			if(pa.count(s))continue;
			pa[s]=a;
			q.push(s);
		}
	}
	return "NO";
}
vector<string> bf(string s){
	pa.clear();
	string a=bfs(s);
	if(a=="NO"){
		cout<<"-1\n";
		exit(0);
	}
	vector<string>res;
	while(a!="END")res.pb(a),a=pa[a];
	res.pop_back();
	reverse(ALL(res));
	return res;
}
vector<string>res;
string a;
ll p=-1;
void move(ll i){
	assert(i<SZ(a)-1);
	assert(a[i]!='.'&&a[i+1]!='.');
	swap(a[i],a[p]);
	swap(a[i+1],a[p+1]);
	p=i;
	res.pb(a);
	//cout<<a<<endl;
}
void swapea(ll i, ll j){
	assert(abs(i-j)>=2);
	ll pi=p;
	move(i);
	move(j);
	move(pi);
}
vector<string> solve(string A){
	a=A;
	ll n=SZ(a);
	res.clear();
	p=-1;
	fore(i,0,SZ(a))if(p==-1&&a[i]=='.')p=i;
	/*if(a.back()=='A'){
		if(a[n-2]=='.')move(0),cout<<"anteu"<<endl;
		move(n-2);
	}*/
	fore(i,0,n){
		//cout<<i<<endl;
		if(done(a))break;
		if(a[i]=='A')continue;
		if(p!=n-2){
			if(p==n-3)move(i);
			move(n-2);
		}
		if(abs(p-i)<2)move(p+2);
		if(done(a))break;
		ll ax=-1,bbb=-1;
		fore(j,i+2,n){
			if(j<n-1&&a[j]=='A'&&a[j+1]!='.')ax=j;
			if(j+2<n&&a[j]=='B'&&a[j+1]=='B'&&a[j+2]=='B')bbb=j;
		}
		if(ax!=-1)swapea(i,ax);
		else {
			if(a[i+1]=='A'){
				assert(bbb!=-1);
				swapea(i,bbb);
				swapea(i,bbb+1);
			}
			else {
				assert(a[p-1]=='A');
				ll pi=p;
				move(i);
				move(pi-1);
			}
		}
	}
	return res;
}
//START
ll N;
string gen(){
	ll n=rand()%(N-5)+6;
	string s(n-1,'A');
	fore(i,0,n-1)s.pb('B');
	random_shuffle(ALL(s));
	ll p=rand()%(SZ(s)+1);
	string t;
	fore(i,0,SZ(s)){
		if(i==p)t+="..";
		t.pb(s[i]);
	}
	if(p==SZ(s))t+="..";
	return t;
}
int main(){FIN;
	ll q; srand((ll)q); cin>>N>>q;
	fore(_,0,q){
		string s=gen();
		cout<<s<<endl;
		solve(s);
	}
	return 0;
}
