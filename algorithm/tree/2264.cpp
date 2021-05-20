#include <cstdio>

int inOrder[100005], postOrder[100005], idx[100005];
void preOrder(int inBegin, int inEnd, int postBegin, int postEnd) {
    if (inBegin > inEnd || postBegin > postEnd) return;

    int rootIdx = idx[postOrder[postEnd]];
    int leftSize = rootIdx - inBegin;
    int rightSize = inEnd - rootIdx;
    printf("%d ", postOrder[postEnd]);
    preOrder(inBegin, rootIdx - 1, postBegin, postBegin + leftSize - 1);
    preOrder(rootIdx + 1, inEnd, postBegin + leftSize, postEnd - 1);
}
int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &inOrder[i]);
    for (int i = 1; i <= N; i++)
        scanf("%d", &postOrder[i]);
    for (int i = 1; i <= N; i++)
        idx[inOrder[i]] = i;

    preOrder(1, N, 1, N);
}


// inorder left -> root -> right
//postorder left -> right -> root