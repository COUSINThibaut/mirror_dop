/*
** EPITECH PROJECT, 2024
** mysh
** File description:
** test
*/

#include <criterion/criterion.h>
#include "../include/test.h"
#include "../include/my.h"

Test (mysh1, clean_redirection)
{
    char *str = clean_str_redirection("ls ; ls -la | grep test >> result");

    cr_assert_str_eq(str, " ;   |   >> ");
}

Test (mysh1, clean_cmd)
{
    char *str = clean_str_cmd("ls ; ls -la | grep test >> result << test");

    cr_assert_str_eq(str, "ls ; ls -la | grep test > result < test");
}

Test (mysh1, clean_cmd_wrong_input)
{
    char *str = clean_str_cmd("ls ; ls -la | grep test >>> result << test");

    cr_assert_str_eq(str, "ls ; ls -la | grep test > result < test");
}

Test (mysh1, clean_str)
{
    char *str = clean_str("ls          ; ls -la    | grep test     > result  < test");

    cr_assert_str_eq(str, "ls ; ls -la | grep test > result < test");
}

Test (mysh1, clean_str_tab)
{
    char *str = clean_str("ls     \t     ; ls -la    | grep test     > result  < test");

    cr_assert_str_eq(str, "ls ; ls -la | grep test > result < test");
}
