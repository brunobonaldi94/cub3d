/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:42:28 by harndt            #+#    #+#             */
/*   Updated: 2023/04/23 23:40:10 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Include external libraries
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// Defines
# define BUFFER_SIZE 42
# define DELIMITER '%'
# define FORMATS "cspdiuxX%"
# define BIN 2
# define OCT 8
# define DEC 10
# define HEX 16

// =============================================================================
// Part 1 - Libc Functions
// =============================================================================

// <ctype.h> functions:
/**
 * @brief Find if a Integer is alphanumeric.
 * @param c Integer containg a position in ASCII.
 * @return Integer greater than or zero if true.
**/
int			ft_isalnum(int c);

/**
 * @brief Find if a Integer is alphabetic.
 * @param c Integer containg a position in ASCII.
 * @return Integer greater than or zero if true.
**/
int			ft_isalpha(int c);

/**
 * @brief Find if a Integer is ASCII.
 * @param c Integer containg a position in ASCII.
 * @return Integer greater than or zero if true.
**/
int			ft_isascii(int c);

/**
 * @brief Find if a Integer is a digit.
 * @param c Integer containg a position in ASCII.
 * @return Integer greater than or zero if true.
**/
int			ft_isdigit(int c);

/**
 * @brief Find if a Integer is printable.
 * @param c Integer containg a position in ASCII.
 * @return Integer greater than or zero if true.
**/
int			ft_isprint(int c);

/**
 * @brief Lowercase a Integer accordingly with ASCII.
 * @param c Integer containg a position in ASCII.
 * @return The lowercase Integer.
**/
int			ft_tolower(int c);

/**
 * @brief Uppercase a Integer accordingly with ASCII.
 * @param c Integer containg a position in ASCII.
 * @return The uppercase Integer.
**/
int			ft_toupper(int c);

// <string.h> functions:
// Memory:

/**
 * @brief Compares the first n bytes of memory area.
 * @param str1 Pointer to a block of memory.
 * @param str2 Pointer to a block of memory.
 * @param n The number of bytes being compared.
 * @return if 0 indicates str1 is equals to str2.
 * @return if >0 indicates str1 is less than str2.
 * @return if <0 indicates str2 is less than str1.
**/
int			ft_memcmp(const void *str1, const void *str2, size_t n);

/**
 * @brief Searches fot he first occurence of the character.
 * @param str Pointer to block of memory where the search is performed.
 * @param c Integer searched byte per byte.
 * @param n The number of bytes being analyzed.
 * @return Pointer to the matching byte or NULL if it soes not occur.
**/
void		*ft_memchr(const void *str, int c, size_t n);

/**
 * @brief Copies the character c to the first n characters of a string.
 * @param str Pointer to block of memory to fill.
 * @param c Value to be set.
 * @param n The number of bytes to set the value.
 * @return Pointer to the memory area str.
**/
void		*ft_memset(void *str, int c, size_t n);

/**
 * @brief Copies n character from memory area src to memory area dest.
 * @param dest Pointer to the destination array.
 * @param src Pointer to the source of data to be copied.
 * @param n The number of bytes to be copied.
 * @return Pointer to to destination.
**/
void		*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies character from src to dst, in case of overlapping memory blocks.
 * @param dst Pointer to the dst array where the content is to be copied.
 * @param src Pointer to the src of data to be copied.
 * @param n The number of bytes to be copied.
 * @return Pointer to the destination.
**/
void		*ft_memmove(void *dst, const void *src, size_t n);

// Strings:
/**
 * @brief Computes the length of the string, not including the null character.
 * @param str String whose length is to be found.
 * @return Length of string.
**/
size_t		ft_strlen(const char *str);

/**
 * @brief Compares the first (at most) n bytes of s1 and s2.
 * @param s1 String to be compared.
 * @param s2 String to be compared.
 * @param n Size in which s1 and s2 will be compared.
 * @return if >=0 indicates the value is found.
 * @return if <0 indicates the value is not found.
**/
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Compare s1 and s2.
 * @param s1 String to be compared.
 * @param s2 String to be compared.
 * @return if == 0 indicates the string are equal.
 * @return if <> 0 indicates the value is different
**/
int			ft_strcmp(char *s1, char *s2);

/**
 * @brief Duplicate a String.
 * @param str String to be duplicated.
 * @return Pointer to the duplicated string.
 * @return NULL is insufficient memory was available.
**/
char		*ft_strdup(const char *str);

/**
 * @brief Searches for the first occurence of the character.
 * @param str String to be scanned.
 * @param c The character to be searched in str.
 * @return Pointer the first occurence of the character.
 * @return NULL if the character is not found.
**/
char		*ft_strchr(const char *str, int c);

