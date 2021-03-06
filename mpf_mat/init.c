/*=============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2010 William Hart
    Copyright (C) 2014 Abhinav Baid

******************************************************************************/

#include <stdlib.h>
#include <gmp.h>
#include "flint.h"
#include "mpf_mat.h"

void
mpf_mat_init(mpf_mat_t mat, slong rows, slong cols, mp_bitcnt_t prec)
{

    if ((rows) && (cols))       /* Allocate space for r*c small entries */
    {
        slong i;
        mat->entries = (mpf *) flint_malloc(rows * cols * sizeof(mpf));
        mat->rows = (mpf **) flint_malloc(rows * sizeof(mpf *));    /* Initialise rows */

        for (i = 0; i < rows * cols; i++)
            mpf_init2(mat->entries + i, prec);
        for (i = 0; i < rows; i++)
            mat->rows[i] = mat->entries + i * cols;
    }
    else
    {
       mat->entries = NULL;
       mat->rows = NULL;
	}

    mat->r = rows;
    mat->c = cols;
    mat->prec = prec;
}
