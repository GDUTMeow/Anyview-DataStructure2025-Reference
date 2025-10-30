#include "allinclude.h"  //DO NOT edit this line

void ChangeColor(GTYPE g, int m, int n, char c, int i0, int j0)
{
    if (i0 < 1 || i0 > m || j0 < 1 || j0 > n) {
        return;
    }

    char original_color = g[i0][j0];

    if (original_color == c) {
        return;
    }

    g[i0][j0] = c;

    if (i0 > 1 && g[i0 - 1][j0] == original_color) {
        ChangeColor(g, m, n, c, i0 - 1, j0);
    }
    if (i0 < m && g[i0 + 1][j0] == original_color) {
        ChangeColor(g, m, n, c, i0 + 1, j0);
    }
    if (j0 > 1 && g[i0][j0 - 1] == original_color) {
        ChangeColor(g, m, n, c, i0, j0 - 1);
    }
    if (j0 < n && g[i0][j0 + 1] == original_color) {
        ChangeColor(g, m, n, c, i0, j0 + 1);
    }
}