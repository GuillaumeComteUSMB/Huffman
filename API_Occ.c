//===== INCLUDEs ===============================================================
#include "Global.h"
#include "stdlib.h"

//===== DEFINEs ================================================================

//===== TYPEDEFs, ENUMs ========================================================

//===== STRUCTs, UNIONs ========================================================

//===== PROTOTYPEs =============================================================
void ApiOccClassiOccurences( char CaractereLu);
int ApiOccDetermineNumberChar( void);

//===== VARIABLEs ==============================================================
int Occ[NB_CARACTERES_ASCII] = {0};
char Car[NB_CARACTERES_ASCII] = {'\0'};

//===== FUNCTIONs ==============================================================

/*******************************************************************************
*  \!brief Classification in a table : number of occurences of each caractere
*
* Return None
*
*******************************************************************************/
void ApiOccClassiOccurences( char CaractereLu)
{
   Occ[ CaractereLu] = Occ[ CaractereLu] + 1 ;
}

/*******************************************************************************
*  \!brief Determine how many characters are presents in input file
*
* Return int
*
*******************************************************************************/
int ApiOccDetermineNumberChar( void)
{
    int iteration = 0;
    int counter = 0;

    for( iteration = 0; iteration < NB_CARACTERES_ASCII; iteration++)
    {
        if( Occ[iteration] != 0)
        {
            // Stock value of presents characters in a table
            Car[counter] = iteration;

            // Incrementation of number of characters
            counter = counter + 1;
        }
        else
        {
            /* Nothing to do */
        }
    }

    return( counter);
}

//===== END OF FILE ============================================================
