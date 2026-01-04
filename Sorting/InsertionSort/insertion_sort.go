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

func InsertionSort(array []int){
	for i := range array {
		for j := i; j > 0 && array[j-1] > array[j]; j-- {
			array[j], array[j-1] = array[j-1], array[j]
		}
	}
}

func main(){
	numbers := GenerateArray(10, 0, 100)
	fmt.Println("Original Array: ", numbers)
	InsertionSort(numbers)
	fmt.Println("Sorted Array: ", numbers)
}
