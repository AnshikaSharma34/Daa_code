#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
}

int main() 
{
    int n, m; 
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int p[n + 1], wt[n + 1]; 
    printf("Enter the profits of the items: ");
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &p[i]);
    }
    
    printf("Enter the weights of the items: ");
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &wt[i]);
    }
    
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &m);
    
    
    int k[n + 1][m + 1];

  
    for (int i = 0; i <= n; i++) 
    {
        for (int w = 0; w <= m; w++) 
        {
            if (i == 0 || w == 0) 
            {
                k[i][w] = 0; 
            } 
            else if (wt[i] <= w) 
            {
                k[i][w] = max(p[i] + k[i - 1][w - wt[i]], k[i - 1][w]);
            } 
            else 
            {
                k[i][w] = k[i - 1][w];
            }
        }
    }
    
    printf("\nMaximum profit: %d\n", k[n][m]);

    
    printf("Items included (1 for included, 0 for not included):\n");
    int i = n, w = m;
    while (i > 0 && w > 0) 
    {
        if (k[i][w] == k[i - 1][w]) 
        {
            printf("Item %d = 0\n", i);
        } 
        else 
        {
            printf("Item %d = 1\n", i);
            w -= wt[i]; 
        }
        i--;
    }
    
    return 0;
}

