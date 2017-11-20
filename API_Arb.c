//===== INCLUDEs ===============================================================
#include "Global.h"
#include "stdlib.h"
#include "API_Arb.h"

//===== DEFINEs ================================================================

//===== TYPEDEFs, STRUCTs, ENUMs ===============================================

//===== VARIABLEs ==============================================================
struct noeud* Arb[NB_CARACTERES_ASCII] = {0};

//===== PROTOTYPEs =============================================================
struct noeud* ApiArbCreateLeaf( int* Occ, int index);

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
*  \!brief Create a Node
*
* Return None
*
*******************************************************************************/
/*void ApiArbCreateNode( struct noeud* Arb[], int size)
{
    int iteration = 0;

    for( iteration = 0, iteration < size, iteration++)
    {
        Arb[iteration]
    }
}
*/

//===== END OF FILE ============================================================

