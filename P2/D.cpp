//Igor Lonak

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PRT(int *wiersze, int** matrix){

    int i,j;
    fflush(stdout);

    printf("%d ", *wiersze);
    printf("\n");
    for(i=0;i<(*wiersze);i++){

        int ilosc = *(*(matrix+i));

        fflush(stdout);

        for(j=0;j<ilosc+1;j++){
            printf("%d ", *(*(matrix+i)+j));
        }
        printf("\n");
    }
    fflush(stdout);
}

int** AFR(int ilosc, int* dane, int** matrix, int *wiersze){

    int i;
    *wiersze = *wiersze+1;
    int* temp = malloc((ilosc+1)*(sizeof(int)));
    *temp = ilosc;

    for(i=1; i<ilosc+1; i++){
        *(temp+i) = *(dane+i-1);
    }

    matrix = realloc(matrix, ((*wiersze))*sizeof(int *));

    if(*wiersze>=2){

        for(i=*(wiersze)-1; i>0; i--){
            *(matrix+i) = *(matrix+i-1);
        }
    }

    *matrix = temp;

    return matrix;
}

int** ALR(int ilosc, int* dane, int** matrix, int* wiersze){

    int i;
    *wiersze = *wiersze+1;
    matrix = realloc(matrix, sizeof(int *)*(*wiersze));
    *(matrix+*wiersze-1) = malloc(sizeof(int)*(ilosc+1));
    *(*(matrix+*wiersze-1)) = ilosc;
    for(i=1;i<ilosc+1;i++){
        *(*(matrix+*wiersze-1)+i) = *(dane+i-1);
    }
    return matrix;
}

int** AFC(int ilosc, int* dane, int** matrix, int* wiersze){
    int i,j;
    if(ilosc<*wiersze){
        for(i=0;i<ilosc;i++){
            int temp = *(*(matrix+i));
            temp = temp+1;
            *(matrix+i) = realloc(*(matrix+i), sizeof(int)*(temp+1));
            *(*(matrix+i)) = temp;
            for(j=temp-1;temp>1;temp--){
                *(*(matrix+i)+temp) = *(*(matrix+i)+temp-1);
            }
            *(*(matrix+i)+1) = *(dane+i);
        }
    }
    else if(ilosc==*wiersze){
        for(i=0;i<*wiersze;i++){
            int temp = *(*(matrix+i));
            temp = temp+1;
            *(matrix+i) = realloc(*(matrix+i), sizeof(int)*(temp+1));
            *(*(matrix+i)) = temp;
            for(j=temp-1;temp>1;temp--){
                *(*(matrix+i)+temp) = *(*(matrix+i)+temp-1);
            }
            *(*(matrix+i)+1) = *(dane+i);
        }
    }
    else{
        matrix = realloc(matrix, sizeof(int *)*ilosc);
        for(i=0;i<*wiersze;i++){
            int temp = *(*(matrix+i));
            temp = temp+1;
            *(matrix+i) = realloc(*(matrix+i), sizeof(int)*(temp+1));
            *(*(matrix+i)) = temp;
            for(j=temp-1;temp>1;temp--){
                *(*(matrix+i)+temp) = *(*(matrix+i)+temp-1);
            }
            *(*(matrix+i)+1) = *(dane+i);
        }
        for(i=*wiersze;i<ilosc;i++){
            for(i=*wiersze;i<ilosc;i++){
                *(matrix+i) = malloc(sizeof(int)*2);
                *(*(matrix+i)) = 1;
                *(*(matrix+i)+1) = *(dane+i);
            }
        }
        *wiersze = ilosc;
    }

    return matrix;
}

