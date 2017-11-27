//===== INCLUDEs ===============================================================
#include "Global.h"
#include "stdlib.h"
#include "API_Arb.h"
#include "API_Occ.h"

//===== DEFINEs ================================================================

//===== TYPEDEFs, STRUCTs, ENUMs ===============================================

//===== VARIABLEs ==============================================================
struct noeud* Arb[NB_CARACTERES_ASCII] = {0};

//===== PROTOTYPEs =============================================================
struct noeud* ApiArbCreateLeaf( int* Occ, int index);
void ApiArbCreateNode( struct noeud* Arb, int size);
void ApiArbSortLeaf( void);

//===== FUNCTIONs ==============================================================

/*******************************************************************************
*  \!brief Initialize a leaf, correspond to a caractere (index)
*
* Return struct noeud
*
*******************************************************************************/
struct noeud* ApiArbCreateLeaf( int* Occ, int index)
{
    struct noeud* leaf = 0;

    // Reservation of memory space to stock each struct
    leaf = malloc(sizeof(struct noeud));

    // Init Content of struct
    leaf->carac = index;
    leaf->occ = Occ[index];
    leaf->code = 0;
    leaf->bits = 0;
    leaf->gauche = NULL;
    leaf->droite = NULL;

    // Reservation of memory space to stock each struct
    Arb[index] = leaf;

    return( leaf);
}

/*******************************************************************************
*  \!brief Sort Leaf --> croissant
*
* Return None
*
*******************************************************************************/
void ApiArbSortLeaf( void)
{

}

/*******************************************************************************
*  \!brief Create a Node
*
* Return None
*
*******************************************************************************/
void ApiArbCreateNode( struct noeud* Arb, int size)
{
    int iteration = 0;
    int indice = 0;
    sAPI_LOWEST_INT OccAnalyze = {0};
    struct noeud temp = {0};

    // nombre de noeuds = nombre de caracteres - 1
    for( iteration = 0; iteration < size-1; iteration++)
    {
        OccAnalyze = ApiOccFindTwoSmallerInt( Arb, size);

        if( ( OccAnalyze.indice1!=0)&&( OccAnalyze.indice2!=0)
        {
            Arb[iteration].carac  = NULL;
            Arb[iteration].occ    = OccAnalyze.lowest_number1 + OccAnalyze.lowest_number2;
            Arb[iteration].code   = NULL;
            Arb[iteration].bits   = NULL;
            Arb[iteration].gauche = &Arb[ OccAnalyze.indice1];
            Arb[iteration].droite = &Arb[ OccAnalyze.indice2];
        }
        else
        {
            //do nothing
        }
    }



}


//===== END OF FILE ============================================================

