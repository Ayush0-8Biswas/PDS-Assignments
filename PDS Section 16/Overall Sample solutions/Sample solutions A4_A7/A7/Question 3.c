// Assignment 7 Question 3

#include <stdio.h.>
#include <string.h>
#include <math.h>

typedef struct
{
    int day, month, year;
}
date;

int leap_year (date);
void day_identify (date, int);
int _diff (date, date);
date date_identify (date, int);

date m_to_d (date x); // Converts months to days e.g. 20/3/2003 becomes 31(Jan) + 28(Feb) + 20 /3/2003 = 79/3/2003

int main()
{
    // Variable Declaration
    date input, input2; // input : Stores first date , input2 : Stores second date
    char day[10]; // day : Stores day of 1st January of year of second date
    int choice, days; // choice : Stores choice in Menu , days : number of days they want after entered date

    // Prompting user for inputting date and storing input.
    printf("Enter a date in dd, mm & yyyy format.\n");
    scanf("%d%d%d", &input.day, &input.month, &input.year);

    // Printing Menu
    printf("\n------------------------------MENU------------------------------\n");
    printf("1. Check if entered date lies in a leap year.\n");
    printf("2. Get day on which the entered date lies.\n");
    printf("3. Calculate the number of days between entered date and another date.\n");
    printf("4. Get the date that lies a particular number of days after entered date.\n\n");

    // Prompting user to enter choice in Menu and storing input.
    printf("Enter number corresponding to your choice.\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1: // Check if entered date lies in a leap year.
        printf((leap_year(input) == 1) ? "\n\nEntered date lies in a leap year.\n" : "\n\nEntered date does not lie in a leap year.\n");
        break;

    case 2: // Get day on which the entered date lies.
        printf("\nEnter day of 1st January, %d.\n", input.year);
        scanf("%s", day);
        strlwr(day); // Reducing string containing day to lowercase.
        // Linking each day with a number, so as to make computations easier, and calling function with appropriate parameters.
        if (strcmp("sunday", day) == 0)
            day_identify(input, 0);
        else if (strcmp("monday", day) == 0)
            day_identify(input, 1);
        else if (strcmp("tuesday", day) == 0)
            day_identify(input, 2);
        else if (strcmp("wednesday", day) == 0)
            day_identify(input, 3);
        else if (strcmp("thursday", day) == 0)
            day_identify(input, 4);
        else if (strcmp("friday", day) == 0)
            day_identify(input, 5);
        else if (strcmp("saturday", day) == 0)
            day_identify(input, 6);
        break;

    case 3: // Calculate the number of days between entered date and another date.
        printf("\nEnter a date in dd, mm & yyyy format.\n");
        scanf("%d%d%d", &input2.day, &input2.month, &input2.year);
        printf("\n\nDifference between the two dates is %d days.\n", _diff(input, input2));
        break;

    case 4: // Get the date that lies a particular number of days after entered date.
        printf("\nEnter number of days.\n");
        scanf("%d", &days);
        date output = date_identify(input, days);
        printf("\n\nThe required date is %2d/%2d/%d\n", output.day, output.month, output.year);
        break;

    default:
        printf("Invalid Choice.\n");
    }

    return 0;
}

int leap_year (date input) // returns 1 if date lies in a leap year and returns 0 otherwise.
{
    // If year is divisible by 400, it a leap year. If indivisible by 400, but divisible by 100 it is not a leap year. All other years divisible by 4 are leap years.
    return (input.year % 400 == 0) ? 1 : (input.year %100 == 0) ? 0 : (input.year % 4 == 0) ? 1 : 0;
}

void day_identify (date input, int day) // Prints day on which date falls.
{
    input = m_to_d(input); // Converts all months to days(excess)

    switch ((input.day  + day) % 7 - 1) // (input.day + day) % 7 - 1 gives odd/excess days
    {
    case 0:
        printf("\n\nIts a Sunday.\n");
        break;

    case 1:
        printf("\n\nIts a Monday.\n");
        break;

    case 2:
        printf("\n\nIts a Tuesday.\n");
        break;

    case 3:
        printf("\n\nIts a Wednesday.\n");
        break;

    case 4:
        printf("\n\nIts a Thursday.\n");
        break;

    case 5:
        printf("\n\nIts a Friday.\n");
        break;

    case 6:
        printf("\n\nIts a Saturday.\n");
    }
}

