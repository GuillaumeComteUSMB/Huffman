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
int ApiArbCreateNode( struct noeud* Arb[], int new_size, int size);
void ApiArbSortLeaf( int size);
int ApiArbFindRoot(struct noeud* Arb[], int size);
void ApiArbCreateCode( struct noeud* element, int code, int niveau);
void ApiArbSortArb( int size);
int ApiArbDeleteAndShift( int size);

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
    //printf("\n***debug*** leaf creation : adress %x ", Arb[num_carac]);
    //printf("\n***debug*** ID of created leaf : %d", num_carac);
    //printf("\n***debug*** leaf 's caractere : %c", Arb[num_carac]->carac);

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
*  \!brief Sort Arb[] --> croissant
*
* Return None
*
*******************************************************************************/
void ApiArbSortArb( int size)
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
       printf("\n[API_Arb.c]\t carac or node : %c", Arb[i]->carac);
       printf("\n[API_Arb.c]\t occurence : %d", Arb[i]->occ);
   }
}

/*******************************************************************************
*  \!brief Delete and Shift of One case
*
* Return None
*
*******************************************************************************/
int ApiArbDeleteAndShift( int size)
{
    int iteration = 1;

    for( iteration = 1; iteration < size-1; iteration++)
    {
        Arb[ iteration] = Arb[ iteration + 1];
    }
    return( size-1);
}

/*******************************************************************************
*  \!brief Create a Node
*
* Return None
*
*******************************************************************************/
int ApiArbCreateNode( struct noeud* Arb[], int new_size, int size)
{
    static int iteration = 0;

    struct noeud* temp = malloc(sizeof(struct noeud));

    // Sort tab
    ApiArbSortArb( new_size);

    if( iteration == ( size - 2))
    {
        temp->carac = '!';
    }
    else
    {
        temp->carac = 0;
    }

    temp->code       = 0;
    temp->bits       = 0;
    temp->occ        = Arb[ 0]->occ + Arb[ 1]->occ;
    temp->gauche     = Arb[ 0];
    temp->droite     = Arb[ 1];

    Arb[ 0] = temp;

    if( iteration != (size -2))
    {
        // delete Arb[1] and shift, Arb[1] was save droite in Arb[ 1]
        new_size = ApiArbDeleteAndShift( new_size);
    }

    iteration = iteration + 1;

    return( new_size);
}

/*******************************************************************************
*  \!brief Create Code of each caracteres
*
* Return None
*
*******************************************************************************/
void ApiArbCreateCode( struct noeud* element, int code, int niveau)
{
    if(( element->droite == NULL)&&( element->gauche == NULL))
    {
        // We are on a leaf
        element->bits = niveau;
        element->code = code;
        printf("\n***debug*** %c\t %d", element->carac, element->occ);
    }
    else
    {
        // Others Paths
        // Go right (0 injection)
        ApiArbCreateCode( element->droite, code<<1, niveau+1);

        // Go left
        ApiArbCreateCode( element->gauche, (code<<1)+1, niveau+1);
    }
}

/*******************************************************************************
*  \!brief Find '!' Node
*
* Return index of Arb[] where is the node
*
*******************************************************************************/
int ApiArbFindRoot(struct noeud* Arb[], int size)
{
    int iteration = 0;

    for( iteration = 0; iteration<size; iteration++)
    {
        if( Arb[ iteration]->carac == '!')
        {
            return( iteration);
        }
        else
        {
            // do nothing, wait the ! node
        }
    }
    return(-1); // Error
}


//===== END OF FILE ============================================================

