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
void ApiArbCreateNode( struct noeud* Arb[], int size);

//===== END OF FILE ============================================================

#endif // API_ARB_H
