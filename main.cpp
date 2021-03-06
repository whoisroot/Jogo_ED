#include <allegro.h>
#include <vector>
#include <stdio.h>
#include "Fila.h"
#include "Hamburguer.h"
#include "Pilha.h"

#define heigth  600
#define width   800

int ComparaHamburguer(Fila pedidos, Hamburguer burgue){
    bool works;
    int i, cmp = 0;
    Hamburguer *first = new Hamburguer;
    first->vazio();
    *first = pedidos.Remover(works);
    if(works)
        cout << "removeu burgue" << endl;
    for(i = 0; i < 8; i++){
        cout << "first " << i << ": " << first->retornaIngrediente(i) << endl;
        cout << "burgue "<< i << ": " << burgue.retornaIngrediente(i) << endl;
        if(first->retornaIngrediente(i) == burgue.retornaIngrediente(i)){
            cmp++;
        }
    }
    delete first;

    if(cmp == 8){
        return 1;
    }else{
        return 0;
    }
}

int botoes(Hamburguer *atual, Fila pedidos, Pilha *ing, bool pao){
    int pos = 0, botoes_valor;
    bool feito = 1, hamb_atual = 0, certo;

    //avalia X dos botões
    if(mouse_x > 0 && mouse_x < 120)
        pos = 10;
    else if(mouse_x > 680 && mouse_x < 800)
        pos = 20;
    else if(mouse_x >= 475 && mouse_x <= 555)
        pos = 30;
    else if(mouse_x >= 340 && mouse_x <=460)
        pos = 40;
    else if(mouse_x >= 230 && mouse_x <= 325)
        pos = 50;

    //avalia Y dos botões
    if(mouse_y > 180 && mouse_y < 300)
        pos += 1;
    else if(mouse_y > 325 && mouse_y < 445)
        pos += 2;
    else if(mouse_y > 470 && mouse_y < 590 && pos < 30)
        pos += 3;
    else if(mouse_y >= 539 && mouse_y <= 593)
        pos += 4;

    switch(pos){
    case 11:
        atual->poeIngrediente(1);
        ing->Inserir(1);
        break;
    case 12:
        atual->poeIngrediente(2);
        ing->Inserir(2);
        break;
    case 13:
        atual->poeIngrediente(3);
        ing->Inserir(3);
        break;
    case 21:
        atual->poeIngrediente(4);
        ing->Inserir(4);
        break;
    case 22:
        atual->poeIngrediente(5);
        ing->Inserir(5);
        break;
    case 23:
        atual->poeIngrediente(6);
        ing->Inserir(6);
        break;
    case 34:
        {
        cout << "ta feito" << endl;
        certo = ComparaHamburguer(pedidos, *atual);
        if(certo){cout << "deu certo\n";}else{cout << "deu errado\n";}
        feito = 0;
        hamb_atual = 1;
        break;
        }
    case 44:
        {
            if(pao){
                atual->poeIngrediente(7);
                ing->Inserir(7);
                pao = 0;
                break;
            }
            else{
                atual->poeIngrediente(0);
                ing->Inserir(0);
                pao = 1;
                break;
            }
        }
    case 54:
        int lixo;
        ing->Remover(lixo);
        hamb_atual++;
        break;

    default:
        //cout << pos << endl;
        break;
    }
    botoes_valor = certo*1000 + hamb_atual*100 + feito*10 + pao;
    return botoes_valor;
    }

