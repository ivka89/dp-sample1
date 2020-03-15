#include <stdio.h>

int main() {
  int n;
  scanf("%d",&n);
  //nope
  if ((0<n) && (n<10000)){
      // for (int i=1 ; i<=n ;i++){
          // if ( (i%3 ==0) && (i%5==0)){
          //          printf( "tiktak\n");}
          // else if ( i%3 ==0){
          //          printf( "tik\n");}
			
          // else if ( i%5 ==0){
          //          printf( "tak\n");}
	       
          // else { printf("%d\n", i);}
      // }
      if ( (n%3 ==0)){
          printf( "tiktak\n");}
      else{
          printf( "tik\n");}
      printf("test\n");
  }
  else {printf( "-1\n");}

return 0;
}

