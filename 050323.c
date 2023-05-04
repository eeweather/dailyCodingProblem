/*Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Run-length encoding is a fast and simple method of encoding strings. 
The basic idea is to represent repeated successive characters as a single count and character. 
For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding.
 You can assume the string to be encoded have no digits and consists solely of alphabetic characters. 
 You can assume the string to be decoded is valid.*/



 #include <stdio.h>

int encode(char* str, int strLength){
   //char encoded[100]; Once I realized i could just print as I went and didn't need to worry about string size/ manipulation this problem was much easier
   int count = 1;
   printf("original: %s, encoded : ", str);
   for (int i=0; i<strLength; i++){
      if(str[i]==str[i+1]){
         count++;
      }
      else{
         printf("%d",count);
         printf("%c",str[i]);
         count = 1;
      }
   }
   printf("\n");
   return 0;
}

int decode(char* str, int strLength){
   int count =0 ;
   printf("original: %s, decoded: ", str);
   for(int i=0;i<strLength; i+=2){
      count=str[i]-48;  
      for(int j=0;j<count;j++){
         printf("%c",str[i+1]);
      }
   }
   printf("\n");
   return 0;
}

int main() {
   // printf() displays the string inside quotation
   //printf("Hello, World!");
   encode("AAABBB", 6);

   decode("3A3B", 4);

   return 0;
}