/**
 * @brief Searches for the last occurence of the character.
 * @param str String to be scanned.
 * @param c The character to be searched in str.
 * @return Pointer the first occurence of the character.
 * @return NULL if the character is not found.
**/
char		*ft_strrchr(const char *str, int c);

// BSD (<bsd/string.h>):
/**
 * @brief Copies up to size -1 character from src to dst.
 * @param dst Pointer to dst where the content is to be copied.
 * @param src Pointer to the source of data to be copied.
 * @return Total length of the String tried to create.
**/
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Append to size -1 character from src to the end of dst.
 * @param dst Pointer to the dst array where the content is to be appended.
 * @param src Pointer to the source of data to be copied.
 * @return Total length of the String tried to create.
**/
size_t		ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Locates the first occurence of the null-terminated String s2 in the s1.
 * @param s1 Pointer to be searched.
 * @param s2 Pointer that will be passed to search.
 * @param n Size limit to where to search s2.
 * @return Pointer to the first character where s2 is found.
 * @return If s2 is empty, s1 is returned.
 * @return If s2 does not occurs in s1 NULL is returned.
**/
char		*ft_strnstr(const char *s1, const char *s2, size_t n);

// <stdlib.h> functions:
/**
 * @brief Converts the String to Integer.
 * @param str String representation of an Integer.
 * @return If converted is done, return the Integer number.
 * @return If the converted is not done, return zero.
**/
int			ft_atoi(const char *str);

/**
 * @brief Allocates the requested memory.
 * @param nitem Number of elements to be allocated.
 * @param size Size of elements.
 * @return If converted is done, return the Integer number.
 * @return Pointer to the allocated memory, or NULL.
**/
void		*ft_calloc(size_t nitems, size_t size);

// <strings.h> functions:
/**
 * @brief Sets the fist n bytes of the area starting as s to zero.
 * @param s Pointer for memory block setted.
 * @param n Size of the memory block.
 * @return None.
**/
void		ft_bzero(void *s, size_t n);

// =============================================================================
// Part 2 - Additional Functions
// =============================================================================

/**
 * @brief Allocates substring from the string.
 * @param s String from wich to create the substring.
 * @param start Start index of the substring in the string.
 * @param len Maximum length of the substring.
 * @return Pointer to the substring, or NULL if the allocation fails.
**/
char		*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates new String with s1 and s2.
 * @param s1 String preffix.
 * @param s2 String preffix.
 * @return Pointer to the new String, or NULL if the allocation fails.
**/
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates a copy of s1 with characters in set removed from both ends.
 * @param s1 String to be trimmed.
 * @param s2 String referenced to trim.
 * @return Pointer to the copied String, or NULL if the allocation fails.
**/
char		*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates an array obtained by splitting s delimited by c.
 * @param s String to be splited.
 * @param c String delimiter character.
 * @return Pointer to the splitted String.
**/
char		**ft_split(char const *s, char c);

/**
 * @brief Allocates a String received by Integers.
 * @param n Integer to convert.
 * @return The String representing the Integer, or NULL if the allocation fails.
**/
char		*ft_itoa(int n);

/**
 * @brief Applies function 'f' to each character in the String 's'.
 * @param s String which to iterate.
 * @param f Function to apply to each character.
 * @return Index to the first position in the new array.
 **/
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies function 'f' to each character in the String 's'.
 * @param s String which to iterate.
 * @param f Function to apply to each character.
**/
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Outputs the character 'c' to the given file descriptor.
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
**/
void		ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the String 's' to the given file descriptor.
 * @param s The String to output.
 * @param fd The file descriptor on which to write.
**/
void		ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the String 's' to the given file descriptor followed newline.
 * @param s The String to output.
 * @param fd The file descriptor on which to write.
**/
void		ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the Integer 'n' to the given file descriptor.
 * @param n The Integer to output.
 * @param fd The file descriptor on which to write.
**/
void		ft_putnbr_fd(int n, int fd);

// =============================================================================
// Bonus Part
// =============================================================================

/**
 * @brief Basic structure of a linked list node.
 * @param content The data contained in the node.
 * @param next The address of the next node.
 * or NULL if the next node is the last one.
**/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Allocates and returns a new node.
 * @param content to create the node with.
 * @return The new node.
**/
t_list		*ft_lstnew(void *content);

/**
 * @brief Adds the node 'new' at the beginning of the list.
 * @param lst Address of a pointer to the first link of a list.
 * @param new Address of a pointer to the node to be added to the list.
**/
void		ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return The lenght of the list.
**/
int			ft_lstsize(t_list *lst);

