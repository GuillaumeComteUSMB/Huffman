//===== INCLUDEs ===============================================================
#include "stdio.h"
#include "Global.h"
#include "API_Fil.h"
#include "API_Arb.h"
#include "API_Occ.h"

//===== DEFINEs ================================================================

//===== TYPEDEFs, STRUCTs, ENUMs ===============================================

//===== VARIABLEs ==============================================================
extern char Car[NB_CARACTERES_ASCII];
extern int Occ[NB_CARACTERES_ASCII];
extern struct noeud* Arb[NB_CARACTERES_ASCII];

//===== PROTOTYPEs =============================================================
void CapCompressFile(char output_path[], char input_path[]);

//===== FUNCTIONs ==============================================================
void CapCompressFile(char output_path[], char input_path[])
{
    int iteration = 0;
    int nb_carac = 0;
    struct noeud* generic_node = NULL;
    sAPI_LOWEST_INT OccAnalyze = {0};

    // Reading of input file, Occurences classification
    ApiFilReadFile( input_path);

    // Determine number of caracteres
    nb_carac = ApiOccDetermineNumberChar();

    for ( iteration = 0 ; iteration < nb_carac ; iteration++)
    {
        generic_node = ApiArbCreateLeaf( Occ, Car[iteration]);
        printf("\nAdresse Mémoire de structure créée : %x", generic_node);
    }

    ApiArbSortLeaf( nb_carac);

    OccAnalyze = ApiOccFindTwoSmallerInt( Arb, nb_carac);
    printf("\n***debug*** OccAnalyze = %d", OccAnalyze.lowest_number1);

    ( void)output_path;
}

//===== END OF FILE ============================================================

