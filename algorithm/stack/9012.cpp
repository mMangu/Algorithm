#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;


int main() {
    int n; scanf("%d", &n);
    while (n--) {
        stack <char> s;
        char word[52];
        scanf("%s", word);
        for (int i = 0; i < strlen(word); i++) {
            if (!s.empty() && word[i] == ')' && s.top() == '(')
                s.pop();
            else s.push(word[i]);
        }
        if (!s.empty()) printf("NO\n");
        else printf("YES\n");
    }
}