//===== INCLUDEs ===============================================================
#include <stdlib.h>
#include <stdio.h>
#include "API_Occ.h"

//===== DEFINEs ================================================================

//===== TYPEDEFs, STRUCTs, ENUMs ===============================================

//===== VARIABLEs ==============================================================

//===== PROTOTYPEs =============================================================
void ApiFilReadFile(char input_path[]);

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

//===== END OF FILE ============================================================
