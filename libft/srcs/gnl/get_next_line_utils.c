#include "get_next_line.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	count1;
	size_t	count2;
	char	*s3;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	count1 = 0;
	count2 = 0;
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[count1])
	{
		s3[count1] = s1[count1];
		count1++;
	}
	while (s2[count2])
		s3[count1++] = s2[count2++];
	s3[count1] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strjoin_free2(char *s1, char *s2)
{
	size_t	count1;
	size_t	count2;
	char	*s3;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	count1 = 0;
	count2 = 0;
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[count1])
	{
		s3[count1] = s1[count1];
		count1++;
	}
	while (s2[count2])
		s3[count1++] = s2[count2++];
	s3[count1] = '\0';
	free(s2);
	return (s3);
}
