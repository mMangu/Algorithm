#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
vector <int> segmentTree;
int arr[5] = {1, 2, 3, 4, 5};
const int arr_size = 5;

int make_segmentTree(int node, int start, int end) {
    if (start == end) return segmentTree[node];
    int mid = (start + end) / 2;
    int left_result = make_segmentTree(node * 2, start, mid);
    int right_result = make_segmentTree(node * 2 + 1, mid + 1, end);
    return left_result + right_result;
}

int sum(int node, int start, int end, int left, int right) {
    //node = 노드 번호, start , end = 해당 노드가 포함하고 있는 범위, left, right = 우리가 구하고자 하는 범위
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return segmentTree[node];

    int mid = (left + right) / 2;
    int left_result = sum(node * 2, start, mid, left, right);
    int right_result = sum(node * 2 + 1, mid + 1, end, left, right);
    return left_result + right_result; 
}

void update_segmentTree(int node, int start, int end, int index, int diff) {
    if (index < start || index > end) return;
    segmentTree[node] = segmentTree[node] + diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update_segmentTree(node * 2, start, mid, index, diff);
        update_segmentTree(node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main() {
    int tree_Height = (int)ceil(log2(arr_size));
    int tree_Size = (1 << (tree_Height + 1));
    segmentTree.resize(tree_Size);
    make_segmentTree(1, 0, arr_size - 1);
}