int** ALC(int ilosc, int* dane, int** matrix, int* wiersze){
    int i;
    if(ilosc<*wiersze){
        for(i=0;i<ilosc;i++){
            int temp = *(*(matrix+i));
            temp = temp+1;
            *(matrix+i) = realloc(*(matrix+i), sizeof(int)*(temp+1));
            *(*(matrix+i)) = temp;
            *(*(matrix+i)+temp) = *(dane+i);
        }
    }
    else if(ilosc==*wiersze){
        for(i=0;i<*wiersze;i++){
            int temp = *(*(matrix+i));
            temp = temp+1;
            *(matrix+i) = realloc(*(matrix+i), sizeof(int)*(temp+1));
            *(*(matrix+i)) = temp;
            *(*(matrix+i)+temp) = *(dane+i);
        }
    }
    else{
        matrix = realloc(matrix, sizeof(int *)*ilosc);
        for(i=0;i<*wiersze;i++){
            int temp = *(*(matrix+i));
            temp = temp+1;
            *(matrix+i) = realloc(*(matrix+i), sizeof(int)*(temp+1));
            *(*(matrix+i)) = temp;
            *(*(matrix+i)+temp) = *(dane+i);
        }
        for(i=*wiersze;i<ilosc;i++){
            *(matrix+i) = malloc(sizeof(int)*2);
            *(*(matrix+i)) = 1;
            *(*(matrix+i)+1) = *(dane+i);
        }
        *wiersze = ilosc;
    }

    return matrix;
}

int** IBR(int numer, int ilosc, int* dane, int** matrix, int* wiersze){
    int i;
    int *temp;
    temp = malloc((ilosc+1)*sizeof(int));
    *temp=ilosc;
    for(i=1;i<ilosc+1;i++)
    {
        *(temp+i)=*(dane+i-1);
    }

    if(numer>=0&&numer<*wiersze){
        *wiersze = *wiersze+1;
        matrix = realloc(matrix, sizeof(int *)*(*wiersze));
        for(i=*wiersze-1;i>numer;i--){
            *(matrix+i) = *(matrix+i-1);
        }
        *(matrix+numer) = temp;
    }
    return matrix;
}

int** IAR(int numer, int ilosc, int* dane, int** matrix, int* wiersze){

    int i;
    int *temp;
    temp = malloc((ilosc+1)*sizeof(int ));
    *temp=ilosc;
    for(i=1;i<ilosc+1;i++)
    {
        *(temp+i)=*(dane+i-1);
    }
    if(numer>=0&&numer<*wiersze){
        *wiersze = *wiersze+1;
        matrix = realloc(matrix, sizeof(int *)*(*wiersze));
        for(i=*wiersze-1;i>numer+1;i--){
            *(matrix+i) = *(matrix+i-1);
        }
        *(matrix+numer+1) = temp;
    }


    return matrix;
}

int** IBC (int kolumna,int liczbawierszy,int *dane,int** matrix,int* wiersze){
    int i;
    int* temp;

    for(i=0;i<liczbawierszy;i++){

        if(i<*wiersze){
            if(kolumna<*(*(matrix+i)))
            {
                *(*(matrix+i))+=1;
                int ilosckolumn=*(*(matrix+i));
                temp = malloc((ilosckolumn+1)*sizeof(int *));
                int j;
                for(j=0;j<kolumna+1;j++){
                    *(temp+j)=*(*(matrix+i)+j);
                }
                *(temp+kolumna+1)=*(dane+i);

                for(j=kolumna+2;j<ilosckolumn+1;j++)
                {
                    *(temp+j)=*(*(matrix+i)+j-1);

                }
                free(*(matrix+i));
                *(matrix+i)=temp;
            }

            else {
                *(*(matrix+i))+=1;
                int ilosckolumn=*(*(matrix+i));
                temp = malloc((ilosckolumn+1)*sizeof(int *));
                int j;
                for(j=0;j<ilosckolumn;j++){
                    *(temp+j)=*(*(matrix+i)+j);
                }
                *(temp+ilosckolumn)=*(dane+i);
                free(*(matrix+i));
                *(matrix+i)=temp;

            }
        }
        else{
            int *temp;
            temp = malloc(sizeof(int));
            *temp=*(dane+i);
            matrix=ALR(1,temp,matrix,wiersze);
            free(temp);
        }
    }
    return matrix;
}

