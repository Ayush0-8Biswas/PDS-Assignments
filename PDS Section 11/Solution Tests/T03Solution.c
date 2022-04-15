/*
Section: 11
Roll No: 21EE30033
Name: Vidunram A R
Group: 4
Test no: 2
Problem no: 3
Description: Menu Based Program to Add, Update and Display Records and Gold Medalists
*/

#include <stdio.h>

int len = 0, records[20][4];

int CheckRecord(int rollno)
{
    int i;
    for (i=0; i<len; i++) if (records[i][0]==rollno) return i;
    return -1;
}

void UpdateRecord(int arr[])
{
    int phy, chem;
    printf("Enter Physics Marks and Chemistry Marks: ");
    scanf("%d %d", &phy, &chem);
    if (phy>100 || phy<0 || chem>100 || chem<0)
    {
        arr[0] = 0;
        len -= 1;
        printf("Invalid Marks. Try Again.\n");
    }
    else
    {
        arr[1] = phy;
        arr[2] = chem;
        arr[3] = phy+chem;
    }
}

void PrintRecords()
{
    int i, j, k, arr[4], rank, marks, phy, common;
    rank = marks = 0;
    common = 1;
    for (i=0; i<len; i++)
    {
        for (j=0; j<len-i-1; j++)
        {
            if (records[j][3] < records[j+1][3] || (records[j][3] == records[j+1][3] && records[j][1] < records[j+1][1]))
            {
                for (k=0; k<4; k++) arr[k] = records[j][k];
                for (k=0; k<4; k++) records[j][k] = records[j+1][k];
                for (k=0; k<4; k++) records[j+1][k] = arr[k];
            }
        }
    }



    for (i=0; i<len; i++)
    {
        if (marks != records[i][3] || (marks == records[i][3] && phy != records[i][1]))
        {
            rank += common;
            marks = records[i][3];
            phy = records[i][1];
            common = 1;
        }
        else common += 1;

        printf("Rank: %2.d|  Roll No: %2.d| Total: %3.d| Phy: %3.d| Chem: %3.d\n", rank, records[i][0], records[i][3], records[i][1], records[i][2]);
    }
}

void GoldMedalists()
{
    /* Student code
    int code, maxroll[4], i;
    for (i=0; i<4; i++) maxroll[i] = records[0];
    for (i=0; i<len; i++)
    {
        for (code=1; code<=3; code++)
        {
            if (records[i][code] > records[maxroll[code]][code] ) maxroll[code] = records[i];
        }
    }

    printf("\nGold Medalists:\n");
    printf("Physics: %d\n",maxroll[1]);
    printf("Chemistry: %d\n",maxroll[2]);
    printf("Total: %d\n",maxroll[3]);
    */
    
    /*Code Modified by TA Evaluator for Solution-Start*/
    int code, maxroll[4], i;
    for (i=0; i<4; i++) maxroll[i] = records[0][0];
    for (code=1; code<=3; code++)
    {
        for (i=0; i<len; i++)
        {
            if (records[i][code] > records[maxroll[code]][code] ) maxroll[code] = i;
        }
    }
    printf("\nGold Medalists:\n");
    printf("Physics Gold Medal: %d, marks=%d\n",records[maxroll[1]][0], records[maxroll[1]][1]);
    printf("Chemistry Gold Medal: %d, marks=%d\n",records[maxroll[2]][0], records[maxroll[2]][2]);
    printf("Total Gold Medal: %d, marks=%d\n",records[maxroll[3]][0], records[maxroll[3]][3]);
    
    PrintRecords();
    /*Modified Code for Solution-End*/
}

char main()
{
    int i, code, run, rollno;
    run = 1;
    for (i=0; i<20; i++) records[i][0]=0;
    while (run)
    {
        printf("Enter code: ");
        scanf("%d",&code);
        switch (code)
        {
        case 0:
            run = 0;
            break;

        case 1:
            printf("Enter Roll No: ");
            scanf("%d",&rollno);
            if (rollno>0 && rollno<=20 && CheckRecord(rollno)==-1)
            {
                records[len][0] = rollno;
                len+=1;
                UpdateRecord(records[len-1]);
            }
            else printf("Invalid Roll No. Try Again.\n");
            break;
        case 2:
            printf("Enter Roll No: ");
            scanf("%d",&rollno);
            if (rollno>0 && rollno<20 && CheckRecord(rollno)!=-1) UpdateRecord(records[CheckRecord(rollno)]);
            else printf("Record Does Not Exist. Try Again.\n");
            break;
        case 3:
            if (len==0)
            {
                printf("Not enough records.\n");
                break;
            }
            printf("Record of Students:\n\n");
            PrintRecords();
            break;

        case 4:
            if (len==0)
            {
                printf("Not enough records.\n");
                break;
            }
            GoldMedalists();
            break;
        }
        printf("\n");
    }


    return 'V';
}
