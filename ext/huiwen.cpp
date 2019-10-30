#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long const g_max_len = 5024000L;
char strs[g_max_len];
char s[2 * g_max_len + 1];
long p[2 * g_max_len + 1];

// Manacher
long max_huiwen(const char* str) {

    long slen = strlen(str);
    cout << slen << endl;

    long len = 2 * slen + 1;
    s[0] = '$';
    long j = 1;
    for (long i = 0; i < slen; ++i) {
        s[j++] = '#';
        s[j++] = str[i];
    }
    s[j++] = '#';
    s[j] = 0;

    // cout << s << endl; 

    cout << __LINE__ << endl;

    long max_len = 0;
    long mx = 0;
    long id = 0;
    for (long i = 0; i < len; ++i) {
        if (i < mx) {
            p[i] = min(p[2 * id - i], mx - i);
        } else {
            p[i] = 1;
        }

        while (s[i - p[i]] == s[i + p[i]]) { // 不需边界判断，因为左有'$',右有'\0'
            ++p[i];
        }

        if (i + p[i] > mx) {
            id = i;
            mx = i + p[i];
        }
        max_len = max(max_len, p[i] - 1);
    }

    return max_len;
}

int main() {

    char s[] = "abcabcba";
    for (long i = 0; i < g_max_len; ++i) {
        int d = i % 24;
        char c = 'a' + d;
        strs[i] = c;
        strs[i] = 'a';
    }
    strcpy(strs + 10000, s);
    strs[strlen(strs)] = 'z';

    // cout << str << endl;
    long len = max_huiwen(strs);
    cout << len << endl;

    return 0;
}
