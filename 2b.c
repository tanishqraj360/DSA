/*Write a C program to read and display the student details. Define a structure
'Student' with fields name(string) , usn(int), marks of 3 subjects (int) and
average(float) in it. Store the details of n students in an array of structure 'Student'.
Display the details of all students in the descending order their total marks*/

#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];
    int usn;
    int marks[3];
    float average;
    int totalMarks;
};

void AverageAndTotal(struct Student *s1)
{
    s1->totalMarks = 0;
    for (int i = 0; i < 3; ++i)
    {
        s1->totalMarks += s1->marks[i];
    }
    s1->average = (float)s1->totalMarks / 3.0;
}

void displayStudents(struct Student s1[], int n)
{
    printf("\nStudent Details (Descending order of total marks):\n");
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Name", "USN", "Subject 1", "Subject 2", "Subject3");

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (s1[j].totalMarks < s1[j + 1].totalMarks)
            {
                struct Student temp = s1[j];
                s1[j] = s1[j + 1];
                s1[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%-20s %-10d %-10d %-10d %-10d\n", s1[i].name, s1[i].usn, s1[i].marks[0], s1[i].marks[1], s1[i].marks[2]);
    }
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student s1[n];
    for (int i = 0; i < n; ++i)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", s1[i].name);
        printf("Enter USN: ");
        scanf("%d", &s1[i].usn);
        printf("Enter marks for Subject 1: ");
        scanf("%d", &s1[i].marks[0]);
        printf("Enter marks for Subject 2: ");
        scanf("%d", &s1[i].marks[1]);
        printf("Enter marks for Subject 3: ");
        scanf("%d", &s1[i].marks[2]);

        AverageAndTotal(&s1[i]);
    }
    displayStudents(s1, n);
    return 0;
}
