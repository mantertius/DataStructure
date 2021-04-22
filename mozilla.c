#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define DEBUG if(1)

int main() {
    char c[8];
    int pos,back,fwd;
    pos = -1;
    back = pos;
    int ct = 0;

    while (1)
    {

        int z;
        for (int i = 0; i < 8; i++)
        {
           z = scanf("%c",&c[i]);
            if(c[i] == '\n') break;
        }
        if(z == EOF)
        {
            break;
        }
        
        // back = 4
        // forward = 7
        // enter = 5
        int q = strlen(c);
        fputs(c,stdout);
        ct++;
        //c[strcspn(c, "\n")] = 0;
        switch (q)
        {
        case 4: //back
            DEBUG printf("{%d} [%s] = %d\n",ct,c,q);
            pos--;
            fwd++;
            break;
        case 7: //fwd
            DEBUG printf("{%d} [%s] = %d\n",ct,c,q);
            pos++;
            fwd--;
            break;
        case 5: //enter
            DEBUG printf("{%d} [%s] = %d\n",ct,c,q);
            pos++;
            break;
        default:
            DEBUG printf("-----%d---- [%s]\n",q,c);
        }
        
    }
    printf("BACK: %d\n",back);
    printf("FORWARD: %d\n",fwd);
    
	return 0;
}