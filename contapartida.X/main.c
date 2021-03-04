/*
 * File:   main.c
 * Author: 19179166
 *
 * Created on 3 de Março de 2021, 16:03
 */


#include <xc.h>
#include "config.h"
#include "display7seg_init.h"
#include "contatos_init.h"
#include "botoes_init.h"
#include "delay.h"

void main(void) 
{
    
    char estado = 0;
    unsigned char cont = 0;
    int t; 
    
    while(1)
    {
        switch (estado)
                
        {
            case 0:
                    botoes_init();
                    display7seg_init();
                    contatos_init();
                    estado = 1;
                    break;    
                
            case 1:
                    if(botao_liga()== 1 && k1status()== 0)
                        estado = 2;
                    break;
                    
            case 2:
                    k1(1);
                    k2(1);
                    k3(0);
                    estado = 3;
                    break;
            
                
            case 3:
                    t = 3000;   
                    estado = 4;
                    break;
            
            case 4:
                    delay(1);
                    --t;
                    if(t <=0)
                        estado = 5;
                    if(botao_desliga()== 1)
                        estado = 7;
                    break;
                    
            case 5:
                    k1(1);
                    k2(0);
                    k3(1);
                    ++cont;
                    if ( cont >= 10 )
                       cont = 0;
                    estado = 6;
                    break;
            case 6:  
                   
                    if(botao_desliga() == 1)
                        estado = 7;
                    break;
            case 7:
                    k1(0);
                    k2(0);
                    k3(0);
                    estado = 1;
                    break;    
        }       
        display7seg (cont);
        
    }                
}
   