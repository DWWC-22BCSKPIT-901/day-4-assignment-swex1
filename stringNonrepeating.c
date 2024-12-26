//2 Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return 
//-1.
#include <stdio.h>
#include <string.h>
int firstUniqChar(char *s) {
    int count[256] = {0}; 
    for (int i = 0; s[i] != '\0'; i++) {
        count[(unsigned char)s[i]]++;
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (count[(unsigned char)s[i]] == 1) {
            return i;         }
    }
return -1; 
}
int main() {
    char s[] = "sweta";
    int index = firstUniqChar(s);
   if (index != -1) {
        printf("The first non-repeating character is at index: %d\n", index);
    } else {
        printf("No non-repeating character found.\n");
    }

    return 0;
}
