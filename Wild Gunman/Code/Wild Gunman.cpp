#include <allegro.h>
#include <stdio.h>

BITMAP *buffer, *fondo, *outlaws;
SAMPLE *menu;

int po=900, animacion=0;

int main ()
{
    allegro_init();
    install_keyboard();

    set_window_title("Wild GunMan");
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,400, 0, 0);


    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }

	set_volume(70,70);

    buffer=create_bitmap(800,400);
    fondo=load_bitmap("../Imagenes/fondo.bmp",NULL);
    outlaws=load_bitmap("../Imagenes/outlaws.bmp",NULL);

    menu=load_wav("../Sonidos/menu.wav");

    play_sample(menu,255,0,1000,0);


   while(!key[KEY_ESC]){

        draw_sprite(buffer,fondo,0,0);

        textprintf_ex(buffer,font,320,100,makecol(255,255,255),-1,"PUT SOME CODE HERE...");


        po-=10;

        if(po==450){
            masked_blit(outlaws,buffer,812,0,po,100,116,240);
            rest(5000);
        }
        else{
        animacion++;
        if(animacion>0 && animacion<=5){
            masked_blit(outlaws,buffer,0,0,po,100,116,240);
            printf("Estoy aca");}

        else if(animacion>5 && animacion<=10)
            masked_blit(outlaws,buffer,116,0,po,100,116,240);

        else if(animacion>10 && animacion<=15)
            masked_blit(outlaws,buffer,232,0,po,100,116,240);

        else if(animacion>15 && animacion<=20)
            masked_blit(outlaws,buffer,116,0,po,100,116,240);

        if(animacion==20) animacion=0;
        }
        draw_sprite(screen,buffer,0,0);
        rest(40);
        clear(buffer);
    }
    destroy_bitmap(fondo);
    destroy_bitmap(outlaws);
    destroy_bitmap(buffer);

    return 0;
}
END_OF_MAIN ()


