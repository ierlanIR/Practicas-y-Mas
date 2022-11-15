#include <stdio.h>
#include <stdbool>
bool es_par(int a)
{
    if (a % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void main()
{
    printf("2 es par? %s", es_par(2) ? "si" : "no");
    6 printf("3 es par? %s", es_par(3) ? "si" : "no");
}
Ahora, creen el archivo fix_if.cocci con el siguiente contenido : @fix_if @expression E;
@ @-if (E)
{
    -return true;
    -
}
else
{
    -return false;
    -
}
+ return E;