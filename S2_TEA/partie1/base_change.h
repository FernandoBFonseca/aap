#pragma once
#include <stdio.h>

#include "../include/check.h"

#include "elt.h"	// T_elt
#include "list.h"	// T_list, T_node
#include "stack_cld.h" // Pile Methods

void base_change_basic(int value, int new_base);
void base_change_stack(int value, int new_base);