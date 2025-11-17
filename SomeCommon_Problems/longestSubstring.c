#include <stdio.h>
#include <string.h>

int findLongest(char * ch){
    int char_map[256] = {0};
    int left = 0, right;
    int max = 0;

    int len = strlen(ch);


    for(right = 0; right < len; right++){        
        int current_ch = ch[right];

        while(char_map[current_ch] == 1){
            char_map[ch[left]] = 0;
            left++;
        }
        char_map[ch[right]] = 1;

        int current_len = right - left +1;
        if(current_len > max)
            max = current_len;
    }

    return max;
}


int main(){
    char * str = "abcdabacd";
    printf("The string: %s\n", str);

    int max_len = findLongest(str);
    printf("The longest substring length = %d", max_len);
    return 0;
}