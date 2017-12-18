//===== INCLUDEs ===============================================================
#include <stdlib.h>
#include <stdio.h>
#include "API_Occ.h"
#include "API_Arb.h"

//===== DEFINEs ================================================================

//===== TYPEDEFs, STRUCTs, ENUMs ===============================================

//===== VARIABLEs ==============================================================

//===== PROTOTYPEs =============================================================
void ApiFilReadFile(char input_path[]);
int ApiFilLeadingCreation( struct noeud* alphabet[], char output_path[], int nb_carac);

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

    fichier = fopen( output_path, "w");
    if( fichier != NULL)
    {
        // We can write in file
        for( iteration = 0; iteration < NB_CARACTERES_ASCII-1; iteration++)
        {
            if( iteration == 0)
            {
                fputc( nb_carac, fichier);
            }
            else
            {
                if( alphabet[ iteration-1] != NULL)
                {
                    fputc( alphabet[ iteration-1]->bits, fichier);
                    fputc( alphabet[ iteration-1]->code, fichier);
                }
                else
                {
                    fputc( 0, fichier);
                    fputc( 0, fichier);
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

//===== END OF FILE ============================================================
