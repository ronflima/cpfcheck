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

static unsigned *
cpf_char_to_digits(const char *, unsigned *);

cpf_t
cpf_new(const char *cpfChar)
{
  cpf_t cpf = (cpf_t)malloc(sizeof(struct cpf_t));
  if (!cpf) {
	return NULL;
  }
  cpf->digits = (unsigned *)malloc(sizeof(unsigned) * CPF_SIZE);
  if (!cpf->digits) {
	free(cpf);
	return NULL;
  }
  memset(cpf->digits, 0x0, sizeof(unsigned) * CPF_SIZE);
  cpf->size = strlen(cpfChar);
  cpf_char_to_digits(cpfChar, cpf->digits);
  
  return cpf;
}

static unsigned *
cpf_char_to_digits(const char *cpfChar, unsigned *digits)
{
  const char *p = cpfChar;
  unsigned *d = digits;
  while(*p) {
	*d = *p - '0';
	++p, ++d;
  }

  return digits;
}
