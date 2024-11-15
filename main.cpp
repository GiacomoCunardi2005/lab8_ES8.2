#include <iostream>

using namespace std;

// Definizione della struttura per un elemento della lista
struct typeSTR_EntitaLista
{
    int i_ValoreInformativo;                                // Campo che contiene il valore informativo dell'elemento
    typeSTR_EntitaLista* STR_p_PuntatoreProssimoElemento;   // Puntatore al prossimo elemento nella lista
};

// Funzione per stampare tutti gli elementi della lista
void FX_void_Stampa(typeSTR_EntitaLista* STR_EL_p_Puntatore)
{
    // Puntatore temporaneo per attraversare la lista
    typeSTR_EntitaLista *STR_p_PunTemporaneo = STR_EL_p_Puntatore;

    // Itera attraverso la lista fino a quando il puntatore è nullptr
    while (STR_p_PunTemporaneo != nullptr)
    {
        // Stampa il valore informativo dell'elemento corrente
        cout << STR_p_PunTemporaneo->i_ValoreInformativo << " ";

        // Passa al prossimo elemento della lista
        STR_p_PunTemporaneo = STR_p_PunTemporaneo->STR_p_PuntatoreProssimoElemento;
    }

    cout << endl; // Fine riga dopo aver stampato tutti gli elementi
}

int main()
{
    // Creare una lista vuota (inizialmente STR_p_Testa è nullptr)
    typeSTR_EntitaLista* STR_p_Testa = nullptr;

    // Aggiungere il primo elemento con valore 50 alla lista
    STR_p_Testa = new typeSTR_EntitaLista;                                 // Alloca memoria per un nuovo elemento
    STR_p_Testa->i_ValoreInformativo = 50;                                 // Assegna il valore 50 all'elemento
    STR_p_Testa->STR_p_PuntatoreProssimoElemento = nullptr;                // Il puntatore al prossimo elemento è nullptr (lista con un solo elemento)

    // Aggiungere un secondo elemento con valore 60 in fondo alla lista
    typeSTR_EntitaLista *STR_p_CodaLista = new typeSTR_EntitaLista;        // Alloca memoria per un nuovo elemento
    STR_p_CodaLista->i_ValoreInformativo = 60;                             // Assegna il valore 60 all'elemento
    STR_p_CodaLista->STR_p_PuntatoreProssimoElemento = nullptr;            // Questo è l'ultimo elemento, quindi il puntatore è nullptr
    STR_p_Testa->STR_p_PuntatoreProssimoElemento = STR_p_CodaLista;        // Collega il nuovo elemento (60) al primo elemento (50)

    // Aggiungere un terzo elemento con valore 70 in testa alla lista
    STR_p_CodaLista = new typeSTR_EntitaLista;                             // Alloca memoria per un nuovo elemento
    STR_p_CodaLista->i_ValoreInformativo = 70;                             // Assegna il valore 70
    STR_p_CodaLista->STR_p_PuntatoreProssimoElemento = STR_p_Testa;        // Collega il nuovo elemento al vecchio primo elemento (50)
    STR_p_Testa = STR_p_CodaLista;                                         // Aggiorna la testa della lista per puntare al nuovo elemento (70)

    // Stampa dell'intera lista (output atteso: "70 50 60")
    FX_void_Stampa(STR_p_Testa);

    // Eliminare il secondo elemento della lista (quello con valore 50)
    STR_p_CodaLista = STR_p_Testa->STR_p_PuntatoreProssimoElemento;         // Puntatore al secondo elemento (50)
    STR_p_Testa->STR_p_PuntatoreProssimoElemento = STR_p_CodaLista->STR_p_PuntatoreProssimoElemento;  // Collega il primo elemento (70) direttamente al terzo (60)
    delete STR_p_CodaLista;                                                // Libera la memoria allocata per il secondo elemento (50)

    // Stampa della lista aggiornata (output atteso: "70 60")
    FX_void_Stampa(STR_p_Testa);

    return 0; // Fine del programma
}
