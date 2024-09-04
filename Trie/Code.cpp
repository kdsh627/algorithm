#include <vector>
#include <string>
using namespace std;

class Trie
{
	static constexpr size_t M = 26;
	static constexpr char OFFSET = 'a';

	struct TrieNode
	{
		int child[M];
		bool is_terminal;
		TrieNode()
		{
			memset(child, -1, sizeof(int) * M);
			is_terminal = false;
		}
	};
	vector<TrieNode> nodes;
public:
	Trie() : nodes(1) {}
	void init()
	{
		nodes.resize(1);
		nodes[0] = TrieNode();
	}

	void insert(const string& str)
	{
		int node_id = 0;
		for (const char& c : str)
		{
			if (nodes[node_id].child[c - OFFSET] == -1)
			{
				//문제에 따라 다르게 응용
				nodes[node_id].child[c - OFFSET] = nodes.size();
				nodes.emplace_back();
			}
			node_id = nodes[node_id].child[c - OFFSET];
		}
		nodes[node_id].is_terminal = true;
	}

	void remove(const string& str)
	{
		int node_id = 0;
		for (const char& c : str)
		{
			if (nodes[node_id].child[c - OFFSET] == -1)
			{
				return;
			}
			node_id = nodes[node_id].child[c - OFFSET];
		}
		nodes[node_id].is_terminal = false;
	}

	void find(const string& str) const
	{
		int nodes_id = 0;
		for (const char& c : str)
		{
			if (nodes[node_id].child[c - OFFSET] == -1)
			{
				return false;
			}
			node_id = nodes[node_id].child[c - OFFSET];
		}
		return nodes[node_id].is_terminal;
	}
};

int main()
{

}