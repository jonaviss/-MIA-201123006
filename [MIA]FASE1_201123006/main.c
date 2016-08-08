#include <stdio.h>

int main()
{
    /*----------------------------------------ANALIZADOR LEXICO----------------------------------------*/

    char *cadena;
    char *palabraInsertada;
    cadena="h afff 1 ";
    int estado=0;
    char *lexema="";

    for(int i=0;i<strlen(cadena);i++){
        char letra=cadena[i];
        int codigoAscii=letra;
        switch (estado) {
        case 0:
            if(isalpha(cadena[i])){
            estado=1;
            lexema=letra;
        }else if(isdigit(cadena[i])){
                estado=2;
                lexema=letra;
            }else if(codigoAscii==32){
                estado=0;
            }else if(codigoAscii>=33 && codigoAscii<=47 ||codigoAscii>=58 && codigoAscii<=63){
                estado=3;
                lexema=letra;
            }

            break;
        case 1:
            if((isalpha(cadena[i]))){
            estado=1;
            lexema=lexema+letra;

        }else{
                printf("\n");
                printf("Palabra aceptada:");
                palabraInsertada =lexema;
                //printf("%s",&lexema);
                printf("\n");
                palabraInsertada="";
                lexema="";
                estado=0;
                i--;
            }

            break;

        case 2:
            if(isdigit(cadena[i])){
            estado=2;
            lexema=lexema+letra;
            }else{
                printf("\n");
                printf("Palabra aceptada:");
                palabraInsertada =lexema;
                //printf("%s",&lexema);
                printf("\n");
                palabraInsertada="";
                lexema="";
                estado=0;
                i--;
            }
            break;

        case 3:
            printf("\n");
            printf("Palabra aceptada:");
            palabraInsertada =lexema;
            //printf("%s",&lexema);
            palabraInsertada="";
            printf("\n");
            lexema="";
            estado=0;
            i--;
            break;

            }

}

    /*----------------------------------------ANALIZADOR LEXICO----------------------------------------*/










    return 0;
}
