vector < vector<int> > g; // graph
int n; // count of nodes

vector<char> used;

void dfs (int v) {
	used[v] = true;
	for (vector<int>::iterator i=g[v].begin(); i!=g[v].end(); ++i)
		if (!used[*i])
			dfs (*i);
}
