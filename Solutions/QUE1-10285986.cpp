/*
	Author - Arvind K
	College - BITS Pilani
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

inline void superFastRead (int *a)
{
    char c = 0;
    while(c<33)
    c = fgetc(stdin);
    *a = 0;
    while(c>33)
    {
               *a = *a*10 + c - '0';
               c = fgetc(stdin);
    }
}
struct Person{
	int h;
	int n_ahead;
};

bool comp(Person a, Person b) { return a.h<b.h; }

Person ppl[10002];
int ordered[10002],n;

int BIT[10003];

void update(int idx, int val){
	while(idx<=10002){
		BIT[idx] += val;
		idx += (idx&-idx);
	}
}

int query(int idx){
	int ans = 0;
	while(idx>0){
		ans += BIT[idx];
		idx -= (idx&-idx);
	}
	return ans;
}

int bs(int x){
	int lo=1,hi=10002,mid;
	while(lo<=hi){
		mid = (lo+hi)>>1;
		int temp = query(mid);
		if(temp>=x) hi = mid-1;
		else lo = mid+1;
	}
	return lo;
}

int main(){
	int t,i,j;
	for(superFastRead(&t);t--;){
		memset(ordered,0,sizeof(ordered));
		memset(BIT,0,sizeof(BIT));
		superFastRead(&n);
		for(i=1;i<=n;i++) superFastRead(&ppl[i].h);
		for(i=1;i<=n;i++) superFastRead(&ppl[i].n_ahead);

		sort(ppl+1,ppl+1+n,comp);

		for(i=1;i<=10002;i++){
			update(i,1);
		}
		for(i=1;i<=n;i++){
			int pos = bs(1+ppl[i].n_ahead);
			ordered[pos] = ppl[i].h;
			update(pos,-1);
		}
		for(i=1;i<=n;i++) printf("%d ",ordered[i]);
		printf("\n");
	}
}

