/* EL2208 Praktikum Pemecahan Masalah dengan C
*Modul       :
*Percobaan   : 
*Hari/Tanggal: Saturday/10-04-2021
*Nama/NIM    : Oktavianus Irvan Sitanggang/13218071
*Asisten/NIM : 
*Nama File   : main.c
*Deskripsi   : 
*/


#include <stdio.h>
#include <math.h>
#include <string.h>

int maks (int a, int b){
    if (a > b)
        return a;
    return b;
}

int solve(char *in){
    if (strlen(in) == 1){
        return 1;
    }
    else if (strlen(in) == 2){
        if (in[0] > in[1]){
            char temp = in[0];
            in[0] = in[1];
            in[1] = temp;
        }
        return 1;
    }

    int n = strlen(in);
    int halfway = n/2;
    int midNum = in[halfway] - '0';
    int add = 0;
    if (midNum%2){
        add = 1;
    }
    char firstHalf[100];
    memset(firstHalf, '\0', sizeof(firstHalf));
    strncpy(firstHalf, in, halfway+add);
    char secondHalf[100];
    memset(secondHalf, '\0', sizeof(secondHalf));
    strncpy(secondHalf, in+halfway+add, halfway+1-add);

    int depth = maks(solve(firstHalf), solve(secondHalf));
    
    char inInverse[100] = "\0";
    strncat(inInverse, secondHalf, 100);
    strncat(inInverse, firstHalf, 100);

    strncpy(in, inInverse, n);
    return 1 + depth;
}


int main(){
    char inNum[100];
    scanf("%[^\n]%*c", inNum);

    int n = strlen(inNum);
    int ans = 0;
    ans = solve(inNum);

    printf("Tingkat Kecantikan = %d\n", ans);
    printf("Potensi = %s\n", inNum);

    return 0;
}
