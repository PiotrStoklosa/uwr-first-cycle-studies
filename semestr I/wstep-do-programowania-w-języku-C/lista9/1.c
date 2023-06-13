#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc<4)
    {
        printf("Za malo argumentow. Prosze podac nazwe pliku wynikowego, liczbe wierszy i nazwy pilkow wejsciowych");
        return 0;
    }
    int lwierszy=atoi(argv[2]);
    FILE *plik= fopen(argv[1], "w");
    if (plik==NULL)
    {
        printf("Nie udalo sie otworzyc pliku do dopisywania");
        return 0;
    }
    int x=lwierszy;
    int znak, liczbawierszy;
    for (int i=3; i<argc; i++)
    {
        znak=' ';
        x=lwierszy;
        liczbawierszy=0;
        FILE *plik2= fopen(argv[i], "rt");
        if (plik2==NULL)
        {
            printf("\nNie udalo sie otworzyc pliku\n");
            continue;
        }
        while(znak!=EOF)
        {
            znak=fgetc(plik2);
            if (znak=='\n')
                liczbawierszy++;
        }
        rewind(plik2);
        fprintf(plik, "\n%s (%d)\n\n", argv[i], liczbawierszy);
        if (liczbawierszy<x)
            x=liczbawierszy;
        while(x)
        {
            znak=fgetc(plik2);
            if (znak=='\n')
                x--;
            fputc(znak,plik);
        }
        fclose(plik2);
    }
    fclose(plik);
    return 0;
}
