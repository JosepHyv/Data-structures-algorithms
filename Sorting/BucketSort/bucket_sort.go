package main

import (
	"fmt"
	"slices"
	"math/rand/v2"
)

func GenerateArray(size, minNumber, maxNumber int) []int {
	array := make([]int, size);
	for index := range array {
		array[index] = rand.IntN(maxNumber - minNumber + 1) + minNumber;
	}
	return array
}


func BucketSort(array []int) {
	// this method works with go 1.21+
	maxValue := slices.Max(array)
	bucket := make([]int, maxValue + 1)
	for _, value := range array {
		bucket[value]++;
	}

	original_it := 0
	for bucket_it := 0;
		bucket_it <= maxValue &&
		original_it < len(array);
		bucket_it ++ {
		for bucket[bucket_it] > 0 {
			array[original_it] = bucket_it;
			bucket[bucket_it]--;
			original_it++;
		}
	}
}

func main(){
	numbers := GenerateArray(10, 0, 100)
	fmt.Println("Original Array: ", numbers)
	BucketSort(numbers)
	fmt.Println("Sorted Array: ", numbers)
}
