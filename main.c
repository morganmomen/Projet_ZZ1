#include <stdio.h>
#include <stdlib.h>
#include "rules/rules.h"
#include "rules/changeRules.h"
#include "rules/choixRules.h"

int main(int argc, char **argv)
{
    rule_t rule[NB_RULES];
    for (int i = 0; i < NB_RULES; i++)
    {
        generateRule(&rule[i]);
        printRule(&rule[i]);
    }



    return 0;
}

