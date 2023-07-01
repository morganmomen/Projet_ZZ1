#define N 4
typedef struct
{
    int possibleValues ={0,1,2,3};
    int rules[N];
    int priority;
}regle;

typedef struct 
{
    regle * rule; 
    int nbrules;
} jeu_de_regle;

