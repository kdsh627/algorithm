#include <iostream>
#include <queue>
#define MAX_SIZE 10001
using namespace std;

struct INFO
{
    int v;
    int e;
    int dist;

    INFO(int _v, int _e, int _d) : v(_v), e(_e), dist(_d){}

    bool operator < (INFO info) const
    {
        return dist > info.dist;
    }
};

priority_queue<INFO> graph;
int parent[MAX_SIZE];
int height[MAX_SIZE];

void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
        height[i] = 1;
    }
}

int Find(int x)
{
    //서로 같으면 그게 루트임
    if (parent[x] == x) return parent[x];
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
    int A = Find(a);
    int B = Find(b);

    //둘이 같으면 이미 같은 트리에 포함되어 있는 것
    if (A == B) return;

    //트리의 높이가 높은 것에 낮은 것을 이식한다.
    if (height[A] > height[B])
    {
        parent[B] = A; //B에다가 A의 낙인을 새긴다...
    }
    else if (height[A] < height[B])
    {
        parent[A] = B;
    }
    else
    {
        parent[B] = A;
        height[B]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int result = 0;
    int V, E;
    cin >> V >> E;
    init(V);

    for (int i = 0; i < E; ++i)
    {
        int v, e, d;
        cin >> v >> e >> d;
        graph.emplace(v, e, d);
    }

    for (int i = 0; i < E; ++i)
    {
        INFO cur = graph.top();
        graph.pop();
        //같은 트리에 없다면
        if (Find(cur.v) != Find(cur.e))
        {
            result = result + cur.dist;
            Union(cur.v, cur.e);
        }
    }

    cout << result;
}
