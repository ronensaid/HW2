#include <stdio.h>
#include "my_mat.h"

int main (){
    
    int i,j;
    char ch;
    scanf("%c",&ch);

    while(ch!='D'){
        if (ch=='A'){
            func1();
        }
        else if(ch=='B'){
            scanf("%d",&i);
            scanf("%d",&j);
            int check=func2(i, j);
            if (check==1)
                printf("True\n");
            else
                printf("False\n");
        }
       else if(ch=='C'){
            scanf("%d",&i);
            scanf("%d",&j);
            int check=func3(i, j);
            printf("%d\n", check);
        }
        scanf("%c",&ch);
    }
    return 0;
}