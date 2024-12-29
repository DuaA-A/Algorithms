#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include <cstring>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef double dbl;
using namespace std;

struct edges{
	int x,y,a,b;
	bool operator <(edges A){return a<A.a;}
} 
a[50005],q[205];
int n,m,A,B,dsu[205];

int find(int x) {
	if(dsu[x]==x)
		return x;
	return dsu[x]=find(dsu[x]);
}
void Q4_MST(){
    cin>>n>>m>>A>>B;
	for(int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].a>>a[i].b;
	sort(a+1,a+m+1); // (sort -->gift Gold(a))
	long long ans=2e18;
	for (int i=1,t=0,s;i<=m;i++){
		q[++t]=a[i];
		s=0;
		for(int j=t-1;j&&q[j+1].b<q[j].b;j--)swap(q[j],q[j+1]);//sorted b -->silver
		for(int j=1;j<=n;j++)dsu[j]=j;
		for(int j=1,x,y;s<n-1&&j<=t;j++)
			if((x=find(q[j].x))!=(y=find(q[j].y)))dsu[x]=y,q[++s]=q[j]; 
		if(s==n-1)ans=min(ans,1ll*A*a[i].a+1ll*B*q[s].b);
		t=s;
	}
	if(ans<2e18)
		cout<<ans<<"\n";
	else 
		cout<<-1<<"\n";

}
int main(){
    Q4_MST();
    return 0;
}
/*

sort by a --> min cost of gold
x   y    a   b
1    2   4    20
1    3   5    1
1    2   10   15



case 1
x     y    a    b
1     2    4    20

cover cities:  1-------2
not all city cover
not optimal cost
cost=0


case   2
x       y     a    b
1       2     4   20
1       3     5    1

cover cities:1,2,3
all city cover
cost = max(a)*A +max(b)*b (because cost cover all cities)
cost=5*2+20*1=30


case 3

x       y       a    b
1       3       5    1
1       2       10   15

cover cities:1,2,3
all city cover
cost = max(a)*A +max(b)*b (because cost cover all cities)
cost=10*2+15*1=35


min cost(optimal)=min(30,35)=30

*/
