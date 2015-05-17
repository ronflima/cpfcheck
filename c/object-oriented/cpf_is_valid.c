/*
 * CPF Validation Demo
 * Copyright (C) 2015 - Ronaldo Faria Lima
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdlib.h>
#include <string.h>
#include "cpf.h"
#include "cpf_internals.h"

static unsigned char
cpf_contains_single_digits(cpf_t);

static unsigned
check_digit(cpf_t, unsigned);

unsigned char
cpf_is_valid(cpf_t cpf)
{
  if (!cpf || cpf->size != CPF_SIZE || cpf_contains_single_digits(cpf)) {
	return (unsigned char)0;
  }	
  unsigned ck_digit = check_digit(cpf, 11) * 10 + check_digit(cpf, 10);
  unsigned cpf_ck_digit = cpf_get_check_digits(cpf);
  unsigned char valid = (unsigned char)(ck_digit == cpf_ck_digit);
  return valid;
}

static unsigned char
cpf_contains_single_digits(cpf_t cpf)
{
  unsigned char single_digits = (unsigned char)1;
  register int i;
  for (i = 1; i < cpf->size && single_digits; ++i) {
	unsigned curr = cpf->digits[i];
	unsigned prev = cpf->digits[i-1];
	single_digits = single_digits && (curr == prev);
  }
  return single_digits;
}

static unsigned
check_digit(cpf_t cpf, unsigned weight)
{
  unsigned ck_digit = 0;
  register int i;
  for (i = 0; i < cpf->size && weight > 1; ++i, --weight) {
	ck_digit += cpf->digits[i] * weight;
  }
  ck_digit = ck_digit % 11;
  ck_digit = ck_digit < 2 ? 0 : 11 - ck_digit;
  return ck_digit;
}
