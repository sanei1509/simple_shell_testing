#include "main.h"

/**
 *_putchar - writes the character c to stdout
 * @c: The character to print.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
**_strcat - function tha concatenate two strings
* @dest : place where append de src string
* @src: place of the string for append
* Return: pointer to dest
*/

char *_strcat(char *dest, char *src)
{
	int dest_length = 0, src_length = 0, i = 0;
	char *new_string = NULL;

	while (dest[dest_length] != '\0')
		dest_length++;

	while (src[src_length] != '\0')
		src_length++;

	new_string = calloc(2, (dest_length + src_length + 1) * sizeof(char));

	while (dest_length > i)
	{
		new_string[i] = dest[i];
		i++;
	}

	i = 0;

	while (src_length > i)
	{
		new_string[dest_length + i] = src[i];
		i++;
	}

	new_string[dest_length + i + 1] = '\0';

	return (new_string);
}

/**
*_strlen - swaps the value of two integers
* @s: The pointer value one
* Return: c
*/
int _strlen(char *s)
{
	int c = 0;

	while (s[c] != '\0')
		c++;

	return (c);
}

/**
*_strcmp- compare two strings
*@s1: string one to compare
*@s2: string two to compare
* Return: 0 if strings are equal
*/

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 != '\0' && *s2 != '\0'))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
*_strncmp- compare two strings n words
* @s1: string one
* @s2: string two
* @n: number the strings to compare
*Return: 0 if strings are equal <0 s1 less than str2 >0 s2 than s1
*/

int _strncmp(const char s1[], const char s2[], size_t n)
{

	unsigned char c1 = '\0';
	unsigned char c2 = '\0';
	int i;

	for (i = 0; i < (int) n; i++)
	{

		c1 = (unsigned char) s1[i];
		c2 = (unsigned char) s2[i];

		if ((c1 == '\0') || (c1 != c2))
		{

			return (c1 - c2);

		}

	}
	return (c1 - c2);
}

/**
 * *_strcpy - return the copy pointed string por src
 * @dest: copy source to here
 * @src: source for copy
 * Return: copy of src
 */

char *_strcpy(char *dest, char *src)
{
	int length = 0;
	int i;

	while (src[length] != '\0')
		length++;

	for (i = 0; i <= length; i++)
		dest[i] = src[i];

	return (dest);

}


