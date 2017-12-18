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
    int ret = 0;
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

    ApiArbCreateNode( Arb, nb_carac);

    ret = ApiArbFindSquare( Arb, nb_carac);

    if( ret < 0)
    {
        printf("\n***debug*** Erreur: pas de noeud trouver en tant que racine");
    }
    else
    {
        ApiArbCreateCode( Arb[ret], 0, 0);
    }

    ( void)output_path;
}

//===== END OF FILE ============================================================