int** IAC (int kolumna,int liczbawierszy,int *dane,int** matrix,int* wiersze){
    int i;
    int* temp;

    for(i=0;i<liczbawierszy;i++){

        if(i<*wiersze){
            if(kolumna<*(*(matrix+i)))
            {
                *(*(matrix+i))+=1;
                int ilosckolumn=*(*(matrix+i));
                temp = malloc((ilosckolumn+1)*sizeof(int *));
                int j;
                for(j=0;j<kolumna+2;j++){
                    *(temp+j)=*(*(matrix+i)+j);
                }
                *(temp+kolumna+2)=*(dane+i);

                for(j=kolumna+3;j<ilosckolumn+1;j++)
                {
                    *(temp+j)=*(*(matrix+i)+j-1);

                }
                free(*(matrix+i));
                *(matrix+i)=temp;
            }

            else {
                *(*(matrix+i))+=1;
                int ilosckolumn=*(*(matrix+i));
                temp = malloc((ilosckolumn+1)*sizeof(int *));
                int j;
                for(j=0;j<ilosckolumn;j++){
                    *(temp+j)=*(*(matrix+i)+j);
                }
                *(temp+ilosckolumn)=*(dane+i);
                free(*(matrix+i));
                *(matrix+i)=temp;

            }
        }
        else{
            int *temp;
            temp = malloc(sizeof(int));
            *temp=*(dane+i);
            matrix=ALR(1,temp,matrix,wiersze);
            free(temp);
        }
    }
    return matrix;

}

void SWR(int* wierszA, int* wierszB, int** matrix){
    int* temp = *(matrix+*wierszA);
    *(matrix+*wierszA) = *(matrix+*wierszB);
    *(matrix+*wierszB) = temp;
}

void SWC(int kolumna1, int kolumna2, int** matrix, int *wiersze){
    int i;
    for( i=0;i<*wiersze;i++)
    {
        if(kolumna1<*(*(matrix+i))&&kolumna2<*(*(matrix+i)))
        {
            int tmp;
            tmp=*(*(matrix+i)+kolumna1+1);
            *(*(matrix+i)+kolumna1+1)=*(*(matrix+i)+kolumna2+1);
            *(*(matrix+i)+kolumna2+1)=tmp;
        }
    }

}

int** DLR(int** matrix, int* wiersze){

    free(*(matrix+*wiersze-1));
    *wiersze = *wiersze-1;
    matrix = realloc(matrix, sizeof(int *)*(*wiersze));

    return matrix;
}

int** DFR(int** matrix, int* wiersze){

    int i;

    free(*matrix);

    for(i=0;i<*wiersze-1;i++){
        *(matrix+i) = *(matrix+i+1);
    }

    *wiersze =  *wiersze-1;
    matrix = realloc(matrix, sizeof(int *)*(*wiersze));

    return matrix;
}

int** RMR(int** matrix, int* wiersze, int ilosc) {
    if (ilosc >= *wiersze){

        return matrix;
    }
    if (ilosc == 0){

        return DFR(matrix, wiersze);
    }
    if (ilosc == *wiersze - 1){
        return DLR(matrix, wiersze);
    }

    int i;
    *wiersze =  *wiersze-1;
    free(*(matrix+ilosc));
    for(i=ilosc;i<*wiersze;i++){
        *(matrix+i) = *(matrix+i+1);
    }

    matrix = realloc(matrix, sizeof(int *)*(*wiersze));

    return matrix;
}

int** DFC(int** matrix, int* wiersze){

    int j, k;

    for (j = 0; j < *wiersze; j++){
        for (k = 1; k < *(*(matrix+j)+0); k++){

            *(*(matrix+j)+k) = *(*(matrix+j)+k+1);

        }
    }

    for (j = 0; j < *wiersze; j++){

        if(*(*(matrix+j)+0) == 1 || *(*(matrix+j)+0) == 0) {
            matrix=RMR(matrix, wiersze, j);
            j--;
        }

        else {
            *(*(matrix + j) + 0) = *(*(matrix + j) + 0) - 1;
            *(matrix + j)= realloc((*(matrix+j)),sizeof(int )*(**(matrix+j)+1));
        }

    }

    return matrix;
}

