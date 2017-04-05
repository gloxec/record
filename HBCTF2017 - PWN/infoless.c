//
//  infoless
//  hbctf
//
//  Created by hook on 2017/4/5.
//  Copyright © 2017年 pwn2crc. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void vulfunc()
{
    char sbuf[10];
    read(0, sbuf, 60);
}

int main()
{
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    puts("welcome to HBCTF\nThis is a classical pwn:");
    vulfunc();
    puts("bye~");
    fflush(stdout);
    return 0;
}