int main(void)
{
    int matrix_ing_hamb[10][8];
    int i = 0, ing, botoes_valor, y = 535, hamb_atual = 0, pontuacao = 0;
    bool fazendo = 0, bacon = 0, click = 0, pao = 0;
    Hamburguer Fazendo;
    Pilha *Ingredientes;
    srand(time(NULL));

    //cria e preenche pedidos
    Fila pedidos;
    while(!pedidos.Cheia()){
        Hamburguer pediu;
        for(i = 0; i < 8; i++){
            matrix_ing_hamb[hamb_atual][i] = pediu.retornaIngrediente(i);
        }
        hamb_atual++;
        //pediu.vazio();
        pedidos.Inserir(pediu);
    }
    hamb_atual = 0;

//________________________________________Inicio_Allegro_______________________________________________________
    if (allegro_init() != 0){
        printf("Erro ao iniciar o Allegro");
        return 1;
    }
    install_keyboard();
    install_mouse();

    int pontua = text_length(font, "Pontuação: 00");
   /* set a graphics mode sized 320x200 */
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, width, heigth, 0, 0);
    BITMAP *FUNDO   = load_bitmap("Imagens/fundo2.bmp", NULL);
    BITMAP *HAMBURGUER_CIMA_ICONE = load_bitmap("Imagens/novos/hamburguercima_icone_2.bmp", NULL);
    BITMAP *HAMBURGUER_CIMA = load_bitmap("Imagens/hamburguercima.bmp", NULL);
    BITMAP *HAMBURGUER_BAIXO_ICONE = load_bitmap("Imagens/novos/hamburguerbaixo_icone_2.bmp", NULL);
    BITMAP *HAMBURGUER_BAIXO = load_bitmap("Imagens/hamburguerbaixo.bmp", NULL);
    BITMAP *CARNE_ICONE = load_bitmap("Imagens/novos/carne_icone.bmp", NULL);
    BITMAP *CARNE = load_bitmap("Imagens/carne.bmp", NULL);
    BITMAP *QUEIJO_ICONE = load_bitmap("Imagens/novos/queijo_icone.bmp", NULL);
    BITMAP *QUEIJO = load_bitmap("Imagens/queijo.bmp", NULL);
    BITMAP *ALFACE_ICONE = load_bitmap("Imagens/alface_icone.bmp", NULL);
    BITMAP *ALFACE = load_bitmap("Imagens/novos/alface.bmp", NULL);
    BITMAP *BACON_ICONE = load_bitmap("Imagens/novos/bacon_icon.bmp", NULL);
    BITMAP *BACON = load_bitmap("Imagens/bacon2.bmp", NULL);
    BITMAP *PICLES_ICONE = load_bitmap("Imagens/novos/Picles_icone.bmp", NULL);
    BITMAP *PICLES = load_bitmap("Imagens/Picles.bmp", NULL);
    BITMAP *TOMATE_ICONE = load_bitmap("Imagens/tomate_icone.bmp", NULL);
    BITMAP *ESPATULA = load_bitmap("Imagens/novos/Espatula_2.bmp", NULL);
    //BITMAP *TOMATE_ICONE = load_bitmap("Imagens/tomate_icone.bmp", NULL);

    BITMAP *buffer  = create_bitmap(width, heigth);

    set_mouse_sprite(ESPATULA);
    //show_mouse(buffer);

