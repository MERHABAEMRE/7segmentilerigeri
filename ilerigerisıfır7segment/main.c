#include <main.h>
   int sayac=0 ,btn=1;
   const int digit[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
   
   butonmap(){
   
   if(input(pin_c0)){
     while(true){
     if(input(pin_c1)||input(pin_c2)){
     break;
     }
     if(sayac==9){
     delay_ms(500);
     output_b(0x3F);
     sayac=0;
     }
     else{
     delay_ms(500);
     sayac++;
     output_b(digit[sayac]);
     }
     }
   }
     
   else if(input(pin_c2)){
     while(true){
     if(input(pin_c0)||input(pin_c1)){
     break;
     }
     if(sayac==0){
     delay_ms(500);
     output_b(0x6F);
     sayac=9;
     }
     else{
     delay_ms(500);
     sayac--;
     output_b(digit[sayac]);
     }
     }
   }
   else if(input(pin_c1)){  
     output_b(digit[sayac]);
     while(true){   
     delay_ms(250);        
     if(input(pin_c0)||input(pin_c2)){
     btn=1;
     break;
     }
     else if(input(pin_c1) && btn==2){
     btn=1;
     output_b(0x6F);
     sayac=9;
     }
     else if(input(pin_c1) && btn==1){
     btn++;
     output_b(0x3F);
     sayac=0;
     } 
     }
   }
     
     
     return sayac;
   }
   
void main()
{
   
   
   while(TRUE)
   {
   butonmap();
   
   }
}


