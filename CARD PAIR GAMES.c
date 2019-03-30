#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Deklarasi gotoxy agar fungsi koordinat dapat dijalankan//
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//fungsi main/utama//
void main(){

    //Deklarasi variabel - variabel yang digunakan//
    int gambar[4][4],i1,i2,x,y,pilih,attempt=15;

    printf("========================================\n");
    printf("PAIRS\nAuthor : SUNU ILHAM PRADIKA\nNPM : 17081010045");
    printf("\n========================================\n\n");
    Sleep(1000);

    //Menu awal game//
    pilihan:
    system("cls");
    printf("1. New Game\n2. How to play(Recommended)\n3. Exit\n\nMasukkan Pilihan : ");scanf("%d",&pilih);
    switch(pilih){        //switch pilihan menu//
    case 1  : system("cls"); goto start; break;
    case 2  : printf("1. Pertama - tama akan ditampilkan gambar yang terbuka selama 4 detik. HAFALKAN!Karena anda hanya diberi 32x kesempatan untuk menebak.\n2. Pilih 2 gambar untuk dibuka dengan menekan angka 1 - 16.\n3. Gambar yang ditampilkan berbentuk persegi dengan tiap baris,kolom berisi gambar - gambar.\n4. Bila gambar yang dibuka sama, maka gambar akan tetap terbuka. Apabila salah, maka akan menutup kembali.\n5. Buka semua gambar hingga terbuka semua dan menangkan game.\n6. Selamat Bermain!!\n\n");system("PAUSE");system("cls");goto pilihan; break;
    case 3  : goto end; break;
    default : printf("SALAH"); break;}

    start:
    gotoxy(36,11);
    printf("GAME START\n\n\n");
    system("pause");system("cls");

     //isi gambar terbuka kunci jawaban//
    gambar[0][0]=1;gambar[0][1]=1;gambar[0][2]=2;gambar[0][3]=2;
    gambar[1][0]=3;gambar[1][1]=3;gambar[1][2]=4;gambar[1][3]=4;
    gambar[2][0]=5;gambar[2][1]=5;gambar[2][2]=6;gambar[2][3]=6;
    gambar[3][0]=7;gambar[3][1]=7;gambar[3][2]=8;gambar[3][3]=8;

    printf("HAFALKAN!\n\n");
    //Menampilkan kunci jawaban//
    for(x=0;x<=3;x++){
    for(y=0;y<=3;y++){
    printf("[%d]",gambar[x][y]);
    }printf("\n");
    }
    Sleep(4000);system("cls");

    //Membuat nilai awal menjadi 0//
    gambar[0][0]=0;gambar[0][1]=0;gambar[0][2]=0;gambar[0][3]=0;
    gambar[1][0]=0;gambar[1][1]=0;gambar[1][2]=0;gambar[1][3]=0;
    gambar[2][0]=0;gambar[2][1]=0;gambar[2][2]=0;gambar[2][3]=0;
    gambar[3][0]=0;gambar[3][1]=0;gambar[3][2]=0;gambar[3][3]=0;

    checkpoint:
    if (attempt>0){
    //Membuat gambar awal dan setelah mengalami perubahan dengan kondisi terakhir//
    printf("Pilihan Gambar :\n");
    for(x=0;x<=3;x++){
    for( y=0;y<=3;y++){
    if(gambar[x][y]){
    printf("[%d]",gambar[x][y]);}
        else{printf("[*]");}
                      }
    printf("\n");}

    //Pemberitahuan sisa kesempatan menebak//
    printf("\n\nSisa kesempatan : %d kali",attempt);
    //Memilih elemen gambar pertama//
    printf("\nMasukkan pilihan elemen gambar 1 : ");scanf("%d",&i1);
    //Memilih elemen gambar kedua//
    printf("Masukkan pilihan elemen gambar 2 : ");scanf("%d",&i2);


        switch (i1){                      //switch pilihan pertama
		case 1  : gambar[0][0]=1; break;
		case 2  : gambar[0][1]=1; break;
		case 3  : gambar[0][2]=2; break;
		case 4  : gambar[0][3]=2; break;
		case 5  : gambar[1][0]=3; break;
		case 6  : gambar[1][1]=3; break;
		case 7  : gambar[1][2]=4; break;
		case 8  : gambar[1][3]=4; break;
		case 9  : gambar[2][0]=5; break;
		case 10 : gambar[2][1]=5; break;
		case 11 : gambar[2][2]=6; break;
		case 12 : gambar[2][3]=6; break;
        case 13 : gambar[3][0]=7; break;
		case 14 : gambar[3][1]=7; break;
		case 15 : gambar[3][2]=8; break;
		case 16 : gambar[3][3]=8; break;
		default : printf("SALAH!"); break;}

        switch (i2){                      //switch pilihan kedua//
		case 1  : gambar[0][0]=1; break;
		case 2  : gambar[0][1]=1; break;
		case 3  : gambar[0][2]=2; break;
		case 4  : gambar[0][3]=2; break;
        case 5  : gambar[1][0]=3; break;
		case 6  : gambar[1][1]=3; break;
		case 7  : gambar[1][2]=4; break;
		case 8  : gambar[1][3]=4; break;
		case 9  : gambar[2][0]=5; break;
		case 10 : gambar[2][1]=5; break;
		case 11 : gambar[2][2]=6; break;
		case 12 : gambar[2][3]=6; break;
        case 13 : gambar[3][0]=7; break;
		case 14 : gambar[3][1]=7; break;
		case 15 : gambar[3][2]=8; break;
		case 16 : gambar[3][3]=8; break;
		default : printf("SALAH!"); break;}


    system("cls");
    //Memunculkan hasil pilihan elemen matriks//
    for(x=0;x<=3;x++){
    for(y=0;y<=3;y++){
    if(gambar[x][y]){
    printf("[%d]",gambar[x][y]);}
    else {printf("[*]");}
                     }printf("\n");
                     }

    //Syarat untuk menang dan apabila salah satu pasangan tidak dipilih bersama maka valuenya akan dikembalikan menjadi 0//
    if(gambar[0][0]!=0&&
       gambar[0][1]!=0&&
       gambar[0][2]!=0&&
       gambar[0][3]!=0&&
       gambar[1][0]!=0&&
       gambar[1][1]!=0&&
       gambar[1][2]!=0&&
       gambar[1][3]!=0&&
       gambar[2][0]!=0&&
       gambar[2][1]!=0&&
       gambar[2][2]!=0&&
       gambar[2][3]!=0&&
       gambar[3][0]!=0&&
       gambar[3][1]!=0&&
       gambar[3][2]!=0&&
       gambar[3][3]!=0)
        {system("cls"); gotoxy(36,11); printf("YOU WIN"); Sleep(2000);goto pilihan; end: system("cls"); gotoxy(36,11); printf("GAME OVER\n"); system("PAUSE");}
        else{//memberi value 0 jika salah satu elemen tidak match dalam pilihan//
            if(gambar[0][0]==0&&gambar[0][1]==1||gambar[0][0]==1&&gambar[0][1]==0)
                {gambar[0][0]=0;gambar[0][1]=0;}
            if(gambar[0][3]==0&&gambar[0][2]==2||gambar[0][3]==2&&gambar[0][2]==0)
                {gambar[0][3]=0;gambar[0][2]=0;}
            if(gambar[1][0]==0&&gambar[1][1]==3||gambar[1][0]==3&&gambar[1][1]==0)
                {gambar[1][0]=0;gambar[1][1]=0;}
            if(gambar[1][2]==0&&gambar[1][3]==4||gambar[1][2]==4&&gambar[1][3]==0)
                {gambar[1][2]=0;gambar[1][3]=0;}
            if(gambar[2][0]==0&&gambar[2][1]==5||gambar[2][0]==5&&gambar[2][1]==0)
                {gambar[2][0]=0;gambar[2][1]=0;}
            if(gambar[2][2]==0&&gambar[2][3]==6||gambar[2][2]==6&&gambar[2][3]==0)
                {gambar[2][2]=0;gambar[2][3]=0;}
            if(gambar[3][0]==0&&gambar[3][1]==7||gambar[3][0]==7&&gambar[3][1]==0)
                {gambar[3][0]=0;gambar[3][1]=0;}
            if(gambar[3][2]==0&&gambar[3][3]==8||gambar[3][2]==8&&gambar[3][3]==0)
                        {gambar[3][2]=0;gambar[3][3]=0;}

    //Pemberian waktu delay selama 1 detik//
    Sleep(1000);
    //Pembersihan layar untuk selanjutnya membuat gambar dengan kondisi terakhir//
    system("cls");
    //printf("\n");
    attempt--;
    goto checkpoint;
    }
    } else
        {system("cls");gotoxy(36,11);printf("YOU LOSE");Sleep(1000);goto pilihan;}
    }
