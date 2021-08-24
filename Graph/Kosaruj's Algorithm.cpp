/*

	--Transepose Graph
		-has same number of connected compenent
		-Each edge is reverse in direction

	--2 DFS:
		First for how to traverse the array in second dfs i.e to find anwser(use original Graph)
		second for finding anwser(use Transepose Graph because it will traverse from graph which has indegree zero)
	IMP
		First dfs we get required traversal using out time of node
		There will a connected compenent which has indegree zero(has highest out time) and we traverse from that
		component in second dfs

*/

std::vector<int> adjencent[1000001];
std::vector<int>Transepose[1000001];
int vis[100001];
std::vector<int> required_traversal;
void graph_travesal_required(int node)
{
	vis[node] = 1;
	for (int child : adjencent[node])
		graph_travesal_required(node);
	required_traversal.push_back(node);
}
void dfs(int node)
{
	vis[node] = 1;
	for (int child : adjencent[node])
		dfs(node);
	// ?required_traversal.push_back(node);
}
void solve()
{
	int n;	//number of nodes
	int m;	//number of edges
	cin >> n >> m;
	for (int i = 0; i < n; i++)				//If there are number of test case
	{
		adjencent[i].clear(),
		          Transepose[i].clear(),
		          vis[i] = 0;

	}
	for (int i = 0; i < m; i++)
	{
		int l, m;	//edge from l to m
		cin >> l >> m;
		adjencent[l].push_back(m);
		Transepose[m].push_back(l);
	}
	for (int i : n)						//find each component
	{
		if (vis[0] == 0)
			graph_travesal_required(i);
	}
	for (int i : n)
		vis[i] = 0;
	reverse(required_traversal.begin(), required_traversal.end()) //reverse to get compen
	//with indegree zero

	for (int i : required_traversal)   //traverse according to the required traversal
	{
		if (vis[i] == 0)
			dfs(i);
	}
}