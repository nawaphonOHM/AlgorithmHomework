# include <stdio.h>

typedef struct structA
{
    unsigned int weight;
    unsigned int price;
}item;

void zeroandoneKnapsack (item items[], unsigned int selectedItems[], 
                        unsigned int* optimazeSolution, 
                        unsigned int weight, unsigned int selected, 
                        unsigned int maxPrice, unsigned int wholeItem);
unsigned int priceSumation (item items[], 
                        unsigned int selectedItems[], 
                        unsigned int wholeItem);
void changedSelecteditems (unsigned int selectedItems[], 
                            unsigned int* optimazeSolution, 
                            unsigned int count);
unsigned int weightSumation (item items[], 
                            unsigned int selectedItems[], 
                            unsigned int wholeItem);                           

int main ()
{
    item items[] = {
        {10, 7}, 
        {24, 15}, 
        {8, 3}, 
        {1, 2}, 
        {15, 9}, 
        {4, 5}
    };
    unsigned int selectedItems[] = {
        0, 
        0,
        0,
        0,
        0,
        0
    };
    unsigned int optimazeSolution[] = {
        0, 
        0,
        0,
        0,
        0,
        0
    };
    unsigned int i;

    zeroandoneKnapsack (items, selectedItems, &optimazeSolution[0], 25, 0, 0, 6);

    for (i = 0; i < 6; i++)
    {
        if (optimazeSolution[i] == 1)
        {
            printf ("Selected the %u item and has value %u\n", 
            i + 1, 
            items[i].price);
        }
    }

    return 0;
}

void zeroandoneKnapsack (item items[], unsigned int selectedItems[], 
                        unsigned int* optimazeSolution, 
                        unsigned int weight, unsigned int selected, 
                        unsigned int maxPrice, unsigned int wholeItem)
{
    unsigned int sumPrice = priceSumation (items, selectedItems, wholeItem);
    unsigned int i;
    
    if (sumPrice > maxPrice)
    {
        maxPrice = sumPrice;
        changedSelecteditems (selectedItems, optimazeSolution, wholeItem);
    }

    for (i = selected; i < wholeItem; i++)
    {
        selectedItems[i] = 1;

        if (weightSumation (items, selectedItems, wholeItem) < weight)
        {
            zeroandoneKnapsack (items, 
            selectedItems, 
            optimazeSolution, 
            weight, i + 1, 
            maxPrice, 
            wholeItem);
        }
        else
        {
            selectedItems[i] = 0;
        }
    }
}

unsigned int priceSumation (item items[], 
                        unsigned int selectedItems[], 
                        unsigned int wholeItem)
{
    unsigned int i;
    unsigned int sum = 0;

    for (i = 0; i < wholeItem; i++)
    {
        sum += (items[i].price) * (selectedItems[i]);
    }

    return sum;
}

void changedSelecteditems (unsigned int selectedItems[], 
                            unsigned int* optimazeSolution, 
                            unsigned int count)
{
    unsigned int i;

    for (i = 0; i < count; i++)
    {
        *(optimazeSolution + i) = selectedItems[i];
    }
}

unsigned int weightSumation (item items[], 
                            unsigned int selectedItems[], 
                            unsigned int wholeItem)
{
    unsigned int i;
    unsigned int sum = 0;

    for (i = 0; i < wholeItem; i++)
    {
        sum += (items[i].weight) * (selectedItems[i]);
    }

    return sum;
}