/**
 * @brief Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return Last node of the list.
**/
t_list		*ft_lstlast(t_list *lst);

/**
 * @brief Adds the node 'new' at the end of the list.
 * @param lst Addres of a pointer to the first of a list.
 * @param new Addres of a pointer to the node to be add to the list.
**/
void		ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Frees the memory of the node given as parameter.
 * The memory of 'next' must no be freed.
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
**/
void		ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the given node and every successor.
 * The pointer to the list must be set to NULL.
 * @param lst Address of a pointer to a node.
 * @param del Address of the function used to delete node's content.
**/
void		ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' in each node.
 * @param lst Address of a pointer to a node.
 * @param f Address of the function used to iterate on the list.
**/
void		ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list 'lst' and applies the funtion 'f' on the content
 * of each node. Creates a new list resultin of the successie applications of
 * the function 'f'. The 'del' function is used to delete the content of a
 * node if needed.
 * @param lst Address ofa pointer to a node.
 * @param f Function's address used to iterate on the list.
 * @param del Function's address used to delete the nodes's content if needed.
 * @return The new list, or NULL if the allocation fails.
**/
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));

/**
 * @brief free a pointer of any type.
 * @param ptr void **ptr - pointer to a void pointer
 * @return void
**/
void		ft_free_ptr(void **ptr);

/**
 * @brief check each char in a string if meets a requirement
 * @param str string to check
 * @param ft_check_each_char function to check each char
 * @return boolean
**/
int			ft_is_all_something(char *str, int (*f)(int));

// =============================================================================
// GNL Functions
// =============================================================================

/**
 * @brief Get the next line read from a file descriptor.
 * @param fd The file desdriptor to read from.
 * @return The read line, or NULL if there is nothing to read
 * or an error occured.
 */
char		*ft_get_next_line(int fd);

/**
 * @brief Copies up to '\n' or the end of a string to dst.
 * @param dst Pointer to dst where the cont is to be copied.
 * @param src Pointer to the source of data to be coped.
 * @param index Indicator of the starting position to be copied at dst.
 * @return The new lengt of dst.
 */
size_t		ft_cpyline(char *dst, const char *src, size_t len);

// =============================================================================
// FT_PRINTF Function
// =============================================================================

/**
 * @brief A type that receives a va_list.
 */
typedef int			(*t_specifier)(va_list);

/**
 * @brief The functions sends formatted output to stdout.
 * @param format the String that contains the text to be written to stdout.
 * It can optionally contain embedded format tags that are replaced by
 * values specified in subsequent additional arguments and formatted as
 * requested.
 * @return Upon success retuns the number of characters printed (excluding
 * the null byte used to end output to strings).On failure, a negative number
 * is returned.
 **/
int			ft_printf(const char *format, ...);

//Specifiers functions
/**
 * @brief Prints the content as a character and find it's length.
 * @param arg_ptr Va_list variables.
 * @return 1.
**/
int			ft_specifier_c(va_list arg_ptr);

/**
 * @brief Prints the content as an int and find it's length.
 * @param arg_ptr Va_list variables.
 * @return The length from the arg_ptr received.
**/
int			ft_specifier_d(va_list arg_ptr);

/**
 * @brief Prints the content as a memory address and find it's length.
 * @param arg_ptr Va_list variables.
 * @return The length from the arg_ptr received + 2.
**/
int			ft_specifier_p(va_list arg_ptr);

/**
 * @brief Prints the content as a character '%' and find it's length.
 * @param arg_ptr Va_list variables.
 * @return 1.
**/
int			ft_specifier_percent(va_list arg_ptr);

/**
 * @brief Prints the content as a String and find it's length.
 * @param arg_ptr Va_list variables.
 * @return The length from the arg_ptr received.
**/
int			ft_specifier_s(va_list arg_ptr);

/**
 * @brief Prints the content as an unsigned int and find it's length.
 * @param arg_ptr Va_list variables.
 * @return The length from the arg_ptr received.
**/
int			ft_specifier_u(va_list arg_ptr);

/**
 * @brief Prints the content as a hexadecimal (lower) and find it's length.
 * @param arg_ptr Va_list variables.
 * @return The length from the arg_ptr received.
**/
int			ft_specifier_upperx(va_list arg_ptr);

/**
 * @brief Prints the content as a hexadecimal (upper) and find it's length.
 * @param arg_ptr Va_list variables.
 * @return The length from the arg_ptr received.
**/
int			ft_specifier_x(va_list arg_ptr);

