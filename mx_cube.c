void mx_printchar(char c);

static void mx_print_cube1(int n, int y, int max_x, int diagon) {
    if (y > diagon)
        return;
    else
        for (int x = 0; x < max_x; x++) {
            if (((y == 0) && ((x == max_x - 1 ) || (x == max_x - n * 2 - 2)))
                  || ((y == diagon) && ((x == 0) || (x == n * 2 + 1))))
                mx_printchar('+');
            else if ((y == 0 && x > n / 2 + 1 && x < max_x)
                      || (y == diagon && x > 0 && x < n * 2 + 1))
                mx_printchar('-');
            else if (y > 0 && y <= n / 2 && ((x == n / 2 + 1 - y) 
                     || (x == max_x - y -1)))
                mx_printchar('/');
            else if ((y !=0 && y < diagon && x == max_x - 1) 
                      || (y == diagon && x == max_x - 1))
                mx_printchar('|');
            else
                mx_printchar(' ');
        }
        mx_printchar('\n');
}

static void mx_print_cube2(int n, int y, int max_x, int diagon) {
    int hight = n + 3 + n / 2;

    if (y <= diagon)
        return;
    else
        for (int x = 0; x < max_x; x++) {
            if ((y == n + 1 && x == max_x - 1) 
                 || ((y == hight - 1) && ((x == 0) || (x == n * 2 + 1))))
                mx_printchar('+');
            else if (((y > diagon && y < n+1 && x == max_x - 1))
                       || (y > diagon && ((x == 0) || (x == n * 2 + 1))))
                mx_printchar('|');
            else if (y > n && y < (hight - 1) && x == max_x - 1)
                mx_printchar('/');
            else if ((y == hight - 1 && x > 0 && x < n * 2 + 1))
                mx_printchar('-');
            else
                mx_printchar(' ');  
        }
        mx_printchar('\n');
}

void mx_cube(int n) {
    int max_x;
    int y;
    int hight;
    int diagon;    

    if (n < 2)
        return;
    else
        max_x = n * 2 + n / 2 + 3;
        hight = n + 3 + n / 2;
        diagon = (n / 2 + 1);
        for (y = 0; y < hight; y++) {
            if (y >= n + 2)
                max_x--;
            mx_print_cube1(n, y, max_x, diagon);
            mx_print_cube2(n, y, max_x, diagon);
        }
}
