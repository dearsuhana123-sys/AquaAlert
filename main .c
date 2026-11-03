#include <stdio.h>

#define MAX 10

int calculateTotal(int water[], int count)
{
    int total = 0;
    int i;

    for (i = 0; i < count; i++)
    {
        total = total + water[i];
    }

    return total;
}

int main()
{
    char name[30];
    int water[MAX];
    int count = 0;
    int target, choice, amount, total;
    int i;

    printf("===== AQUAALERT =====\n");
    printf("Daily Water Intake Tracker\n");

    printf("Enter your first name: ");
    scanf("%29s", name);

    printf("Enter your daily water target in ml: ");
    scanf("%d", &target);

    if (target <= 0)
    {
        printf("Invalid target!\n");
        return 0;
    }

    do
    {
        printf("\nWelcome, %s!\n", name);
        printf("\n1. Add Water Intake\n");
        printf("2. View Total Intake\n");
        printf("3. View All Records\n");
        printf("4. Check Target\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        if(scanf("%d",&choice)!=1)
        {
            printf("Please enter a valid number.\n");
        break;
        }
        if (choice == 1)
        {
            if (count < MAX)
            {
                printf("Enter water consumed in ml: ");
                scanf("%d", &amount);

                if (amount > 0)
                {
                    water[count] = amount;
                    count++;
                    printf("Water intake recorded!\n");
                }
                else
                {
                    printf("Enter a positive amount.\n");
                }
            }
            else
            {
                printf("Maximum entries reached!\n");
            }
        }
        else if (choice == 2)
        {
            total = calculateTotal(water, count);
            printf("Total water consumed: %d ml\n", total);
        }
        else if (choice == 3)
        {
            if (count == 0)
            {
                printf("No records available.\n");
            }
            else
            {
                printf("\nWater Intake Records:\n");

                for (i = 0; i < count; i++)
                {
                    printf("%d. %d ml\n", i + 1, water[i]);
                }
            }
        }
        else if (choice == 4)
        {
            total = calculateTotal(water, count);

            printf("Daily target: %d ml\n", target);
            printf("Total consumed: %d ml\n", total);

            if (total >= target)
            {
                printf("Congratulations! Target reached.\n");
            }
            else
            {
                printf("Warning: %d ml remaining to reach target.\n",
                       target - total);
            }
        }
        else if (choice == 5)
        {
            printf("Thank you for using AquaAlert!\n");
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}