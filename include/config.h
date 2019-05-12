/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** The redcode configuration.
*/

#ifndef REDCODE_CONFIG_H
#define REDCODE_CONFIG_H

#define NULL_ARGV {0}
#define AFF_ARGV {T_REG}
#define LIVE_ARGV {T_DIR}
#define LFORK_ARGV {T_DIR | T_2B}
#define ZJMP_ARGV {T_DIR | T_2B}
#define FORK_ARGV {T_DIR | T_2B}
#define ST_ARGV {T_REG, T_IND | T_REG}
#define LD_ARGV {T_DIR | T_IND | T_4B, T_REG}
#define ADD_ARGV {T_REG, T_REG, T_REG}
#define SUB_ARGV {T_REG, T_REG, T_REG}
#define LLD_ARGV {T_DIR | T_IND | T_4B, T_REG}
#define LLDI_ARGV {T_REG | T_DIR | T_IND | T_2B, T_DIR | T_REG | T_2B, T_REG}
#define AND_ARGV {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}
#define XOR_ARGV {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}
#define OR_ARGV {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}
#define STI_ARGV {T_REG, T_REG | T_DIR | T_IND | T_2B, T_DIR | T_REG | T_2B}
#define LDI_ARGV {T_REG | T_DIR | T_IND | T_2B, T_DIR | T_REG | T_2B, T_REG}

#ifndef REDCODE_HEADER
#define REDCODE_HEADER (0xf383ea00)
#endif

#ifndef MAX_ARGS
#define MAX_ARGS (4)
#endif

#ifndef IND_SIZE
#define IND_SIZE (2)
#endif

#ifndef REG_SIZE
#define REG_SIZE (1)
#endif
#ifndef REG_CHAR
#define REG_CHAR ('r')
#endif
#ifndef REG_COUNT
#define REG_COUNT (16)
#endif

#ifndef DIR_SIZE
#define DIR_SIZE (4)
#endif
#ifndef DIR_CHAR
#define DIR_CHAR ('%')
#endif

#ifndef LAB_CHAR
#define LAB_CHAR (':')
#endif
#ifndef COMMENT_CHAR
#define COMMENT_CHAR ('#')
#endif
#ifndef SEPARATOR_CHAR
#define SEPARATOR_CHAR (',')
#endif

#ifndef LAB_CHARS
#define LAB_CHARS ("abcdefghijklmnopqrstuvwxyz_0123456789")
#endif

#ifndef NAME_STR
#define NAME_STR ("name")
#endif
#ifndef NAME_LENGTH
#define NAME_LENGTH (128)
#endif

#ifndef COMMENT_STR
#define COMMENT_STR ("comment")
#endif
#ifndef COMMENT_LENGTH
#define COMMENT_LENGTH (2048)
#endif

#endif
