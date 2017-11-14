#ifndef API_OCC_H
#define API_OCC_H

//===== INCLUDEs ===============================================================
#include <stdlib.h>

//===== DEFINEs ================================================================

//===== TYPEDEFs, STRUCTs, ENUMs ===============================================
typedef struct
{
    int indice1;
    int lowest_number1;
    int indice2;
    int lowest_number2;
}sAPI_LOWEST_INT;

//===== VARIABLEs ==============================================================

//===== PROTOTYPEs =============================================================
void ApiOccClassiOccurences( char CaractereLu);
int ApiOccDetermineNumberChar( void);
sAPI_LOWEST_INT ApiOccFindTwoSmallerInt( void);

//===== END OF FILE ============================================================

#endif // API_OCC_H
