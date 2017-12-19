#ifndef API_FIL_H
#define API_FIL_H

//===== INCLUDEs ===============================================================

//===== DEFINEs ================================================================

//===== TYPEDEFs, STRUCTs, ENUMs ===============================================

//===== VARIABLEs ==============================================================

//===== PROTOTYPEs =============================================================
void ApiFilReadFile(char input_path[]);
int ApiFilLeadingCreation( struct noeud* alphabet[], char output_path[], int nb_carac);
void ApiFilReadLeading( char output_path[]);

//===== FUNCTIONs ==============================================================

//===== END OF FILE ============================================================


#endif // API_FIL_H
