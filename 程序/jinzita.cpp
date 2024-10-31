#include <stdio.h>

int main() {
    int M; 
    char C; 
    scanf("%d", &M);
    scanf(" %c", &C); 

    for (int i = 1; i <= M; i++) {
    	      int space=M-i;
        for (int j = 0; j <=space ; j++) { 
        printf(" ");}
        for(int k=1;k<=i;k++){
		
		    printf("%c ", C);
			}{
        
        printf("\n");  
    }
}

    return 0;
}
