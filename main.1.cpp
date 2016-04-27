#include <allegro.h>
#include <vector>
#include <stdio.h>
#include "Fila.h"
#include "Hamburguer.h"

#define heigth  600
#define width   800

int ComparaHamburguer(Fila pedidos, Hamburguer burgue){
    int i, cmp = 0;
    Hamburguer *first = new Hamburguer;
    first->vazio();
    if(pedidos.Remover(*first))
        printf("removeu\n");
    else
        printf("bugou\n");
    //first.vazio();
    for(i = 0; i < 8; i++){
        if(first->retornaIngrediente(i) == burgue.retornaIngrediente(i)){
            //printf("cmp: %d i: %d\nfirst: %d\nburgue: %d\n", cmp, i, first.retornaIngrediente(i), burgue.retornaIngrediente(i));
            cmp++;
        }
    }
    if(cmp == 8){
        return 1;
    }else{
        return 0;
    }
    delete first;
}

int botoes(Hamburguer *atual, Fila pedidos){
    int pos = 0;
    bool feito = 1, certo;

    //avalia X dos botões
    if(mouse_x > 0 && mouse_x < 120)
        pos = 10;
    else if(mouse_x > 680 && mouse_x < 800)
        pos = 20;
    else if(mouse_x >= 475 && mouse_x <= 555)
        pos = 30;

    //avalia Y dos botões
    if(mouse_y > 180 && mouse_y < 300)
        pos += 1;
    else if(mouse_y > 325 && mouse_y < 445)
        pos += 2;
    else if(mouse_y > 470 && mouse_y < 590)
        pos += 3;
    else if(mouse_y >= 539 && mouse_y <= 593)
        pos += 4;
        
        

    switch(pos){
    case 11:
        atual->poeIngrediente(1);
        break;
    case 12:
        atual->poeIngrediente(2);
        break;
    case 13:
        atual->poeIngrediente(3);
        break;
    case 21:
        atual->poeIngrediente(4);
        break;
    case 22:
        atual->poeIngrediente(5);
        break;
    case 23:
        atual->poeIngrediente(6);
        break;
    case 34:
        {
        cout << "ta feito" << endl;
        bool certo = ComparaHamburguer(pedidos, *atual);
        if(certo){cout << "deu certo\n";}else{cout << "deu errado\n";}
        feito = 0;
        break;
        }
    default:
        //cout << "click vazio" << endl;
        break;
    }
    //centraliza o mouse para impedir cliques extras
    position_mouse(width/2,heigth/2);
    return feito;
}

int main(void)
{
    int i = 0, ing;
    bool fazendo = 0, certo = 0, click = 0;
    Hamburguer Fazendo;
    Fazendo.vazio();
    srand(time(NULL));

    //cria e preenche pedidos
    Fila pedidos;
    while(!pedidos.Cheia()){
        Hamburguer pediu;
        pediu.vazio();
        pedidos.Inserir(pediu);
    }

//________________________________________Inicio_Allegro_______________________________________________________
    if (allegro_init() != 0){
        printf("Erro ao iniciar o Allegro");
        return 1;
    }
    install_keyboard();
    install_mouse();

   /* set a graphics mode sized 320x200 */
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, width, heigth, 0, 0);
    BITMAP *BURGUE  = load_bitmap("Imagens/burgue.bmp", NULL);
    BITMAP *BURGUE2 = load_bitmap("Imagens/burgue2.bmp", NULL);
    BITMAP *FUNDO   = load_bitmap("Imagens/fundo.bmp", NULL);
    BITMAP *HAMBURGUER_CIMA_ICONE = load_bitmap("Imagens/hamburguercima_icone.bmp", NULL);
    BITMAP *HAMBURGUER_BAIXO_ICONE = load_bitmap("Imagens/hamburguerbaixo_icone.bmp", NULL);
    BITMAP *CARNE_ICONE = load_bitmap("Imagens/carne_icone1.bmp", NULL);
    BITMAP *QUEIJO_ICONE = load_bitmap("Imagens/queijo_icone.bmp", NULL);
    BITMAP *ALFACE_ICONE = load_bitmap("Imagens/alface_icone.bmp", NULL);
    BITMAP *BACON_ICONE = load_bitmap("Imagens/bacon_icone.bmp", NULL);
    BITMAP *PICLES_ICONE = load_bitmap("Imagens/Picles_icone.bmp", NULL);
    BITMAP *TOMATE_ICONE = load_bitmap("Imagens/tomate_icone.bmp", NULL);
    BITMAP *buffer  = create_bitmap(width, heigth);

    //blit(FUNDO, screen, 0, 0, 0, 0, width, heigth);
    show_mouse(screen);

//________________________________________Fim_Allegro______________________________________________________

    //jogo começa aqui
    do{
        if(!fazendo){//Cria hamburguer para ser preenchido e trava impede criação de novos
            printf("Aqui nois faiz\n");
            Hamburguer *Fazendo;
            //Fazendo.vazio();
            fazendo = 1;
        }

        blit(FUNDO, buffer, 0, 0, 0, 0, width, heigth);
        draw_sprite(buffer, CARNE_ICONE, 0, 180);
        draw_sprite(buffer, QUEIJO_ICONE, 0, 325);
        draw_sprite(buffer, BACON_ICONE, 0, 470);
        draw_sprite(buffer, ALFACE_ICONE, 680, 180);
        draw_sprite(buffer, TOMATE_ICONE, 680, 325);
        draw_sprite(buffer, PICLES_ICONE, 680,470);

        if(keypressed()){
            int burgui = readkey();
            if(burgui == 7217){
                draw_sprite(buffer, BURGUE, (width - BURGUE->w)/2, (heigth - BURGUE->h)/2);
            }
            if(burgui == 7474){
                draw_sprite(buffer, BURGUE2, (width - BURGUE2->w)/2, (heigth - BURGUE2->h)/2);
                i += 10;
            }
            clear(screen);
            blit(buffer, screen, 0, 0, 0, 0, width, heigth);
        }

        /*
        if((mouse_x >= 475 && mouse_x <= 555) && (mouse_y >= 539 && mouse_y <= 593) && mouse_b){
            printf("Ta feito\n");
            bool certo = ComparaHamburguer(pedidos, Fazendo);
            position_mouse(width/2,heigth/2);
            if(certo){printf("deu certo\n");}else{printf("deu errado\n");}
            fazendo = 0;
        }*/
        if(!mouse_b){
            click = 0;
        }else{
            click = 1;
        }
        if(click){
            click = 0;
           botoes(&Fazendo, pedidos);

        }
    }
    while(!key[KEY_ESC]);

   return 0;
}


END_OF_MAIN()
