/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Check for errors before encoding.
*/

#include "redcode.h"
#include "my/my_string.h"

static const check_t checks[] = {
    CHECK(has_missing_name, "No name specified."),
    CHECK(has_missing_comment, "No comment specified."),
    CHECK(has_messy_directives, "The comment must be after the name."),
    CHECK(has_invalid_name, "The name specified is invalid."),
    CHECK(has_invalid_comment, "The comment specified is invalid."),
    CHECK(has_invalid_directives, "Invalid directive."),
    CHECK(has_duplicate_directives, "Duplicate directives found."),
    CHECK(has_invalid_labels, "Invalid label definition."),
    CHECK(has_duplicate_labels, "Multiple definition of the same label."),
    CHECK(has_invalid_arguments, "The instruction arguments are invalid."),
    DONE()
};

int redcode_check(parser_t *parser, const char **msg)
{
    for (size_t i = 0; checks[i].callback != NULL; i++) {
        if (!checks[i].callback(parser))
            continue;

        *msg = checks[i].message;

        return -1;
    }

    return 0;
}
