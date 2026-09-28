#include <stdio.h>

#define TABLE_SIZE 10
#define NUM_IDS 8

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void displayTable(int hashTable[])
{
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("[%d] -> Empty\n", i);
        else
            printf("[%d] -> %d\n", i, hashTable[i]);
    }
}

int hashingSearch(int hashTable[], int key, int *comparisons)
{
    int index = hashFunction(key);

    *comparisons = 1;

    if (hashTable[index] == key)
        return index;

    return -1;
}

int linearSearch(int arr[], int n, int key, int *comparisons)
{
    int i;

    *comparisons = 0;

    for (i = 0; i < n; i++)
    {
        (*comparisons)++;

        if (arr[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    int songIDs[NUM_IDS] =
    {
        105, 210, 315, 420,
        525, 630, 735, 840
    };

    int hashTable[TABLE_SIZE];
    int i, index;
    int collisions = 0;

    int searchID;
    int hashComparisons;
    int linearComparisons;

    for (i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;

    printf("SONG ID HASHING USING DIVISION METHOD\n");
    printf("=====================================\n");

    for (i = 0; i < NUM_IDS; i++)
    {
        index = hashFunction(songIDs[i]);

        printf("\nInserting %d\n", songIDs[i]);
        printf("Hash value = %d %% %d = %d\n",
               songIDs[i], TABLE_SIZE, index);

        if (hashTable[index] != -1)
        {
            printf("Collision occurred at index %d\n", index);
            collisions++;
        }
        else
        {
            hashTable[index] = songIDs[i];
        }

        displayTable(hashTable);
    }

    printf("\nTotal Collisions = %d\n", collisions);

    printf("\nEnter Song ID to search: ");
    scanf("%d", &searchID);

    index = hashingSearch(hashTable, searchID, &hashComparisons);

    if (index != -1)
        printf("\nHashing Search: %d found at index %d\n",
               searchID, index);
    else
        printf("\nHashing Search: %d not found\n", searchID);

    printf("Hashing comparisons = %d\n", hashComparisons);

    index = linearSearch(songIDs, NUM_IDS,
                         searchID, &linearComparisons);

    if (index != -1)
        printf("\nLinear Search: %d found at position %d\n",
               searchID, index);
    else
        printf("\nLinear Search: %d not found\n", searchID);

    printf("Linear search comparisons = %d\n",
           linearComparisons);

    printf("\nLoad Factor = %d / %d = %.2f\n",
           NUM_IDS, TABLE_SIZE,
           (float)NUM_IDS / TABLE_SIZE);

    printf("\nAnalysis:\n");
    printf("Hashing provides approximately O(1) average search time.\n");
    printf("Linear search has O(n) average and worst-case time.\n");
    printf("Collisions can increase the number of operations in hashing.\n");

    return 0;
}
