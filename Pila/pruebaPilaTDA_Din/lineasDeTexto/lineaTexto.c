#include "lineaTexto.h"

int ingresarTexto(char *linea, int tamLinea)
{
    static const char *texto[] = {
        "Se necesita un amigo - Fragmento del poema de Vinicius de Moraes",
        "",
        "Debe tener un ideal, y miedo de perderlo,",
        "y en caso de no ser asi,",
        "debe sentir el gran vacio que esto deja.",
        "Tiene que tener resonancias humanas,",
        "su principal objetivo debe ser el del amigo.",
        "Debe sentir pena por las personas tristes",
        "y comprender el inmenso vacio de los solitarios.",
        "Se busca un amigo para gustar",
        "de los mismos gustos,",
        "que se conmueva cuando es tratado de amigo.",
        NULL };
    static int posi = 0;

    if(texto[posi] == NULL)
    {
        posi = 0;
        return 0;
    }
    *linea = '\0';
    strncat(linea, texto[posi],tamLinea-1);
    posi++;
    return 1;
}
