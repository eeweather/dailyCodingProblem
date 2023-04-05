// /*Good morning! Here's your coding interview problem for today.

// This problem was asked by Grammarly.

// Soundex is an algorithm used to categorize phonetically, such that two names that sound alike but are spelled differently have the same representation.

// Soundex maps every name to a string consisting of one letter and three numbers, like M460.

// One version of the algorithm is as follows:

// Remove consecutive consonants with the same sound (for example, change ck -> c).
// Keep the first letter. The remaining steps only apply to the rest of the string.
// Remove all vowels, including y, w, and h.
// Replace all consonants with the following digits:
// b, f, p, v → 1
// c, g, j, k, q, s, x, z → 2
// d, t → 3
// l → 4
// m, n → 5
// r → 6
// If you don't have three numbers yet, append zeros until you do. Keep the first three numbers.
// Using this scheme, Jackson and Jaxen both map to J250.

// Implement Soundex.*/
#include <stdio.h>
#include <string.h>

void Soundex(char *name, int stringLength);
 
// Driver Code
int main()
{
    Soundex("Jackson", 7);
    return 0;
}

void Soundex(char *name, int stringLength){
    char map[]= {'0','0','0','0','\0'};
    char lastletter = '0';
    char currentletter; 
    currentletter = '0';
    int count =1;
    map[0]= name[0];
    int i;

    for(i=1; i<stringLength; i++){
        if(count!=4){
            if (name[i]== 'b' ||name[i]== 'f' ||name[i]== 'p' ||name[i]== 'v'){
                currentletter='1';
            }
            else if (name[i]== 'c' ||name[i]== 'g' ||name[i]== 'j' ||name[i]== 'k' ||name[i]== 'q' ||name[i]== 's' ||name[i]== 'x' ||name[i]== 'y'){
                currentletter='2';
            }
            else if(name[i]== 'd' ||name[i]== 't'){
                currentletter='3';
            }
            else if(name[i]== 'l'){
                currentletter= '4';
            }
            else if(name[i]== 'm' ||name[i]== 'n'){
                currentletter='5';
            }
            else if(name[i]== 'r'){
                currentletter='6';
            }
            if(currentletter!=lastletter){
                //printf("count: %d,curletter: %c,lastletter: %c,map:%s, name[i]: %c\n",count,currentletter,lastletter,map, name[i]); 
                map[count]=currentletter;
                lastletter= currentletter;
                count++;
            }
        }
    }
    
    printf("soundex map: %s\n", map);

    return;
}