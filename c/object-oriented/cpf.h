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

#ifndef CPF_H_
#define CPF_H_

typedef struct cpf_t * cpf_t;

extern cpf_t cpf_new(const char *);
extern void cpf_destroy(cpf_t);
extern unsigned char cpf_is_valid(cpf_t);
extern unsigned cpf_get_check_digits(cpf_t);

#endif /* CPF_H_ */
