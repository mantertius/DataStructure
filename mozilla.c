#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define DEBUG if(0)

int main() {
    char c[8];
    int pos,back,fwd,enter;
    pos = -1;
    back = 0;
    int ct = 0;
    fwd = 0;
    enter = -1;

    while (1)
    {
        int z;
        // for (int i = 0; i < 8; i++)
        // {
        //    z = scanf("%c",&c[i]);
        //    DEBUG printf("[%c]",c[i]);
        //     if(c[i] == '\n') break;
        // }
        char* b = fgets(c,9,stdin);
        //puts(c);
        // back = 4
        // forward = 7
        // enter = 5
        if(b == NULL)
        {
            //DEBUG printf("QUEBRA!\n");
            break;
        }
        
        int q = strlen(c);
        if (c[q-1] == '\n')
        {
            c[q-1] = '\0';
        }
        q = strlen(c);
        //printf("%s\n",c);
        fflush(stdin);
        ct++;
        switch (q)
        {
        case 4: //back
            DEBUG printf("4 {%d} [%s] = %d\t\t",ct,c,q);
            if(ct == 1 ) break;
            if(pos == 0) break;
            if (back>=0)
            {
                pos--;
                back--;
                fwd++;
                enter--; 
            }
            break;
        case 7: //fwd
            DEBUG printf("7 {%d} [%s] = %d\t\t",ct,c,q);
            if (fwd != 0)
            {
                back++;
                fwd--;
                pos++;
                break;
            }
            break;
        case 5: //enter
            DEBUG printf("5 {%d} [%s] = %d\t\t",ct,c,q);
            if(enter == -1)
            {
                pos++;
                enter++;
                back = 0;
                fwd = 0;
                break;    
            }
            if (pos == 0 && back == 0)
            {
                fwd = 0;
            }
            pos++;
            enter++;
            back++;
            break;
        default:
            // DEBUG printf("{%d} [%s] = %d\t",ct,c,q);
            // DEBUG printf("back:[%d] | fwd:[%d]\n",back,fwd);
            DEBUG printf("DEFAULT.\n");
            break;
        }
        DEBUG printf("back:[%d] | fwd:[%d] | pos:[%d]\n",back,fwd,pos);
    }
    printf("BACK: %d\n",back);
    printf("FORWARD: %d\n",fwd);
	return 0;
}