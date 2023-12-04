#include <stdio.h>
#include <string.h>

int lenoflastword(char *s) {
    int length = 0;
    int i = strlen(s) - 1;

    
    while (i >= 0 && s[i] == ' ') {
        i--;
    }


    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    char input[100]; 
    
   
    scanf("%99[^\n]", input); 

    
    int ans = lenoflastword(input);
    printf("%d\n", ans);
    return 0;
}
