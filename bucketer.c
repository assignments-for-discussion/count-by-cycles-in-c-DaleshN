#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
}s;

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  for(int i=0;i<nBatteries;i++)
  {
    if(cycles[i]<=150 && cycles[i]>=0)
    {
        s.lowCount++;
    }
        if(cycles[i]>150&&cycles[i]<649)
    {
        s.mediumCount++;
    }
        if(cycles[i]>650)
    {
        s.highCount++;
    }
    
  }
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000, 0, 150, 650};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(&chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount = 2);
  assert(counts.mediumCount = 4);
  assert(counts.highCount = 3);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
