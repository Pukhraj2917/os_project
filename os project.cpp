// C++ program to implement longest Job first
#include<bits/stdc++.h>
using namespace std;
 
struct Student
{
   int pid; // student ID
   int gift;  // no. of gifts with student
};
 
// This function is used for sorting all
// student in increasing order of burst
// time
bool comparison(Student a, Student b)
{
     return (a.gift > b.gift);
}
 
// Function to find the waiting time for all
// students
void findWaitingTime(Student Stu[], int n, int wt[])
{
    // waiting time for first Student is 0
    wt[0] = 0;
 
    // calculating waiting time
    for (int i = 1; i < n ; i++ )
        wt[i] = Stu[i-1].gift + wt[i-1] ;
}
 
// Function to calculate turn around time
void findTurnAroundTime(Student Stu[], int n,
                        int wt[], int tat[])
{
    // calculating turnaround time by adding
    // gift[i] + wt[i]
    for (int i = 0; i < n ; i++)
        tat[i] = Stu[i].gift + wt[i];
}
 
//Function to calculate average time
void findavgTime(Student Stu[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // Function to find waiting time of all Students
    findWaitingTime(Stu, n, wt);
 
    // Function to find turn around time for all processes
    findTurnAroundTime(Stu, n, wt, tat);
 
    // Display processes along with all details
    cout << "\nStudent ID "<< " No. of Gifts "
         << " Waiting time " << " Turn around time\n";
 
    // Calculate total waiting time and total turn
    // around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << Stu[i].pid << "\t\t"
             << Stu[i].gift << "\t " << wt[i]
             << "\t\t " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}
 
// Driver code
int main()
{
    Student Stu[] = {{1, 6}, {2, 8}, {3, 7}, {4, 3}};
    int n = sizeof Stu / sizeof Stu[0];
 
    // Sorting Students by burst time.
    sort(Stu, Stu + n, comparison);
 
    cout << "Order in which students will pay bill\n";
    for (int i = 0 ; i < n; i++)
        cout << Stu[i].pid <<" ";
 
    findavgTime(Stu, n);
    return 0;
}

