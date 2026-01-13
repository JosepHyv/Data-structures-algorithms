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


func merge(start, mid, end int, array []int){
	left := make([]int, mid - start + 1)
	right := make([]int, end - mid)

	for i := range left {
		left[i] = array[start + i];
	}
	for i := range right{
		right[i] = array[mid + i + 1];
	}


	i , j := 0, 0

	for i < len(left) && j < len(right) {
		if left[i] < right[j] {
			array[start] = left[i]
			i++
		} else {
			array[start] = right[j]
			j++
		}
		start++
	}


	for i < len(left) {
		array[start] = left[i]
		start++
		i++
	}
	for j < len(right) {
		array[start] = right[j]
		start++
		j++
	}
}


func mergeSort(start, end int, array []int){
	if start >= end {
		return
	}

	middle := (end + start) / 2
	mergeSort(start, middle, array)
	mergeSort(middle + 1, end, array)
	merge(start, middle, end, array)
}


func MergeSort(array []int){
	start := 0
	end := len(array) - 1
	mergeSort(start, end, array)
}

func main(){
	numbers := GenerateArray(10, 0, 100)
	fmt.Println("Original Array: ", numbers)
	MergeSort(numbers)
	fmt.Println("Sorted Array: ", numbers)
}
