//NawaphonIsarathanachaikul 4/24/2018

#include <stdio.h>

typedef struct structA
{
    unsigned char starttime : 4;
    unsigned char endtime : 4;
    unsigned int reservedMoney;
}reservedTransections;

void quicksort (reservedTransections* startFlag, reservedTransections* lastFlag);
reservedTransections* partition (reservedTransections* startFlag, reservedTransections* lastFlag);
void sortByMoney (reservedTransections* startFlag, reservedTransections* lastFlag);

int main (void)
{
    reservedTransections data[] = {
        {0, 3, 620}, 
        {2, 5, 400}, 
        {8, 10, 200}, 
        {4, 8, 400}, 
        {1, 4, 300}, 
        {0, 2, 200}, 
        {5, 8, 300}
    };

    reservedTransections* startFlag;
    reservedTransections* lastFlag;
    unsigned int starterTimeFlag;
    unsigned int counterFlag;
    unsigned int totalData;

    startFlag = &data[0];
    totalData = sizeof (data) / sizeof (reservedTransections);
    lastFlag = &data[0] + (totalData - 1);
    starterTimeFlag = 0;

    quicksort (startFlag, lastFlag);
    sortByMoney (startFlag, lastFlag);

    for(counterFlag = 0; counterFlag < totalData; counterFlag++)
    {
        if (startFlag -> starttime >= starterTimeFlag)
        {
            printf("Choose the %u list is <%u, %u, %u>\n", 
            counterFlag + 1, 
            startFlag -> starttime, 
            startFlag -> endtime, 
            startFlag -> reservedMoney);

            starterTimeFlag = startFlag -> endtime;
        }

        startFlag++;
    }

    return 0;
}

reservedTransections* partition (reservedTransections* startFlag, reservedTransections* lastFlag)
{
    reservedTransections* pivot;
    reservedTransections* intialFlag;
    reservedTransections temp;

    pivot = startFlag;
    intialFlag = pivot - 1;
    lastFlag++;

    while (intialFlag < lastFlag)
    {
        while ((--lastFlag) -> starttime > pivot -> starttime)
        {

        }

        while ((++intialFlag) -> starttime < pivot -> starttime)
        {

        }

        if (intialFlag < lastFlag)
        {
            temp = *intialFlag;
            *intialFlag = *lastFlag;
            *lastFlag = temp;
        }
        
    }

    return lastFlag;
}

void quicksort (reservedTransections* startFlag, reservedTransections* lastFlag)
{
    reservedTransections* intialFlag;
    reservedTransections* newLastFlag;
    
    intialFlag = startFlag;

    if (intialFlag >= lastFlag)
    {
        return;
    }

    newLastFlag = partition (intialFlag, lastFlag);
    quicksort (intialFlag, newLastFlag);
    quicksort (newLastFlag + 1, lastFlag);
}

void sortByMoney (reservedTransections* startFlag, reservedTransections* lastFlag)
{
    reservedTransections temp;

    while (startFlag < lastFlag)
    {
        if (startFlag -> starttime == (startFlag + 1) -> starttime 
        && startFlag -> reservedMoney < (startFlag + 1) -> reservedMoney)
        {
            temp = *startFlag;
            *startFlag = *(startFlag + 1);
            *(startFlag + 1) = temp;
        }

        startFlag++;
    }

    return;
}
