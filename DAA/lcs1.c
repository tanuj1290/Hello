// The longest common subsequence in C

#include <stdio.h>
#include <string.h>

int i, j, m, n, LCS_table[20][20];
char lcs_p[20][20];
char S1[20] = "ABCBDAB", S2[20] = "BDCABA", b[20][20];
// char S1[20] = "10010101", S2[20] = "010110110", b[20][20];

void lcsAlgo()
{
  m = strlen(S1);
  n = strlen(S2);

  for (i = 0; i <= m; i++)
  {
    LCS_table[i][0] = 0;
    lcs_p[i][0] = '0';
  }
  for (i = 0; i <= n; i++)
  {
    LCS_table[0][i] = 0;
    lcs_p[0][i] = '0';
  }

  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
    {
      if (S1[i - 1] == S2[j - 1])
      {
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
        lcs_p[i][j] = 'D';
      }
      else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1])
      {
        LCS_table[i][j] = LCS_table[i - 1][j];
        lcs_p[i][j] = 'U';
      }
      else
      {
        LCS_table[i][j] = LCS_table[i][j - 1];
        lcs_p[i][j] = 'L';
      }
    }

  int index = LCS_table[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0)
  {
    if (S1[i - 1] == S2[j - 1])
    {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }
  int length = strlen(lcsAlgo);
  printf("S1 : %s \nS2 : %s \n", S1, S2);

  printf("\nLength Table:\n");
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%d ", LCS_table[i][j]);
        }
        printf("\n");
    }
    printf("\nArrow Table:\n");
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%c ", lcs_p[i][j]);
        }
        printf("\n");
    }

  printf("LCS: %s", lcsAlgo);
  printf("\nLCS length is: %d", length);
}

int main()
{
  lcsAlgo();
  printf("\n");
}