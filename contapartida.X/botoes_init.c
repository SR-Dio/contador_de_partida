/*
 * File:   botoes_init.c
 * Author: 19179166
 *
 * Created on 3 de Março de 2021, 16:09
 */


#include <xc.h>

#include "botoes_init.h"

void botoes_init (void)
{
    TRISDbits.TRISD0 = 1;
    TRISDbits.TRISD1 = 1;
}

int botao_liga (void)
{
    return (PORTDbits.RD1);
}

int botao_desliga (void)
{
    return (PORTDbits.RD0);
}