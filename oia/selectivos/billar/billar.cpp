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
const ll MAXN=3e3+5;
struct pt{
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){};
	pt operator+(pt q){return pt(x+q.x,y+q.y);}
};
vector<pt>go={pt(0,1),pt(1,0),pt(-1,0),pt(0,-1)};
vector<string>flecha={"^",">","<","v"};
ll dir[MAXN][MAXN],vis[MAXN][MAXN][4];
void f(pt p, ll d){
	while(!vis[p.x][p.y][d]){
		assert((p.x&1)||(p.y&1));
		//assert(!(/*p.x<0||p.y<0||*/p.x>MAXN||p.y>MAXN));
		vis[p.x][p.y][d]=1;
		//cout<<"{ "<<p.x/2.0<<" , "<<p.y/2.0<<" } "<<flecha[d]<<"\n";
		ll h=dir[p.x][p.y];
		if(h==2||h==3)d=3-d;//return;
		else if(h!=-1)d^=1<<h;
		p=p+go[d];
		if(p.x<0||p.y<0||p.x>MAXN||p.y>MAXN)return;
	}
	//cout<<"==================================================================\n";
}
int main(){FIN;
	ifstream cin;   cin.open("billar.in", ios::in);
	ofstream cout; cout.open("billar.out", ios::out);
	vector<pt>a;
	vector<pair<pt,pt>>ex;
	ll n; cin>>n;
	pt s; cin>>s.x>>s.y;s.x*=2,s.y*=2; pt S=s;
	mset(dir,-1);
	fore(i,1,n+1){
		pt e;
		if(i==n)e=S;
		else cin>>e.x>>e.y,e.x*=2,e.y*=2;
		ll d=0;
		//cout<<s.x<<","<<s.y<<"-->"<<e.x<<","<<e.y<<"\n";
		if(s.x==e.x)d=3;
		else if(s.y==e.y)d=2;
		else if((s.x<e.x)^(s.x<e.x))d=1;
		pt r=s;
		while(s.x!=e.x||s.y!=e.y){
			if((s.x&1)||(s.y&1))dir[s.x][s.y]=d,a.pb(s),ex.pb({r,pt(-1,-1)});
			//,cout<<"."/*s.x<<","<<s.y<<":"<<d<<" "*/;
			//cout<<s.x<<","<<s.y<<":"<<d<<" ";
			r=s;
			if(s.x<e.x)s.x++;
			else if(s.x>e.x)s.x--;
			if(s.y<e.y)s.y++;
			else if(s.y>e.y)s.y--;
			if(!(s.x&1)&&!(s.y&1))ex.back().snd=s;
		}
		s=e;
	}
	//cout<<"\n";
	/*fore(h,0,SZ(a)){
		pt i=a[h];
		cout<<"["<<ex[h].fst.x<<","<<ex[h].fst.y<<" ";
		cout<<i.x<<","<<i.y<<":"<<dir[i.x][i.y]<<" ";
		cout<<ex[h].snd.x<<","<<ex[h].snd.y<<"] ";
	}
	cout<<"\n";*/
	ll x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2; x1*=2,x2*=2,y1*=2,y2*=2;
	if(x2<x1)swap(x1,x2);
	if(y2<y1)swap(y1,y2);
	//cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<"\n";
	for(pt p={x1+1,y1};p.x<x2;p.x+=2)f(p,3),f(p,0);
	for(pt p={x2,y1+1};p.y<y2;p.y+=2)f(p,1),f(p,2);
	ll l=-1,r=l;
	vector<pair<ll,ll>>res;
	fore(h,0,SZ(a)){
		ll v=0; pt i=a[h];
		for(auto j:vis[i.x][i.y])if(j)v=1;
		if(l!=-1){
			if(!v||dir[i.x][i.y]!=dir[a[r].x][a[r].y])res.pb({l,r}),l=-1;
			else r=h;
		}
		if(l==-1&&v)l=r=h;
		//cout<<"{"<<i.x/2.0<<","<<i.y/2.0<<"} "<<dir[i.x][i.y]<<": "<<v<<"\n";
	}
	if(l!=-1)res.pb({l,r});
	for(auto i:res){
		cout<<ex[i.fst].fst.x/2<<" "<<ex[i.fst].fst.y/2<<" ";
		cout<<ex[i.snd].snd.x/2<<" "<<ex[i.snd].snd.y/2<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
