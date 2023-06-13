#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tab[18]= {165,198,202,163,209,211,140,143,175,185,230,234,179,241,243,156,159,191};
int tab2[18]= {0xC4,0xC4,0xC4,0xC5,0xC5,0xC3,0xC5,0xC5,0xC5,0xC4,0xC4,0xC4,0xC5,0xC5,0xC3,0xC5,0xC5,0xC5};
int tab3[18]= {0x84,0x86,0x98,0x81,0x83,0x93,0x9A,0xB9,0xBB,0x85,0x87,0x99,0x82,0x84,0xB3,0x9B,0xBA,0xBC};
int main(int argc, char *argv[])
{
    int d,c,p=0,w=0;
    if (argv <= 1)
    {
        printf("Brak argumentow \n");
        return 1;
    }
    if (strcmp(argv[1], "win2utf") ==0)
    {
        while((c=getchar())!=EOF)
        {
            p=0;
            for(int i=0; i<18; i++)
            {
                if (c==tab[i])
                {
                    putchar(tab2[i]);
                    putchar(tab3[i]);
                    p=1;
                    break;
                }
            }
            if (p==0)
                putchar(c);
        }
    }
    else
    {
       while((c=getchar())!=EOF)
        {
            p=0;
            w=0;
            for(int i=0; i<18; i++)
            {
                if (c==tab2[i])
                {
                    d=getchar();
                    p=0;
                    for (int j=i; j<18; j++)
                    {
                        if (tab3[j]==d)
                            {
                                putchar(tab[j]);
                                w=1;
                                break;
                            }
                    }
                    if (w==0)
                        putchar(d);
                    p=1;
                    break;
                }
            }
            if (p==0)
                putchar(c);
        }
    }
    return 0;
}
