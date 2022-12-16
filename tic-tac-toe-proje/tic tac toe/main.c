#include <stdio.h>
#include <stdlib.h>

//oyuncu bilgisi girme
struct oyuncuBilgisi
{
    char isim[50];
    char soyisim[50];
    int yas;

}oyuncu1,oyuncu2;

//oyun matrisindeki kareleri tanýmlama



//matris olusturma
void matris_olustur()
{

    char kare[10] = { '0','1', '2', '3', '4', '5', '6', '7', '8', '9' };

    system("cls");
    printf("\t\t\   Tic Tac Toe\n");
    printf("\t\t   ***********\n\n");

    printf("\n\n");

    printf("1. Oyuncu  (X)  -  2. Oyuncu (O)\n\n\n");


    printf("     |     |    \n");
    printf("  %c  |  %c  |  %c\n", kare[1], kare[2], kare[3]);

    printf("____ |____ |____\n");
    printf("     |     |    \n");

    printf("  %c  |  %c  |  %c\n", kare[4], kare[5], kare[6]);

    printf("____ |____ |____\n");
    printf("     |     |    \n");

    printf("  %c  |  %c  | %c \n", kare[7], kare[8], kare[9]);

    printf("     |     |    \n\n");
}

//oyun galibiyet durumunu belirleme
int oyunKazan()
{

    char kare[10] = { '0','1', '2', '3', '4', '5', '6', '7', '8', '9' };

    if (kare[1] == kare[2] && kare[2] == kare[3])
        return 1;

    else if (kare[4] == kare[5] && kare[5] == kare[6])
        return 1;

    else if (kare[7] == kare[8] && kare[8] == kare[9])
        return 1;

    else if (kare[1] == kare[4] && kare[4] == kare[7])
        return 1;

    else if (kare[2] == kare[5] && kare[5] == kare[8])
        return 1;

    else if (kare[3] == kare[6] && kare[6] == kare[9])
        return 1;

    else if (kare[1] == kare[5] && kare[5] == kare[9])
        return 1;

    else if (kare[3] == kare[5] && kare[5] == kare[7])
        return 1;

    else if (kare[1] != '1' && kare[2] != '2' && kare[3] != '3' &&
        kare[4] != '4' && kare[5] != '5' && kare[6] != '6' && kare[7]
        != '7' && kare[8] != '8' && kare[9] != '9')
        return -1;
    else
        return  0;
}

/* 1 dönüyorsa oyun bitti, oyuncu kazandý
-1 dönüyorsa oyun bitti, kazanan yok.
0 dönüyorsa oyuna devam et.*/

int main()
{

    FILE *dosya;
    char cumle1[10],cumle2[10],cumle3[10],cumle4[10];
    int i;

    if((dosya=fopen("tictactoe.txt","r"))!=NULL)
    {
        fscanf(dosya,"%s",&cumle1);
        fscanf(dosya,"%s",&cumle2);
        fscanf(dosya,"%s",&cumle3);
        fscanf(dosya,"%s",&cumle4);
        printf("\t\t*****%s %s*****\n\n\t\t----%s %s----", cumle1,cumle2,cumle3,cumle4);
    }
    else
    {
        printf("DOSYA BULUNAMADI!");
    }
    fclose(dosya);

    struct oyuncuBilgisi oyuncu1,oyuncu2;

    printf("\n\n");

    printf("\t\t\   Tic Tac Toe\n");
    printf("\t\t   ***********\n\n");

    printf("***********Oyuncu Bilgilerini Giriniz***********\n");

    printf("\n");

    printf("1. oyuncunun adi: ");
    scanf("%s", &oyuncu1.isim);

    printf("1. oyuncunun soyadi: ");
    scanf("%s", &oyuncu1.soyisim);

    printf("1. oyuncunun yasi: ");
    scanf("%d", &oyuncu1.yas);

    printf("2. oyuncunun adi: ");
    scanf("%s", &oyuncu2.isim);

    printf("2. oyuncunun soyadi: ");
    scanf("%s", &oyuncu2.soyisim);

    printf("2. oyuncunun yasi: ");
    scanf("%d", &oyuncu2.yas);

    matris_olustur();
    oyunKazan();

    return 0;
}