int _diff (date input, date input2) // Returns number of days between the two dates.
{
    int diff = 0; // Stores required output

    // Converts all months of both dates into days(excess).
    input = m_to_d(input);
    input2 = m_to_d(input2);

    // max : stores date with year that comes later , min : stores date with year that comes earlier
    date max = (input.year > input2.year) ? input : input2, min = (input.year > input2.year) ? input2 : input;

    for (int i = min.year; i < max.year; i++)
        diff += (i % 4 == 0) ? 366 : 365; // Adds number of days that max is ahead of min in years

    return abs(diff + max.day - min.day); // Adds number of days that max is ahead of min in days and returns it
}

date date_identify (date input, int days) // Returns date that lies a particular number of days after entered date.
{
    input.day += days; // input.days now stores excess days.
    int flag = 0, num; // flag: To keep track of when all excess days have been converted to months , num : To store number of days in Feb

    // Converting excess days to months.
    while (flag == 0) // While there are excess days, that need to be converted.
    {
        switch (input.month % 12) // Months might be greater than 12 (excess), so we take month % 12. Dec = 0 instead of 12
        {
            // 31 day months
        case 0: // December
        case 1: // January
        case 3: // March
        case 5: // May
        case 7: // July
        case 8: // August
        case 10: // October
            if (input.day > 31)
            {
                input.day -= 31; // Removes excess days for current 31-day month.
                input.month += 1; // Updates month to next month.
            }
            switch (input.month % 12) // Checks if there are still excess days left and updates flag accordingly.
            {
            case 2: // February (next month after January)
                if (input.day <= (leap_year(input) == 0) ? 28 : 29) // If excess days remain
                    flag++;
                    break;

                // 30 day months
            case 4: // April (next month after March)
            case 6: // June (next month after May)
            case 9: // September (next month after August)
            case 11: // November (next month after October)
                if (input.day <= 30) // If excess days remain
                    flag++;
                    break;

                // 31 day months
            case 1: // January (next month after December)
            case 8: // August (next month after July)
                if (input.day <= 31) // If excess days remain
                    flag++;
            }
            break;

            // 30 day months
        case 4: // April
        case 6: // June
        case 9: // September
        case 11: // November
            if (input.day > 30)
            {
                input.day -= 30; // Removes excess days of current 30-day month.
                input.month += 1; // Updates month to next month.
            }
            if (input.day <= 31) // All months after 30 day months are 31 day months.
                flag++;
            break;

        case 2: // February
            num = (leap_year(input) == 1) ? 29 : 28;
            if (input.day > num)
            {
                input.day -= num; // Removes excess days of current month.
                input.month += 1; // Updates month to next month.
            }
            if (input.day <= 31) // Next month is March with 31 days.
                flag++;
        }
    }

    // Converting excess months to years.
    while (input.month > 12)
    {
        input.month -= 12; // Removes excess months of current year.
        input.year += 1; // Updates year to next year.
    }

    return input;
}

date m_to_d (date x) // Converts months to days e.g. 20/3/2003 becomes 31(Jan) + 28(Feb) + 20 /3/2003 = 79/3/2003
{
    switch (x.month)
    {
    case 12: // If month = December, add number of days of November = 31, and move on to next case, as there is no break statement. Similar for following cases.
        x.day += 30;

    case 11:
        x.day += 31;

    case 10:
        x.day += 30;

    case 9:
        x.day += 31;

    case 8:
        x.day += 31;

    case 7:
        x.day += 30;

    case 6:
        x.day += 31;

    case 5:
        x.day += 30;

    case 4:
        x.day += 31;

    case 3:
        x.day += (leap_year(x) == 0) ? 28 : 29;

    case 2: // If month = February, add number of days of January = 31
        x.day += 31;
    }

    return x;
}
