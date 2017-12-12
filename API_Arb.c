//===== INCLUDEs ===============================================================
#include "Global.h"
#include "stdlib.h"
#include "stdio.h"
#include "API_Arb.h"
#include "API_Occ.h"

//===== DEFINEs ================================================================

//===== TYPEDEFs, STRUCTs, ENUMs ===============================================

//===== VARIABLEs ==============================================================
struct noeud* Arb[NB_CARACTERES_ASCII] = {0};

//===== PROTOTYPEs =============================================================
struct noeud* ApiArbCreateLeaf( int* Occ, int index);
void ApiArbCreateNode( struct noeud* Arb[], int size);
void ApiArbSortLeaf( int size);

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
    static int num_carac = 0;

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
    Arb[num_carac] = leaf;
    printf("\n***debug*** creation feuille : adress %x ", Arb[num_carac]);
    printf("\n***debug*** numero de feuille creee : %d", num_carac);
    printf("\n***debug*** caractere de la feuille creee : %c", Arb[num_carac]->carac);

    num_carac = num_carac + 1;

    return( leaf);
}

/*******************************************************************************
*  \!brief Sort Leaf --> croissant
*
* Return None
*
*******************************************************************************/
void ApiArbSortLeaf( int size)
{
    //tab containing address of all leafs : arb[]
   struct noeud* temp; //temporary stock address
   int i = 0;

   for(i = 0; i < size; i++)
   {
       printf("\n***debug*** caractere trie : %c", Arb[i]->carac);
       if(i == (size-1))
       {
           // do nothing, we are on last leaf
       }
       else if(Arb[i]->occ > Arb[i+1]->occ)
       {
           temp = Arb[i+1];
           Arb[i+1] = Arb[i];
           Arb[i] = temp;
       }
   }
   for(i = 0; i < size; i++)
   {
       printf("\n[API_Arb.c]\t carac : %c", Arb[i]->carac);
       printf("\n[API_Arb.c]\t occurence carac : %d", Arb[i]->occ);
   }
}

/*******************************************************************************
*  \!brief Create a Node
*
* Return None
*
*******************************************************************************/
void ApiArbCreateNode( struct noeud* Arb[], int size)
{
    int iteration = 0;
    sAPI_LOWEST_INT OccAnalyze = {0};

    int old_node_index = NULL;

    // nombre de noeuds = nombre de caracteres - 1
    for( iteration = 0; iteration < size-1; iteration++)
    {
        OccAnalyze = ApiOccFindTwoSmallerInt( Arb, size);

        if( ( OccAnalyze.indice1!=0)&&( OccAnalyze.indice2!=0))
        {
            Arb[ OccAnalyze.indice2]->carac  = '!';
            Arb[ OccAnalyze.indice2]->occ    = OccAnalyze.lowest_number1 + OccAnalyze.lowest_number2;
            Arb[ OccAnalyze.indice2]->code   = NULL;
            Arb[ OccAnalyze.indice2]->bits   = NULL;
            Arb[ OccAnalyze.indice2]->gauche = &Arb[ OccAnalyze.indice1];
            Arb[ OccAnalyze.indice2]->droite = &Arb[ OccAnalyze.indice2];

            if( old_node_index == NULL)
            {
                // do nothing, first node created
            }
            else
            {
                Arb[ old_node_index]->carac = NULL;
            }

            old_node_index = OccAnalyze.indice2;
        }
        else
        {
            //do nothing
        }
    }

}


//===== END OF FILE ============================================================

