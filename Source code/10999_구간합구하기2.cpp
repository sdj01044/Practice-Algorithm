// Lazy propagation & Segment Tree
// http://bowbowbow.tistory.com/4

#include <cstdio> 
#define MAXN 1000010 
#define ll long long 
ll arr[MAXN]; 
typedef struct Tree{ 
	ll value, lazy; }
Tree; 

Tree tree[3*MAXN]; 

//최초로 Segment트리의 대표값을 지정하는 함수 
ll init(int node, int start, int end){
	if(start == end) 
		return tree[node].value = arr[start]; 
	else 
		return tree[node].value = init(node*2, start, (start+end)/2)+init(node*2+1, (start+end)/2+1, end); 
}

//i~j 구간에 diff만큼 더해줄 때 SegmentTree를 업데이트 하는 함수 
void update_range(int node, int start, int end, int i, int j, ll diff){
	//lazy가 남아있을 때 
	if(tree[node].lazy != 0){ 
		tree[node].value += (end-start+1)*tree[node].lazy; 
		if(start != end){ 
			tree[node*2].lazy += tree[node].lazy; 
			tree[node*2+1].lazy += tree[node].lazy; 
		} 
		tree[node].lazy =0; 
	} 
	
	if(j < start || i > end) return; 
	
	//대표 구간을 찾았을 때 
	if(i <= start && end <= j){ 
		tree[node].value += (end-start+1)*diff; 
		if(start != end){ 
			tree[node*2].lazy += diff; 
			tree[node*2+1].lazy += diff; 
		} return; 
	} 
	update_range(node*2, start, (start+end)/2, i, j, diff); 
	update_range(node*2+1, (start+end)/2+1, end, i, j, diff); 
	tree[node].value = tree[node*2].value+tree[node*2+1].value; 
} 

//i번째 값부터 j번째 값 까지의 합을 구하는 함수 
ll sum(int node, int start, int end, int i, int j){ 
	if(tree[node].lazy != 0){ 
		tree[node].value += (end-start+1)*tree[node].lazy; 
		if(start != end){ 
			tree[node*2].lazy += tree[node].lazy; 
			tree[node*2+1].lazy += tree[node].lazy; 
		} 
		tree[node].lazy =0; 
	}
	
	if(i> end || j < start)
		return 0; 
	if(i <= start && end <= j) 
		return tree[node].value; 
	return sum(node*2, start, (start+end)/2, i, j)+sum(node*2+1, (start+end)/2+1, end, i, j); 
} 

int main(){ 
	int N, M, K; 
	scanf("%d%d%d", &N, &M, &K); 
	for(int i=1; i<= N; i++) 
		scanf("%lld", &arr[i]); 
	init(1, 1, N);
	for(int i=1; i<= M+K; i++){ 
		int t1, a, b; 
		ll diff; 
		scanf("%d", &t1); 
		if(t1==1){ 
			scanf("%d%d%lld", &a, &b, &diff);
			update_range(1, 1, N, a, b, diff); 
		}
		else{ 
			scanf("%d%d", &a, &b); 
			printf("%lld\n", sum(1, 1, N, a, b));
		} 
	} 
	return 0; 
}