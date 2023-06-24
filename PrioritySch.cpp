#include <iostream>
using namespace std;

int main()
{
    int i, j;
    int bt[50], p[50], wt[50], tat[50], pr[50];
    int n, total = 0, pos, temp, avg_wt, avg_tat;

    cout << "Enter Total Number of Process:";
    cin >> n;

    cout << "\nEnter Burst Time and Priority of processes: \n";
    for (i = 0; i < n; i++)
    {
        cout << "\nP[" << i + 1 << "]\n";
        cout << "Burst Time:";
        cin >> bt[i];

        cout << "Priority:";
        cin >> pr[i];
        p[i] = i + 1; // contains process number
    }

    // Sorting priority, burst time and process number in ascending order using selection sort
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
                pos = j;
        }
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    // waiting time for first process is zero.
    wt[0] = 0; 

    // calculate waiting time
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] = wt[i] + bt[j];
        total = total + wt[i];
    }

    // average waiting time
    avg_wt = total / n; 

    total = 0;
    cout << "\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for (i = 0; i < n; i++)
    {
        // Calculating turn around time
        tat[i] = bt[i] + wt[i]; 
        total = total + tat[i];
        cout << "\nP[" << p[i] << "]\t\t  " << bt[i] << "\t\t    " << wt[i] << "\t\t\t" << tat[i];
    }

    avg_tat = total / n; // average turnaround time
    cout << "\n\nAverage Waiting Time=" << avg_wt;
    cout << "\nAverage Turnaround Time=" << avg_tat << endl;
    return 0;
}