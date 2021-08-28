#include<stdio.h>
#include<bitset>
#include<iostream>

void show_mem_rep(char* start, int n)
{
    for(int i= 0; i < n; i++)
    {
        printf("%.2x", start[i]);
    }

    printf("\n");
}


int main()
{
 std::bitset<4> bt(12);
 std::cout << bt <<std::endl;

    int i = 0x01234567;
    show_mem_rep((char*)&i, sizeof(i));
    getchar();

    return 0;
}