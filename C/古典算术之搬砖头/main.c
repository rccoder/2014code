#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf ("����һ�����ϵ��������⣡\n");
    printf ("ĳ����Ҫ����ש�飬��֪����һ�˰�3�飬Ů��һ�˰�2�飬С�����˰�һ�顣����45�����ð�45��ש���ж����ְᷨ?\n");
    int man, woman, child, type;
    type = 0;
    for (man = 0; man <= 45; man ++){
        for (woman = 0; woman <= 45; woman ++){
            for (child = 0; child <= 45; child ++){
                if ((man * 3 + woman *1 + child * 0.5 == 45) && (man + woman + child == 45)){
                    printf ("man�� %d  woman: %d  child:%d\n", man, woman, child);
                    type ++;
                }
            }
        }
    }printf ("\nThis question has %d type!\n ");
    return 0;
}
