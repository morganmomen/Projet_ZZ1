#include "choixRules.h"


action_t choixRule(rule_t *rule, joueur_t *joueur){
    int ruleValide[NB_RULES];
    int nbRuleValide = 0;
    int nbRuleChoisi = -1;
    printf("ALED \n");
    for (int i = 0; i < NB_RULES; i++)
    {
        ruleValide[i] = -1;
    }
    printf("ALED 2\n");

    for(int i = 0; i < NB_RULES; i++){
        if(isRuleValid(&rule[i], joueur)){
            ruleValide[nbRuleValide] = i;
            nbRuleValide++;
        }
    }

    if(nbRuleValide == 0){
        return -1;
    }

    for(int i = 0; i < nbRuleValide; i++){
        printf("Rule valide : ");
        printRule(&rule[ruleValide[i]]);
    }

    int nbRulePondere = 0;
    for(int i = 0; i < nbRuleValide; i++){
        nbRulePondere += rule[ruleValide[i]].priority+1;
    } 

    int tabPondereRule[nbRulePondere];
    int nbRuleDansTab = 0;
    for(int i = 0; i < nbRuleValide; i++){
        for(int j = 0; j < rule[ruleValide[i]].priority+1; j++){
            tabPondereRule[nbRuleDansTab] = ruleValide[i];
            nbRuleDansTab++;
        }
    } 

    return rule[tabPondereRule[rand() % nbRulePondere]].action;
}

int isRuleValid(rule_t *rule, joueur_t *joueur){
    int res = 0;
    if((rule->_case[0]== joueur->devant || rule->_case[0]== -1) && 
        (rule->_case[1] == joueur->gauche || rule->_case[1] == -1) && 
        (rule->_case[2] == joueur->derriere || rule->_case[2]== -1) &&
        (rule->_case[3] == joueur->droite || rule->_case[3] == -1) ){
            if(rule->direction_predateur == joueur->direction_predateur || rule->direction_predateur == -1){
                if(rule->direction_terrier == joueur->direction_terrier || rule->direction_terrier == -1){
                    if(rule->distance_predateur == joueur->distance_predateur || rule->distance_predateur == -1){
                        if(rule->distance_terrier == joueur->distance_terrier || rule->distance_terrier == -1){
                            res = 1;
                        }
                    }
                }
            }
    }
    return res;
    

}
