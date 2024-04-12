#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<vector<string>>res={
	{
	"yoink a",
	"yoink b",
	"*slaps a on top of b*",
	"yeet b",
	"go touch some grass"
	}
	,
	{
	"yoink a",
	"bruh b is lowkey just 0",
	"rip this b fell off by a",
	"vibe check a ratios b",
	"simp for 7",
	"bruh a is lowkey just b",
	"yeet a",
	"go touch some grass"
	}
	,
	{
	"yoink n",
	"yoink a",
	"bruh m is lowkey just a[0]",
	"bruh i is lowkey just 1",
	"vibe check n ratios i",
	"simp for 9",
	"yeet m",
	"go touch some grass",
	"vibe check a[i] ratios m",
	"bruh m is lowkey just a[i]",
	"*slaps 1 on top of i*",
	"simp for 5"
	}
	,
	{
	"yoink n",
	"yoink a",
	"yoink k",
	"vibe check 2 ratios n",
	"simp for 29",
	"bruh p is lowkey just n",
	"rip this p fell off by k",
	"bruh r is lowkey just 0",
	"vibe check n ratios r",
	"simp for 13",
	"yeet a[p]",
	"go touch some grass",
	"bruh i is lowkey just 1",
	"vibe check n ratios i",
	"simp for 18",
	"*slaps 1 on top of r*",
	"simp for 9",
	"bruh j is lowkey just i",
	"rip this j fell off by 1",
	"bruh ai is lowkey just a[i]",
	"bruh aj is lowkey just a[j]",
	"vibe check aj ratios ai",
	"simp for 26",
	"*slaps 1 on top of i*",
	"simp for 14",
	"bruh a[i] is lowkey just aj",
	"bruh a[j] is lowkey just ai",
	"simp for 24",
	"yeet a[0]",
	"go touch some grass"
	}
};

int main(){FIN;
	ll x; cin>>x; x--;
	for(auto s:res[x]){
		cout<<s<<"\n";
	}
	return 0;
}
