#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 4096

int read_file(char *text, char *filename);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./readability file\n");
        return 1;
    }

    char text[MAX];

    if (read_file(text, argv[1])) {
        printf("Archivo no encontrado\n");
        return 1;
    }

    int i=0;
    int palabras = 0;
    int letras = 0;
    int oraciones = 0;
    int grado = 0;
    int L = 0;
    int S = 0;
    while (text[i]>0) {
        if (text[i]=='!'||text[i]=='?'||text[i]=='.') {
            oraciones++;
        }
        if (text[i] == ' ') {
            palabras++;    
        }
        if (text[i]!='\0'){
            letras++;
        }
        i++;
    }
        
    L= 100*letras/palabras;
    S= 100*oraciones/palabras;

    grado = 0.0588 * L - 0.296 * S - 15.8;
    grado= round(grado);

        if(grado<1){
            printf("Before Grade 1\n");
        }
            
        else if(grado>16){
            printf("Grade 16+\n");
        }
            
         else if(grado>=2 || grado<=15){
            printf("Grade %d\n", grado);
        }
        return 0;
    }
     
int read_file(char *text, char *filename) {

    FILE *fp;
    char c;
    char full_name[30];
    
    sprintf(full_name, "texts/%s.txt", filename);
    fp = fopen(full_name, "r");
    
    if (!fp) {
        return 1;
    } 
    while ((c = getc(fp)) != EOF) {
        *text = c;
        text++;
    }
    return 0;
}
