#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int MAXV=1e9+5;
const int MAXFT=1e6+5;

//int ft[MAXV+1][MAXV+1];
//unordered_map<ll,int> ft;
unordered_map<int,int> ft[MAXFT+1];
ll cv(ll i, ll j){return (i<<30)^j;}
void upd(int i0, int j0, int v){
	//cout<<"upd "<<i0<<","<<j0<<" "<<v<<endl;
	for(int i=i0+1;i<MAXFT;i+=i&-i)
	for(int j=j0+1;j<MAXFT;j+=j&-j)
		ft[i][j]+=v;
		//ft[cv(i,j)]+=v;
}
int get(int i0, int j0){
	int r=0;
	for(int i=i0;i;i-=i&-i)
	for(int j=j0;j;j-=j&-j)
		r+=ft[i][j];
		//r+=ft[cv(i,j)];
	//cout<<"get "<<i0<<","<<j0<<": "<<r<<"\n";
	return r;
}
int get_sum(int i0, int i1, int j0, int j1){
	return get(i1,j1)-get(i1,j0)-get(i0,j1)+get(i0,j0);
}
const int MAXN=2e5+5;
ii a[MAXN];
int h2;
ii calc(int s0, int e0, int s1, int e1){
	int des=get_sum(0,e0,s0+1,s1+1);
	int apa=get_sum(e0,e1,s1+1,h2+1);
	return {des,apa};
}

signed main(){FIN;
	int n,q,h1,bas; cin>>n>>q>>h1>>h2>>bas;
	vector<pair<int,int*>>com;
	fore(i,0,n){
		int l,r; cin>>l>>r;
		cin>>bas>>bas;
		a[i]={l,r};
		com.pb({l,&a[i].fst});
		com.pb({r,&a[i].snd});
	}
	int s=0,e=h1;
	com.pb({s,&s});
	com.pb({e,&e});
	pair<char,int> qs[q];
	vector<ii> se(q);
	fore(i,0,q){
		char c; cin>>c;
		if(c=='A'){
			int id,l,r; cin>>id>>l>>r>>bas>>bas; id--;
			a[id]={l,r};
			qs[i]={c,id};
			com.pb({l,&a[id].fst});
			com.pb({r,&a[id].snd});
		}
		else if(c=='D'){
			int id; cin>>id; id--;
			qs[i]={c,id};
		}
		else {
			int si,ei; cin>>si; ei=si+h1;
			qs[i]={c,-1};
			se[i]={si,ei};
			com.pb({si,&se[i].fst});
			com.pb({ei,&se[i].snd});
		}
	}
	h2=0;
	sort(ALL(com));
	fore(i,0,SZ(com)){
		if(i&&com[i].fst!=com[i-1].fst)h2++;
		*(com[i].snd)=h2;
	}
	fore(i,0,n){
		upd(a[i].fst,a[i].snd,1);
	}
	fore(i,0,q){
		char c=qs[i].fst; int id=qs[i].snd;
		int apa=0,des=0;
		if(c=='A'){
			int l=a[id].fst,r=a[id].snd;
			upd(l,r,1);
			if(l<e&&r>s)apa++;
		}
		else if(c=='D'){
			int l=a[id].fst,r=a[id].snd;
			if(l<e&&r>s)des++;
			upd(l,r,-1);
		}
		else {
			int si=se[i].fst,ei=se[i].snd;
			if(s<si){
				//cout<<"abajo\n";
				ii res=calc(s,e,si,ei);
				apa=res.snd;
				des=res.fst;
			}
			else {
				//cout<<"arriba\n";
				ii res=calc(si,ei,s,e);
				apa=res.fst;
				des=res.snd;
			}
			s=si,e=ei;
		}
		cout<<apa<<" "<<des<<"\n";
	}
	return 0;
}

