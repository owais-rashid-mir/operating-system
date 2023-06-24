#include <iostream>

using namespace std;

int main()
{
    int i, j;
    int n, bt[50], wt[50], tat[50];
    int avwt = 0, avtat = 0;

    cout << "Enter total number of processes: ";
    cin >> n;

    cout << "\nEnter the Burst Time of the processes\n";
    for (i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]: ";
        cin >> bt[i];
    }

    // The waiting time for the first process is 0
    wt[0] = 0; 

    // Calculating the waiting time:
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] = wt[i] + bt[j];
    }

    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

    // Calculating the turnaround time:
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avwt = avwt + wt[i];
        avtat = avtat + tat[i];

        cout << "\nP[" << i + 1 << "]"
             << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }

    avwt = avwt / i;
    avtat = avtat / i;

    cout << "\n\nThe Average Waiting Time is:" << avwt;
    cout << "\nThe Average Turnaround Time is:" << avtat << endl;

    return 0;
}