int** DLC(int** matrix, int* wiersze){

    int j;

    for (j = 0; j < *wiersze; j++){

        if(*(*(matrix+j)+0) == 1 || *(*(matrix+j)+0) == 0) {
            matrix=RMR(matrix, wiersze, j);
            j--;
        }

        else {
            *(*(matrix + j) + 0) = *(*(matrix + j) + 0) - 1;
            *(matrix + j)= realloc((*(matrix+j)),sizeof(int )*(**(matrix+j)+1));
        }

    }

    return matrix;
}

int** RMC (int kolumna,int** matrix,int* wiersze){
    int i;
    for(i=0;i<*wiersze;i++)
    {
        if(kolumna==0&&*(*(matrix+i))==1)
        {
            matrix=RMR(matrix,wiersze,i);
            i--;
        }
        else if(kolumna<*(*(matrix+i))){
            *(*(matrix+i))-=1;
            int ilosckolumn=*(*(matrix+i));
            int *temp;
            temp = malloc((ilosckolumn+1)*sizeof(int *));
            int j;
            for(j=0;j<kolumna+1;j++)
            {
                *(temp+j)=*(*(matrix+i)+j);
            }
            for(j=kolumna+1;j<ilosckolumn+1;j++)
            {
                *(temp+j)=*(*(matrix+i)+j+1);

            }
            free(*(matrix+i));
            *(matrix+i)=temp;

        }
    }
    return matrix;
}

int** ISB (int wiersz,int kolumna,int iloscwierszy,int ilosckolumn,int* dane,int**matrix,int* wiersze){
    int i;
    if(wiersz>=*wiersze)
    {
        for(i=0;i<iloscwierszy;i++){

            int *tmp;
            tmp=malloc(ilosckolumn*sizeof(int*));
            int j;
            for(j=0;j<ilosckolumn;j++){

                *(tmp+j)=*(dane+i*ilosckolumn+j);

            }

            matrix=ALR(ilosckolumn,tmp,matrix,wiersze);
            free(tmp);
        }
    }
    else for(i=wiersz;i<wiersz+iloscwierszy;i++){
            if(i<*wiersze){
                if(kolumna>=*(*(matrix+i))){

                    *(*(matrix+i))+=ilosckolumn;
                    int ilosckolumn1=*(*(matrix+i));
                    int* temp;
                    temp = malloc((ilosckolumn1+1)*sizeof(int *));
                    int j;
                    for(j=0;j<ilosckolumn1-ilosckolumn+1;j++){
                        *(temp+j)=*(*(matrix+i)+j);
                    }
                    for(j=ilosckolumn1-ilosckolumn+1;j<ilosckolumn1+1;j++){

                        *(temp+j)=*(dane+((i-wiersz)*ilosckolumn)+j-ilosckolumn1+ilosckolumn-1);

                    }
                    free(*(matrix+i));
                    *(matrix+i)=temp;
                }
                else {

                    *(*(matrix+i))+=ilosckolumn;
                    int ilosckolumn1=*(*(matrix+i));
                    int* temp;
                    temp = malloc((ilosckolumn1+1)*sizeof(int *));
                    int j;
                    for(j=0;j<kolumna+1;j++){
                        *(temp+j)=*(*(matrix+i)+j);
                    }
                    for(j=kolumna+1;j<kolumna+1+ilosckolumn;j++){

                        *(temp+j)=*(dane+((i-wiersz)*ilosckolumn)+j-kolumna-1);

                    }
                    for(j=kolumna+1+ilosckolumn;j<ilosckolumn1+1;j++){

                        *(temp+j)=*(*(matrix+i)+j-ilosckolumn);
                    }
                    free(*(matrix+i));
                    *(matrix+i)=temp;
                }
            }
            else{
                int *tmp;
                tmp=malloc(ilosckolumn*sizeof(int*));

                int j;
                for(j=0;j<ilosckolumn;j++){

                    *(tmp+j)=*(dane+((i-wiersz)*ilosckolumn)+j);
                }
                matrix=ALR(ilosckolumn,tmp,matrix,wiersze);
                free(tmp);

            }
        }

    return matrix;
}

