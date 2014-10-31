#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf ("这是一个古老的算术问题！\n");
    printf ("某地需要搬运砖块，已知男人一人搬3块，女人一人搬2块，小孩两人搬一块。问用45人正好搬45块砖，有多少种搬法?\n");
    int man, woman, child, type;
    type = 0;
    for (man = 0; man <= 45; man ++){
        for (woman = 0; woman <= 45; woman ++){
            for (child = 0; child <= 45; child ++){
                if ((man * 3 + woman *1 + child * 0.5 == 45) && (man + woman + child == 45)){
                    printf ("man： %d  woman: %d  child:%d\n", man, woman, child);
                    type ++;
                }
            }
        }
    }printf ("\nThis question has %d type!\n ");
    return 0;
}
