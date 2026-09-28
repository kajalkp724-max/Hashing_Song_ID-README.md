# Hashing of Song IDs

## Assignment

Implementation of a hash table using the Division Method for storing and searching song IDs.

---

## 1. Aim

To implement a hash table using the Division Method and compare hashing search with linear search.

---

## 2. Song IDs

The following song IDs are used:

- 105
- 210
- 315
- 420
- 525
- 630
- 735
- 840

---

## 3. Hash Function

The Division Method is used.

The hash function is:

h(k) = k % 10

where:

- `k` = song ID
- `10` = hash table size

---

## 4. Hash Values

| Song ID | Hash Calculation | Hash Index |
|--------:|------------------:|-----------:|
| 105 | 105 % 10 | 5 |
| 210 | 210 % 10 | 0 |
| 315 | 315 % 10 | 5 |
| 420 | 420 % 10 | 0 |
| 525 | 525 % 10 | 5 |
| 630 | 630 % 10 | 0 |
| 735 | 735 % 10 | 5 |
| 840 | 840 % 10 | 0 |

---

## 5. Collision

A collision occurs when two or more keys produce the same hash index.

For this data:

- 105, 315, 525 and 735 produce index 5.
- 210, 420, 630 and 840 produce index 0.

Therefore, collisions occur frequently because the selected song IDs have the same last digit.

---

## 6. Searching

Two searching methods are considered:

### Hashing Search

The hash value of the required song ID is calculated and the corresponding position is checked.

Average time complexity:

O(1)

### Linear Search

The array is searched sequentially from the first element until the required song ID is found.

Average time complexity:

O(n)

Worst-case time complexity:

O(n)

---

## 7. Load Factor

The load factor is calculated as:

Load Factor = Number of stored elements / Hash table size

For this assignment:

Load Factor = 8 / 10

Load Factor = 0.8

Therefore, the hash table is 80% occupied.

---

## 8. Collision Effect

Collisions increase the number of operations required to insert or search for elements.

A good hash function should distribute keys across the table as evenly as possible.

In this example, many song IDs map to only two hash indexes, resulting in a high number of collisions.

---

## 9. Complexity Comparison

| Method | Average Time | Worst-case Time |
|--------|--------------|-----------------|
| Hashing | O(1) | O(n) |
| Linear Search | O(n) | O(n) |

Hashing can provide faster searching when the hash function distributes the keys efficiently and collisions are properly handled.

---

## 10. Conclusion

The Division Method provides a simple way to calculate hash indexes.

For the given song IDs, several collisions occur because multiple IDs generate the same hash index.

Hashing can provide efficient average-case searching, while linear search checks elements sequentially.

The performance of hashing depends on the hash table size, load factor, hash function, and collision-handling method.
