#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
	Graph(int n) {
		g.clear();
		g.resize(n);
	}
	void insert(int a, int b, int w) {
		a--;
		b--;
		g.at(a).push_back(make_pair(b, w));
		g.at(b).push_back(make_pair(a, w));
	}
	vector<int> Dijkstra(int a, int b) {
		a--;
		b--;
		int n = g.size();
		vector<int> parent(n, INT_MAX), dist(n, INT_MAX);
		vector<bool> visited(n, false);
		dist.at(a) = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push(make_pair(0, a));

		while (!pq.empty()) {
			pair<int, int> p = pq.top();
			pq.pop();
			int id = p.second, w = p.first;
			visited.at(id) = true;
			if (id == b) {
				vector<int> path;
				while (id != a) {
					path.push_back(id + 1);
					id = parent.at(id);
				}
				path.push_back(a + 1);
				reverse(begin(path), end(path));
				return path;
			}
			for (const auto &i : g.at(id)) {
				int nid = i.first, nw = i.second + w;
				if (!visited.at(nid) and nw < dist.at(nid)) {
					parent.at(nid) = id;
					dist.at(nid) = nw;
					pq.push(make_pair(nw, nid));
				}
			}
		}
		return {-1};
	}
private:
	vector<vector<pair<int, int>>> g;
};

int main(void) {
	int n, m;
	cin >> n >> m;
	Graph graph(n);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph.insert(a, b, w);
	}
	vector<int> path = graph.Dijkstra(1, n);
	for (const auto &i : path) {
		cout << i << ' ';
	}
	return 0;
}
