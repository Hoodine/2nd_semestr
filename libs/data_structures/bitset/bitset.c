#include <stdio.h>
#include <assert.h>
#include "bitset.h"

bitset bitset_create(unsigned maxValue) {
    assert(maxValue < 32);
    bitset temp_set;
    temp_set.values = 0;
    temp_set.maxValue = maxValue;

    return temp_set;
}

bool bitset_in(bitset set, unsigned int value) {
    if (value > set.maxValue)
        return false;

    return (set.values & (1 << value)) != 0;
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values;
}

bool bitset_isSubset(bitset subset, bitset set) {
    return ((subset.values & set.values) == set.values) && (set.values != subset.values);
}

bool bitset_isSubsetStrong(bitset subset, bitset set) {
    return (!bitset_isSubset(subset, set));
}

void bitset_insert(bitset *set, unsigned int value) {
    set->values = set->values | (1 << value);
}

void bitset_deleteElement(bitset *set, unsigned int value) {
    set->values = set->values & ~(1 << value);
}

bitset bitset_union(bitset set1, bitset set2) {
    bitset temp_set = {
            0,
            10
    };
    temp_set.values = set1.values | set2.values;

    return temp_set;
}

bitset bitset_intersection(bitset set1, bitset set2) {
    bitset temp_set = {
        0,
        10
    };
    temp_set.values = set1.values & set2.values;

    return temp_set;
}

bitset bitset_difference(bitset set1, bitset set2) {
    bitset temp_set = {
            0,
            10
    };
    temp_set.values = set1.values & ~set2.values;

    return temp_set;
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    bitset temp_set = {
            0,
            10
    };
    temp_set.values = set1.values ^ set2.values;

    return temp_set;
}

bitset bitset_complement(bitset set) {
    bitset complement;
    complement.values = ~set.values & ((1 << set.maxValue) - 1);
    complement.maxValue = set.maxValue;

    return complement;
}

void bitset_print(bitset set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i <= set.maxValue; i++) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = 0;
        }
    }

    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}
