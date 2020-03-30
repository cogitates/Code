#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 这个题目潜在的说明是str是足够长的
	void replaceSpace(char *str,int length) {
        int numOfSpace = 0;
        for(int i = 0;i < length;i++){
            if(str[i] == ' ')
                numOfSpace++;
        }

        int newLength = length + 2 * numOfSpace;

        char temp[3] = {'0', '2', '%'};

        while(newLength - 1 >= 0 && newLength > length){
            if(str[length-1] != '0'){
                str[--newLength] = str[length-1];
                newLength--;
            }else{
                for(int i = 0;i < 3;i++){
                    str[--newLength] = temp[i];
                    newLength--;
                }
            }
            length--;
        }
	}
};