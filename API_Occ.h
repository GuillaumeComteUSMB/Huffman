#ifndef API_OCC_H
#define API_OCC_H

//===== INCLUDEs ===============================================================
#include <stdlib.h>
#include "API_Arb.h"

//===== DEFINEs ================================================================

//===== TYPEDEFs, STRUCTs, ENUMs ===============================================
typedef struct
{
    int indice1;
    unsigned int lowest_number1;
    int indice2;
    unsigned int lowest_number2;
}sAPI_LOWEST_INT;

//===== VARIABLEs ==============================================================

//===== PROTOTYPEs =============================================================
void ApiOccClassiOccurences( char CaractereLu);
int ApiOccDetermineNumberChar( void);
sAPI_LOWEST_INT ApiOccFindTwoSmallerInt( struct noeud* Arb[], int size);

//===== END OF FILE ============================================================

#endif // API_OCC_H
