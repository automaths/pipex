#include "pipex.h"

bool	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

bool	is_whitespace(char c)
{
	if (c == ' ' && c == '\t' && c == '\v' && c == '\n' && c == '\r' && c == '\f')
		return (1);
	return (0);
}
