#include <stdio.h>

//int main(int argv, char **argv) {
int main() {
   /*
    int nDigit = 0, nWhite = 0, nOther = 0;
    char c;
    while ((c = getchar()) != EOF) {
          switch (c) {
                 case ' ':
                          nWhite++;
                          break;
                 case '\n':
                          nWhite++;
                          break;
                 case '\t':
                          nWhite++;
                          break;
                 case '0':
                          nDigit++;
                          break;
                 case '1':
                          nDigit++;
                          break;
                 case '2':
                          nDigit++;
                          break;
                 case '3':
                          nDigit++;
                          break;
                 case '4':
                          nDigit++;
                          break;
                 case '5':
                          nDigit++;
                          break;
                 case '6':
                          nDigit++;
                          break;
                 case '7':
                          nDigit++;
                          break;
                 case '8':
                          nDigit++;
                          break;
                 case '9':
                          nDigit++;
                          break;
                 default: 
                          nOther++;
                          break;
*/
    int nDigit = 0, nOther = 0;
    char c;
    while ((c = getchar()) !=EOF) {
          switch (c) {
                
                 case '0':

                 case '1':

                 case '2':

                 case '3':

                 case '4':

                 case '5':

                 case '6':

                 case '7':

                 case '8':

                 case '9':
                          nDigit++;
                          break;
                 default: 
                         ;
                           
                            
        }
   }        
          printf("the number of digits is: %d \n", nDigit);  
       //   printf("the number of white spaces is: %d \n", nWhite);
        //  printf("the number of others is: %d \n", nOther); 

     return 0;
}
             
          
