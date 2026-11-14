
#include <stdio.h>

int main()
{
    int pages[100], frames[20], lastUsed[20];
    int n, f, i, j;
    int faults = 0, time = 0;

    // Total pages input lena
    printf("Enter reference string length: ");
    scanf("%d", &n);

    // Page reference string input lena
    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    // Total memory frames input lena
    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initially saare frames empty aur last-used time -1
    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
        lastUsed[i] = -1;
    }

    printf("\nPage\tFrames\n");

    // Har page ko ek-ek karke process karenge
    for(i = 0; i < n; i++)
    {
        int found = -1;

        // Har page access par time increase hoga
        time++;

        // Check karna ki current page already frame mein hai ya nahi
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = j;    // Page jis frame mein mila uska index
                break;
            }
        }

        // Agar page already present hai (Page Hit)
        if(found != -1)
        {
            // Us page ka last-used time update karenge
            lastUsed[found] = time;
        }
        else
        {
            // Page present nahi hai (Page Fault)
            int position = -1;

            // Pehle check karenge koi empty frame available hai ya nahi
            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    position = j;
                    break;
                }
            }

            // Agar koi empty frame nahi mila, toh LRU page replace karenge
            if(position == -1)
            {
                position = 0;

                // Sabse chhota lastUsed time find karna
                for(j = 1; j < f; j++)
                {
                    if(lastUsed[j] < lastUsed[position])
                    {
                        position = j;
                    }
                }
            }

            // Selected frame mein new page insert karna
            frames[position] = pages[i];

            // New page ka last-used time update karna
            lastUsed[position] = time;

            // Page fault count increase karna
            faults++;
        }

        // Current page aur frames display karna
        printf("%d\t", pages[i]);

        for(j = 0; j < f; j++)
        {
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        printf("\n");
    }

    // Total page faults display karna
    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
