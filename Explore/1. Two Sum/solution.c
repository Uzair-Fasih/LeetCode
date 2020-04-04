#include <stdio.h>
#include <stdlib.h>

unsigned int mapsize = 100;

typedef struct entry_t {
  int key;
  int val;
  struct entry_t *next;
} entry_t;

entry_t **hashtable;

void initHashtable () {
  hashtable = malloc(sizeof(entry_t*) * mapsize);
  for (int i = 0; i < mapsize; i++) {
    entry_t entry;
    entry.key = -1;
    entry.val = -1;
    hashtable[i] = malloc(sizeof(entry));
    *hashtable[i] = entry;
  }
}

void addToHashTable (int key, int val) {
  unsigned int index = key % mapsize;
  entry_t entry;
  entry.key = key;
  entry.val = val;
  entry_t *iterator = hashtable[index];

  while (iterator -> val != -1) {
    entry_t entry_default;
    entry.key = -1;
    entry.val = -1;
    iterator -> next = malloc(sizeof(entry_default));
    *iterator -> next = entry_default;
    iterator = iterator -> next;
  }

  *iterator = entry;
}

int checkIfKeyExists (int key) {
  unsigned int index = key % mapsize;
  entry_t *iterator = hashtable[index];
  int exists = -1;
  while (iterator -> val != -1) {
    if (iterator -> key == key) {
      exists = iterator -> val;
      break;
    }
    iterator = iterator -> next;
  }
  return exists;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  if (mapsize <= numsSize) mapsize += (numsSize / 10) * 10;
  initHashtable();

  int exists, complement, i = 0;
  for (; i < numsSize; i++) {
    complement = target - nums[i];
    exists = checkIfKeyExists(complement);
    if (exists != -1) break;
    addToHashTable(nums[i], i);
  }
  free(hashtable);
  *returnSize = 2;
  int *solution = (int*) malloc(*returnSize * sizeof(int));
  solution[0] = exists;
  solution[1] = i;
  return solution;
}

int main (int argc, char *argv) {
  int problem[] = { 230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};
  int *sol = twoSum(problem, 100, 542, problem);
  printf("{ %d, %d }", sol[0], sol[1]);
  return 0;
}