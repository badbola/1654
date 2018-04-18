#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main() 
{
      int avt[10],t[10], bst[10] ;
      double wtt = 0, trat = 0, end;
      int i, sml, count = 0, time, lmt;
      float avgwt, avgtr;
      printf("\n***** Enter number of processes you want*****:\n");
      scanf("%d", &lmt); 
      printf("\n===== %d Processes, enter the listed requiremets =====\n", lmt);
      for(i = 0; i < lmt; i++)
      {
            printf("\n_____Arrival time:_____\n");
            scanf("%d", &avt[i]);
            printf("_____Burst time:_____\n");
            scanf("%d", &bst[i]); 
            t[i] = bst[i];
      }
      bst[9] = 9999;  
      for(time = 0; count != lmt; time++)
      {
            sml = 9;
            for(i = 0; i < lmt; i++)
            {
                  if(avt[i] <= time && bst[i] < bst[sml] && bst[i] > 0)
                  {
                        sml = i;
                  }
            }
            bst[sml]--;
            if(bst[sml] == 0)
            {
                  count++;
                  end = time + 1;
                  wtt = wtt + end - avt[sml] - t[sml];
                  trat = trat + end - avt[sml];
            }
      }
      avgwt = wtt / lmt; 
      avgtr = trat / lmt;
      printf("\n\n .....Average Waiting time is=\t%lf.....\n", avgwt);
      printf(".....Average Turnaround time is=\t%lf.....\n", avgtr);
      return 0;
}