//________________________________________Fim_Allegro______________________________________________________

    //jogo começa aqui
    do{
        if(!fazendo){//Cria hamburguer para ser preenchido e trava impede criação de novos
            printf("Aqui nois faiz\n");
            Ingredientes = new Pilha;
            Fazendo.vazio();
            fazendo = 1;
            y = 515;
        }

        //Imprime fundo e ícones dos botões
        //clear_to_color(buffer, makecol(255, 255, 255));
        blit(FUNDO, buffer, 0, 0, 0, 0, width, heigth);
        textprintf_ex(buffer, font, width - (pontua + 20), 30, makecol(255, 255, 255), -1, "PONTUAÇÃO: %d", pontuacao);
        textprintf_centre_ex(buffer, font, width/2, 130, makecol(255, 255, 255),
            -1, "Hamburguer: %d                    Alface: %d", matrix_ing_hamb[hamb_atual][1], matrix_ing_hamb[hamb_atual][4]);
        textprintf_centre_ex(buffer, font, width/2, 140, makecol(255, 255, 255),
            -1, "Queijo: %d                        Tomate: %d", matrix_ing_hamb[hamb_atual][2], matrix_ing_hamb[hamb_atual][5]);
        textprintf_centre_ex(buffer, font, width/2, 150, makecol(255, 255, 255),
            -1, "Bacon: %d                         Picles: %d", matrix_ing_hamb[hamb_atual][3], matrix_ing_hamb[hamb_atual][6]);
        draw_sprite(buffer, CARNE_ICONE, 0, 180);
        draw_sprite(buffer, QUEIJO_ICONE, 0, 325);
        draw_sprite(buffer, BACON_ICONE, 0, 470);
        draw_sprite(buffer, ALFACE_ICONE, 680, 180);
        draw_sprite(buffer, TOMATE_ICONE, 680, 325);
        draw_sprite(buffer, PICLES_ICONE, 680, 470);
        if(pao)
            draw_sprite(buffer, HAMBURGUER_CIMA_ICONE, 340, 505);
        else
            draw_sprite(buffer, HAMBURGUER_BAIXO_ICONE, 340, 505);


        //Imprime hamburguer em execução
        ing = 1;
        y = 0;
        //cout << ing;
        while(ing){
            ing = Ingredientes->Percorre();
            int y_pos = 515 - y;
            switch(ing){
            case 1:
                draw_sprite(buffer, HAMBURGUER_BAIXO, (width - HAMBURGUER_BAIXO->w)/2, (y_pos - HAMBURGUER_BAIXO->h));
                break;
            case 2:
                draw_sprite(buffer, CARNE, (width-CARNE->w)/2, (y_pos + 100 + CARNE->h/2)/2);
                y += 0.57 * CARNE->h;
                break;
            case 3:
                draw_sprite(buffer, QUEIJO, (width - QUEIJO->w)/2, (y_pos + 180 + QUEIJO->h/2)/2);
                y += 0.4 * QUEIJO->h;
                break;
            case 4:
                draw_sprite_ex(buffer, BACON, (width - BACON->w)/2, (y_pos + BACON->h/2)/2, 0, bacon);
                bacon = Fazendo.retornaIngrediente(3)%2;
                break;
                //y += BACON->h;
                break;
            case 5:
                cout << "acabou o alface" << endl;
                //draw_sprite(buffer, ALFACE, (width - ALFACE)/2, (y_pos - ->h));
                //y += ALFACE->h;
                break;
            case 6:
                cout << "sem tomates" << endl;
                //draw_sprite(buffer, TOMATE_ICONE);
                //y += TOMATE->h;
                break;
            case 7:
                draw_sprite(buffer, PICLES, (width - PICLES->w)/2, (y_pos - PICLES->h));
                y += PICLES->h;
                break;
            case 8:
                draw_sprite(buffer, HAMBURGUER_CIMA, (width - HAMBURGUER_CIMA->w)/2, (y_pos - HAMBURGUER_CIMA->h));
                y += HAMBURGUER_CIMA->h;
                break;
            }
        }

        if(!(mouse_b & 1)){
            click = 0;
        }else{
            click = 1;
        }
        if(click){
            while(mouse_b){}
            click = 0;
            //cout << "x: " << mouse_x << "\ny: " << mouse_y << endl;
            botoes_valor = botoes(&Fazendo, pedidos, Ingredientes, pao);
            pontuacao += (botoes_valor/1000)*75;
            hamb_atual += (botoes_valor/100)%10;
            fazendo = ((botoes_valor/10)%10)%10;
            pao = botoes_valor%10;
            //cout << "pao: " << botoes_valor%10 << " fazendo: "<< fazendo << " hamb_atual: " << hamb_atual << endl;
        }
        //clear(screen);
        blit(buffer, screen, 0, 0, 0, 0, width, heigth);
        //clear_to_color(buffer, makecol(255, 255, 255));
        show_mouse(screen);
    }
    while(!key[KEY_ESC]);

   return 0;
}


END_OF_MAIN()
