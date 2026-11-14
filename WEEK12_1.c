
#include <stdio.h>

int main()
{
    int pages[100];       // Page reference string store karne ke liye
    int frames[20];       // Memory frames store karne ke liye
    int n, f;             // n = total pages, f = total frames
    int i, j;
    int pointer = 0;      // Next page kis frame mein replace hoga
    int faults = 0;       // Total page faults count karega

    // Total pages input lena
    printf("Enter number of pages: ");
    scanf("%d", &n);

    // Page reference string input lena
    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    // Total frames input lena
    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initially saare frames empty rakhenge
    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\n");

    // Har page ko ek-ek karke memory mein check karenge
    for(i = 0; i < n; i++)
    {
        int found = 0;    // Check karega page already present hai ya nahi

        // Current page ko saare frames mein search karna
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;    // Page already present hai (Page Hit)
                break;
            }
        }

        // Agar page memory mein present nahi hai
        if(!found)
        {
            // FIFO ke according pointer wale frame ko replace karenge
            frames[pointer] = pages[i];

            // Pointer ko next frame par move karenge
            // Modulo se pointer last frame ke baad 0 par aa jayega
            pointer = (pointer + 1) % f;

            // Page fault count increase karenge
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
