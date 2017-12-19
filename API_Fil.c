//===== INCLUDEs ===============================================================
#include <stdlib.h>
#include <stdio.h>
#include "API_Occ.h"
#include "API_Arb.h"

//===== DEFINEs ================================================================

//===== TYPEDEFs, STRUCTs, ENUMs ===============================================
struct leading_c
{
    int code;
    int bits;
};

//===== VARIABLEs ==============================================================
struct leading_c reading_alphabet[NB_CARACTERES_ASCII];

//===== PROTOTYPEs =============================================================
void ApiFilReadFile(char input_path[]);
int ApiFilLeadingCreation( struct noeud* alphabet[], char output_path[], int nb_carac);
void ApiFilReadLeading( char output_path[]);
void ApiFilWriteIntInFile( int to_write, FILE* fichier);
int ApiFilReadNumberCaracInFile( FILE* fichier);
void ApiFilReadAlphabetInFile( FILE* fichier, struct leading_c reading_alphabet[]);

//===== FUNCTIONs ==============================================================

/*******************************************************************************
*  \!brief Reading of file
*
* Return None
*
*******************************************************************************/
void ApiFilReadFile(char input_path[])
{
   // Variable utilisée en locale
   FILE* fichier = NULL;
   char CaractereLu = '\0';
   unsigned int Char = 0;
   unsigned int counter = 0;

   // Ouverture du fichier à passer dans l'API
   fichier = fopen( ( char*)input_path, "r+");

   // Lecture du caractere
   do
   {
       Char = fgetc( fichier);
       CaractereLu = ( char)Char;
       printf( "\nCaractereLu : %c", CaractereLu);
       if( CaractereLu == '\0')
       {
          printf( "\n[\033[33m Warn \033[37m]\t CaractereLu = NULL");
       }
       ApiOccClassiOccurences( CaractereLu);
       // Incrémentation du compteur de caractères
       counter = counter + 1;

   } while( CaractereLu != EOF);

   printf( "\n[\033[33m Info \033[37m]\tNombre de Caractères  : %d", counter);

   fclose( fichier);
}

/*******************************************************************************
*  \!brief Leading Creation
*
* Return None
*
*******************************************************************************/
int ApiFilLeadingCreation( struct noeud* alphabet[], char output_path[], int nb_carac)
{
    int iteration = 0;
    FILE* fichier = NULL;
    int temp = 0;

    fichier = fopen( output_path, "w");
    if( fichier != NULL)
    {
        // We can write in file
        for( iteration = 0; iteration < NB_CARACTERES_ASCII-1; iteration++)
        {
            if( iteration == 0)
            {
                fwrite( &nb_carac, sizeof(nb_carac), 1, fichier);
            }
            else
            {
                if( alphabet[ iteration-1] != NULL)
                {
                    fwrite( &alphabet[ iteration-1]->bits, sizeof(alphabet[ iteration-1]->code), 1, fichier);
                    fwrite( &alphabet[ iteration-1]->code, sizeof(alphabet[ iteration-1]->code), 1, fichier);
                }
                else
                {
                    fwrite( &temp, sizeof(temp), 1, fichier);
                    fwrite( &temp, sizeof(temp), 1, fichier);
                }

            }
        }
    }
    else
    {
        printf("\n[Erreur]\t Impossible d'ouvrir le fichier %s", output_path);
        return( -1);
    }

    fclose(fichier);


    return(0);
}

/*******************************************************************************
*  \!brief Read leading of file
*
* Return None
*
*******************************************************************************/
void ApiFilReadLeading( char output_path[])
{
    FILE* fichier = NULL;
    int number_carac = 0;

    fichier = fopen( output_path, "r+");

    // Reading of number of char
    number_carac = ApiFilReadNumberCaracInFile( fichier);
    printf("\n***debug*** number of char in leading : %d", number_carac);

    ApiFilReadAlphabetInFile( fichier, reading_alphabet);

    fclose( fichier);

}

/*******************************************************************************
*  \!brief Read Alphabet in leading of file
*
* Return None
*
*******************************************************************************/
void ApiFilReadAlphabetInFile( FILE* fichier, struct leading_c reading_alphabet[])
{
    int iteration = 0;
    int temp_init = 0;

    for( iteration = 0; iteration< NB_CARACTERES_ASCII; iteration++)
    {
        fread( &temp_init, sizeof(temp_init), 1, fichier);

        reading_alphabet[ iteration].bits = temp_init;

        fread( &temp_init, sizeof(temp_init), 1, fichier);

        reading_alphabet[ iteration].code = temp_init;
    }

    // Affichage des caracteres lu
    for( iteration = 0; iteration < NB_CARACTERES_ASCII; iteration++)
    {
        if(reading_alphabet[ iteration].bits != 0)
        {
            printf("\n***debug*** carac : %c", iteration);
            printf(" bits %d", reading_alphabet[ iteration].bits);
            printf(" code : %d", reading_alphabet[ iteration].code);
        }
    }
}

/*******************************************************************************
*  \!brief Read number of caracteres in leading of file
*
* Return None
*
*******************************************************************************/
int ApiFilReadNumberCaracInFile( FILE* fichier)
{
    int temp_init = 0;

    fread( &temp_init, sizeof(temp_init), 1, fichier);

    return( temp_init);
}


//===== END OF FILE ============================================================
