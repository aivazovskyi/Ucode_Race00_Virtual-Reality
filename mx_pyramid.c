void mx_printchar(char c);

static void mx_print_pyramid(int n, int max_x) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x <= max_x; x++) {
            if ((y < n / 2 && x == max_x) || (y != 0 && x == n - 1 + y))
                mx_printchar('\\');
            else if (y >= n / 2 && x == max_x)
                mx_printchar('|');
            else if (x == n - 1 - y)
                mx_printchar('/');
            else if (y == n - 1 && x > 0 && x < (max_x - 1))
                 mx_printchar('_');
            else
                mx_printchar(' ');
        }
        if (y < n / 2)
            max_x += 2;
        if (max_x > n * 2 - 1)
            max_x = n * 2 - 1;
        mx_printchar('\n');
    }    
}

void mx_pyramid(int n) {
    int max_x;
    
    if (n < 2 || n % 2 == 1)
        return;
    else {
        max_x = n;
        mx_print_pyramid(n, max_x);
    }
}
