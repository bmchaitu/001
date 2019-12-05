#include <stdio.h>
#include <string.h>
 
int hash[1000001][26];
char string[1000005];
 
int main()
{
	int n, q, len = 0, i = 0;
	scanf("%d%d", &n, &q);
	scanf("%s", string);
 
	len = strlen(string);
 
	/*
	 * Prepare the hash.
	 */
	for (i = 0; i < 26; i++) {
		hash[0][i] = 0;
	}
 
	/*
	 * Fill the hash for the remaining elements.
	 */
	for (i = 1; i <= len; i++) {
		int j, index;
		for (j = 0; j < 26; j++) {
			hash[i][j] = hash[i - 1][j];
		}
 
		index = string[i - 1] - 'a';
		hash[i][index]++;
	}
#if 0
	for (i = 0; i <= len; i++) {
		int j;
		for (j = 0; j < 26; j++) {
			printf("%d ", hash[i][j]);
		}
		printf("\n");
	}
#endif
	/*
	 * Read the individual queries and fill the ring.
	 */
	while (q--) {
		int l, m, k, count = 0;
		scanf("%d%d%d", &l, &m, &k);
 
		for (i = 0; i < 26; i++) {
			count += hash[m][i] - hash[l - 1][i];
			if (count >= k)
				break;
		}
 
		printf("%c\n", 'a' + i,count);
	}
 
	return 0;
}
