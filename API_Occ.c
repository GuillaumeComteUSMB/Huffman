//===== INCLUDEs ===============================================================
#include "Global.h"
#include "stdlib.h"
#include "stdio.h"
#include "API_Occ.h"

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

/*******************************************************************************
*  \!brief Determine the two most smaller int in a table
*
* Return int
*
*******************************************************************************/
sAPI_LOWEST_INT ApiOccFindTwoSmallerInt( void)
{
    int iteration = 0;

    sAPI_LOWEST_INT OccAnalyze;
    OccAnalyze.indice1 = 0;
    OccAnalyze.indice2 = 0;
    OccAnalyze.lowest_number1 = 65535;
    OccAnalyze.lowest_number2 = 65535;

    for( iteration = 0; iteration < NB_CARACTERES_ASCII; iteration++)
    {
        if(( Occ[iteration]<= OccAnalyze.lowest_number1)&&( Occ[iteration]>0))
        {
            OccAnalyze.lowest_number2 = OccAnalyze.lowest_number1;
            OccAnalyze.lowest_number1 = Occ[iteration];

            OccAnalyze.indice2 = OccAnalyze.indice1;
            OccAnalyze.indice1 = iteration;
        }
    }

    printf("\n***Debug***");

    return(OccAnalyze);
}

//===== END OF FILE ============================================================
