//===== INCLUDEs ===============================================================
#include <stdlib.h>
#include <stdio.h>
#include "CAP_Com.h"
#include "CAP_Dec.h"

//===== DEFINEs ================================================================
#define     MAX_HEIGHT_ARGUMENT         50

//===== TYPEDEFs, STRUCTs, ENUMs ===============================================
typedef enum
{
   COMPRESS,
   DECOMPRESS,
   NO_ORDER,
}eCAP_ORDER;

//===== VARIABLEs ==============================================================

//===== PROTOTYPEs =============================================================

void CapOrderStartSequence(int argc, char *argv[]);

//===== FUNCTIONs ==============================================================

/*******************************************************************************
*  \!brief Determine order called by the interpreted command
*
* Return None
*
*******************************************************************************/
void CapOrderStartSequence(int argc, char *argv[])
{
   unsigned short int               count                               = 0;
   eCAP_ORDER                       order                               = NO_ORDER;
   char                             input_path[MAX_HEIGHT_ARGUMENT];
   char                             output_path[MAX_HEIGHT_ARGUMENT];

   /* Reading parameters of main */
   for (count = 0; count < argc ; count ++)
   {
      if(0 /*(count % 2)==0*/)
      {
         /* Do nothing */
      }
      else
      {
          if( strcmp( "-c",argv[count]) == 0)
          {
              strcpy( input_path, argv[count+1]);
              order = COMPRESS;
          }
          else if( strcmp( "-d", argv[count]) == 0)
          {
              strcpy( input_path, argv[count+1]);
              order = DECOMPRESS;
          }
          else if ( strcmp( "-o", argv[count]) == 0)
          {
              strcpy( output_path, argv[count+1]);
          }
          else
          {
              //order = NO_ORDER;
          }
      }

   }

   /* Starting of application */
   switch(order)
   {
      case COMPRESS :
         CapCompressFile(output_path, input_path);
      break;
      case DECOMPRESS :
         CapDecompressFile(output_path, input_path);
      break;
      case NO_ORDER :
         printf("\n[\033[33m Warn \033[37m]\tAucun ordre de Compression ou Décompression");
         perror("\nErreur");
      break;
   }
}
//===== END OF FILE ============================================================

