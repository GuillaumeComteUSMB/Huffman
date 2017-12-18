#ifndef API_ARB_H
#define API_ARB_H

//===== INCLUDEs ===============================================================
struct noeud
{
    char                carac;
    unsigned int        occ;
    int                 code;
    int                 bits;
    struct noeud        *gauche;
    struct noeud        *droite;
};

//===== DEFINEs ================================================================

//===== TYPEDEFs, STRUCTs, ENUMs ===============================================

//===== VARIABLEs ==============================================================

//===== PROTOTYPEs =============================================================
struct noeud* ApiArbCreateLeaf( int* Occ, int index);
int ApiArbCreateNode( struct noeud* Arb[], int new_size, int size);
void ApiArbSortLeaf( int size);
int ApiArbFindRoot(struct noeud* Arb[], int size);
void ApiArbCreateCode( struct noeud* element, int code, int niveau);

//===== END OF FILE ============================================================

#endif // API_ARB_H
