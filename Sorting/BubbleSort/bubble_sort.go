package main

import (
	"fmt"
	"math/rand/v2"
)

func GenerateArray(size, minNumber, maxNumber int) []int {
	array := make([]int, size);
	for index := range array {
		array[index] = rand.IntN(maxNumber - minNumber + 1) + minNumber;
	}
	return array
}

func BubbleSort(array []int) {
	for i := 0; i < len(array); i++ {
		for j := i+1; j < len(array); j++ {
			if array[i] > array[j] {
				array[i], array[j] = array[j], array[i]
			}
		}
	}
}

// Using Effective and modern golang https://go.dev/doc/effective_go#arrays
func ModernSyntaxBubbleSort(array []int) {
	for i := range array {
		for j := range array{
			if i != j && array[i] < array[j] {
				array[i], array[j] = array[j], array[i]
			}
		}
	}
}

func main(){
	numbers := GenerateArray(10, 0, 100)
	fmt.Println("Original Array: ", numbers)
	// BubbleSort(numbers)
	ModernSyntaxBubbleSort(numbers)
	fmt.Println("Sorted Array: ", numbers)
}
