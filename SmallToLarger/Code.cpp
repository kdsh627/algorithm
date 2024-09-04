#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define MAX_SIZE 100;
using namespace std;

int parent[MAX_SIZE];

vector<set<int>> S;

void init(int n)
{
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }
}


int Find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
    int a = FInd(a);
    int b = FInd(b);

    if (a == b) return;
    //더 큰 집합에 작은 집합을 삽입하기 위한 조건문
    if (S[x].size() < S[y].size()) swap(x, y);
    //무조건 a 집합에 b집합을 삽입
    S[a].insert(S[b].begin(), S[b].end());
    S[b].clear();

    //a에 b를 편입
    parent[b] = a;
}


int main()
{
    std::cout << "Hello World!\n";
}