/**
 * @brief Prints one char.
 * @param c Char to be printed.
**/
void		ft_putchar(char c);

/**
 * @brief Finds a char in a String.
 * @param str String to be searched.
 * @param c Char to search for.
 * @return The index position 'c' is found. -1 if there is no 'c'.
 */
int			ft_strnchr(const char *str, int c);

/**
 * @brief Converts the Unsigned integer n into a character String.
 * @param n Unsigned int to be converted.
 * @param base Base in which 'n' must be converted into.
 * @return Pointer to a String contaning the unsigned int converted.
 */
char		*ft_utoa_base(unsigned long n, int base);

/**
 * @brief Prints a string.
 * @param str String to be printed.
**/
void		ft_putstr(char *str);

/**
 * @brief Comnputes the absolute calue of the integer argument 'x'.
 *
 * @param x The value to compute.
 * @return int The abosulute value of the integer argument.
 */
int			ft_abs(int x);

// =============================================================================
// MINITALK
// =============================================================================

# define TRUE 1
# define FALSE 0

typedef int			t_bool;

/**
 * @brief Checks if the str is a number.
 *
 * @param str The string to check.
 * @return t_bool If the string only contains numbers TRUE, else FALSE.
 */
int		ft_isnum(char *str);

/**
 * @brief Checks a condition.
 *
 * @param condition Tp be tested.
 * @param a First parameter.
 * @param b Second parameter.
 * @return int The correct parameter.
 */
int			ft_ternary(int condition, int a, int b);

// =============================================================================
// PUSH_SWAP
// =============================================================================

/**
 * @brief Converts the String to Long.
 * @param str String representation of an Integer.
 * @return If converted is done, return the Long number.
 * @return If the converted is not done, return zero.
**/
long		ft_atol(const char *str);

/**
 * @brief Found the position of the given content.
 * @param t_list The list to be searched.
 * @param unsigned int The content to be looked for.
 * @return The list at the position founded.
**/
t_list		*ft_lstat(t_list *list, unsigned int n);

/**
 * @brief Duplicates the given list.
 * @param t_list The list to be duplicated.
 * @return The new duplicated list.
**/
t_list		*ft_lstdup_int(t_list *list);

/**
 * @brief Sorts a list.
 * @param t_list The list to be sorted.
 * @param int The first content.
 * @param int The last content.
**/
void		ft_lstsort(t_list *list, int start, int end);

/**
 * @brief Found a position in the list.
 * @param t_list The list to be scrapped.
 * @param void The data to be compared.
 * @param int The result from the cmp function.
 * @return The list at the founded position.
**/
t_list		*ft_lstfind(t_list *list, void *data, int (*cmp)());

// =============================================================================
// MINISHELL
// =============================================================================

/**
 * @brief free a pointer of any type.
 * @param ptr void **ptr - pointer to a void pointer

**/
void		ft_free_ptr(void **ptr);

/**
 * @brief Allocates new String with s1 and s2, free both strings received
 * as args.
 * @param s1 String preffix.
 * @param s2 String preffix.
 * @return Pointer to the new String, or NULL if the allocation fails.
**/
char		*ft_strjoin_free(char const *s1, char const *s2);

/**
 * @brief create a new string that replace the
 *  string "to_find" to "to replace" str.
 * @param s String to be scanned.
 * @param to_find string to be found.
 * @param to_replace string to replace.
 * @return  with malloc, new str with replaced value.
 * @return NULL if to_find not found in s string.
**/
char		*ft_replace_str(char *s, char *to_find, char *to_replace);

/**
 * @brief Deletes and frees the given node and every successor,
 * does not free content.
 * The pointer to the list must be set to NULL.
 * @param lst Address of a pointer to a node.
 * @param del Address of the function used to delete node's content.
**/
void		ft_lstclear_not_free_content(t_list **lst, void (*del)(void *));

/**
 * @brief Searches for the first occurence of the character.
 * @param str String to be scanned.
 * @param c The character to be searched in str.
 * @return index of charcter found in str.
 * @return -1 if the character is not found.
**/
int			ft_strchr_pos(const char *str, int c);

/**
 * @brief Count occurrences of a char in a string.
 * @param str String to be scanned.
 * @param c The character to be searched in str.
 * @return count of ocurrences of char found in str.
 * @return 0 if the character is not found.
**/
int			ft_count_char(char *str, char c);

/**
 * @brief free a matrix of any type.
 * @param matrix void ***matrix - pointer to pointer to a void pointer
 * @return void
**/
void		ft_free_matrix(void ***matrix);

typedef long long	t_llong;

t_llong		ft_atoll(const char *str);

#endif