int** RMB (int wiersz,int iloscwierszy,int kolumna,int ilosckolumn, int** matrix, int *wiersze){

    int i;
    for(i=0;i<iloscwierszy;i++){

        if(wiersz+i<*wiersze){
            if(ilosckolumn>=(*(*(matrix+wiersz+i)))&&kolumna==0){

                matrix=RMR(matrix , wiersze, wiersz+i);
                i--;
                iloscwierszy--;
            }
            else  {
                int k;
                if(kolumna<*(*(matrix+wiersz+i))){

                    if(kolumna+ilosckolumn+1 > **(matrix+wiersz+i)){

                        *(matrix+wiersz+i)= realloc(*(matrix+wiersz+i),sizeof(int)*(kolumna+1));
                        **(matrix+wiersz+i)=kolumna;
                    }
                    else{
                        for( k=kolumna+ilosckolumn+1;k<(*(*(matrix+wiersz+i)))+1;k++){

                            *(*(matrix+wiersz+i)+k-ilosckolumn)=*(*(matrix+wiersz+i)+k);

                        }
                        *(*(matrix+wiersz+i))-=ilosckolumn;
                        *(matrix+wiersz+i)= realloc(*(matrix+wiersz+i),sizeof(int)*(*(*(matrix+wiersz+i))));
                    }

                }
            }
        }
    }
    return matrix;

}

int intBigEndian(int a){
    int temp = ((a>>24)&0xff) | ((a<<8)&0xff0000) |
               ((a>>8)&0xff00) | ((a<<24)&0xff000000);
    return temp;
}

unsigned short unsshortBigEndian(unsigned short a){
    unsigned short temp = (a>>8) | (a<<8);
    return temp;
}

int** RDF(int** matrix, unsigned short* wiersze, char* nazwa) {
    int i;
    for(i = 0; i < *wiersze; i++){
        free(*(matrix + i));
    }
    free(matrix);


    FILE* plik = fopen(nazwa, "rb");

    if(plik == NULL) {
        *wiersze = 0;
        return NULL;
    }

    unsigned short wiersze1 = 0;
    unsigned short kolumny;
    char temp;
    fread(&temp, sizeof(char), 1, plik);
    while (temp != '\n') {
        wiersze1 *= 10;
        wiersze1 += temp - '0';

        fread(&temp, sizeof(char), 1, plik);
    }

    if(wiersze1 == 0) {
        fclose(plik);
        *wiersze = wiersze1;
        return NULL;
    }
    *wiersze = wiersze1;
    matrix = malloc(*wiersze * sizeof(int*));
    for(i = 0; i < *wiersze; i++) {
        fread(&kolumny, sizeof(unsigned short), 1, plik);
        kolumny = unsshortBigEndian(kolumny);
        *(matrix + i) = malloc((kolumny + 1)*sizeof(int));
        *(*(matrix + i)) = kolumny;
        int j;
        for(j = 1; j < kolumny+1; j++) {
            int temp1;
            fread(&temp1, sizeof(int), 1, plik);
            temp1 = intBigEndian(temp1);
            *(*(matrix + i) + j) = temp1;
        }
    }
    fclose(plik);
    return matrix;
}

int** WRF(int** matrix, unsigned short* wiersze , char* nazwa) {
    FILE* plik = fopen(nazwa, "wb");
    if(plik == NULL) {
        return matrix;
    }
    fprintf(plik, "%d\n", *(wiersze));
    int i;
    for(i = 0; i < *(wiersze); i++) {
        int kolumny = *(*(matrix + i));
        kolumny = unsshortBigEndian(kolumny);
        fwrite(&kolumny, sizeof(unsigned short), 1, plik);
        int j;
        for(j = 1; j < *(*(matrix + i))+1; j++) {
            int temp = intBigEndian(*(*(matrix + i) + j));
            fwrite(&temp, sizeof(int), 1, plik);
        }
    }
    fclose(plik);
    return matrix;
}

