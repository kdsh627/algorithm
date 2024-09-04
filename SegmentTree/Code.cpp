#include <iostream>

using namespace std;

int arr[10];

//트리는 넉넉하게 데이터의 4배 크기로 지정 
int init(int* tree, int node, int s, int e)
{
    //node는 현재 노드를 말함
    if (s == e) return tree[node] = arr[s];

    int m = (s + e) / 2;
    //완전 이진 트리에 가까운 형태로 node * 2가 왼쪽 자식 노드
    // node * 2 + 1은 오른쪽 자식 노드
    int a = init(tree, node * 2, s, m);
    int b = init(tree, node * 2 + 1, m + 1, e);
    return tree[node] = a + b; //구간 합
    //return tree[node] = min(a, b); //최소값
}

int query(int* tree, int node, int ts, int te, int qs, int qe)
{
    //트리의 구간이 질의 구간에 완전 포함되는 경우 트리가 값을 내주는 형태
    
    //트리 구간이 질의 구간에 포함
    if (ts >= qs && qe >= te) return tree[node];

    //트리 구간이 질의 구간과 전혀 겹치지 않음
    if (te < qs || qe < ts) return 0;
    //if (te < qs || qe < ts) return 999999; //최소값

    int m = (ts + te) / 2;
    int a = query(tree, node * 2, ts, m, qs, qe);
    int b = query(tree, node * 2 + 1, m + 1, te, qs, qe);

    return a + b;
    //return min(a, b); //최소값
}

int update(int* tree, int node, int s, int e, int ii, int value)
{
    //ii: 수정할 인덱스
    //value: 더할 값

    //ii가 범위 내에 있으면 업데이트 진행
    if (ii < s || ii > e) return tree[node];
    tree[node] += value;
    if (s == e) return tree[node];

    int m = (s + e) / 2;
    int a = update(tree, node * 2, s, m, ii, value);
    int b = update(tree, node * 2 + 1, m + 1, e, ii, value);

    return tree[node] = a + b;
    //return tree[node] = min(a, b);
}


int main()
{
    std::cout << "Hello World!\n";
}
