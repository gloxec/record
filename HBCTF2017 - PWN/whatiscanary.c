//
//  whatiscanary
//  hbctf
//
//  Created by hook on 2017/4/5.
//  Copyright © 2017年 pwn2crc. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_LEN
char flagbuf[32];

void readFlag(char *str)
{
    FILE *pFile = fopen("flag", "r");
    fseek(pFile, 0, SEEK_END);
    int len = ftell(pFile);
    rewind(pFile);
    fread(str, 8, len, pFile);
    fclose(pFile);
    str[len] = '\0';
}

void readBuf(char *str)
{
    int i;
    for (i = 0; ; i++) {
        char temp = getchar();
        if (temp == 10) {
            str[i] = '\0';
            break;
        }
        str[i] = temp;
    }
}

void vulFun()
{
    char buf[32];
    printf("input your name(length < 10):");
    readBuf(buf);
    int len = strlen(buf);
    if (len > 10) {
        printf("error, will exit!\n");
        exit(0);
    }
    printf("hello, '%s', wish you have a good result!\n", buf);
}

int main()
{
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    printf("hello, welcome to HBCTF!\n");
    readFlag(flagbuf);
    vulFun();
    printf("exit\n");
    return 0;
}
