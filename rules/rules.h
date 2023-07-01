#define N 4
typedef struct
{
    int rules[N];
    int priority;
}regle;

typedef struct 
{
    regle * rule; 
    int nbrules;
} jeu_de_regle;

