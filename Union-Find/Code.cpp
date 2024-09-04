#define MAX_SIZE 100
using namespace std;

int parent[MAX_SIZE];
int height[MAX_SIZE];

void init()
{
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        parent[i] = i;
        height[i] = 1;
    }
}

int Find(int x)
{
    //부모가 자신이라는 뜻은 가장 상위 노드라는 뜻이다.
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]); //각각 노드들은 부모를 가리키고 있으므로 재귀함수로 구현가능
}

void Union(int a, int b)
{
    int A = Find(a);
    int B = Find(b);

    //같은 소속이면 그냥 리턴
    if (A == B) return;
    //높이가 낮은 트리를 높은 트리로 편입
    if (height[A] < height[B])
    {
        //A의 최상단 부모를 B로 지정한다 = A를 B아래에 편입
        parent[A] = B;
    }
    else if (height[A] > height[B])
    {
        parent[B] = A;
    }
    else
    {
        //높이가 같으면 B를 A에 편입시키고 높이를 1상승
        parent[B] = A;
        height[B]++;
    }

}

int main()
{
}
