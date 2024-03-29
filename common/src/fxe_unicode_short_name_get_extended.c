/***************************************************************************
 * Copyright (c) 2024 Microsoft Corporation 
 * 
 * This program and the accompanying materials are made available under the
 * terms of the MIT License which is available at
 * https://opensource.org/licenses/MIT.
 * 
 * SPDX-License-Identifier: MIT
 **************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** FileX Component                                                       */
/**                                                                       */
/**   Unicode                                                             */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#define FX_SOURCE_CODE


/* Include necessary system files.  */

#include "fx_api.h"
#include "fx_unicode.h"


FX_CALLER_CHECKING_EXTERNS

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _fxe_unicode_short_name_get_extended                PORTABLE C      */
/*                                                           6.1          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    William E. Lamie, Microsoft Corporation                             */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function checks for errors in the Unicode short name get       */
/*    service.                                                            */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    media_ptr                             Pointer to media              */
/*    source_unicode_name                   Pointer to unicode name       */
/*    source_unicode_length                 Length of unicode name        */
/*    destination_short_name                Pointer to destination name   */
/*    short_name_buffer_length              Buffer length of short name   */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    Completion Status                                                   */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    _fx_unicode_short_name_get_extended   Actual unicode short name get */
/*                                            service                     */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Application Code                                                    */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  05-19-2020     William E. Lamie         Initial Version 6.0           */
/*  09-30-2020     William E. Lamie         Modified comment(s),          */
/*                                            resulting in version 6.1    */
/*                                                                        */
/**************************************************************************/
UINT  _fxe_unicode_short_name_get_extended(FX_MEDIA *media_ptr, UCHAR *source_unicode_name, ULONG source_unicode_length,
                                  CHAR *destination_short_name, ULONG short_name_buffer_length)
{

UINT status, i;


    /* Check for a NULL media or name pointers.  */
    if ((media_ptr == FX_NULL) || (source_unicode_name == FX_NULL) || (source_unicode_length == 0) || (destination_short_name == FX_NULL))
    {
        return(FX_PTR_ERROR);
    }

    /* Check for zero length buffer.  */
    if (short_name_buffer_length == 0)
    {
        return(FX_BUFFER_ERROR);
    }

    /* Check for a valid caller.  */
    FX_CALLER_CHECKING_CODE

    /* Check unicode zero in source_unicode_name */
    for (i = 0; i < (source_unicode_length << 1); i += 2)
    {
        if ((source_unicode_name[i] == 0) && (source_unicode_name[i + 1] == 0))
        {
            return(FX_INVALID_NAME);
        }
    }

    /* Call actual Unicode short name get service.  */
    status =  _fx_unicode_short_name_get_extended(media_ptr, source_unicode_name, source_unicode_length, destination_short_name, short_name_buffer_length);

    /* Return status to the caller.  */
    return(status);
}

