/*Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?*/
#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10

int *hash_table[TABLE_SIZE];

int hash(int num){
    return num;
}

void init_hash_table() {
    for(int i = 0; i<TABLE_SIZE; i++){
        hash_table[i]= NULL;
    }
}

bool hash_table_insert(int *num){
    int index = hash(*num);
    if (hash_table[index]==NULL){
        hash_table[index] = *num; 
    }
}

void print_hash_table(){
    for(int i =0;i<TABLE_SIZE;i++){
        if(hash_table[i]==NULL){
            printf("%d ---\n",i);
        }
        else{
            printf("%d -%d-\n",i, hash_table[i]);
        }
    }
}

bool addUp(int *list, int listLength, int k){
//do double loop first, even tho you know its not efficient, to think about it

    // for(int i = 0; i<listLength; i++){
    //     for(int j=i+1; j<listLength; j++){
    //         if(list[i]+list[j]==k){
    //             return true;
    //         }
    //     }
    //     return false; //this works, how to do it one loop now
    // }

// do it with differences? a hash table!
init_hash_table();
for(int i =0; i<listLength;i++){
    hash_table_insert(&list[i]);
}

print_hash_table();

for(int i =0; i<listLength;i++){
    if(hash_table[k-list[i]]==NULL){
        return 0;
    }
    else{
        return 1;
    }
}

}

int main() {
    int list[]={1,2,4,5};
   printf("does it addUp: %d", addUp(list,4,8));
   return 0;
}