#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int chara[200];
    int best = 0;
    int start = 0, end = 0;
    memset(chara, -1, sizeof(chara));
    while (s[end] != '\0') {
        if (chara[s[end]] == -1) {
            chara[s[end]] = end;
            best = best > (end - start + 1) ? best : (end - start + 1);
        }
        else {
            for (int j = start; j < chara[s[end]]; j++) {
                chara[s[j]] = -1;
            }
            start = chara[s[end]] + 1;
            chara[s[end]] = end;
        }
        end++;
    }
    return best;
}

int main() {
	return 0;
}
