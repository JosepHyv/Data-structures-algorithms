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


func SelectionSort(array []int) {
	for i := range array {
		minElement := len(array) - 1
		for j := len(array) - 1; j >= i; j-- {
			if array[minElement] > array[j] {
				minElement = j
			}
		}
		if array[i] > array[minElement] {
			array[i], array[minElement] = array[minElement] , array[i]
		}
	}
}

func main(){
	numbers := GenerateArray(10, 0, 100)
	fmt.Println("Original Array: ", numbers)
	SelectionSort(numbers)
	fmt.Println("Sorted Array: ", numbers)
}
