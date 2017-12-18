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
extern struct noeud* alphabet[NB_CARACTERES_ASCII];

//===== PROTOTYPEs =============================================================
void CapCompressFile(char output_path[], char input_path[]);

//===== FUNCTIONs ==============================================================
void CapCompressFile(char output_path[], char input_path[])
{
    int iteration = 0;
    int nb_carac = 0;
    int new_size = 0;
    int ret = 0;
    struct noeud* generic_node;
    //sAPI_LOWEST_INT OccAnalyze = {0};

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

    // Initialization of new_size of Arb
    new_size = nb_carac;

    for( iteration = 0 ; iteration < nb_carac-1 ; iteration++)
    {
        new_size = ApiArbCreateNode( Arb, new_size, nb_carac);
    }

    if( Arb[ 0]->carac != '!')
    {
        printf("\n***debug*** Erreur: pas de noeud trouver en tant que racine");
    }
    else
    {
        ApiArbCreateCode( Arb[0], 0, 0);
    }

    ret = ApiFilLeadingCreation( alphabet, output_path, nb_carac);
    if( ret == 0)
    {
        printf("\n***debug*** writed Leading");
    }
    else
    {
        printf("\n***debug*** Error in writing file");
    }
}

//===== END OF FILE ============================================================

