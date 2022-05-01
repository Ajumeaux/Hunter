/*
** EPITECH PROJECT, 2020
** main function for my_hunter
** File description:
** main main main
*/

#include "hunter.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        central();
        return (0);
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        read_file(_README_);
        return (0);
    }
    else
        return 84;
}