int main() {

    int exit=0;
    int** matrix;
    int wiersze=0;
    matrix = malloc(sizeof(int *)*1);

    char* polecenie = malloc(4*sizeof(char));
    do {
        fflush(stdin);
        scanf("%s", polecenie);
        if (strcmp(polecenie,"AFR") == 0) {
            int ilosc;
            int *argumenty;
            scanf("%d", &ilosc);
            argumenty = malloc(ilosc * sizeof(int));
            int i;
            for ( i = 0; i < ilosc; i++) {
                scanf("%d", (argumenty + i));
            }
            fflush(stdin);
            matrix = AFR(ilosc, argumenty, matrix, &wiersze);
            free(argumenty);
        }
        else if(strcmp(polecenie,"ALR") == 0){
            int ilosc;
            int *argumenty;
            scanf("%d", &ilosc);
            argumenty = malloc(ilosc*sizeof(int));
            int i;
            for(i=0;i<ilosc;i++){
                scanf("%d",(argumenty+i));
            }
            fflush(stdin);
            matrix = ALR(ilosc, argumenty, matrix, &wiersze);
            free(argumenty);
        }
        else if(strcmp(polecenie,"AFC") == 0){
            int ilosc;
            int *argumenty;
            scanf("%d", &ilosc);
            argumenty = malloc(ilosc*sizeof(int));
            int i;
            for(i=0;i<ilosc;i++){
                scanf("%d",(argumenty+i));
            }
            fflush(stdin);
            matrix = AFC(ilosc, argumenty, matrix, &wiersze);
            free(argumenty);
        }
        else if(strcmp(polecenie,"ALC")==0){

            int ilosc;
            scanf("%d", &ilosc);
            int *argumenty;
            argumenty = malloc(ilosc*sizeof(int));
            int i;
            for(i=0;i<ilosc;i++){
                scanf("%d",(argumenty+i));
            }
            fflush(stdin);
            matrix = ALC(ilosc, argumenty, matrix, &wiersze);
            free(argumenty);
        }
        else if(strcmp(polecenie,"IBR")==0){
            int numer;
            scanf("%d", &numer);
            int ilosc;
            scanf("%d", &ilosc);
            int *argumenty;
            argumenty = malloc(ilosc*sizeof(int));
            int i;
            for(i=0;i<ilosc;i++){
                scanf("%d",(argumenty+i));
            }
            fflush(stdin);
            if(numer>=0&&numer<wiersze)
            matrix = IBR(numer, ilosc, argumenty, matrix,&wiersze);
            free(argumenty);

        }
        else if(strcmp(polecenie,"IAR")==0){
            int numer;
            scanf("%d", &numer);
            int ilosc;
            scanf("%d", &ilosc);
            int *argumenty;
            argumenty = malloc(ilosc*sizeof(int));
            int i;
            for(i=0;i<ilosc;i++){
                scanf("%d",(argumenty+i));
            }
            fflush(stdin);
            if(numer>=0&&numer<wiersze)
            matrix = IAR(numer, ilosc, argumenty, matrix, &wiersze);
            free(argumenty);
        }
        else if(strcmp(polecenie,"IBC")==0){
            int iloscwierszy;
            int kolumna;
            scanf("%d", &kolumna);
            scanf("%d", &iloscwierszy);
            int *argumenty;
            argumenty = malloc(iloscwierszy*sizeof(int));
            int i;
            for(i=0;i<iloscwierszy;i++){
                scanf("%d",(argumenty+i));
            }
            fflush(stdin);
            matrix=IBC(kolumna,iloscwierszy,argumenty,matrix,&wiersze);
            free(argumenty);
        }
        else if(strcmp(polecenie,"IAC")==0){
            int iloscwierszy;
            int kolumna;
            scanf("%d", &kolumna);
            scanf("%d", &iloscwierszy);
            int *argumenty;
            argumenty = malloc(iloscwierszy*sizeof(int));
            int i;
            for(i=0;i<iloscwierszy;i++){
                scanf("%d",(argumenty+i));
            }
            fflush(stdin);
            matrix=IAC(kolumna,iloscwierszy,argumenty,matrix,&wiersze);
            free(argumenty);
        }
        else if(strcmp(polecenie,"SWR")==0){
            int wierszA;
            int wierszB;
            scanf("%d",&wierszA);
            scanf("%d",&wierszB);
            fflush(stdin);
            if(wierszA<wiersze && wierszB<wiersze && wierszA>=0 &&wierszB>=0){
                SWR(&wierszA, &wierszB, matrix);
            }
        }
        else if(strcmp(polecenie,"SWC")==0){
            int kolumna1;
            int kolumna2;
            scanf("%d",&kolumna1);
            scanf("%d",&kolumna2);
            fflush(stdin);
            SWC(kolumna1,kolumna2,matrix,&wiersze);
        }
        else if(strcmp(polecenie,"DFR")==0){
            if(wiersze>0){
                matrix=DFR(matrix, &wiersze);
            }
        }
        else if(strcmp(polecenie,"DLR")==0){
            if(wiersze>0){
                matrix=DLR(matrix, &wiersze);
            }
        }
        else if(strcmp(polecenie,"DFC")==0){
            if(wiersze>0){
                matrix=DFC(matrix, &wiersze);
            }
        }
        else if(strcmp(polecenie,"DLC")==0){
            if(wiersze>0){
                matrix=DLC(matrix, &wiersze);
            }
        }
        else if(strcmp(polecenie,"RMR")==0){
            int ilosc;
            scanf("%d", &ilosc);
            if(ilosc<wiersze){
                matrix=RMR(matrix, &wiersze, ilosc);
            }
        }
        else if(strcmp(polecenie,"RMC")==0){
            int kolumna;
            scanf("%d", &kolumna);
            matrix=RMC(kolumna,matrix,&wiersze);

        }
        else if(strcmp(polecenie,"ISB")==0){

            int wiersz;
            int kolumna;
            int iloscwierszy;
            int ilosckolumn;
            scanf("%d",&wiersz);
            scanf("%d",&kolumna);
            scanf("%d",&iloscwierszy);
            scanf("%d",&ilosckolumn);
            int *argumenty;

            argumenty = malloc((iloscwierszy*ilosckolumn)*sizeof(int));
            int i;
            for(i=0;i<iloscwierszy*ilosckolumn;i++){
                scanf("%d",(argumenty+i));
            }
            fflush(stdin);

            matrix=ISB(wiersz,kolumna,iloscwierszy,ilosckolumn,argumenty,matrix,&wiersze);

            free(argumenty);
        }
        else if(strcmp(polecenie,"RMB")==0){
            int wiersz;
            int iloscwierszy;
            int kolumna;
            int ilosckolumn;
            scanf("%d", &wiersz);
            scanf("%d", &iloscwierszy);
            scanf("%d", &kolumna);
            scanf("%d", &ilosckolumn);
            fflush(stdin);
            matrix = RMB(wiersz,iloscwierszy,kolumna,ilosckolumn,matrix,&wiersze);

        }
        else if(strcmp(polecenie,"WRF")==0){
            char* nazwa = malloc(sizeof(char)*20);
            scanf("%s", nazwa);
            fflush(stdin);
            matrix=WRF(matrix,&wiersze,nazwa);
            free(nazwa);
        }
        else if(strcmp(polecenie,"RDF")==0){
            char* nazwa = malloc(sizeof(char)*20);
            scanf("%s", nazwa);
            fflush(stdin);
            matrix=RDF(matrix,&wiersze,nazwa);
            free(nazwa);
        }
        else if(strcmp(polecenie,"PRT") == 0){
            PRT(&wiersze, matrix);
        }
        else if(strcmp(polecenie,"END") == 0){
            int i;
            for(i=0;i<(wiersze);i++){

                    free (*(matrix+i));
            }

            free(matrix);
            free(polecenie);
            exit=1;
        }
    }
    while(exit==0);
    return 0;
}
